#include <cstdlib>
#include <stdio.h>
#include "PiMotor.h"

using namespace std;

int m1_A = 20; //Motor 1 Forward
int m1_B = 21; //Motor 1 Reverse

int main(int argc, char** argv) {
    //Create a new instance for our Motor.
    PiMotor motor1(m1_A, m1_B);
    
    motor1.setDebug(true); //Turn on Debug message output (see console window!)
    motor1.run(0, 255); //Set PWM value for direction (0 = reverse, 1 = forwards)
    motor1.stop(); //Stop the motor  
    motor1.runForMS(0, 100, 4000); //Run for 4 seconds.
   
    return 0;
}

