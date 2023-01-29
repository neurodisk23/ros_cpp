#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include "pcl_conversions/pcl_conversions.h"
#include "pcl/point_cloud.h"
#include "pcl/point_types.h"

void cloudCallback(const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
{
  // Convert the incoming ROS message to a PCL point cloud
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::fromROSMsg(*cloud_msg, *cloud);

  // Do processing on the point cloud here...

  ROS_INFO("Received a Velodyne LiDAR point cloud with %d points.", (int)cloud->points.size());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "lidar_subscriber_node");
  ros::NodeHandle nh;

  ros::Subscriber cloud_sub = nh.subscribe("/velodyne_points", 1000, cloudCallback);

  ros::spin();

  return 0;
}

