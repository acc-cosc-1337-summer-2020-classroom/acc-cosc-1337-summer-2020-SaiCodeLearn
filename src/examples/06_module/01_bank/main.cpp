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
	BankAccount* a1 = new SavingsAccount(50);
	
	
	/*BankAccount* account = new CheckingAccount(500);

	BankAccount *account2 = account;
	cout<<account->get_balance()<<"\n";
	cout<<account2->get_balance()<<"\n";
	
	account->deposit(50);
	cout<<account->get_balance()<<"\n";
	cout<<account2->get_balance()<<"\n";

	delete account;
	account = nullptr;
	account2 = nullptr;*/
	SavingsAccount account;
	SavingsAccount account2 = account;
	cout<<account.get_balance()<<"\n";
	cout<<account.get_ptr_value()<<"\n";
	cout<<account2.get_balance()<<"\n";
	cout<<account2.get_ptr_value()<<"\n";

	account.set_ptr_value(50);
	cout<<account.get_ptr_value()<<"\n";
	cout<<account2.get_ptr_value()<<"\n";
	cout<<account.get_balance();
	cout<<account2.get_ptr_value();

	/*Customer c("John Doe");
	cout<<c.get_name()<<"\n";
	unique_ptr<BankAccount>& account = c.get_account(1);
	cout<<account->get_balance()<<"\n";*/


	/*unique_ptr<BankAccount> a = make_unique<SavingsAccount>(600);//Heap
	cout<<a->get_balance()<<"\n";//-> mimics an * to access the functions
	unique_ptr<BankAccount> c = make_unique<CheckingAccount>(100);
	cout<<c->get_balance();*/



	/*unique_ptr<BankAccount> a = make_unique<BankAccount>(600);//heap
	display_account(a);//No need to move a value because its by reference
	display_account_val(std::move(a));*/

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

