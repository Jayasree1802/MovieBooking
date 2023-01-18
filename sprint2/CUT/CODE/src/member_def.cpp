//include header file
#include"member.h"

time_t t = time(NULL);              // current date/time based on current system
tm* timePtr = localtime(&t);        // convert now to string form

/***************************************************************************************
* Function name :: MemberInitialize
* Description   :: This function is intialize the data members of member class which consists of details of member
* Parameters    :: parameters of string for name,email,password,icno,acc_no int for month,year
* Return Type   :: No Return type
*****************************************************************************************/

void Member:: MemberInitialize(string name,string icno,string email, string phone_number, string acc_num, string password, int valid_month, int valid_year)
{
            this -> name = name;
            this -> email = email;
            this -> phone_number = phone_number;
            this -> icno = icno;
            this -> password[MAXIMUM] = password[MAXIMUM];
            this -> acc_num = acc_num;
            this -> valid_month = valid_month;
            this -> valid_year = valid_year;
}
/***************************************************************************************
* Function name :: setIC
* Description   :: Give Input for the IC of the object
* Parameters    :: No Parameters
* Return Type   :: No Return type
*****************************************************************************************/
void Member::setIC()
{
             int length;
             char name[MAXIMUM],icnum[MAXIMUM],email[AVERAGE],phone_number[MINIMUM],acc_num[MINIMUM],password[MINIMUM],month[MINIMUM],year[MINIMUM];
             bool icFound = 0;
             fstream membership;

             int check_ic = 0;
             do{
                 if(check_ic == 0){
                    cout << "Enter your Identification Number(IC) without dash (-) : ";
                    cin >> icno;
                    cout << endl;
                 }
                 else
		{
                    cout << "\t Enter a valid IC Number: ";
                    cin >> icno;
                    cout << endl;
                 }

                 length = icno.length();

                 membership.open("Membership.txt", ios::in);
                 while(!membership.eof())
                 {
                     membership.getline(name,MAXIMUM,'|');
                     membership.getline(icnum,MINIMUM,'|');
                     membership.getline(email,AVERAGE,'|');
                     membership.getline(phone_number,MINIMUM, '|');
                     membership.getline(acc_num,MINIMUM, '|');
                     membership.getline(password,MINIMUM,'|' );
                     membership.getline(month,MINIMUM,'|' );
                     membership.getline(year, MINIMUM);

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
/***************************************************************************************
* Function name :: setAccNum
* Description   :: Set account number for the object
* Parameters    :: No Parameters
* Return Type   :: No Return type
*****************************************************************************************/
void Member:: setAccNum()
{
             srand(time(0));
             int AccNum1 = (rand() % 999999 )+ 100000;
             acc_num = to_string(AccNum1);
}
/***************************************************************************************
* Function name :: setPassword
* Description   :: Set Password for the object
* Parameters    :: No Parameters
* Return Type   :: No Return type
*****************************************************************************************/
void Member:: setPassword()
{
            char password_1[MAXIMUM];
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
/***************************************************************************************
* Function name :: getAccNum
* Description   :: Accessor for the account number of this object
* Parameters    :: No Parameters
* Return Type   :: Return string
*****************************************************************************************/
string Member:: getAccNum()
{
            return acc_num;
}
/***************************************************************************************
* Function name :: getIC
* Description   :: Accessor for the IC number of this object
* Parameters    :: No Parameters
* Return Type   :: Return string
*****************************************************************************************/
string Member::getIC()
{
            return icno;
}
/***************************************************************************************
* Function name :: setMonth
* Description   :: set Month for this object 
* Parameters    :: No Parameters
* Return Type   :: No Return type
*****************************************************************************************/
void Member::setMonth()
{
         valid_month = timePtr->tm_mon+ 1;
}
/***************************************************************************************
* Function name :: setYear
* Description   :: set Year for the object
* Parameters    :: No Parameters
* Return Type   :: No Return type
*****************************************************************************************/
void Member::setYear()
{
            valid_year = timePtr->tm_year + 1900 + 1;  //give extra one year upon registration for validity
}
/***************************************************************************************
* Function name :: getMonth
* Description   :: Accessor for the Month of this object
* Parameters    :: No Parameters 
* Return Type   :: Return type int
*****************************************************************************************/
int Member:: getMonth()
{
            return valid_month;
}
/***************************************************************************************
* Function name :: getYear
* Description   :: Accessor for the year of this object
* Parameters    :: No parameters 
* Return Type   :: Return type int
*****************************************************************************************/
int Member:: getYear()
{
           return valid_year;
}
/***************************************************************************************
* Function name :: getPassword
* Description   :: Accessor for the Password of this object
* Parameters    :: No Parameters
* Return Type   :: Return type string
*****************************************************************************************/
string Member:: getPassword()
{
            return password;
}

Member::Member()
{

}
