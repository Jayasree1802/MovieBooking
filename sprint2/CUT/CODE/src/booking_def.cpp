//include header file
#include"booking.h"

/***************************************************************************
 * Function name:   menu 
 * Description  :   This function is the menu of movie booking, ticket cancellation, membership, Admin and exit
 * Parameters   :   no parameters
 * Return type  :   no return type
 * 
 * **************************************************************************/
  
void MovieBooking::menu()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    char selection_role;

    title();
    cout << "   The local date and time is: " << dt << endl;
    cout <<
    "      ==========================        ===========================\n"
    "       *(A)  MOVIE BOOKING *            * (B)TICKET CANCELLATION *      \n"
    "      ==========================        ===========================\n"
    "      ==========================        =========================\n"
    "        *(C)  MEMBERSHIP *                 * (D) EMPLOYEES/ADMIN *  \n"
    "      ==========================        =========================\n"
    "                         ==========================\n"
    "                               * (E)   QUIT   *           \n"
    "                         ==========================        \n\n";
     do{
        cout << " SELECT AN OPTION: ";
        cin >> selection_role;
       
        selection_role = tolower(selection_role);
        if (selection_role < 'a' || selection_role > 'e')
            cout << " You have entered a wrong selection. Try again.\n\n";
    }while(selection_role < 'a' || selection_role > 'e');
    
    if (selection_role == 'a'){
       movie_booking();
    }else if (selection_role == 'b'){
        ticket_cancel();
    }

    else if (selection_role == 'c'){
        membership();
    }
    else if (selection_role == 'd'){
        management();
    }
    else{
        exit(1);
    }
}

/***************************************************************************
 * Function name:   title
 * Description  :   This function is to beautify format for the output
 * Parameters   :   no parameters
 * Return type  :   no return type
 * **************************************************************************/

void MovieBooking:: title()
{
    const int WIDTH = TITLE_WIDTH1;
    const int WIDTH1 = TITLE_WIDTH2;
    const string heading =  "                   MOVIE TICKET BOOKING              " ;
    cout << "\n\n ";
         
         for(int setwidth = ZERO; setwidth< WIDTH; setwidth++){
                cout << '*';
            }
    cout << "\n\n";
    cout << "    " << heading;
    cout << "\n\n ";
         
            
         for(int setwidth = ZERO; setwidth < WIDTH; setwidth++){
                cout << '*';
            }
    cout << "\n\n";
}

