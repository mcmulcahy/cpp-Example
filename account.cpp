/*
File: account.cpp
Created By: Michael Mulcahy
Created On: 4-3-14
*/

#include <iostream>
#include <string>
using namespace std;
#include "account.h"


//access private data members
std::string bankAcc::getName()
{
  return(name);
}

void bankAcc::setName(std::string _name)
{
  name = _name;
}

double bankAcc::getBal()
{
  return(bal);
}



//member functions
bool mmAcc::withdraw(double amt)
{
  if (numWith < 2)
    {
      if (bal - amt >= 0 && amt > 0)
	{
	  bal = bal - amt;
	  numWith++;
	  cout<< "Your transaction was successful, your new balance is: $" << bal << endl;
	  return true;
	}
      else if (amt <= 0)
	{
	  cout << "Your transaction was unsuccessful, please try again with a positive amount to withdraw" << endl;
	  return false;
	}
      else if (bal - amt < 0)
	{
	  cout << "Insufficient funds, your current balance is: " << bal << endl;
	  return false;
	}
    }
  else
    {
      if (bal - amt - 1.50 >= 0 && amt > 0)
	{
	  bal = bal - amt - 1.50;
	  numWith++;
	  cout << "Your transaction was successful! Your new balance is: $" << bal << endl;
	  return true;
	}
      else if (amt < 0)
	{
	  cout << "Your transaction was unsuccessful, please try again with a positive dolar amount to withdraw" << endl;
	  return false;
	}
      else if (bal - amt -1.50 < 0)
	{
	  cout << "Your transaction was unsuccessful due to insufficient funds, your current balance is: $" << bal << endl;
	  return false;
	}
    }
}


bool cdAcc::withdraw(double amt)
{
  if (amt > 0 && bal - amt - (intRate * bal *.25) >= 0)
    {
      bal = bal - amt - (intRate * bal * .25);
      cout << "Your transaction was successful, your new balance is: $" << bal << endl;
      return true;
    }
  else if (amt <= 0)
    {
      cout << "Your transaction was unsucessful, please withdraw a positive dollar amount." << endl;
      return false;
    }
  else if (bal - amt - (intRate * bal * .25) < 0 )
    {
      cout <<"Your transaction was unsuccessful due to insufficient funds, your current balance is: $" << bal << endl;
      return false;
    }
}

bool bankAcc::deposit(double amt)
{
  if (amt > 0)
    {
      bal = bal + amt;
      cout << "Your transaction was successful, your new balance is: $" << bal << endl;
      return true;
    }
  
  else
    {
      cout << "Your transaction was unsuccessful, please deposit a positive dollar amount." << endl;
      return false;
    }
}
