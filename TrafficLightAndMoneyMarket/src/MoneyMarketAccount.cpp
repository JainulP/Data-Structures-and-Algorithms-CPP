#include "MoneyMarketAccount.h"

MoneyMarketAccount::MoneyMarketAccount()
{
   balance = 0;
   no_of_transactions =0;
   charge = 0;
   min_monthly_balance = 0;
}

/**
   Gets the current balance.
*/
double MoneyMarketAccount::get_balance() const
{
   return balance;
}

/**
   Deposits the given amount and deducts any transaction fees.
*/
void MoneyMarketAccount::deposit(double amount)
{
   balance += amount;
   if (amount <= 1000)
   {
      no_of_transactions++;
      if(no_of_transactions> 5)
      {
    	   	   balance -= 10;
      }
   }

   if(balance < min_monthly_balance )
   {
	   min_monthly_balance = balance;
   }
}

/**
   Withdraws the given amount and deducts any transaction fees.
*/
void MoneyMarketAccount::withdraw(double amount)
{
   balance -= amount;
   no_of_transactions++;
   if(no_of_transactions> 5)
	{
	   balance -= 10;
	}
   if(balance < min_monthly_balance )
     {
  	   min_monthly_balance = balance;
     }

}

/**
   Apply interest, reset month state.
*/
void MoneyMarketAccount::end_of_month()
{
   balance += min_monthly_balance * 0.005; // 0.5 percent
   no_of_transactions =0;
   min_monthly_balance = balance;
}
