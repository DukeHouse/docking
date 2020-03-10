﻿#ifndef PCLHELPERS_H
#define PCLHELPERS_H

// Auto-generated from cfg/ directory.
#include <docking/Headers.h>
#include <tf/tf.h>
#include <tf_conversions/tf_eigen.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Vector3.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2/convert.h>
#include <tf2/utils.h>
#include <tf2/impl/utils.h>
#include <tf2/impl/convert.h>
#include <tf2_eigen/tf2_eigen.h>
#include <tf2_ros/transform_broadcaster.h>
#include  <tf/transform_listener.h>
#include  <tf2_ros/transform_listener.h>
#include  <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include  <tf2/LinearMath/Transform.h>
#include  <tf2/LinearMath/Quaternion.h>
#include  <tf2/convert.h>
#include  <tf2/utils.h>
#include  <tf2/impl/utils.h>
#include  <tf2/impl/convert.h>
#include  <tf2/transform_datatypes.h>
#include <geometry_msgs/TransformStamped.h>
#include <math.h>

//void printTF2Matrix(tf2::Matrix3x3 tf2m){
//  tf2::Vector3 r0 = tf2m.getRow(0);
//  tf2::Vector3 r1 = tf2m.getRow(1);
//  tf2::Vector3 r2 = tf2m.getRow(2);
//  std::cout << r0.x() << " " << r0.y() << " " << r0.z() << std::endl;
//  std::cout << r1.x() << " " << r1.y() << " " << r1.z() << std::endl;
//  std::cout << r2.x() << " " << r2.y() << " " << r2.z() << std::endl;
//}

void printTF2Matrix(tf2::Matrix3x3 tf2m)
{
  tf2::Vector3 r0 = tf2m.getRow(0);
  tf2::Vector3 r1 = tf2m.getRow(1);
  tf2::Vector3 r2 = tf2m.getRow(2);
  printf("Rotation matrix :\n");
  printf("    | %6.3f %6.3f %6.3f | \n", r0.x(), r0.y(), r0.z());
  printf("R = | %6.3f %6.3f %6.3f | \n", r1.x(), r1.y(), r1.z());
  printf("    | %6.3f %6.3f %6.3f | \n", r2.x(), r2.y(), r2.z());
//  printf("Translation vector :\n");
//  printf("t = < %6.3f, %6.3f, %6.3f >\n\n", matrix(0, 3), matrix(1, 3), matrix(2, 3));
}

void print4x4Matrix(const Eigen::Matrix4d &matrix)
{
  printf("Rotation matrix :\n");
  printf("    | %6.3f %6.3f %6.3f | \n", matrix(0, 0), matrix(0, 1), matrix(0, 2));
  printf("R = | %6.3f %6.3f %6.3f | \n", matrix(1, 0), matrix(1, 1), matrix(1, 2));
  printf("    | %6.3f %6.3f %6.3f | \n", matrix(2, 0), matrix(2, 1), matrix(2, 2));
  printf("Translation vector :\n");
  printf("t = < %6.3f, %6.3f, %6.3f >\n\n", matrix(0, 3), matrix(1, 3), matrix(2, 3));
}

void printTF2Quarternion(tf2::Quaternion tf2q)
{
  printf("QUARTERNION :\n");
  printf("    | %6.3f | \n", tf2q.x());
  printf("Q = | %6.3f | \n", tf2q.y());
  printf("    | %6.3f | \n", tf2q.z());
  printf("    | %6.3f | \n", tf2q.w());
}

void printTFQuarternion(tf::Quaternion tfq)
{
  printf("QUARTERNION :\n");
  printf("    | %6.3f | \n", tfq.x());
  printf("Q = | %6.3f | \n", tfq.y());
  printf("    | %6.3f | \n", tfq.z());
  printf("    | %6.3f | \n", tfq.w());
}

// Convert Pose->Orientation to String
std::string quaternionString(tf::Quaternion tfq){
  std::ostringstream qss;
  qss << std::fixed << std::setprecision(3) << "[ "<< tfq.getX() << ",  " << tfq.getY() << ",  " << tfq.getZ() << ",  " << tfq.getW() << " ]";
 return qss.str();
}

