//include header files
//------------------------------------------
#ifndef __MOVIE_H__
#define __MOVIE_H__
#include"member.h"
#include<iostream>
#include<string.h>
using namespace std;

/********************************************************************************************
**     CLASSNAME     :    Movie
**
**    DESCRIPTION    :    This Class Movie contains the list of data members of Movie name,day,time1,time2,time3
                            
*****************************************************************************************/
class Movie{
    public:
        string name, day, time1, time2, time3;
};
#endif /*__MOVIE_H__ */