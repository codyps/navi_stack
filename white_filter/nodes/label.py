#!/usr/bin/env python

from __future__ import print_function

import roslib
roslib.load_manifest('white_filter')

import cv
import csv
import itertools
import sys

try:
	file_clr = sys.argv[1]
	file_tru = sys.argv[2]
except IndexError:
	print('err: incorrect number of arguments', file=sys.stderr)
	print('usage: label.py <image> <mask>', file=sys.stderr)
	sys.exit(1)

writer   = csv.writer(sys.stdout)
img_clr = cv.LoadImageM(file_clr, cv.CV_LOAD_IMAGE_COLOR)
img_tru = cv.LoadImageM(file_tru, cv.CV_LOAD_IMAGE_GRAYSCALE)

img_hsv = cv.CreateMat(img_clr.rows, img_clr.cols, cv.CV_8UC3)
cv.CvtColor(img_clr, img_hsv, cv.CV_RGB2HSV)

assert(img_clr.rows == img_tru.rows)
assert(img_clr.cols == img_tru.cols)

pixels = itertools.product(range(0, img_clr.rows), range(0, img_clr.cols))
for (y, x) in pixels:
	rgb   = map(int, img_clr[y, x])
	hsv   = map(int, img_hsv[y, x])
	label = [ int(img_tru[y, x]) ]
	writer.writerow(rgb + hsv + label)