/**************************************************************************************************************************************
 * Function name:   member_reg
 * Description  :   The member_reg function is for registering new members
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/
void MovieBooking:: member_reg(){
    fstream member;
    member.open("Membership.txt",ios::app);
    int acc_num;
    char resp, resp1;
    Member * m1 = new Member;


        title();
        cout << "\t\t\t\t WELCOME TO THIS CINEMA !!\t\t\t\n\n"
     "\t\t\tWe are glad on your interest to be a part of our family\t\t\n\n\n";
    m1 -> setName();
    m1 -> setPhonenumber();
    m1 -> setIC();
    m1 -> setEmail();
    m1 -> setMonth();
    m1 -> setYear();

    details:

    title();
    cout << "\n\t---------------------------------------------------\n\n" <<
         setw(AVERAGE)<< "\tHello Mr/MS , " << endl << endl <<

         setw(MAXIMUM)<< "Your Name is : " << m1 -> getName() << endl << endl <<
         setw(MAXIMUM)<< "Your IC is : " << m1 -> getIC() << endl << endl <<
         setw(MAXIMUM)<< "Your Phone Number is : " << m1 -> getPhonenumber() << endl << endl <<
         setw(MAXIMUM)<< "Your Email is : " << m1 -> getEmail() << endl << endl
         << "\t -----------------------------------------------------\n\n"
         << "\t\t\tWOULD YOU LIKE TO CONFIRM YOUR DETAILS [Y/N] : ";
    cin >> resp;
    resp = tolower(resp);

    while ((resp != 'y') && (resp != 'n') ){
            cout << "\nEnter a valid response: ";
            cin >> resp;
        }

    if (resp == 'n'){
	     title();
        cout << "\n\t\tWHICH DATA YOU WOULD LIKE TO CHANGE :\t\t\n\n"
             << "\t\t\t(A) NAME\n\n"
             << "\t\t\t(B) IDENTIFICATION NUMBER\n\n"
             << "\t\t\t(C) EMAIL ADDRESS\t\n\n"
             << "\t\t\t(D) PHONE NUMBER\t\n\n"
             << "\t\t\tEnter your response:\t" ;
        cin >> resp;
        resp = tolower(resp);

        while ((resp != 'a') &&  (resp != 'b') && (resp != 'c') && (resp != 'd') ){
              cout << "\nEnter a valid response: ";
              cin >> resp;
        }
        cout << endl << endl;
        if (resp == 'a'){
                m1 -> setName();
                goto details;
            }
        else if (resp == 'b'){
            m1 -> setIC();
            goto details;
        }
        else if (resp == 'c'){
            m1 -> setEmail();
            goto details;
        }
        else{
            m1 -> setPhonenumber();
            goto details;
        }
    }

    else{
	     title();
        cout << endl;
        m1 -> setAccNum();

cout <<setw(AVERAGE)<< "\t\t---------------------------------------------------------------\t\t";
cout << "\n                 Your Account Number is : |\t\t" << m1 -> getAccNum() << setw(MAX_MOVIES)<<"|\n";
cout <<setw(AVERAGE)<< "\t\t----------------------------------------------------------------\n\n";
cout << "  You are required to set a password for your account: \n\n";

        m1 ->setPassword();

  cout << endl << endl;
 cout << "\t\t\tYou are done with your account registration !!\n"
 << "\t\t\tNO FEES FOR NEW MEMBERS \n"
 << "\t\t\tOne point will be given for each ringgit in purchase\n"
<< "\t\t\tThere are alot of exciting rewards that you can claim using the points\n";
//write above details to membership.txt file
      member << m1 ->getName() << '|' << m1->getIC() << '|' << m1->getEmail() << '|' << m1->getPhonenumber() <<  '|' << m1->getAccNum() <<  '|'
             << m1 ->getPassword() << '|' << m1-> getMonth () << '|' << m1-> getYear() << '\n';
      member.close();//closing file
    }

    cout << "\nIf you wish continue to go back to the main menu please press 'b' :";
    cin >> resp1;
    resp1 = tolower(resp1);

    while (resp1 != 'b'){
         cout << "Please enter the correct input: ";
         cin >> resp1;
        resp1 = tolower(resp1);
   }

   menu();
}
/**************************************************************************************************************************************
 * Function name:   member_renew
 * Description  :   The member_renew function is for renewal and extending the years of membership
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/
void MovieBooking:: member_renew()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    fstream member, temp;
    int count = ZERO , extend, pay_amount, acc_renew, current_year,  read_temp = ZERO, year_int, month_int;
    char resp;
    string account_num, line;



    account_num = member_login();

    title();
    cout << endl << endl;
    cout << " Hello " << MemberProg ->getName() << " ,\n\n"
         << " Your account is valid until " << MemberProg->getMonth() << " - " << MemberProg->getYear() << endl << endl;

    if ((MemberProg->getYear() <= current_year) && ((MemberProg->getMonth()) < (timePtr->tm_mon + 1))){
        cout << " YOUR ACCOUNT HAS EXPIRED !!!\n\n" ;
    }

    cout << " Select an option to extend your membership :- \n\n"
         << "\t\t---------------\t\t----------------\t---------------\n"
         << "\t\t/ (a) 1 years  /\t/  (b) 3 years  /\t/ (c) 5 years  /\n"
         << "\t\t---------------\t\t----------------\t----------------\n\n";

    checking:
    cout << " Your selection [ A, B, C ] = ";
    cin >> resp;
    resp = tolower(resp);

    while((resp != 'a') && (resp != 'b') && (resp != 'c')){
        cout << " Please select a correct option [ a, b, c] : ";
        cin >> resp;
    }

    if (resp == 'a'){
        extend = ONE;
    }else if (resp == 'b'){
        extend = THREE;
    }
    else{
        extend = FIVE;
    }

    cout << endl;
    cout << " You have selected " << extend << " years to extend your membership !!!\n" ;

    member.open("Membership.txt",ios::in);
    while (!member.eof()){
        getline(member, line);
        count++;
    }
    member.close();

    cout << "\n Do you want to change the years to be extended [Y/N]: ";
    cin >> resp;
    resp = tolower(resp);

    if (resp == 'y'){
        goto checking;
    }

    member.open("Membership.txt",ios::in);
    temp.open("temp.txt",ios::out);

      count = count - TWO;
    while(read_temp <= count){
        member.getline(name,MINIMUM,'|');
        member.getline(icno,MINIMUM,'|');
        member.getline(email,AVERAGE,'|');
        member.getline(phone_number,MINIMUM, '|');
        member.getline(acc_num,MINIMUM, '|');
        member.getline(password,MINIMUM,'|' );
        member.getline(month,MINIMUM,'|' );
        member.getline(year, MINIMUM);

        sscanf(year, "%d", &year_int);
       sscanf(month, "%d", &month_int);
       if (acc_num == account_num){

                temp << name << '|' << icno << '|' << email << '|' << phone_number <<  '|' << acc_num <<  '|' << password << '|' << month << '|' << (year_int + extend) << '\n';
        }
        else {
            temp << name << '|' << icno << '|' << email << '|' << phone_number <<  '|' << acc_num <<  '|' << password << '|' << month << '|' << year << '\n';
        }

        read_temp++;
    }
    member.close();
    temp.close();

    if (extend == ONE){
        pay_amount =  EXTEND_1_YEAR;
    }else if(extend == THREE){
        pay_amount =  EXTEND_2_YEAR ;
    }else if(extend == FIVE){
        pay_amount =  EXTEND_3_YEAR ;
    }


    title();
    payment(pay_amount);
    temp.open("temp.txt",ios::in);
    member.open("Membership.txt",ios::out);

    read_temp = ZERO;
    while(read_temp <= count){
        temp.getline(name,MINIMUM,'|');
        temp.getline(icno,MINIMUM,'|');
        temp.getline(email,AVERAGE,'|');
        temp.getline(phone_number,MINIMUM, '|');
        temp.getline(acc_num,MINIMUM, '|');
        temp.getline(password,MINIMUM,'|' );
        temp.getline(month,MINIMUM,'|' );
        temp.getline(year,MINIMUM);
        member << name << '|' << icno << '|' << email << '|' << phone_number <<  '|' << acc_num <<  '|' << password << '|' << month << '|' << year << '\n';
        read_temp++;
    }

    member.close();
    temp.close();
    remove ("temp.txt");
    cout << " You are done our beloved customer !!!";
    cout << "\nIf you wish continue to go back to the main menu please press 'b' :";
    cin >> resp;
    resp = tolower(resp);

   while (resp != 'b'){
         cout << "Please enter the correct input: ";
         cin >> resp;
        resp = tolower(resp);
   }
     menu();
}

/**************************************************************************************************************************************
 * Function name:   membership
 * Description  :   The membership function is to become new member and renew membership
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/


void MovieBooking::membership()
{
    char resp;

    title();
    cout << "\n\t\t========================\t==========================\t\n"
         << "\t\t* (A) NEW MEMBER  \t\t(B) RENEW MEMBERSHIP \t\t\n"
         << "\t\t========================\t==========================\t\n\n"
         << "\t\t\t\t\t\t\t Input :" ;
    cin >> resp;
    resp = tolower(resp);

    while ((resp != 'a') && (resp != 'b') && (resp != 'c'))
    {
        cout << "\nEnter a valid response: ";
        cin >> resp;
    }

    if (resp == 'a'){
        system("CLS");
        member_reg();
    }
      else{  system("CLS");
        member_renew();
    }
}


/***************************************************************************
 * Function name:   ComapreNames
 * Description  :   This function is compare the two movie names 
 * Parameters   :   namespace of MOVIE with variables movie1 and movie2
 * Return type  :   return type is boolean
 * 
 * **************************************************************************/

