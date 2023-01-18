#include"customer.h"

/**************************************************************************************************************************************
 * Function name:   setName
 * Description  :   The setName function takes one parameter, name, and prints out an input prompt for the user to enter their name.
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/

void Customer::setName()
{
            cout<< " Enter your name : ";
            cin.ignore();
            getline(cin, name);
            cout << endl;
}

/**************************************************************************************************************************************
 * Function name:   setEmail
 * Description  :   The setEmail function takes email from user and validate the email.
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/

void Customer::setEmail()
{
            int valid_email = 0;
            char temp;
            cout << " Enter your email address: ";
            cin >> email;
            cout << endl;

            int email_length = email.length();

            for (int check=ZERO; check<email.length(); ++check)
            {
                temp = email.at(check);
                if (temp == '@' )
                {
                    valid_email = 1;
                }
            }
	        while (valid_email != 1)
	        {
                cout << " Enter a valid email address: ";
                cin.ignore();
                cin >> email;
                cout << endl;

                for (int check=0; check<email.length(); ++check)
                {
                  temp = email.at(check);
                  if (temp == '@' )
                  {
                     valid_email = 1;
                  }
                }
            }
}    


/**************************************************************************************************************************************
 * Function name:   setPhonenumber
 * Description  :   The setPhonenumber function takes phone number from user and validates the phone number.
 * Parameters   :   no parameters
 * Return type  :   no return type
 * ***********************************************************************************************************************************/

        void Customer::setPhonenumber()
        {
            cout << " Enter your phone number : ";
            cin >> phone_number;

            int phone_length = phone_number.length();

            while (phone_length != 10)
            {
               cout << endl;
               cout << " Enter a valid phone number: ";
               cin >> phone_number;
               phone_length = phone_number.length();
            }

            cout << endl;
        }

        string Customer::getName()
        {
            return name;
        }

        string Customer::getPhonenumber()
        {
            return phone_number;
        }

        string Customer::getEmail()
        {
            return email;
        }

      Customer:: ~Customer()
      {
          
      }
      
