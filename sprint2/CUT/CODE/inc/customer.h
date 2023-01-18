#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__
#include<iostream>
#include<string.h>
#include<ctime>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include"header.h"
using namespace std;


static int counter, selection_movie;
const int WIDTH=width , MAXMOVIES=MAX_MOVIES ;
static char name[MAXIMUM], icno[MINIMUM], email[AVERAGE], phone_number[MINIMUM],acc_num[MINIMUM],password[MINIMUM],month[MINIMUM], year[MINIMUM];

static vector<string> movie_name(MINIMUM);
static vector<string> movie_day(MINIMUM);  
static vector<string> showtime1(MINIMUM);
static vector<string> showtime2(MINIMUM);
static vector<string> showtime3(MINIMUM);


/********************************************************************************************************
 * Class name   :   Customer
 * Description  :   It defines the Customer class, which has three members: name, email and phone number.
 * Parameters   :   no parameters
 * Return type  :   no return type
 * 
 * **************************************************************************/

class Customer
{
    protected:
         string name,email,phone_number;
    public:
        void setName();
        void setEmail();
        void setPhonenumber();
        string getPhonenumber();
        string getName();
        string getEmail();
        ~Customer();
    
};
#endif /*__CUSTOMER_H__ */