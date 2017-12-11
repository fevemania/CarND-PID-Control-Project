#include "PID.h"
#include <vector>
#include <numeric>

/*
* TODO: Complete the PID class.
*/

PID::PID(double Kp, double Ki, double Kd) {
  
  p.resize(3);
  p[0] = Kp;
  p[1] = Ki;
  p[2] = Kd;
  
  p_error = i_error = d_error = 0.0;
}

PID::~PID() {}

void PID::UpdateError(double cte) {
  
  d_error = cte - p_error; // the p_error here means the previous cte
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  return - p[0] * p_error - p[1] * i_error - p[2] * d_error;
}

