/*
File: account.h
Created By: Michael Mulcahy
Created On: 4-3-14
*/

#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <iostream>
#include <string>

class bankAcc {
 private:
  std::string name;
 protected:
  double bal;

 public:
  //constructor
  bankAcc(std::string _name)
    {
      setName(_name);
    }
  
  //access private data members
  std::string getName();
  void setName(std::string _name);
  double getBal();

  //member functions
  virtual bool deposit(double amt);
  virtual bool withdraw(double amt)=0;


};

class mmAcc : public bankAcc{
 private:
  int numWith;

 public:

  //constructor
 mmAcc(std::string _name):bankAcc(_name)
  {
    numWith=0;
  }

  //member functions
  bool withdraw(double amt);
};

class cdAcc: public bankAcc {
 private:
  double intRate;

 public:

  //constrctor
 cdAcc(std::string _name, double _intRate):bankAcc(_name)
  {
    intRate = _intRate;
  }

  //member functions
  bool withdraw(double amt);
};



#endif
