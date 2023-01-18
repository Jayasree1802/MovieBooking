#ifndef __BOOKING_H__
#define __BOOKING_H__
#include<iostream>
#include<string.h>
#include<ctime>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>
//#include"customer.h"
#include"movie.h"

using namespace std;

/**********************************************************
 * Class name   :   MovieBooking
 * Description  :   It defines the add movie,delete movie,member login,ticket cancel,management.
 * Parameters   :   no parameters
 * Return type  :   no return type
 *
 * ***********************************************************/
 
class MovieBooking
{
    public:
       Member *MemberProg = new Member;
       using MOVIE = Movie[MAXMOVIES];

       void menu();
       void title();
       static bool CompareNames(Movie movie1, Movie movie2);
       int ReadFile(MOVIE &movies, int &movieCount);
       void showmovielist(MOVIE& movies, const int movieCount);
       void time_checking(int time[],int time_);
       void showTicket();
       void payment(float);
       void member_reg();
       void member_renew();
       void membership();
       void movie_booking();
       void add_movie();
       void delete_movie();
       void management();
       string member_login();
       void ticket_cancel();
    
};
#endif /*__BOOKING_H__ */
