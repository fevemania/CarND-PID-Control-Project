#ifndef PID_H
#define PID_H

#include <vector>

class PID {

public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  std::vector<double> p;
  // There are three element in pid array:
  //
  // the gain coefficient that proportional to cross track error (cte). -> used to keep the trajectory around reference line.
  // the gain coefficient that sum up all the history cte to overcome system bias problem.
  // the gain coefficient that multiply with the differentiate of cte to overcome oscillation
  
  /*
  * Constructor
  */
  PID(double Kp, double Ki, double Kd);

  /*
  * Destructor.
  */
  virtual ~PID();

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
