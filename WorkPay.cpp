#include "WorkPay.h"


// Declares the constructor //

WorkPay::WorkPay(int input)
{
  hours = input;
}

// Sets the value of hours to x //

void WorkPay:: storeData(int x)
{
  hours = x;
}

// Returns the hours in a double form //

double WorkPay:: retrieveHours()
{
  return (double) hours; 
}

// returns the days in a double form //

double WorkPay:: retrieveDays()
{
  return (double) hours / 8; 
}

// Overloads the "+" operator to add hours //

WorkPay WorkPay:: operator+(int other)
{
  
  return hours + other;
}

// Overloads the "-" operator to subtract hours //

WorkPay WorkPay:: operator-(int other)
{
  if(hours - other <= 0)
    {
      return 0;
    }
  
  return hours - other;
}

// These all overload post fix and pre fix operators to add and subtract days of a WorkPay object //

WorkPay WorkPay:: operator++(int x)
{
  double temp = (double) hours;
  hours += 8;
  return temp; 
}



WorkPay WorkPay:: operator--(int x)
{

  double temp = (double)hours;
  if(hours - 8 <= 0)
    {
      hours = 0;
      return temp;
    }
  
  hours -= 8;
  return temp;
}

WorkPay WorkPay:: operator--()
{
  if(hours - 8 <= 0)
    {
      return 0;
    }

  return hours -= 8;
}




WorkPay WorkPay:: operator++()
{
  hours += 8;
  return hours;
}