std::string quaternionString(tf2::Quaternion tf2q){
  std::ostringstream qss;
  qss << std::fixed << std::setprecision(3) << "[ "<< tf2q.getX() << ",  " << tf2q.getY() << ",  " << tf2q.getZ() << ",  " << tf2q.getW() << " ]";
 return qss.str();
}

// Convert Pose->Orientation to String
std::string quaternionString(geometry_msgs::Quaternion q){
  std::ostringstream qss;
  qss << std::fixed << std::setprecision(2) << "[ "<< q.x << ",  " << q.y << ",  " << q.z << ",  " << q.w << " ]";
 return qss.str();
}

std::string twistString(geometry_msgs::Twist t){
  std::ostringstream tss;
  tss << std::fixed << std::setprecision(3) << "[ X: "<< t.linear.x << ",  Z: " << t.angular.z <<  " ]";
 return tss.str();
}

std::string vectorString(tf2::Vector3 tf2v3){
  std::ostringstream qss;
  qss << std::fixed << std::setprecision(2) << "[ "<< tf2v3.getX() << ",  " << tf2v3.getY() << ",  " << tf2v3.getZ() << " ]";
 return qss.str();
}

std::string transformString(tf2::Transform tf2)
{
  // Convert Transform->Position to String
  tf2::Vector3 v = tf2.getOrigin();
  std::ostringstream positionSS;
  positionSS << std::fixed << std::setprecision(2) << std::endl << "[ "<< v.getX() << ",  " << v.getY() << ",  " << v.getZ() << " ] ";

//  // Extract Yaw from Quarternion
//  std::ostringstream yawSS;
//  yawSS << std::fixed << std::setprecision(2) << "YAW: " << tf2::getYaw(tf2.getRotation()) << "\n";

  // Concatenate strings
  std::string poseString = positionSS.str() + quaternionString(tf2.getRotation());
//  std::string poseString = positionSS.str() + yawSS.str() + quarternionSS.str();
  return poseString;
}

std::string transformString(geometry_msgs::Transform tfMsg)
{
  tf2::Transform tf2;
  tf2::convert(tfMsg,tf2);
  return transformString(tf2);
}

std::string transformString(geometry_msgs::TransformStamped tfMsgStamped)
{
  std::ostringstream frameSS;
  frameSS << " frame_id: " << tfMsgStamped.header.frame_id;
  frameSS << " child_frame_id: " << tfMsgStamped.child_frame_id;

  tf2::Transform tf2;
  tf2::convert(tfMsgStamped.transform,tf2);

  // Concatenate strings
  std::string pose_string =  transformString(tf2) + frameSS.str() ;
  return pose_string;
  }


Eigen::Vector4f toEigen(pcl::ModelCoefficients pmc){
  pcl::ModelCoefficients::Ptr pmcPtr (new pcl::ModelCoefficients(pmc));
  pmcPtr->values.resize (4);
  pmcPtr->values[0] = 1.0;
  pmcPtr->values[1] = 2.0;
  pmcPtr->values[2] = 3.0;
  pmcPtr->values[3] = 4.0;
  Eigen::Vector4f ev4f (pmcPtr->values.data());
  return ev4f;
}

geometry_msgs::PoseStamped Matrix4TFtoPose(Eigen::Matrix4f m4f){

  Eigen::Matrix4d m4d = m4f.cast <double> ();
  geometry_msgs::PoseStamped poseStamped;

////  ROS_INFO_STREAM("Matrix4TFtoPose-- Creating tf::Transform object");
  tf2::Transform tf2;
  Eigen::Affine3d eigenAffine;
  eigenAffine.matrix() = m4d;
  geometry_msgs::TransformStamped tfMsg;
  tfMsg = tf2::eigenToTransform(eigenAffine);
  tf2::convert(tfMsg.transform,tf2);
  tf2::toMsg(tf2,poseStamped.pose);

  poseStamped.header.stamp = ros::Time::now();
  poseStamped.header.frame_id = "laser";

  return poseStamped;
}


