#include<iostream>
using namespace std;
#include<string.h>
#include "ticket.h"
#include"admin.h"
#include "Logger.h"

int main()
{
        cout<<"Movie Booking System"<<endl;;
        LOG_INFO(" Ticket number is %d\n",ticket(123456));
        LOG_INFO("Ticket number is %d\n",ticket(0));
        cout<<"enter name : ";
        char name[10],pswd[10];
        cin>>name;
        cout<<"enter password : ";
        cin>>pswd;

        /*LOG_INFO("entered name is in correct format: %s ",*/
        userName(name);
        user_pswd(pswd);
        return 0;
}