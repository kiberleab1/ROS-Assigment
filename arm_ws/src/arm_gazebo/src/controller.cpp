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
#include "std_msgs/Float32.h"
#include "arm_gazebo/JointValues.h"
#include "arm_gazebo/fk.h"
#include <arm_gazebo/ik.h>
#include <sstream>
namespace gazebo
{
	class ModelPush : public ModelPlugin
	{
	public:
		void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
		{
			ROS_INFO("Received %s", "Hello World1");
			// Store the pointer to the model
			this->model = _parent;

			// // intiantiate the joint controller
			this->jointController = this->model->GetJointController();

			// // set your PID values
			this->pid = common::PID(600.0, 200.0, 100.0);

			auto joint_name = "arm1_arm2_joint";
			auto joint_name2 = "arm2_arm3_joint";

			auto joint_name3 = "arm3_arm4_joint";
			auto joint_name0 = "chasis_arm1_joint";

			std::string name = this->model->GetJoint("arm1_arm2_joint")->GetScopedName();
			std::string name1 = this->model->GetJoint("arm2_arm3_joint")->GetScopedName();
			std::string name2 = this->model->GetJoint("arm3_arm4_joint")->GetScopedName();
			std::string name0 = this->model->GetJoint("chasis_arm1_joint")->GetScopedName();

			this->jointController->SetPositionPID(name, pid);
			this->jointController->SetPositionPID(name1, pid);

			this->jointController->SetPositionPID(name2, pid);
			this->jointController->SetPositionPID(name0, pid);
			// Listen to the update event. This event is broadcast every
			// simulation iteration.
			//
			this->pid2 = common::PID(100.0, 200.0, 100.0);
			jointController->SetPositionPID(model->GetJoint("arm6_arm7_joint")->GetScopedName(), this->pid2);
			jointController->SetPositionPID(model->GetJoint("arm6_arm8_joint")->GetScopedName(), this->pid2);

			jointController->SetPositionTarget(model->GetJoint("arm1_arm2_joint")->GetScopedName(), -0.4);
			jointController->SetPositionTarget(model->GetJoint("arm6_arm7_joint")->GetScopedName(), -0.7);
			jointController->SetPositionTarget(model->GetJoint("arm6_arm8_joint")->GetScopedName(), 0.7);
			//
			arm_gazebo::JointValues msg;
			//msg.joint1 = 1.0;

			if (!ros::isInitialized())
			{
				int argc = 0;
				char **argv = NULL;
				ros::init(argc, argv, "gazebo_client");
			}

			// Create our ROS node. This acts in a similar manner to
			// the Gazebo node
			this->rosNode.reset(new ros::NodeHandle("gazebo_client"));
			this->rosPub = this->rosNode->advertise<arm_gazebo::JointValues>("/out_joints", 10, true);
			this->timer = this->rosNode->createTimer(ros::Duration(1.0 / 50.), &ModelPush::timerCallback,
													 this);

			/// Create a named topic, and subscribe to it.

			ros::SubscribeOptions so =
				ros::SubscribeOptions::create<arm_gazebo::JointValues>(
					"/coming_joints",
					1000,
					boost::bind(&ModelPush::OnRosMsg, this, _1),
					ros::VoidPtr(), &this->rosQueue);
			this->rosSub = this->rosNode->subscribe(so);
			this->rosQueueThread =
				std::thread(std::bind(&ModelPush::QueueThread, this));
			
			//
			//Spin up the queue helper thread.
			
			this->updateConnection = event::Events::ConnectWorldUpdateBegin(
				std::bind(&ModelPush::OnUpdate, this));
			int argc = 0;
			char **argv = NULL;
			ros::init(argc, argv, "gazebo_client");
			this->rosSub = rosNodes.subscribe("/coming_joints", 1000, &ModelPush::OnRosMsg, this);

			this->rosPub = this->rosNodes.advertise<arm_gazebo::JointValues>("/out_joints", 10, true);
			

			//
			this->fkServiceClient = rosNodes.serviceClient<arm_gazebo::fk>("fk");
			this->ikServiceClient = rosNodes.serviceClient<arm_gazebo::ik>("iks");

			ros::spinOnce();
		}

