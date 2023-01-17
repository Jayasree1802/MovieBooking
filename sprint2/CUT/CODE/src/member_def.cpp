#include"member.h"

time_t t = time(NULL);//to-get-the-current-year-in-c
tm* timePtr = localtime(&t);

         void Member:: MemberInitialize(string name,string icno,string email, string phone_number, string acc_num, string password, int valid_month, int valid_year)
         {
            this -> name = name;
            this -> email = email;
            this -> phone_number = phone_number;
            this -> icno = icno;
            this -> password[maximun] = password[maximun];
            this -> acc_num = acc_num;
            this -> valid_month = valid_month;
            this -> valid_year = valid_year;
         }
         void Member::setIC(){
             int length;
             char name[maximun],icnum[maximun],email[average],phone_number[minimun],acc_num[minimun],password[minimun],month[minimun],year[minimun];
             bool icFound = 0;
             fstream membership;

             int check_ic = 0;
             do{
                 if(check_ic == 0){
                cout << "Enter your Identification Number(IC) without dash (-) : ";
                    cin >> icno;
                    cout << endl;
                 }
                 else{
                    cout << "\t Enter a valid IC Number: ";
                    cin >> icno;
                    cout << endl;
                 }

                 length = icno.length();

                 membership.open("Membership.txt", ios::in);
                 while(!membership.eof())
                 {
                     membership.getline(name,maximun,'|');
                     membership.getline(icnum,minimun,'|');
                     membership.getline(email,average,'|');
                     membership.getline(phone_number,minimun, '|');
                     membership.getline(acc_num,minimun, '|');
                     membership.getline(password,minimun,'|' );
                     membership.getline(month,minimun,'|' );
                     membership.getline(year, minimun);

                     for(int check_ic=0; check_ic<length; check_ic++){
                        if(icno[check_ic] == icnum[check_ic]){
                            icFound = 1;
                        }
                        else{
                            icFound = 0;
                            break;
                        }
                     }
                     if(icFound){
                        break;
                     }
                 }
                 membership.close();
                 check_ic++;
            }while(length != 12 || icFound);
        }
         void Member:: setAccNum(){
             srand(time(0));
             int AccNum1 = (rand() % 999999 )+ 100000;
             acc_num = to_string(AccNum1);
        }
         void Member:: setPassword(){
            char password_1[maximun];
             passwordset:
            cout << " ENTER YOUR PASSWORD : ";
            cin >> password;
            string pw = password;
            cout << "\n REENTER YOUR PASSWORD :";
            cin >> password_1;
            string pw1 = password_1;
            if(pw1==pw){
              cout << "\n Your password set. you are a member now !!\n";}
              else{
               cout << "\n Your password does not match. Try again !!\n";
              goto passwordset;}

        }
         string Member:: getAccNum(){
            return acc_num;
        }
	 string Member::getIC(){
            return icno;
         }

         void Member::setMonth()
         {
         valid_month = timePtr->tm_mon+ 1  ;
         }

         void Member::setYear(){
            valid_year = timePtr->tm_year + 1900 + 1;  //give extra one year upon registration for validity
         }

         int Member:: getMonth(){
            return valid_month;
         }

         int Member:: getYear(){
            return valid_year;
         }

         string Member:: getPassword(){
            return password;
         }


        Member::Member ()
        {
            
        }
