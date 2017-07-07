/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PiMotor.h
 * Author: Steve McMillan
 *
 * Created on 07 July 2017, 17:13
 */

#ifndef PIMOTOR_H
#define PIMOTOR_H

class PiMotor {
private:
    int fPin;
    int rPin;
    bool DEBUG = false;
  public:
      PiMotor(int, int);
      void run (int,int);
      void runForMS(int direction, int speed, int milliseconds);
      void stop();
      void setDebug(bool); 
};

#endif /* PIMOTOR_H */