geometry_msgs::TransformStamped Matrix4TFtoTransform(Eigen::Matrix4f m4f){

  Eigen::Matrix4d m4d = m4f.cast <double> ();
  Eigen::Affine3d eigenAffine;
  eigenAffine.matrix() = m4d;

  tf2::Transform tf2;
  geometry_msgs::TransformStamped tfMsg;
  tf2::convert(tf2,tfMsg.transform);

  tfMsg = tf2::eigenToTransform(eigenAffine);

//  ROS_INFO_STREAM("Matrix4TFtoTransformStamped-- Extracting Rotation Matrix in Eigen::Matrix3d ");
//  ROS_INFO_STREAM("Matrix4TFtoTransformStamped-- Copying Rotation Matrix into tf::Matrix3x3");

  tfMsg.header.stamp = ros::Time::now();
  tfMsg.header.frame_id = "laser";
  tfMsg.child_frame_id = "dock";


//  ROS_INFO_STREAM("Matrix4TFtoTransformStamped-- RETURNING TRANSFORM ");
//  ROS_INFO_STREAM("Matrix4TFtoTransformStamped-- TRANSFORM " << tfs.transform);

  return tfMsg;
}



double getAngle(docking::Line l1, docking::Line l2){

  pcl_msgs::ModelCoefficients lmc1 = l1.coefficients;
//  ROS_WARN_STREAM("GET_ANGLE-- COEF 1 " << l1.coefficients);
//  ROS_WARN_STREAM("GET_ANGLE-- START/END 1 " << l1.segment);
  pcl::ModelCoefficients pmc1;
  pcl_conversions::toPCL(lmc1, pmc1);
  tf2::Vector3 tf2v1(pmc1.values[3],pmc1.values[4],pmc1.values[5]);
//  ROS_WARN_STREAM("GET_ANGLE-- TF2 Vec 1 tf2v1.x() " <<  tf2v1.x() << " tf2v1.y() " << tf2v1.y() << " tf2v1.z() " << tf2v1.z());

  pcl_msgs::ModelCoefficients lmc2 = l2.coefficients;
//  ROS_WARN_STREAM("GET_ANGLE-- COEF 2 " << l2.coefficients);
//  ROS_WARN_STREAM("GET_ANGLE-- START/END 2 " << l2.segment);
  pcl::ModelCoefficients pmc2;
  pcl_conversions::toPCL(lmc2, pmc2);
  tf2::Vector3 tf2v2(pmc2.values[3],pmc2.values[4],pmc2.values[5]);
//  ROS_WARN_STREAM("GET_ANGLE-- TF2 Vec 2 tf2v2.x() " <<  tf2v2.x() << " tf2v2.y() " << tf2v2.y() << " tf2v2.z() " << tf2v2.z());

  double angleRad, angleDeg;
  angleRad = tf2::tf2Angle(tf2v1,tf2v2);
  angleRad = fabs(angleRad);
  angleDeg = angleRad * (180/M_PI);

//  ROS_WARN_STREAM("GET_ANGLE-- ANGLE DEG " << angleDeg << " RAD " << angleRad);
  return angleDeg;
}

geometry_msgs::Point pointPCLToMSG(pcl::PointXYZ point) {
  geometry_msgs::Point pointMsg;
  // Get Min Point
  pointMsg.x = double(point.x);
  pointMsg.y = double(point.y);
  pointMsg.z = double(point.z);
  return pointMsg;
}

geometry_msgs::Point pointPCLToMSG(pcl::PointXYZRGB point) {
  geometry_msgs::Point pointMsg;
  // Get Min Point
  pointMsg.x = double(point.x);
  pointMsg.y = double(point.y);
  pointMsg.z = double(point.z);
  return pointMsg;
}

