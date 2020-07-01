//atm.h
#include "bank_account.h"
#include <iostream>
#include <vector>
#include <memory>

//When you use 1 or more classes - Safeguard with header guards
#ifndef ATM_H
#define ATM_H


class ATM
{
public:
    ATM(){}
    void run();

private:
    void scan_card();
    void display_menu();//helper functions, utility functions
    void set_choice();
    void handle_transaction();//Don't worry about parameters //because they are auto accessed with bankacct header
    int choice;
    int selected_account_index;
    std::vector<BankAccount> accounts{BankAccount(100), BankAccount(200), BankAccount(300)}; //Vector w/in bank account
};

#endif

//Unique pointers
void display_account(std::unique_ptr<BankAccount> &account);//Putting const can determine read write status
void display_account_val(std::unique_ptr<BankAccount> account);//Here, we create a copy
std::unique_ptr<BankAccount> get_account();
