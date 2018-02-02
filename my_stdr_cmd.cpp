#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
//node to send Twist commands to the Simple 2-Dimensional Robot Simulator via cmd_vel
int main(int argc, char **argv) {
    ros::init(argc, argv, "stdr_commander"); 
    ros::NodeHandle n; // two lines to create a publisher object that can talk to ROS
    ros::Publisher twist_commander = n.advertise<geometry_msgs::Twist>("/robot0/cmd_vel", 1);
    //some "magic numbers"
    double sample_dt = 0.01; //specify a sample period of 10ms  
    double speed = 1.0; // 1m/s speed command
    double yaw_rate = 0.5; //0.5 rad/sec yaw rate command
    double yaw_minus_rate = -0.5; //-0.5 rad/sec yaw rate command
    double time_3_sec = 3.0; // should move 3 meters or 1.5 rad in 3 seconds
    double time_4_sec = 4.0;
    
      
    geometry_msgs::Twist twist_cmd; //this is the message type required to send twist commands to STDR 
    // start with all zeros in the command message; should be the case by default, but just to be safe..
    twist_cmd.linear.x=0.0;
    twist_cmd.linear.y=0.0;    
    twist_cmd.linear.z=0.0;
    twist_cmd.angular.x=0.0;
    twist_cmd.angular.y=0.0;
    twist_cmd.angular.z=0.0;   

    ros::Rate loop_timer(1/sample_dt); //create a ros object from the ros “Rate” class; set 100Hz rate     
    double timer=0.0;
    //start sending some zero-velocity commands, just to warm up communications with STDR
    for (int i=0;i<10;i++) {
      twist_commander.publish(twist_cmd);
      loop_timer.sleep();
    }
//====================[First Move]===========================
    twist_cmd.linear.x=speed; //command to move forward
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }
    twist_cmd.linear.x=0.0; //stop moving forward
//=================[End of First Move, 3m]=============================
    
//=================[First Spin]====================================
    twist_cmd.angular.z=yaw_rate; //and start spinning in place
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }

    twist_cmd.angular.z=0.0; //and stop spinning in place 
//=================[End of First Spin,90 degree]=====================
    
//=================[Second Move]================================= 
   twist_cmd.linear.x=speed; //and move forward again
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }
    twist_cmd.linear.x=0.0;
//===============[End of Second Move,3m]=========================

//================[My Edit]===========================

//=================[Second Spin]====================================
    twist_cmd.angular.z=yaw_minus_rate; //and start spinning in place
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }

    twist_cmd.angular.z=0.0; //and stop spinning in place 
//=================[End of Second Spin,90 degree]=====================

//=================[Third Move]================================= 
   twist_cmd.linear.x=speed; //and move forward again
    timer=0.0; //reset the timer
    while(timer<time_4_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }
    twist_cmd.linear.x=0.0;
//===============[End of Third Move,4m]=========================

//=================[Third Spin]====================================
    twist_cmd.angular.z=yaw_rate; //and start spinning in place
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }

    twist_cmd.angular.z=0.0; //and stop spinning in place 
//=================[End of Second Spin,90 degree]=====================

//==============[Forth Move]==========================================
    twist_cmd.linear.x=speed; //and move forward again
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }
    twist_cmd.linear.x=0.0;
//===========[End of forth move,3m]================================

//=================[Forth Spin]====================================
    twist_cmd.angular.z=yaw_rate; //and start spinning in place
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }

    twist_cmd.angular.z=0.0; //and stop spinning in place 
//=================[End of forth Spin,90 degree]=====================

//==============[Fifth Move]==========================================
    twist_cmd.linear.x=speed; //and move forward again
    timer=0.0; //reset the timer
    while(timer<time_4_sec/2) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }
    twist_cmd.linear.x=0.0;
//===========[End of fifth move,2m]================================

//=================[Fifth Spin]====================================
    twist_cmd.angular.z=yaw_minus_rate; //and start spinning in place
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }

    twist_cmd.angular.z=0.0; //and stop spinning in place 
//=================[End of fifth Spin,-90 degree]=====================

//==============[Sixth Move]==========================================
    twist_cmd.linear.x=speed; //and move forward again
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }
    twist_cmd.linear.x=0.0;
//===========[End of fifth move,3m]================================

//=================[Sixth Spin]====================================
    twist_cmd.angular.z=yaw_rate+0.07; //added correction value 0.05
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }

    twist_cmd.angular.z=0.0; //and stop spinning in place 
//=================[End of sixth Spin,90 degree]=====================

//==============[Seventh Move]==========================================
    twist_cmd.linear.x=speed; //and move forward again
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }
    twist_cmd.linear.x=0.0;
//===========[End of seventh move,3m]================================

//=================[Seventh Spin]====================================
    twist_cmd.angular.z=yaw_minus_rate; //added correction value 0.05
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }

    twist_cmd.angular.z=0.0; //and stop spinning in place 
//=================[End of seventh Spin,-90 degree]=====================

//==============[Eigth Move]==========================================
    twist_cmd.linear.x=speed-.08; //and move forward again
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }
    twist_cmd.linear.x=0.0;
//===========[End of eigth move,2.7m]================================

//=================[eigth Spin]====================================
    twist_cmd.angular.z=yaw_rate-0.02; //added correction value 0.02
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }

    twist_cmd.angular.z=0.0; //and stop spinning in place 
//=================[End of eigth Spin,~90 degree]=====================

//=======[final Move/ Zeta Move ]=======================================
    twist_cmd.linear.x=speed-.5; //and move forward again
    timer=0.0; //reset the timer
    while(timer<time_3_sec) {
          twist_commander.publish(twist_cmd);
          timer+=sample_dt;
          loop_timer.sleep();
          }
    twist_cmd.linear.x=0.0;
//===========[End of Zeta move,1.5m]================================



    //halt the motion
    twist_cmd.angular.z=0.0; 
    twist_cmd.linear.x=0.0; 
    for (int i=0;i<10;i++) {
      twist_commander.publish(twist_cmd);
      loop_timer.sleep();
    }               
    //done commanding the robot; node runs to completion
}