docking::MinMaxPoint getMinMaxPointMsg(typename pcl::PointCloud<pcl::PointXYZ>::Ptr inCloudPtr) {
  pcl::PointXYZ minPointPCL, maxPointPCL;
  pcl::getMinMax3D(*inCloudPtr, minPointPCL, maxPointPCL);
  docking::MinMaxPoint minMaxMsg;
//  ROS_INFO_STREAM("PCL minPoint: " << minPointPCL);
//  ROS_INFO_STREAM("PCL maxPoint: " << maxPointPCL);
  minMaxMsg.min = pointPCLToMSG(minPointPCL);
  minMaxMsg.max = pointPCLToMSG(maxPointPCL);
//  ROS_INFO_STREAM("MinMax msg: " << minMaxMsg);
//  std::cout << std::endl;
  return minMaxMsg;
}

docking::MinMaxPoint getMinMaxPointMsg(typename pcl::PointCloud<pcl::PointXYZRGB>::Ptr inCloudPtr) {
  pcl::PointXYZRGB minPointPCL, maxPointPCL;
  pcl::getMinMax3D(*inCloudPtr, minPointPCL, maxPointPCL);
  docking::MinMaxPoint minMaxMsg;
//  ROS_INFO_STREAM("getMinMaxPointMsg");
//  ROS_INFO_STREAM("PCL minPoint: " << minPointPCL);
//  ROS_INFO_STREAM("PCL maxPoint: " << maxPointPCL);
  minMaxMsg.min = pointPCLToMSG(minPointPCL);
  minMaxMsg.max = pointPCLToMSG(maxPointPCL);
//  ROS_INFO_STREAM(minMaxMsg);
//  std::cout << std::endl;
  return minMaxMsg;
}

double getEuclideanDistance(docking::Line line) {
  double length, x1, x2, y1, y2;
  x1 = line.segment.start_point.x;
  x2 = line.segment.end_point.x;
  y1 = line.segment.start_point.y;
  y2 = line.segment.end_point.y;
//  ROS_INFO_STREAM("getEuclideanDistance");
//  ROS_INFO_STREAM("SEG: ");
//  ROS_INFO_STREAM(line.segment);

  double dx = x2-x1;
  double dy = y2-y1;

  length = sqrt( dx*dx + dy*dy  );
//  ROS_INFO_STREAM("EUCLIDEAN DISTANCE: " << length);
//  std::cout << std::endl;
  return length;
}

double getEuclideanDistance(geometry_msgs::Point p1, geometry_msgs::Point p2) {
  double length, x1, x2, y1, y2;
  x1 = p1.x;
  x2 = p2.x;
  y1 = p1.y;
  y2 = p2.y;

  length = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)  );
  return length;
}

jsk_recognition_msgs::Segment minMaxToSegment(docking::MinMaxPoint minMax) {
  jsk_recognition_msgs::Segment segment;
  segment.start_point = minMax.min;
  segment.end_point = minMax.max;
  return segment;
}

float comparePoints(geometry_msgs::Point p1, geometry_msgs::Point p2){
  float avgDelta;
  avgDelta += abs(p2.x - p1.x);
  avgDelta += abs(p2.y - p1.y);
  avgDelta += abs(p2.z - p1.z);
  avgDelta = avgDelta/3;
  if(avgDelta < 0){
    avgDelta = 0;
  }
  return avgDelta;
}

float compareSegments(jsk_recognition_msgs::Segment s1, jsk_recognition_msgs::Segment s2){
  float avgDelta;
  avgDelta += comparePoints(s1.start_point, s2.start_point);
  avgDelta += comparePoints(s1.end_point, s2.end_point);
  avgDelta = avgDelta/2;
  if(avgDelta < 0){
    avgDelta = 0;
  }
  return avgDelta;
}

float compareOrientation(geometry_msgs::Quaternion q1, geometry_msgs::Quaternion q2){
  float avgDelta;
  avgDelta += abs(q2.x - q1.x);
  avgDelta += abs(q2.y - q1.y);
  avgDelta += abs(q2.z - q1.z);
  avgDelta += abs(q2.w - q1.w);
  avgDelta = avgDelta/4;
  if(avgDelta < 0){
    avgDelta = 0;
  }
  return avgDelta;
}