	public:
		void timerCallback(const ros::TimerEvent &event)
		{
			this->rosPub.publish(this->jointValues);
		}

	public:
		void OnRosMsg(const arm_gazebo::JointValuesConstPtr &_msg)
		{
			//	this->SetVelocity(_msg->data);
			//std::cout << "Current chasis_arm1_joint values: " << _msg->joint1 << std::endl;
			//this->SetAngles(_msg);
			arm_gazebo::ik srv;
			double a0 = physics::JointState(this->model->GetJoint("chasis_arm1_joint")).Position(0);
			double a1 = physics::JointState(this->model->GetJoint("arm1_arm2_joint")).Position(0);
			double a2 = physics::JointState(this->model->GetJoint("arm2_arm3_joint")).Position(0);
			double a3 = physics::JointState(this->model->GetJoint("arm3_arm4_joint")).Position(0);
			double a4 = physics::JointState(this->model->GetJoint("arm4_arm5_joint")).Position(0);
			double a5 = physics::JointState(this->model->GetJoint("arm5_arm6_joint")).Position(0);
				
			srv.request.joint_axis = {0.0, 0.0, 0.0, 0.0};
			srv.request.joint_values = {a0,a1,a2,a3,a4,a5};
			srv.request.target_values = {_msg->x, _msg->y, _msg->z};
			if (this->ikServiceClient.call(srv))
			{
				//	ROS_INFO("I am here","I am here");
				//	ROS_INFO("asd", srv.response.new_joint_values);
				std::string name0 = this->model->GetJoint("chasis_arm1_joint")->GetScopedName();


				std::string name1 = this->model->GetJoint("arm1_arm2_joint")->GetScopedName();
				std::string name2 = this->model->GetJoint("arm2_arm3_joint")->GetScopedName();

				std::string name3 = this->model->GetJoint("arm3_arm4_joint")->GetScopedName();

				std::string name4 = this->model->GetJoint("arm4_arm5_joint")->GetScopedName();
				std::string name5 = this->model->GetJoint("arm5_arm6_joint")->GetScopedName();

				this->jointController->SetPositionTarget(name0, srv.response.new_joint_values[0]);
				this->jointController->SetPositionTarget(name1, srv.response.new_joint_values[1]);
				this->jointController->SetPositionTarget(name2, srv.response.new_joint_values[2]);
				this->jointController->SetPositionTarget(name3, srv.response.new_joint_values[3]);
				this->jointController->SetPositionTarget(name4, srv.response.new_joint_values[4]);
				this->jointController->SetPositionTarget(name5, srv.response.new_joint_values[5]);
				//this->jointController->Update();
			}
		}

