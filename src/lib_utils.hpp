#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/arrayobject.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/keypoints/sift_keypoint.h>

pcl::PointCloud<pcl::PointNormal>::Ptr build_point_cloud(const double *array,
                                                          const double *normals,
                                                          const npy_intp *dimensions);

pcl::PointCloud<pcl::PointWithScale>::Ptr detect_sift_keypoints(const pcl::PointCloud<pcl::PointNormal>::Ptr &point_cloud);
