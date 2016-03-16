/*
File: main.cpp
Created By: Michael Mulcahy
Created On: 4-3-14
*/

#include <iostream>
#include <string>
#include "account.h"

using namespace std;

bool transfer(bankAcc *from, bankAcc *to, double amt);


int main()
{
  bankAcc *mmA = new mmAcc("Michael");
  bankAcc *cdA = new cdAcc("James", 0.20);

  cout << "Depositing $600.00 into mmA. . . " << endl; mmA->deposit(600.00);
  cout << "Depositing $400.00 into cdA. . . " << endl; cdA->deposit(400.00);
  cout << "MMA balance = $" << mmA->getBal() << endl;
  cout << "CDA balance = $" << cdA->getBal() << endl;

  cout << "Transfering $100.00 from cdA to mmA . . . "<< endl;
  transfer(cdA, mmA, 100);
  cout << "MMA balance = $" << mmA->getBal() << endl;
  cout << "CDA balance = $" << cdA->getBal() << endl;

  cout << "Withdrawing $200.00 from mmA . . ." << endl; mmA->withdraw(200);

  cout << "Transferring $100.00 from mmA to cdA . . ." << endl; transfer(mmA, cdA, 100);

  cout << "Withdrawing $100.00 from mmA . . ."<<endl; mmA->withdraw(100);
  cout << "Withdrawing $400.00 from mmA . . ."<<endl; mmA->withdraw(400);

  cout <<"Withdrawing $400.00 from cdA. . . " <<endl; cdA->withdraw(400);

  cout << "The owner of the cdA is: " << cdA ->getName() << endl;
  cout << "The owner of the mmA is: " << mmA ->getName() << endl;

  return 0;
}


bool transfer(bankAcc *from, bankAcc *to, double amt)
{
  if (from->withdraw(amt) == true)
    {
      to->deposit(amt);
      return true;
    }
  return false;
}