float comparePoses(geometry_msgs::Pose p1, geometry_msgs::Pose p2){
  float positionDelta = comparePoints(p1.position, p2.position);
  float orientationDelta = compareOrientation(p1.orientation, p2.orientation);
  float avgDelta = positionDelta + orientationDelta;
  avgDelta = avgDelta/2;
  if(avgDelta < 0){
    avgDelta = 0;
  }
  return avgDelta;
}

float compareCoefficients(pcl_msgs::ModelCoefficients c1, pcl_msgs::ModelCoefficients c2){
  float avgDelta;
  avgDelta = abs(c2.values[0] - c1.values[0]);
  avgDelta = abs(c2.values[1] - c1.values[1]);
  avgDelta = abs(c2.values[2] - c1.values[2]);
  avgDelta = abs(c2.values[3] - c1.values[3]);
  avgDelta = avgDelta/4;
  if(avgDelta < 0){
    avgDelta = 0;
  }
  return avgDelta;
}

void printIndices(pcl::PointIndices indices) {
   for(size_t i=0; i < indices.indices.size(); i++)
      std::cout << indices.indices.at(i) << ' ';
   //std::cout << std::endl;
}

int comparePointIndices(pcl_msgs::PointIndices pi1, pcl_msgs::PointIndices pi2){
  pcl_msgs::PointIndices diffPoints;
  int numDiffPoints;
//  int size1 = pi1.indices.size();
//  int size2 = pi2.indices.size();
  int biggerSize; int smallerSize;
  pcl_msgs::PointIndices bigger;
  pcl_msgs::PointIndices smaller;

  if(pi2.indices.size() == pi1.indices.size()){
    return 0.0;
  } else if (pi2.indices.size() > pi1.indices.size()){
    biggerSize = pi2.indices.size();
    bigger = pi2;
    smaller = pi1;
    smallerSize = pi1.indices.size();
  } else if (pi2.indices.size() < pi1.indices.size()){
    biggerSize = pi1.indices.size();
    bigger = pi1;
    smaller = pi2;
    smallerSize = pi2.indices.size();
  }

  for(int i=0; i<smallerSize; i++){
    for(int j=0; j<biggerSize; j++){
      if(smaller.indices.at(i) == bigger.indices.at(j)){
        bigger.indices.erase(bigger.indices.begin()+j);
        biggerSize -= 1;
      }
    }
  }

    numDiffPoints = bigger.indices.size();
    return numDiffPoints;
  }

///////////////// BEGIN COMBINE CLOUDS /////////////////
/// \brief CombineClouds      std::vector of pcl::PointXYZRGB Clouds
/// \param lineCloudVector
/// \param combinedCloud
///
void CombineClouds(
    std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr> lineCloudVector,
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr combinedCloud) {
  for (int i = 0; i < lineCloudVector.size(); i++) {
    *combinedCloud += (*lineCloudVector.at(i));
  }
}

/////
/// \brief CombineClouds sensor_msgs::PointCloud2
/// \param augendCloudMsgPtr    Main cloud
/// \param addendCloudMsgPtr    Cloud to be added to Main cloud
///
sensor_msgs::PointCloud2
CombineClouds(sensor_msgs::PointCloud2 augendCloudMsg,
              sensor_msgs::PointCloud2 addendCloudMsg) {

  pcl::PointCloud<pcl::PointXYZRGB> augendCloudPCL;
  //      ROS_INFO_STREAM("CONVERTING AUGENDCLOUDMSG TO PCL");
  pcl::fromROSMsg(augendCloudMsg, augendCloudPCL);

  pcl::PointCloud<pcl::PointXYZRGB>::Ptr addendCloudPCLPtr(
      new pcl::PointCloud<pcl::PointXYZRGB>);
  // ROS_INFO_STREAM("CONVERTING ADDENDCLOUDMSG TO PCL");
  pcl::fromROSMsg(addendCloudMsg, *addendCloudPCLPtr);

  // ROS_INFO_STREAM("ADDING PCL DETECTED LINE CLUSTERS");
  augendCloudPCL += *addendCloudPCLPtr;
  // ROS_INFO_STREAM("CONVERTING COMBINED LINE CLUSTER CLOUD TO ROS MSG");
  pcl::toROSMsg(augendCloudPCL, augendCloudMsg);
  return augendCloudMsg;
}
///////////////// END COMBINE CLOUDS /////////////////

