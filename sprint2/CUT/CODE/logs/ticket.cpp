#include<iostream>
#include "ticket.h"
#include "Logger.h"

int ticket(int num)
{
   if(num==0)
          LOG_INFO("Ticket number should not be zero ");
   return num;
}