In this example, we include the necessary ROS headers, including ros/ros.h, sensor_msgs/PointCloud2.h, pcl_conversions/pcl_conversions.h, pcl/point_cloud.h, and pcl/point_types.h. The cloudCallback function is defined to process incoming Velodyne LiDAR point clouds.

The ros::init function is called to initialize the ROS system and create a node handle. Next, a ROS subscriber is created using the nh.subscribe method. This creates a subscriber that listens to the topic /velodyne_points and passes incoming point clouds to the cloudCallback function for processing.

In the cloudCallback function, the incoming ROS message is converted to a PCL point cloud using the pcl::fromROSMsg function. The point cloud can then be processed as desired. In this example, a simple message is printed to the console indicating the number of points in the point cloud. Finally, the ros::spin method is called to keep the node running and processing messages as they are received.
