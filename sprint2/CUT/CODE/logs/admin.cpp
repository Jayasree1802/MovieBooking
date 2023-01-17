#include<iostream>
#include"admin.h"
#include<string.h>
using namespace std;
#include"Logger.h"

void userName(char str[])
{
        int flag=0;
        for(int i=0; str[i]!='\0'; i++)
        {

                if( (str[i]<65 || str[i]>90) && (str[i]<97 || str[i]>122) )
                {
                        flag=1;

                        break;
                }

        }

        if(flag==1)
             LOG_INFO("Enter valid name");
        else
                LOG_INFO("entered name is in correct format: %s ",str);
}
void user_pswd(char str[])
{
        int d,l,s,u;
        d=s=l=u=0;

        for(int i=0; str[i]!='\0';i++)
        {
                if(isdigit(str[i]))
                        d++;
                if(islower(str[i]))
                        l++;
                if(isupper(str[i]))
                        u++;
                if(str[i]=='@')
                      s++;
        }
        if(d !=0 && l!=0 && u!=0 && s)
                LOG_INFO("entered password is in correct format: %s ",str);
        else
                LOG_INFO("entered password is not correct ");
}


