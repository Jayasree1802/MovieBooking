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
const int WIDTH =width , MAXMOVIES =max_movies ;
static char name[maximun], icno[minimun], email[average], phone_number[minimun],acc_num[minimun],password[minimun],month[minimun], year[minimun];

static vector<string> movie_name(minimun);
static vector<string> movie_day(minimun);  
static vector<string> showtime1(minimun);
static vector<string> showtime2(minimun);
static vector<string> showtime3(minimun);

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