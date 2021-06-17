#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <iostream>
#include <thread>
#include "ros/ros.h"
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include <sstream>
#include <arm_gazebo/GripCommand.h>

namespace gazebo
{
	class GripperController : public ModelPlugin
	{

	public:
		void commandCallback(const arm_gazebo::GripCommand &msg)
		{
			
			ROS_INFO("Received %s", msg.grip_command.c_str());
			
			std::string command = msg.grip_command;			
			
			std::string arm6_arm8 = this->model->GetJoint("arm6_arm8_joint")->GetScopedName();
			std::string arm6_arm7 = this->model->GetJoint("arm6_arm7_joint")->GetScopedName();
			
			if(command == "catch"){
			
				this->jointController->SetPositionTarget(arm6_arm8, -0.4);
				this->jointController->SetPositionTarget(arm6_arm7, 0.4);
			}
			
			else if(command == "release"){
			
				this->jointController->SetPositionTarget(arm6_arm8, 0.7);
				this->jointController->SetPositionTarget(arm6_arm7, -0.7);
			}
		}

		void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
		{
			
			ROS_INFO("Received %s", "Hello World");
            this->model = _parent;
			this->jointController = this->model->GetJointController();

			this->updateConnection = event::Events::ConnectWorldUpdateBegin(
				std::bind(&GripperController::OnUpdate, this));

			int argc = 0;
			char **argv = NULL;
			ros::init(argc, argv, "gazebo_client1");			
			sub = n.subscribe("/command_chatter", 1000, &GripperController::commandCallback, this);
			ros::spinOnce();

		}

		void OnUpdate()
		{
			ros::spinOnce();
		}

	private:
		physics::ModelPtr model;

		physics::JointControllerPtr jointController;

		event::ConnectionPtr updateConnection;

		ros::NodeHandle n;

		ros::Subscriber sub;
	};

	GZ_REGISTER_MODEL_PLUGIN(GripperController)

}