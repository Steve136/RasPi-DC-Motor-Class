/* 
 * File:   PiMotor.cpp
 * Author: Steve McMillan
 *
 * Created on 07 July 2017, 17:13
 */
#include <stdio.h>
#include <pigpio.h>
#include <unistd.h>
#include "PiMotor.h"

PiMotor::PiMotor(int forwardPin, int reversePin) {
    if (DEBUG) {
        printf("Creating motor object with pins %i and %i\n\r", forwardPin, reversePin);
    }
    
    fPin = forwardPin;
    rPin = reversePin;
}

void PiMotor::setDebug(bool debug) {
    DEBUG = debug;
    if (DEBUG) {
        printf("Debug messages enabled. Outputting all operations...\n\r");
    }
}

void PiMotor::stop() {
    //Initialise GPIO.
    if (gpioInitialise() < 0) {
        if (DEBUG) {
            fprintf(stderr, "PiGPIO initialisation failed.\n\r");
        }
      return;
   }
    gpioSetMode(fPin, PI_OUTPUT);
    gpioSetMode(rPin, PI_OUTPUT);
    gpioPWM(fPin, 0);
    gpioPWM(rPin, 0);
    
    if (DEBUG) {
        printf("Stopping motors on pin %i and pin %i.\n\r", rPin, fPin);
    }
   
   //Free resources & GPIO access
   gpioTerminate();   
}

void PiMotor::runForMS(int direction, int speed, int milliseconds) {
    //Convert Milliseconds to Microseconds for usleep (unix)
    unsigned int microseconds = (milliseconds * 1000.0);
    if (DEBUG) {
        printf("Running PiMotor::run for %i milliseconds.\n\r", milliseconds);
    }
    //Run
    PiMotor::run(direction, speed);
    //Wait
    usleep(microseconds);
    //Stop
    PiMotor::run(direction, 0);
    
    if (DEBUG) {
        printf("Stopping PiMotor::run\n\r");
    }
}

void PiMotor::run (int direction, int speed) {
    //Initialise GPIO.
    if (gpioInitialise() < 0) {
        if (DEBUG) {
            fprintf(stderr, "PiGPIO initialisation failed in PiMotor::run.\n\r");
        }
      return;
   }
  
  if (direction == 0) {
      direction = rPin;
  } else if (direction == 1) {
      direction = fPin;
  } else {
      if (DEBUG) {
        fprintf(stderr, "Invalid Direction Value in PiMotor::run\n\r");
      }
      return;
  }
  
   //Set motor as output.
    gpioSetMode(direction, PI_OUTPUT);
    gpioPWM(direction, speed);
    if (DEBUG) {
        printf("Setting speed to %i on motor pin %i \n\r", speed, direction);
    }
   
   //Free resources & GPIO access
   gpioTerminate();
}
