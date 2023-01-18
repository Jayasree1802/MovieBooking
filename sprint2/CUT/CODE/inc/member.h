//includes header files
//-------------------------------------------------
#ifndef __MEMBER_H__
#define __MEMBER_H__
#include"customer.h"
#include<iostream>
#include<string.h>
using namespace std;

/********************************************************************************************
**     CLASSNAME     :      Member 
**
**    DESCRIPTION    :      This Class Member Inherited from class Customer contains  the  list of data members of Member name,email,phone_number,
                            IC number,AccountNumber and member functions of setname(),setEmail(),setPhonenumber(),setIC(),setAccNum(),
                            setPassword(),setMonth(),setYear(),getName(),getEmail(),getPhonenumber(),getIC(),getAccNum(),getMonth(),
                            getYear(),getPassword()
**
*****************************************************************************************/
class Member:public Customer
{
    private:
       string icno,acc_num;
       char password[MAXIMUM];
       int valid_month, valid_year;
    public:
         void MemberInitialize(string,string,string,string,string,string,int,int);
         void setIC();
         void setAccNum();
         void setPassword();
         string getAccNum();
         string getIC();
         void setMonth();
         void setYear();
         int getMonth();
         int getYear();
         string getPassword();
         Member ();
};
#endif /*__MEMBER_H__ */
