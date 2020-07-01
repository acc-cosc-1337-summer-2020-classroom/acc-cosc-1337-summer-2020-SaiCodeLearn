#include "bank_account.h"
#include "checking_account.h"
#include <iostream>
#include "atm.h"
#include "savings_account.h"
#include "memory"

using std::cout;
using std::cin;
using std::unique_ptr;
using std::make_unique; //Allows us to create dynamic memory for a pointer

int main()
{	
	BankAccount a1(500); //Stack
	unique_ptr<BankAccount> a = make_unique<BankAccount>(600);//heap
	display_account(a);//No need to move a value because its by reference
	display_account_val(std::move(a));

	/*CheckingAccount c(1000);
	cout<<c;
	CheckingAccount c1;
	cout<<c1;


	SavingsAccount s(100);
	cout<<s;
	cout<<s.get_balance()<<"\n";
	SavingsAccount s1;
	cout<<s1;*/
	
	//ATM atm;
	//atm.run();
	//BankAccount account(900);
	//cout<<account;
	/*BankAccount account;
	BranchBank bank(10000);
	bank.update_balance(500);
	cout<<account;
	cin>>account;
	cout<<account.get_balance();

	cout<<account.get_bank_balance()<<"\n";
	cout<<bank.get_branch_balance()<<"\n";*/

	return 0;
}

