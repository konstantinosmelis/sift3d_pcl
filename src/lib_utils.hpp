#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/arrayobject.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/keypoints/sift_keypoint.h>

pcl::PointCloud<pcl::PointXYZ> *build_point_cloud(double *array,
                                                  npy_intp *dimensions);

pcl::PointCloud<pcl::PointNormal> *build_point_cloud(double *array,
                                                     double *normals,
                                                     npy_intp *dimensions);

pcl::PointCloud<pcl::PointWithScale> *detect_keypoints(pcl::PointCloud<pcl::PointXYZ> *point_cloud);

pcl::PointCloud<pcl::PointWithScale> *detect_keypoints(pcl::PointCloud<pcl::PointNormal> *point_cloud);
