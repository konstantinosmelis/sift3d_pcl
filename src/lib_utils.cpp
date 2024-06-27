#include "lib_utils.hpp"

pcl::PointCloud<pcl::PointXYZ>::Ptr
*build_point_cloud(double *array, 
                   npy_intp *dimensions)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr
                            point_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    /* Populate the point cloud */
    for (int i = 0; i < dimensions[0]; i++)
    {
        pcl::PointXYZ point;
        /* The point coordinates */
        point.x = array[i * dimensions[0] + 0];
        point.y = array[i * dimensions[0] + 1];
        point.z = array[i * dimensions[0] + 2];
        point_cloud->push_back(point);
    }
    return point_cloud;
}

pcl::PointCloud<pcl::PointNormal>::Ptr
*build_point_cloud(double *array,
                   double *normals,
                   npy_intp *dimensions)
{
    pcl::PointCloud<pcl::PointNormal>::Ptr
                        point_cloud(new pcl::PointCloud<pcl::PointNormal>);
    /* Populate the point cloud */
    for (int i = 0; i < dimensions[0]; i++)
    {
        pcl::PointNormal point;
        /* The point coordinates */
        point.x = array[i * dimensions[0] + 0];
        point.y = array[i * dimensions[0] + 1];
        point.z = array[i * dimensions[0] + 2];
        /* The point normals */
        point.normal_x = normals[i * dimensions[0] + 0];
        point.normal_y = normals[i * dimensions[0] + 1];
        point.normal_z = normals[i * dimensions[0] + 2];
        point_cloud->push_back(point);
    }
    return point_cloud;
}

pcl::PointCloud<pcl::PointWithScale>::Ptr
*detect_keypoints(pcl::PointCloud<pcl::PointXYZ>::Ptr *point_cloud)
{
    pcl::SIFTKeypoint<pcl::PointXYZ, pcl::PointWithScale> sift;
    pcl::search::KdTree<pcl::PointXYZ>::Ptr
                        tree_sift(new pcl::search::KdTree<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointWithScale>::Ptr
                        keypoints(new pcl::PointCloud<pcl::PointWithScale>);
    /* Detect the keypoints */
    sift.setInputCloud(point_cloud);
    sift.setSearchMethod(tree_sift);
    sift.setScales(.5f, 8, 5);
    sift.setMinimumContrast(min_contrast);
    sift.compute(*keypoints);

    return keypoints;
}

pcl::PointCloud<pcl::PointWithScale>::Ptr
*detect_keypoints(pcl::PointCloud<pcl::PointNormal>::Ptr *point_cloud)
{

}
