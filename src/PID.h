#ifndef PID_H
#define PID_H

#include <cmath>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double prev_p_error;
  double i_error;
  double d_error;


  /*
  * Coefficients
  */
  double pid_Kp;
  double pid_Ki;
  double pid_Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
