#include "lib_utils.hpp"

pcl::PointCloud<pcl::PointXYZ>
*build_point_cloud(double *array, npy_intp *dimensions)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    /* Populate the point cloud */
    for (int i = 0; i < dimensions[0]; i++)
    {
        pcl::PointXYZ point;
        point.x = array[i * dimensions[0] + 0];
        point.y = array[i * dimensions[0] + 1];
        point.z = array[i * dimensions[0] + 2];
        cloud->push_back(point);
    }
    return cloud.get();
}
