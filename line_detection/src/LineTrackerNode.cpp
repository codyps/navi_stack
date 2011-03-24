#include "LineTrackerNode.hpp"

#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl_ros/point_cloud.h>

LineTrackerNode::LineTrackerNode(ros::NodeHandle nh)
	: m_nh(nh)
{
	m_sub_pts = nh.subscribe<PointNormalCloud>("line_points", 1, &LineTrackerNode::PointCloudCallback, this);
}

void LineTrackerNode::PointCloudCallback(PointNormalCloud::ConstPtr const &msg_ptsn)
{
	// Discard the points' normal vector (for now).
	// TODO: Can I do this without copying any memory?
	PointCloud msg_pts;
	msg_pts.points.resize(msg_ptsn->points.size());

	for (size_t i = 0; i < msg_ptsn->points.size(); ++i) {
		pcl::PointNormal  pt_src = msg_ptsn->points[i];
		pcl::PointXYZ    &pt_dst = msg_pts.points[i];
		pt_dst.x = pt_src.x;
		pt_dst.y = pt_src.y;
		pt_dst.z = pt_src.z;
	}

	// Use RANSAC to fit as many linear models as possible.
	int fits = 0;
	for (;;) {
		pcl::SACSegmentation<pcl::PointXYZ> seg;
		seg.setOptimizeCoefficients(true);
		seg.setModelType(pcl::SACMODEL_LINE);
		seg.setMethodType(pcl::SAC_RANSAC);
		seg.setDistanceThreshold(0.010);
		seg.setInputCloud(msg_pts.makeShared());

		pcl::ModelCoefficients coefficients;
		pcl::PointIndices inliers;
		seg.segment(inliers, coefficients);

		// Stop fitting linear models when we run out of points.
		if (inliers.indices.size() < 5) break;
		++fits;

		// TODO: Remove the inliers for the next fit.

		int n = msg_pts->points.size();
		ROS_INFO("Fit %d lines to %d points.", fits, n);
	}

	// TODO: Publish the PWL fit as visualization markers.
}