		/// \brief ROS helper function that processes messages
	private:
		void QueueThread()
		{
			static const double timeout = 0.01;
			while (this->rosNode->ok())
			{
				this->rosQueue.callAvailable(ros::WallDuration(timeout));
			}
		}
		// Called by the world update start event
	public:
		void OnUpdate()
		{
			float angleDegree = -90;
			float rad = M_PI * angleDegree / 180;

			std::string name = this->model->GetJoint("arm1_arm2_joint")->GetScopedName();
			std::string name1 = this->model->GetJoint("arm2_arm3_joint")->GetScopedName();

			std::string name2 = this->model->GetJoint("arm3_arm4_joint")->GetScopedName();
			std::string name0 = this->model->GetJoint("chasis_arm1_joint")->GetScopedName();

			// this->jointController->SetPositionPID(name, pid);
			// this->jointController->SetPositionTarget(name, rad);
			// this->jointController->Update();
			this->pid = common::PID(90.0, 00.00, 00.03);

			// Get joint position by index.
			// 0 returns rotation accross X axis
			// 1 returns rotation accross Y axis
			// 2 returns rotation accross Z axis
			// If the Joint has only Z axis for rotation, 0 returns that value and 1 and 2 return nan
			double a0 = physics::JointState(this->model->GetJoint("chasis_arm1_joint")).Position(0);
			double a1 = physics::JointState(this->model->GetJoint("arm1_arm2_joint")).Position(0);
			double a2 = physics::JointState(this->model->GetJoint("arm2_arm3_joint")).Position(0);
			double a3 = physics::JointState(this->model->GetJoint("arm3_arm4_joint")).Position(0);

			// double a2 = this->model->GetJoint("chasis_arm1_joint").Position(0);
			// double a3 = physics::JointState(this->model->GetJoint("chasis_arm1_joint")).Position(2);
			// 	std::cout << "Current arm1_arm2_joint values: " << a1 * 180.0 / M_PI << std::endl;
			// 	std::cout << "Current arm2_arm3_joint values: " << a2 * 180.0 / M_PI << std::endl;
			// 	std::cout << "Current arm3_arm4_joint values: " << a3 * 180.0 / M_PI << std::endl;
			// 	std::cout << "Current chasis_arm1_joint values: " << a0 * 180.0 / M_PI << std::endl;
			//0
			//this->jointValues.joint1 = (a0 * 180.0 / M_PI);

			//this->jointValues.joint2 = (a1 * 180.0 / M_PI);

			//this->jointValues.joint3 = (a2 * 180.0 / M_PI);

			//this->jointValues.joint4 = (a3 * 180.0 / M_PI);
			ros::spinOnce();
		}

	public:
		void SetAngles(const arm_gazebo::JointValuesConstPtr &_msg)
		{
			float angleDegree = -90;
			float rad = M_PI * angleDegree / 180;

			std::string name = this->model->GetJoint("arm1_arm2_joint")->GetScopedName();
			std::string name1 = this->model->GetJoint("arm2_arm3_joint")->GetScopedName();

			std::string name2 = this->model->GetJoint("arm3_arm4_joint")->GetScopedName();
			std::string name0 = this->model->GetJoint("chasis_arm1_joint")->GetScopedName();
		//	this->jointController->SetPositionTarget(name0, _msg->joint1);
		//	this->jointController->SetPositionTarget(name1, _msg->joint2);
		//	this->jointController->SetPositionTarget(name2, _msg->joint3);
		//	this->jointController->SetPositionTarget(name, _msg->joint4);
		//	this->jointController->Update();
		}
		// a pointer that points to a model object
	private:
		physics::ModelPtr model;

		// 	// A joint controller object
		// 	// Takes PID value and apply angular velocity
		// 	//  or sets position of the angles
	private:
		physics::JointControllerPtr jointController;

	private:
		event::ConnectionPtr updateConnection;

		// // 	// PID object
	private:
		common::PID pid;

	private:
		common::PID pid2;

	private:
		std::unique_ptr<ros::NodeHandle> rosNode;

		/// \brief A ROS subscriber
	private:
		ros::Subscriber rosSub;

	private:
		ros::Publisher rosPub;
		/// \brief A ROS callbackqueue that helps process messages
	private:
		ros::CallbackQueue rosQueue;

		/// \brief A thread the keeps running the rosQueue
	private:
		std::thread rosQueueThread;

	private:
		ros::Timer timer;

	private:
		ros::Timer timer1;

	private:
		arm_gazebo::JointValues jointValues;

	private:
		ros::ServiceClient fkServiceClient;

	private:
		ros::ServiceClient ikServiceClient;

	private:
		ros::NodeHandle rosNodes;
	};

	// Register this plugin with the simulator
	GZ_REGISTER_MODEL_PLUGIN(ModelPush)
}