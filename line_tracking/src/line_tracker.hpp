#ifndef LINE_TRACKER_HPP_
#define LINE_TRACKER_HPP_

#include <string>

#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <nav_msgs/GridCells.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <tf/transform_listener.h>

namespace tracker_node {

using nav_msgs::GridCells;

typedef unsigned int   Value;
typedef pcl::PointXY   Point2D;
typedef pcl::PointXYZ  Point3D;
typedef pcl::PointCloud<Point2D>  PointCloud2D;
typedef pcl::PointCloud<Point3D>  PointCloud3D;

class TrackerNodelet : public nodelet::Nodelet {
public:
	virtual void onInit(void);
	void AddPoints(PointCloud3D::ConstPtr const &pts_3d);

	double Distance(Point2D const &p1, Point2D const &p2) const;
	void ProjectPoint(Point3D const &pt_3d, Point2D &pt_2d) const;
	void GetRobotCenter(ros::Time stamp, Point2D &pt_2d) const;

	Value GetCellValue(double x, double y) const;
	void IncrementCell(double x, double y);

private:
	int m_grid_width;
	int m_grid_height;
	double m_grid_size;
	double m_range_max;
	std::string m_fr_fixed;
	std::string m_fr_robot;

	std::vector<Value> m_grid;
	boost::shared_ptr<tf::TransformListener> m_tf;

	ros::Publisher  m_pub_ren;
	ros::Subscriber m_sub_pts;

	void Point2Grid(double x, double y, int &grid_x, int &grid_y) const;
	int  Point2Index(double x, double y) const;

	void    Index2Grid(int i, int &grid_x, int &grid_y) const;
	Point2D Index2Point(int i) const;

	int     Grid2Index(int grid_x, int grid_y) const;
	Point2D Grid2Point(int grid_x, int grid_y) const;

};

};

#endif
