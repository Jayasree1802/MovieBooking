#include"customer.h"
void Customer::setName()
{
            cout<< " Enter your name : ";
            cin.ignore();
            getline(cin, name);
            cout << endl;
}

void Customer::setEmail()
{
            int valid_email = 0;
            char temp;
            cout << " Enter your email address: ";
            cin >> email;
            cout << endl;

            int email_length = email.length();

            for (int check=0; check<email.length(); ++check)
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
      
