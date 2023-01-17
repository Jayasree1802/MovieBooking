#ifndef __MEMBER_H__
#define __MEMBER_H__
#include"customer.h"
//#include"header.h"
#include<iostream>
#include<string.h>
//#include<fstream>

using namespace std;

class Member:public Customer
{
    private:
       string icno,acc_num;
       char password[maximun];
       int valid_month, valid_year;
    public:
         void MemberInitialize(string ,string,string, string,string , string, int, int);
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