ROS 2 Cytron MDD10A Motor Driver Interface

This repository contains a ROS 2 package for controlling motors using the Cytron MDD10A motor driver. The package provides an interface to control differential-drive robots or other robotic systems with DC motors.
Features

    ROS 2 node to control the Cytron MDD10A motor driver.
    Supports differential-drive robot configurations.
    Adjustable PID control parameters for precise motor control.
    Easy integration with teleoperation and autonomous navigation stacks.

Requirements
Hardware

    Cytron MDD10A motor driver.
    DC motors with encoders (optional for PID-based control).
    Microcontroller (e.g., Raspberry Pi, Arduino, or a compatible ROS 2 hardware platform).
    Power supply suitable for the motor and driver.

Software

    ROS 2 Humble
    rclcpp, geometry_msgs, and other standard ROS 2 dependencies.
