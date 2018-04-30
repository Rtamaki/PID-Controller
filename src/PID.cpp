#include "PID.h"
#include <iostream>


using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

  pid_Kp = Kp;
  pid_Ki = Ki;
  pid_Kd = Kd;

  p_error = 0;
  i_error = 0;
  d_error = 0;
  prev_p_error = 0;

}

void PID::UpdateError(double cte) {

  p_error = cte;
  i_error += cte;
  d_error = cte - prev_p_error;
  prev_p_error = cte;
}

double PID::TotalError() {
  return abs(p_error) + abs(d_error) + abs(i_error);
}


double PID::Steering(){

  return (pid_Kp * p_error - pid_Kd * d_error - pid_Ki * i_error);

}
