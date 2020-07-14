//checking_account.h
#include "bank_account.h"

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

class CheckingAccount: public BankAccount
{
public:
    CheckingAccount(int b) : BankAccount(b){}//Call base class use to use BankAccount Constructor
    CheckingAccount(){}
    int get_balance() const{return BankAccount::get_balance();}
    ~CheckingAccount(){}
};

#endif 