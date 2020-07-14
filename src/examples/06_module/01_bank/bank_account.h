//bank_account.h
#include <iostream>

#ifndef BRANCH_BANK_H
#define BRANCH_BANK_H

class BranchBank
{
public:
    BranchBank(int b) : branch_balance{b}{}
    void update_balance(int b);
    int get_branch_balance()const{return branch_balance;}

private:
    int branch_balance;


};

#endif

//----------------------------------------------------------------------------

#ifndef BANK_ACCOUNT_H //If bank account header isn't defined
#define BANK_ACCOUNT_H //PLease just auto define it.

enum class OPTION{DEPOSIT = 1, WITHDRAW = 2, DISPLAY = 3};//C++11

class BankAccount
{
public:
    BankAccount() : BankAccount(0){std::cout<<"\ncreate new memory\n";ptr_value = new int(10);} //Delegating constructor
    explicit BankAccount(int b) : balance{b} {std::cout<<"\ncreate new memory\n";ptr_value = new int(10); bank_balance += balance;}//Intializer list - C++ differentiates using parameters
    //Added create memory in statement ^ to allow for create new memory to show
    virtual int get_balance() const = 0;//const because we don't want to modify anything within the function
    //Relating to options 
    void deposit(int amount);
    void withdraw(int amount);
    void set_option(OPTION o){option = o;};
    static int get_bank_balance() {return bank_balance;}
    //Declaring a friend - In this case - Allowing update balance to use these functions here
    friend void BranchBank::update_balance(int b);
    //Operator overloading
    friend std::ostream& operator<<(std::ostream & out, const BankAccount &account);
    friend std::istream &operator>>(std::istream& in, BankAccount& account);
    int get_ptr_value()const{return *ptr_value;}
    void set_ptr_value(int value){*ptr_value = value;}
    virtual ~BankAccount(){std::cout<<"delete memory\n"; delete ptr_value; ptr_value = nullptr;}//Destructor to clear dynamic memory from pointer
    //Put virtual so that derived can have its own
private:
    int balance; //lock this variable
    static int bank_balance;//This will be bank's balance of ALL accounts
    OPTION option;
    int* ptr_value;//I want to point to an integer
};


//BankAccount & get_account(int i);
//FREE functions here

//void display_menu();

//int get_choice();

//void handle_transaction(BankAccount & account, int choice);

#endif