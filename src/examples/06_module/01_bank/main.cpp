#include "bank_account.h"
#include "checking_account.h"
#include <iostream>
#include "atm.h"
#include "savings_account.h"
#include "memory"
#include "customer.h"
#include "time.h" //so that we can use srand
#include <vector>

using std::cout;
using std::cin;
using std::unique_ptr;
using std::make_unique; //Allows us to create dynamic memory for a pointer

void test_delete()
{
	std::vector<std::unique_ptr<BankAccount>> accounts;
	std::unique_ptr<BankAccount> s = std::make_unique<SavingsAccount>();
	std::unique_ptr<BankAccount> c = std::make_unique<CheckingAccount>();
	accounts.push_back(std::move(s));
	accounts.push_back(std::move(c));

	for(int i=0; i<accounts.size(); ++i)
	{
		cout<<accounts[i]->get_balance()<<"\n";
	}
}

int main()
{	
	srand(time(NULL));//Generates random value each time - forcefully
	{	
		const int SIZE = 3;
		BankAccount*accounts[3];//reserve memory slots

		//add dynamic memory
		accounts[0] = new SavingsAccount(50);
		accounts[1] = new CheckingAccount(100);
		accounts[2] = new CheckingAccount(200);

		//use the memory data
		for(auto account: accounts)
		{
			cout<<account->get_balance()<<"\n";
		}

		//delete allocated memory and free it
		for(int i =0; i<SIZE; ++i)
		{
			delete accounts[i];
			accounts[i] = nullptr;
		}
	}
	
	
	

	return 0;
}

