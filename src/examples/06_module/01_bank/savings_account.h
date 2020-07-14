//savings_account.h
#include "bank_account.h"

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

class SavingsAccount: public BankAccount //Syntax to inherit funcitons 
{
public:
    SavingsAccount(){}
    SavingsAccount(int b) : BankAccount(b){}
    int get_balance() const{return BankAccount::get_balance() * 1050 / 1000 * 1000 / 12000+
                            BankAccount::get_balance();}
    ~SavingsAccount(){}
};

#endif