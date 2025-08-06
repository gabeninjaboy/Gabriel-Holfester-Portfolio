#ifndef WORKPAY_H
#define WORKPAY_H

class WorkPay
{

 public:

  // Required functions in workpay //
  
  WorkPay(int input);
  void storeData(int x);
  double retrieveHours();
  double retrieveDays();

  WorkPay operator+(int);
  WorkPay operator-(int);
  WorkPay operator++(int);
  WorkPay operator--(int);
  WorkPay operator++();
  WorkPay operator--();
  
  

 private:

  int hours = 0;


};










#endif
