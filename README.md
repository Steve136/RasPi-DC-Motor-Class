Raspberry Pi C++ DC Motor Class
==============

This is a basic helper class for using DC Motors with the Raspberry Pi, it uses the PiGPIO that comes with the Raspbian image.

How to use
--------------

- 1) Add the **PiMotor.h** and **PiMotor.cpp** to your project.
- 2) Initalise the class passing in the Forward/Reverse GPIO pin numbers for your DC motor.
- 3) Use the functions to control the motor (see main.cpp)
- 4) **If you get an error, make sure that PiGPIO service is running:** *sudo pigpiod* - Also try turning on **motor1.setDebug(true)** for console message output.

Netbeans Remote Build Host
--------------

If you are using Netbeans and remote build host for the Pi you need to specifiy the compiler to include the PiGPIO library. Right Click *Project > Properties > Build > C++ Compiler > Additional Options > Enter:* **-I/usr/local/include -lpigpio -lrt -lpthread**

You will also need to be logging in via root as PiGPIO needs to run the application as root to access the GPIO. See here for setting up root access:http://www.raspberry-projects.com/pi/programming-in-c/compilers-and-ides/netbeans-windows/creating-a-new-project


Example Usage
--------------

  ```
  PiMotor motor1(17, 18); //Initialise the class with Pin numbers for your DC Motor
  motor1.run(1, 255); //Set PWM value for direction (0 = reverse, 1 = forwards)
  motor1.stop(); //Stop the motor  
  ```
See example main.cpp for basic example usage.

Connecting More Motors?
--------------
Simply create another instance of the class and specify the GPIO pins... e.g.
  ```
  PiMotor motor1(17, 18); //DC Motor 1
  PiMotor motor2(19, 20); //DC Motor 2
  PiMotor motor3(21, 22); //DC Motor 3
  
  motor1.run(1, 255); 
  motor1.stop();  
  
  motor2.run(1, 50);
  motor2.stop();
  
  motor3.run(0, 100);
  motor3.stop();
  ```