bool MovieBooking::CompareNames(Movie movie1, Movie movie2)
{
    if (movie2.name > movie1.name)
        return true;  
        return false;
        
}

/**************************************************************************************************************************************
 * Function name:   ReadFile
 * Description  :   The ReadFile function is to read the data of the movies into the file  
 * Parameters   :   namespace MOVIES with reference variable movies and moviecount
 * Return type  :   return type is int
 * ***********************************************************************************************************************************/


int MovieBooking::ReadFile(MOVIE &movies, int &movieCount)
{

    string file_name = "Movies.txt";  //filename
    int insert=ZERO;
    ifstream movies_file(file_name);

    if (!movies_file){
        cout << "\n File " << "\"" << file_name << "\"" << " did not open." << endl;
    }

    while (getline(movies_file, movies[insert].name, '|')){
        getline(movies_file, movies[insert].day, '|');
        getline(movies_file, movies[insert].time1, '|');
        getline(movies_file, movies[insert].time2, '|');
        getline(movies_file, movies[insert].time3);
        movies_file.clear();

        insert++;
    }

    movieCount = insert + 1;  //added
    return 1;
}

/**************************************************************************************************************************************
 * Function name:   showmovielist
 * Description  :   The showmovielist function is displays the movies list which are present in the file
 * Parameters   :   namespace MOVIES with reference variable movies and moviecount
 * Return type  :   no return type
 * ***********************************************************************************************************************************/


void MovieBooking:: showmovielist(MOVIE& movies, const int movieCount)
{

    ifstream movie("Movies.txt");
    title();
    cout << "\n ";
    for(int setwidth = ZERO; setwidth < WIDTH; setwidth++){
                    cout << '=';
            }
    cout << endl
         << "| SERIAL |";
           for(int setwidth = ZERO; setwidth < SHOW_MOVIE_LIST; setwidth++){
                    cout << '=';
           }
    cout << "|  SHOWTIME  | " << '\n'
         << "| NUMBER |                 MOVIE NAME                    |  DAY  |  AVAILABLE | " << '\n'
         << ' ';
    for(int setwidth = ZERO; setwidth < WIDTH; setwidth++){
                cout << '=';
        }
    cout << endl;

    int s_no = ONE;
    int print_movie = ONE;

    sort(movies, movies + movieCount, CompareNames);

    int moviec;
    for (moviec = ONE; moviec < movieCount; moviec++)
    {
        if (movies[moviec+ONE].name == movies[moviec].name)
        {
            cout <<
		                    "   (" << moviec << ")     " <<
                std::left << setw(AVERAGE) <<
                setw(MOVIE_NAME)<< movies[moviec].name << "    " <<
                setw(MOVIE_DAY) << movies[moviec].day <<
                "(" << s_no << ") " <<
                movies[moviec].time1 << "\n" <<
                setw(MOVIE_TIME1) << "                                                                                           ("<< s_no + 1 << ") " <<
                movies[moviec].time2 << "\n" <<
                setw(MOVIE_TIME1) << "                                                                                           ("<< s_no + 2 << ") " <<
                movies[moviec].time3 << "\n";
        }

        else{
                cout <<
                    "   (" << moviec <<  ")     " << std::left << setw(AVERAGE) <<
                    setw(MOVIE_NAME) << movies[moviec].name << "    " <<
                    setw(MOVIE_DAY) << movies[moviec].day <<     
                    "("<<s_no<<") " <<
                    movies[moviec].time1 << "\n" <<
                    setw(MOVIE_TIME1 ) << "                                                                       ("<<s_no + 1<<") " <<
                    movies[moviec].time2 << "\n" <<
                    setw(MOVIE_TIME1 ) << "                                                                        ("<<s_no + 2<<") " <<
                    movies[moviec].time3 << "\n";

                cout << ' ' ;
                for(int setwidth = ZERO; setwidth < WIDTH; setwidth++){
                        cout << '=';
                }
                cout << endl;
        }

         movie_name[print_movie] = movies[moviec].name;
         movie_day[print_movie] = movies[moviec].day;
         showtime1[print_movie] = movies[moviec].time1;
         showtime2[print_movie] = movies[moviec].time2;
         showtime3[print_movie] = movies[moviec].time3;
         print_movie = print_movie + ONE;
         s_no = ONE;
    }
   counter = moviec;
}

/**************************************************************************************************************************************
 * Function name:   time_checking
 * Description  :   The time_checking function to check the user entered time is available for show or not
 * Parameters   :   array of time with int type and time_ of int
 * Return type  :   no return type
 * ***********************************************************************************************************************************/


void MovieBooking::time_checking(int time[], int time_)
{
    while(!cin >> time[time_])
    {
        cout << endl;
        cout << " Enter a valid time: " ;
        cin.clear();
        cin.ignore(MINIMUM,'\n');
        cin >> time[time_];
    }

    while((time[time_] > 2400) || (time[time_] < 0))
    {
        cout << endl;
        cout << " You have entered a wrong time for movie. Enter again!!"<< endl;
        cout << " Enter the time for " << time_ << " show  (HHMM): ";
        cin >> time[time_];
    }
}