///////////////// BEGIN SEPARATE CLOUDS /////////////////
/// \brief SeparateClouds
/// \param inliers
/// \param cloud
/// \return
///
std::pair<pcl::PointCloud<pcl::PointXYZRGB>::Ptr,pcl::PointCloud<pcl::PointXYZRGB>::Ptr> SeparateClouds(pcl::PointIndices::Ptr inliers, pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud) {

  pcl::PointCloud<pcl::PointXYZRGB>::Ptr inCloud(new pcl::PointCloud<pcl::PointXYZRGB>());
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr outCloud(new pcl::PointCloud<pcl::PointXYZRGB>());
  pcl::PointIndices outliers;

  // Obtain the inlier point cloud by copying only inlier indices to the
  // planeCloud for(int index : inliers->indices)
  //     inCloud->points.push_back(cloud->points[index]);
  // ****** ^ does the same as below for the inliers, cuz we already have the
  // inlier indices******
  //Create extract object
  pcl::ExtractIndices<pcl::PointXYZRGB> extract (true);
  extract.setInputCloud(cloud);
  extract.setIndices(inliers);

  // Get plane cloud (inliers)
  extract.setNegative(false); // Extract the inliers, not outliers
  extract.filter(*inCloud);   // Output cloud

  extract.getRemovedIndices(outliers);

  // Get obstacle cloud (outliers)
  extract.setNegative(true); // Extract the outliers, not inliers
  extract.filter(*outCloud); // Output cloud

//    ROS_INFO_STREAM("Inliers: " << inCloud->width * inCloud->height << " points Outliers: " << outCloud->width * outCloud->height << " points");
//    ROS_INFO_STREAM("Inliers: ");
//    printIndices(*inliers);
//    ROS_INFO_STREAM("Outliers: ");
//    printIndices(outliers);

  std::pair<pcl::PointCloud<pcl::PointXYZRGB>::Ptr,pcl::PointCloud<pcl::PointXYZRGB>::Ptr>segResult(inCloud, outCloud);
  return segResult;
}
///////////////// END SEPARATE CLOUDS /////////////////


///////////////// BEGIN GET CENTROID/////////////////
/// \brief getCentroid
/// \param inCloudPtr
/// \return centroid
///
geometry_msgs::Pose getCentroid(pcl::PointCloud<pcl::PointXYZRGB>::Ptr inCloudPtr) {
  Eigen::Vector4f centroidVec4f;
  pcl::compute3DCentroid(*inCloudPtr, centroidVec4f);
  geometry_msgs::Pose centroid;
  centroid.position.x = double(centroidVec4f[0]);
  centroid.position.y = double(centroidVec4f[1]);
  centroid.position.z = double(centroidVec4f[2]);
  centroid.orientation.x = 0.0;
  centroid.orientation.y = 0.0;
  centroid.orientation.z = 0.0;
  centroid.orientation.w = 1.0;
  //        std::cout << "The XYZ coordinates of the centroid are: ("
  //              << centroid.x << ", "
  //              << centroid.y << ", "
  //              << centroid.z << ")." << std::endl;
  return centroid;
}
///////////////// END GET CENTROID /////////////////

///////////////// BEGIN GET SEGMENT /////////////////
/// \brief getSegment
/// \param inCloudPtr
/// \return Segment
///
jsk_recognition_msgs::Segment getSegment(pcl::PointCloud<pcl::PointXYZRGB>::Ptr inCloudPtr){
  docking::MinMaxPoint mmp = getMinMaxPointMsg(inCloudPtr);
  jsk_recognition_msgs::Segment segment = minMaxToSegment(mmp);
  return segment;
}
///////////////// END GET SEGMENT /////////////////



#endif // PCLHELPERS_H
