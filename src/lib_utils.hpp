#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/arrayobject.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/keypoints/sift_keypoint.h>

pcl::PointCloud<pcl::PointXYZ>::Ptr *build_point_cloud(double *array,
                                                       npy_intp *dimensions);

pcl::PointCloud<pcl::PointNormal>::Ptr *build_point_cloud(double *array,
                                                          double *normals,
                                                          npy_intp *dimensions);

pcl::PointCloud<pcl::PointWithScale>::Ptr *detect_sift_keypoints(pcl::PointCloud<pcl::PointXYZ>::Ptr *point_cloud);

pcl::PointCloud<pcl::PointWithScale>::Ptr *detect_sift_keypoints(pcl::PointCloud<pcl::PointNormal>::Ptr *point_cloud);