/**************************************************************************************************************************************
 * Function name:   showTicket
 * Description  :   The showTicket function is display the ticket number for the user
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/

void MovieBooking::showTicket(){

    int ticket_num;

    ticket_num = rand() % 9999999999 + 10000000000;//it gives random ticket_num
    cout << endl << "   --------------------------------------" << endl;
    cout << "     " << ticket_num << "             |" << endl;
    cout << "   --------------------------------------" << endl << endl;
    cout << " This is your ticket number !!! " << endl;
    cout << " Thank you !!!" << endl;
}
/**************************************************************************************************************************************
 * Function name:   payment
 * Description  :   The payment takes card type ,card number choose by the user, whether to book movie or to cancel the ticket or to register.
 * Parameters   :   pay is the parameter
 * Return type  :   no return type
 * ***********************************************************************************************************************************/

void MovieBooking::payment(float pay)
{
    char resp;
    string card_type, card_num, cvv;
    cout << " Select the payment method: " << endl;
    cout << "                 (A) CASH  " << endl;
    cout << "                 (B) DEBIT CARD " << endl;
    cout << "                 (C) CREDIT CARD " << endl << endl;
    cout << " Your option [A, B, C] :  ";
    cin >> resp;
    while((resp != 'A') && (resp != 'a') && (resp != 'B') && (resp != 'b') && (resp != 'C') && (resp != 'c') )
    {
        cout << " Please select a correct option [ a, b, c] : ";
        cin >> resp;
    }


    title();
    if (resp == 'A' || resp == 'a'){
        cout << " You have selected to pay on cash" << endl;
        cout << " The amount you need to pay is : RM " << pay << endl << endl;
    }

    else {
        if(resp == 'B' || resp == 'b'){
            card_type = "debit card";
        }
        else{
        card_type = "credit card";
        }

        cout << "You have selected " << card_type << " to pay !!" << endl << endl;
        cout << "The amount you need to pay is : RM " << pay << endl << endl;
        cout << "Enter your " << card_type << " number: " ;
        cin >> card_num;
        cout << "\n Enter your CVV : " ;
        cin >> cvv;
        cout<<"Payment succesfull";
    }

}
/**************************************************************************************************************************************
 * Function name:   movie_booking
 * Description  :   This function is used to allow the member the book tickets
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/


void MovieBooking::movie_booking()
{
	Customer* c1 = new Customer;
	fstream movie;
	movie.open("Movies.txt", ios::in);
	string showtime;
	int seat_price, lines, select_movie, selection_show;
	char response, response2, response3, pay_res, reuse_response, seat_type, temp, seat_row[ROW_COLOUM_SIZE], seat_column[ROW_COLOUM_SIZE], response1;
	float remaining = ZERO, cash = ZERO;
	srand(time(0)); //getting random no.
	int ticket_num;
login:
    ticket_num = (rand() % 99999) + 10000;
	
	title();
	cout << "\n\t\t\t*********\n"
		<< "\t\t\t*    (A) MEMBER LOGIN   * \n"
		<< "\t\t\t********* \n\n\n"
		<< "\t\t\t********* \n"
		<< "\t\t\t*    (B) GUEST LOGIN    * \n"
		<< "\t\t\t********* \n\n\n";

    cout << "\t\t\tSELECT AN OPTION: ";
    cin >> response;
    response = tolower(response);

	while(response != 'a' && response != 'b')
	{
		cout << "\t\t\tYou have entered a wrong selection. Try again: ";
		cin.ignore(10000, '\n');
		cin >> response;
		response = tolower(response);
	}

	if (response == 'a') {

		string acc_num = member_login();
		c1 = MemberProg;
	}

	else
	{

		title();

		c1->setName();
		c1->setEmail();
		c1->setPhonenumber();
	}

movies:
	int movieCount{}, readStatus{};
	MOVIE movies;
	if (readStatus = ReadFile(movies, movieCount))
		showmovielist(movies, movieCount);
	cout << endl << endl;
	int p = sizeof(movie_name) / sizeof(movie_name[0]);

	cout << " Please select a movie [1,2,3....]: ";
	cin >> select_movie;
	cout << endl;

	while ((!cin >> select_movie) || (select_movie > counter - 1) || (select_movie < 1)) {
		cout << " TRY AGAIN [1,2,3....]: ";
		cin.clear();
		cin.ignore(25, '\n');
		cin >> select_movie;
	}


	cout << "========= You have selected " << movie_name[select_movie] << ".============\n"
		<< "\nWhich show you want to select for [SHOW(1) / SHOW(2) / SHOW(3)]: ";
	cin >> selection_show;

	while ((!cin >> selection_show) || (selection_show > 3) || (selection_show < 1)) {
		cout << " TRY AGAIN [1,2,3....]: ";
		cin.clear();
		cin.ignore(MINIMUM, '\n');
		cin >> selection_show;
	}

	if (selection_show == ONE) {
		cout << "========= You have selected " << showtime1[select_movie] << ".============" << endl;
		showtime = showtime1[select_movie];
	}
	else if (selection_show == TWO) {
		cout << "======== You have selected " << showtime2[select_movie] << ".===========" << endl;
		showtime = showtime2[select_movie];
	}
	else {
		cout << "========== You have selected " << showtime3[select_movie] << ".===============" << endl;
		showtime = showtime3[select_movie];
	}


	cout << "\nWould you wish to [B]ack, [P]roceed or [R]eselect? :";
	cin >> response2;
	response2 = tolower(response2);

	while (response2 != 'b' && response2 != 'p' && response2 != 'r')
	{
cout << "\nSorry! You have entered a wrong selection. Please try again.\n\n";
cout << "Would you wish to [B]ack, [P]roceed or [R]eselect? :";
		cin >> response2;
	}
	if (response2 != 'b') {
		if (response2 != 'p') {
			int change = ZERO;
			select_movie = ZERO;
			selection_show = change;

			goto movies;
		}
		else {

			goto seats;
		}
	}
	else {
		int change = ZERO;
		selection_show = change;

		goto movies;
	}
	cout << endl;

seats:

	title();
cout << "           ===================================\n"
<< "                               SCREEN                     \n"
<< "                ===================================\n\n\n"
<< " [A,1]        [A,2]        [A,3]        [A,4]        [A,5]        [A,6]\n\n"
<< " [B,1]        [B,2]        [B,3]        [B,4]        [B,5]        [B,6]\n\n"
<< " [C,1]        [C,2]        [C,3]        [C,4]        [C,5]        [C,6]\n\n"
<< " [D,1]        [D,2]        [D,3]        [D,4]        [D,5]        [D,6]\n\n"
<< " [E,1]        [E,2]        [E,3]        [E,4]        [E,5]        [E,6]\n\n\n\n";
	int seat_no = 0;
	cout << "Enter the number of seats you want to book [Maximum : 10 seats] : ";
	cin >> seat_no;

    while ((!cin >> seat_no) || (seat_no > 10) || (seat_no < 1)) {  // added
        cout << "\nError: Invalid seat numbers";
        cout << "\nEnter the number of seats you want to book: ";
        cin.clear();
        cin.ignore();
        cin >> seat_no;
	}
    	bool check = false;
	for (int select_seat = ZERO; select_seat < seat_no ; select_seat++) {

		cout << "\nEnter the row of seat you would like to book for [ROW : A,B,C...]: ";
		cin >> seat_row[select_seat];
		seat_row[select_seat] = tolower(seat_row[select_seat]);

		while (seat_row[select_seat] != 'a' && seat_row[select_seat] != 'b' && seat_row[select_seat] != 'c' && seat_row[select_seat] != 'd' && seat_row[select_seat] != 'e') {
cout << "Sorry! You have entered a wrong selection. Please try again.\n\n"
<< "Enter the row of seat you would like to book for [ROW : A,B,C...]: ";
			cin >> seat_row[select_seat];
		}

cout << "\nEnter the column of seat you would like to book for [COLUMN : 1,2,3...]:  ";
		cin >> seat_column[select_seat];

		while (seat_column[select_seat] < '1' || seat_column[select_seat] > '6')
		{
cout << "Sorry! You have entered a wrong selection. Please try again.\n\n"
<< "Enter the column of seat you would like to book for [COLUMN : 1,2,3...]:  ";
			cin >> seat_column[select_seat];
		}
		//checking
		for (int check_seat = ZERO; check_seat < select_seat; check_seat++)
		{
			if (seat_row[check_seat] == seat_row[select_seat] && seat_column[check_seat] == seat_column[select_seat]) {
				check = true;
			}
			else
			{	check = false;
			}
		}
		while (check)
		{
			cout<< "Sorry, this seat has already been chosen.\n";
			cout << "Choose another seat again\n";

			cout << "Enter the row of seat you would like to book for [ROW : A,B,C...]: ";
			cin >> seat_row[select_seat];
			seat_row[select_seat] = tolower(seat_row[select_seat]);

			while (seat_row[select_seat] != 'a' && seat_row[select_seat] != 'b' && seat_row[select_seat] != 'c' && seat_row[select_seat] != 'd' && seat_row[select_seat] != 'e') {
				cout << "Sorry! You have entered a wrong selection. Please try again.\n\n"
					<< "Enter the row of seat you would like to book for [ROW : A,B,C...]: ";
				cin >> seat_row[select_seat];
			}

			cout << "\nEnter the column of seat you would like to book for [COLUMN : 1,2,3...]:  ";
			cin >> seat_column[select_seat];

			while (seat_column[select_seat] < '1' || seat_column[select_seat] > '6')
			{
				cout << "Sorry! You have entered a wrong selection. Please try again.\n\n"
					<< "Enter the column of seat you would like to book for [COLUMN : 1,2,3...]:  ";
				cin >> seat_column[select_seat];
			}

			for (int check_seat = ZERO; check_seat < select_seat; check_seat++)
			{
				if (seat_row[check_seat] == seat_row[select_seat] && seat_column[check_seat] == seat_column[select_seat]) {
					check = true;
				}
				else {
					check = false;
				}
			}
		}

	}

	cout << "\nYour selection of seat(s) is : ";
	for (int select_seat = ZERO; select_seat< seat_no; select_seat++) {
		cout << "(" << seat_row[select_seat] << "," << seat_column[select_seat] << ")";

		if(select_seat < (seat_no-ONE)){
            cout << ", ";
        }
	}
		cout << "\nThere are two types of seats available:  (A) DELUXE (RM 150) \n"
		<< "\t\t\t\t\t (B) NORMAL (RM 100)\n\n\n"
		<< "Do you want further explanation about the type of seats available in our cinemas before selecting it? (Y/N) :";
	cin >> response1;
	response1 = tolower(response1);

	while (response1 != 'y' && response1 != 'n')
	{
		cout << "Sorry! You have entered a wrong selection. Please try again.\n\n"
			<< "Do you want further explanation about the type of seats available in our cinemas before selecting it? (Y/N) :";
		cin >> response1;
	}

	if (response1 == 'y' || response1 == 'Y') {
		cout << "\n- 'DELUXE' seats provides a unique experience to the customers .";
		cout << "\n- 'NORMAL' seats does not include the special privileges.\n";
	}

    cout << endl;
	cout << "Please select the type of seat (A/B): ";
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
	cin >> seat_type;
	seat_type = tolower(seat_type);

	while (seat_type != 'a' && seat_type != 'b')
	{
		cout << "Sorry! You have entered a wrong selection. Please try again.\n\n"
			<< "Please select the type of seat (A/B): ";
		cin >> seat_type;
	}

	if (seat_type == 'a')
		seat_price = DELUX_PRICE * seat_no;

	else
		seat_price = NORMAL_PRICE  * seat_no;

	cout << "Would you wish to [B]ack, [P]roceed or [R]eselect?\n";
	cin >> response3;

	while (response3 != 'b' && response3 != 'p' && response3 != 'r')
	{
		cout << "Sorry! You have entered a wrong selection. Please try again.\n\n"
			<< "Would you wish to [B]ack, [P]roceed or [R]eselect? :";
		cin >> response3;
	}
		if ((response3 != 'b'))
		if ((response3 != 'p')) {
			char seat_row = ZERO, seat_column = ZERO, response = ZERO, seat_type = ZERO;
			int start = ZERO;
			selection_show = start;

			goto seats;
		}
		else {

			goto receipt;
		}
	else {
		char seat_row = ZERO, seat_column = ZERO, response = ZERO, seat_type = ZERO;

		goto movies;
	}
	cout << endl;

receipt:

	cout << "========================================================\n"
		<< "=                         RECEIPT                       =\n"
		<< "------------------------------------------------------\n"
		<< "=                       MOVIE TICKET                    =\n"
		<< "======================================================\n\n"
		<< "\nTicket No. : " << ticket_num << endl
		<< "\nTo Mr/Ms " << c1->getName() << ",\n"
		<< "\nYou have booked " << movie_name[select_movie] << " at " << showtime << ", " << movie_day[select_movie];

	cout << "\nYour selection of seat(s) is : ";
	for (int select_seat = ZERO; select_seat < seat_no; select_seat++) {
		cout << "(" << seat_row[select_seat] << "," << seat_column[select_seat] << ")";
		// The comma will not be print out after last seat
		if(select_seat < (seat_no-1)){
            cout << ", ";
        }
	}
	cout << "\nPrice of seat(s) : " << "RM " << seat_price << endl << endl;
	cout << "---------------------------------------------------------" << endl
		<< left << setw(MAX_MOVIES) << "\nAmount to PAY : RM " << seat_price << endl;

	payment(seat_price);

	fstream booking;
	booking.open("Booking.txt", ios::app);


	booking << ticket_num << '|' << c1->getName() << '|' << c1->getPhonenumber() << '|' << c1->getEmail() << '|';
	booking << movie_name[select_movie] << '|' << movie_day[select_movie] << '|' << showtime << '|' << seat_type << '|';

	for (int i = ZERO; i < seat_no; i++) {
		booking << '(' << seat_row[i] << ',' << seat_column[i] << ')';
	}
	booking << '\n';



	cout << endl << endl;
	movie.close();

	cout << "\nDo you wish to use it again, [Y]es or [N]o ?\n";
	cout << "\nResponse : ";
	cin >> reuse_response;
	reuse_response = tolower(reuse_response);

	while (reuse_response != 'y' && reuse_response != 'n')
	{
		cout << "\nWrong selection. Enter Again !!"
			<< "\nResponse : ";
		cin >> reuse_response;
	}
	booking.close();
	if (reuse_response == 'n') {
		delete c1;
		char seat_row = 0, seat_column = 0, response = 0, seat_type = 0, MTRS_response = 0;

		menu();
	}else

	{
	     goto login;
	}
}

/**************************************************************************************************************************************
 * Function name:   management
 * Description  :   The management function is to login for the admin
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/

void MovieBooking:: management()
{

    title();
    string userName;
    string pass = "Group1@123";
    char userPassword[MAXIMUM];

    int loginAttempt = ZERO;


    cout << endl << endl;
    while (loginAttempt < FIVE)
    {
        cout << "\t\t\t\tPlease enter your user name: ";
        cin >> userName;
        cout << endl;
        cout << "\t\t\t\tPlease enter your user password: ";
        cin>> userPassword;


        if (userName == "Moviebooking" && userPassword == pass){
            cout << "Welcome Group1!" << endl;
            break;
        }
        
        
        else{
            cout << "\n\n\t\t\t\tInvalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }

    if (loginAttempt == FIVE)
    {
        cout << "Too many login attempts! The program will now terminate.";
        menu();

    }
    bool flag=true;

    while (flag && loginAttempt!=FIVE){

        title();
        cout << endl << endl << endl;
        cout << "  (1) Enter a new movie " << endl << endl << endl;

        cout << "  (2) Delete a movie " << endl << endl << endl;

        char c;
        cout << "Enter your selection manager: ";
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        cin >> c;

        switch (c){
            case '1':
                add_movie();
                break;
            case '2':
                delete_movie();
                break;


            default :
               cout << endl;
               cout << "Please input a correct selection\n";
               cout << "If you continue to use program press ' y ',if no please press any input to restart\n ";
        }

        cout << " if you continue to use program press ' y ', if no please press any key to go back to the main menu \n ";
        char f;
        cin >> f;
        f = tolower(f);
        if(f!='y')
        {
            menu();
        }
    }
}

/**************************************************************************************************************************************
 * Function name:   add_movie
 * Description  :   The add_movie function to add movie by the admin
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/

void MovieBooking::add_movie()
{

    char name [MINIMUM], day[MINIMUM];
    int time[3] = {}, time_ = 0;
    fstream movie;
    movie.open("Movies.txt",ios::app);

    title();
    cout << "Adding new movie!!" << endl << endl;

    cin.ignore();
    cout << " Enter the movie name: ";

    cin.getline(name,MINIMUM);
    cout<<endl;
    cout << " Enter the day of the showtime: ";
    cin.getline(day,MINIMUM);
    cout<<endl;
    cout << " Enter the time for First show  (HHMM): ";
    cin >> time[0];
    cout<<endl;
    time_checking(time, time_);
    time_ = 1;

    cout << " Enter the time for Second show (HHMM): ";
    cin >> time[1];
    cout<<endl;
    time_checking(time, time_);
    time_ = 2;

    cout << " Enter the time for Third show  (HHMM): ";
    cin >> time[2];
    cout<<endl;
    time_checking(time, time_);

    movie << name << '|'  << day << '|' << std::setfill('0') << std::setw(4) << time[0] << '|' << std::setfill('0') << std::setw(4) << time[1] << '|'  << std::setfill('0') << std::setw(4) << time[2] << '\n';
    cout << endl;
    cout << "You are done, Manager!";
    movie.close();
}

/**************************************************************************************************************************************
 * Function name:   delete_movie
 * Description  :   The delete_movie function is to delete the movie by admin
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/
 void MovieBooking::delete_movie(){
    fstream movie, temp;
    int lines, select_movie;
    char day[MINIMUM], name[MINIMUM], time1[MINIMUM], time2[MINIMUM], time3[MINIMUM];
    movie.open("Movies.txt",ios::in);
    temp.open("temp.txt",ios::out);

    int movieCount{}, readStatus{};
    MOVIE movies;
    if (readStatus = ReadFile(movies, movieCount))
    showmovielist(movies, movieCount);

    char count = '0';
    string line;

    ifstream file("Movies.txt");
    while (!file.eof())
    {
        getline(file, line);
        count++;
    }
 lines = count - 48 ;

	cout << " Please select a movie [1,2,3....]: ";
	cin >> select_movie;
	cout << endl;

	while ((select_movie > counter - 1) || (select_movie < 1) || (!cin >> select_movie)) {
		cout << " TRY AGAIN [1,2,3....]: ";
		cin.clear();
		cin.ignore(MINIMUM, '\n');
		cin >> select_movie;
	}

	cout << "============== You have selected to delete " << movie_name[select_movie] << " (" << movie_day[select_movie] << ") " << "=====================\n";

    int read = 0;

    for(int read = 0; read < lines ; read++)
    {
        movie.getline(name,MINIMUM,'|');
 movie.getline(day,MINIMUM,'|');
        movie.getline(time1,MINIMUM,'|');
        movie.getline(time2,MINIMUM,'|');
        movie.getline(time3,MINIMUM);

        if (name == movie_name[select_movie] && day == movie_day[select_movie] && time1 == showtime1[select_movie] && time2 == showtime2[select_movie] && time3 == showtime3[select_movie])  //added
        {
            continue;
        }

        else{
             temp << name << '|' << day << '|'  << time1 << '|' << time2 << '|' << time3 <<'\n';
        }
    }
    temp.close();
    movie.close();
    movie.open("Movies.txt",ios::out);
    temp.open("temp.txt",ios::in);

    for (int read1 =0;read1 < (lines - 2);read1++){
        temp.getline(name,MINIMUM,'|');
        temp.getline(day,MINIMUM,'|');
        temp.getline(time1,MINIMUM,'|');
        temp.getline(time2,MINIMUM,'|');
        temp.getline(time3,MINIMUM);
        movie << name << '|' << day << '|'  << time1 << '|'  << time2 << '|' <<  time3 << '\n';
    }

    temp.close();
    movie.close();

    cout << "\n You have done deleting the showtime manager!!! \n";
    remove("temp.txt");
}

/**************************************************************************************************************************************
 * Function name:   member_login
 * Description  :   The member_login function is to member login into the system
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/

string MovieBooking:: member_login(){
    title();
    fstream member;
    char pass_input[MAXIMUM];
    string line, acc_num1, password1, accno_input, name1, icno1, email1, phone_number1;
    int login_attempt = 0, count = 0 , account = 0, month_int, year_int;
    char dummy, resp;

    account_num:
    member.open("Membership.txt",ios::in);
    cout << " Enter your account number : ";
    cin >> accno_input;

    ifstream file("Membership.txt");
    while (getline(file, line)) {
        count++;
     }

    int read = 0;
    while(read <= count)
    {
	    member.getline(name,MINIMUM,'|');
        member.getline(icno,MINIMUM,'|');
        member.getline(email,AVERAGE,'|');
        member.getline(phone_number,MINIMUM, '|');
        member.getline(acc_num,MINIMUM, '|');
        member.getline(password,MINIMUM,'|' );
        member.getline(month,MINIMUM,'|' );
        member.getline(year,MINIMUM);

        acc_num1 = acc_num;
        if (acc_num == accno_input){
            account = 1;
            break;
        }

        read ++;
    }

    member.close();

    if ( account != 1 ){
        cout << endl;
        cout << "   Your account not found !!!"<< endl;

        goto account_num;
    }

    password1 = password;
    cout << endl;
    cout << "   Enter your account password : ";

    cin>>pass_input;

    for (login_attempt = 1 ; login_attempt <= 2 ; login_attempt ++){
        if (pass_input == password1){
            cout << "Login Successful !!!";
            break;
        }

        cout << endl;
        cout << "Login Failed. Attempt " << login_attempt  << " of 3" << endl;
        cout << "Please re-enter Password: " ;

        cin>>pass_input;

        if (pass_input == password1){
            cout << "Login Successful !!!";
                break;
        }
    }

    if ( login_attempt == 3){
        cout << endl;
        cout << "Login Failed. Attempt 3 of 3" << endl;
        cout << "You have exceeded the login attempt! Press P to go back to the main menu." << endl;
        cin >> resp;
        tolower(resp);
        while(resp != 'p'){
            cout << "You have exceeded the login attempt! Press P to go back to the main menu." << endl;
            cin >> resp;
        }
        menu();

    }
 name1 = name, icno1 = icno, email1 = email, phone_number1 = phone_number;
    sscanf(year, "%d", &year_int);
    sscanf(month, "%d", &month_int);

    MemberProg -> MemberInitialize (name1, icno1, email1, phone_number1, acc_num1, password1, month_int, year_int);
    return acc_num1;
}

/**************************************************************************************************************************************
 * Function name:   ticket_cancel
 * Description  :   The ticket_cancel function is to cancel the ticket of the movie by the member
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/
 void MovieBooking:: ticket_cancel(){

    fstream booking, temp;

    string search_receipt;
    char ticket_num[MINIMUM], name[MINIMUM], phone[MINIMUM], email[AVERAGE], seat_type[MINIMUM], movie[MINIMUM], day[MINIMUM], showtime[MINIMUM], seat_booked[NO_OF_SEATS];
    bool isExist = 0, isFound = 0;
    char response;

    do{
        int lines = 0;
        system("CLS");
        title();

        cout << "\t\t\t\t\t\tTICKET CANCELLATION\n\n";
        cout << "\n\t\tEnter your ticket no. : ";
        cin >> search_receipt;

        booking.open("Booking.txt", ios::in);
        while(!booking.eof())
        {
            booking.getline(ticket_num,MINIMUM,'|');
            booking.getline(name,MINIMUM,'|');
            booking.getline(phone,MINIMUM,'|');
            booking.getline(email,AVERAGE,'|');
            booking.getline(movie,MINIMUM,'|');
            booking.getline(day,MINIMUM,'|');
            booking.getline(showtime,MINIMUM,'|');
            booking.getline(seat_type,MINIMUM,'|');
            booking.getline(seat_booked,NO_OF_SEATS);

            if(ticket_num == search_receipt){
                isExist = 1;
                break;
            }
            else{
                isExist=0;
            }
        }
        booking.close();

        if(!isExist){
            cout << "\t\tRecord do not exist!" << endl;
        }
        else{
            booking.open("Booking.txt", ios::in);
            temp.open("temp.txt", ios::out);

            while(!booking.eof())
            {
                booking.getline(ticket_num,MINIMUM,'|');
                booking.getline(name,MINIMUM,'|');
                booking.getline(phone,MINIMUM,'|');
                booking.getline(email,MINIMUM,'|');
                booking.getline(movie,MINIMUM,'|');
                booking.getline(day,MINIMUM,'|');
                booking.getline(showtime,MINIMUM,'|');
                booking.getline(seat_type,MINIMUM,'|');
                booking.getline(seat_booked,NO_OF_SEATS);

                if(ticket_num == search_receipt){

                    string s_type;
                    for(int Seat=0; Seat<1;Seat++){
                        if(seat_type[Seat] == 'a'){
                            s_type = "Deluxe";
                        }
                        if(seat_type[Seat] == 'b'){
                            s_type = "Normal";
                        }
                    }
 cout << "\t\tRecord is found!\n\n"
                         << "\t\t=========================================================\n"
                        << "         =                BOOKING RECORD                  =\n"
                         << "\t\t=========================================================\n"
                         << "\n\t\tTicket No.     : " << ticket_num
                         << "\n\t\tName           : " << name
                         << "\n\t\tPhone no.      : " << phone
                         << "\n\t\tE-mail         : " << email
                         << "\n\t\tMovie selected : " << movie
                         << "\n\t\tDay            : " << day
                         << "\n\t\tShowtime       : " << showtime
                         << "\n\t\tSeat selected  : " << seat_booked
                         << "\n\t\tSeat type      : " << s_type << " seat\n"
                         << "\n\t\t---------------------------------------------------------" << endl;
                }
                else{
                    temp << ticket_num << '|' << name << '|' << phone << '|' << email << '|' << movie << '|'
                         << day << '|' << showtime << '|' << seat_type << '|' << seat_booked << '\n';
                }
                lines++;  // Count number of lines in the file
            }
     temp.close();
            booking.close();


            char ch;
            cout << "\t\tAre you sure you want to cancel your ticket booking?[Y/n]: ";
            cin >> ch;
            tolower(ch);

            while(ch!='y' && ch !='n'){
                cout << "\t\tWrong input! Are you sure you want to cancel your ticket booking?[Y/n]: ";
                cin >> ch;
                tolower(ch);
            }

            if(ch=='y'){
                lines = lines - 2; // Will not read the extra two lines in temp.txt
                booking.open("Booking.txt",ios::out);
                temp.open("temp.txt",ios::in);
                for(int read1=0; read1<lines; read1++){
                    temp.getline(ticket_num,MINIMUM,'|');
                    temp.getline(name,MINIMUM,'|');
                    temp.getline(phone,MINIMUM,'|');
                    temp.getline(email,AVERAGE,'|');
                    temp.getline(movie,MINIMUM,'|');
                    temp.getline(day,MINIMUM,'|');
                    temp.getline(showtime,MINIMUM,'|');
                    temp.getline(seat_type,MINIMUM,'|');
                    temp.getline(seat_booked,NO_OF_SEATS);

                    booking << ticket_num << '|' << name << '|' << phone << '|' << email << '|' << movie << '|'
                            << day << '|' << showtime << '|' << seat_type << '|' << seat_booked << '\n';
                }
                temp.close();
                booking.close();
                cout << "\n\t\tTicket cancel successfully !!!";
            }
            else{
                cout << "\n\t\tTicket is not being cancelled." << endl;
            }
            remove("temp.txt");


        }

        cout << "\n\n\t\tDo you want to use it again?[Y/n]: ";
        cin >> response;
        tolower(response);

        while(response!='y' && response!='n'){
            cout << "\n\t\tWrong selection. Enter Again !!"
                 << "\n\t\tResponse : ";
            cin >> response;
        }

    }while(response=='y');

  
    menu();
}
