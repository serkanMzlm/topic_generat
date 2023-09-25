#include "dynamic_topic.hpp"

using namespace std::placeholders;

DynamicTopic::DynamicTopic(): Node("dynamic_topic_node"){
    pub.imu = this->create_publisher<imuMsg>("/out/imu", 10);
    pub.range = this->create_publisher<rangeMsg>("/out/range", 10);
    pub.twist = this->create_publisher<twistMsg>("/out/twist", 10);

    sub.range = this->create_subscription<rangeMsg>("/in/range", 10,
                std::bind(&DynamicTopic::subRangeCallback,this,_1)); 
    sub.twist = this->create_subscription<twistMsg>("/in/twist", 10,
                std::bind(&DynamicTopic::subTwistCallback,this,_1)); 
    sub.float32 = this->create_subscription<float32Msg>("/in/float32", 10,
                std::bind(&DynamicTopic::subFloat32Callback,this,_1)); 

    timer.imu = this->create_wall_timer(std::chrono::milliseconds(P2F(100)),
                        std::bind(&DynamicTopic::pubImuCallback, this));
    timer.range = this->create_wall_timer(std::chrono::milliseconds(P2F(25)),
                        std::bind(&DynamicTopic::pubRangeCallback, this));
    timer.twist = this->create_wall_timer(std::chrono::milliseconds(P2F(5)),
                        std::bind(&DynamicTopic::pubTwistCallback, this));

    RCLCPP_INFO(this->get_logger(), "Topic Started.");
}

DynamicTopic::~DynamicTopic(){

}

void DynamicTopic::pubImuCallback(){

}
void DynamicTopic::pubRangeCallback(){

}
void DynamicTopic::pubTwistCallback(){

}

void DynamicTopic::subRangeCallback(const rangeMsg msg){
    (void)msg;
}
void DynamicTopic::subTwistCallback(const twistMsg msg){
    (void)msg;
}
void DynamicTopic::subFloat32Callback(const float32Msg msg){
    (void)msg;
}
