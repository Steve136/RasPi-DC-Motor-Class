Raspberry Pi C++ DC Motor Class
==============

- 1) Add the PiMotor.h and PiMotor.cpp to your project.
- 2) Initalise the class passing in the Forward/Reverse GPIO pin numbers for your DC motor.
- 3) Use the functions to control the motor (see main.cpp)

Netbeans Remote Build Host
--------------

If you are using Netbeans and remote build host for the Pi you need to specifiy the compiler to include the PiGPIO library. Right Click *Project > Properties > Build > C++ Compiler > Additional Options > Enter:* **-I/usr/local/include -lpigpio -lrt -lpthread**

You will also need to be logging in via root as PiGPIO needs to run the application as root to access the GPIO. See here for setting up root access:http://www.raspberry-projects.com/pi/programming-in-c/compilers-and-ides/netbeans-windows/creating-a-new-project
