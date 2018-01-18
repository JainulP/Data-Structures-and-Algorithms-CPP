#include <iostream>
#include "MoneyMarketAccount.h"

using namespace std;

int main()
{
   MoneyMarketAccount acct;
   acct.deposit(100);
   acct.deposit(100);
   acct.deposit(100);
   acct.deposit(100);
   acct.deposit(100);
   acct.withdraw(100);
   cout << acct.get_balance() << endl;
   cout << "The sixth transaction carries a $10 fee" << endl;
   acct.deposit(2000);
   cout << acct.get_balance() << endl;
   cout << "...except for deposits > $1000" << endl;
   acct.end_of_month();
   cout << acct.get_balance() << endl;
   cout << "No interest since monthly minimum balance was zero." << endl;
   acct.deposit(100);
   acct.withdraw(400);
   acct.withdraw(90); // Minimum monthly balance is $2000
   acct.deposit(2000);
   acct.deposit(100);
   acct.withdraw(100);
   cout << acct.get_balance() << endl;
   cout << "The $2000 deposit doesn't count towards the free transaction limit." << endl;
   acct.deposit(100);
   cout << acct.get_balance() << endl;
   cout << "Now there are six transactions." << endl;
   acct.end_of_month();
   cout << acct.get_balance() << endl;
   cout << "$10 interest is computed on the monthly minimum balance." << endl;

   return 0;
}
