#include "times.h"
#include "appointmentMaker.h"
#include <stdio.h>
#include <stdlib.h>

bool checkMonth(int month)
{
	if (month <= MONTH && month > 0)
	{
		return true;
	}
	else
		return false;
}
int getDay(int year, int month)
{
	//Jan
	if (month == 1)
	{
		return (31);
	}
	//Feb
	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		{
			return (29);
		}
		else
			return(28);
	}
	//March
	if (month == 3)
	{
		return(31);
	}
	//April
	if (month == 4)
	{
		return(30);
	}
	//May
	if (month == 5)
	{
		return(31);
	}
	//June
	if (month == 6)
	{
		return(30);
	}
	//July
	if (month == 7)
	{
		return (31);
	}
	//August
	if (month == 8)
	{
		return(31);
	}
	//Sept
	if (month == 9)
	{
		return(30);
	}
	//Oct
	if (month == 10)
	{
		return(31);
	}
	//Nov
	if (month == 11)
	{
		return(30);
	}
	//Dec
	if (month == 12)
	{
		return(31);
	}
}

bool checkDay(int day, int month, int year)
{
	int tempDAY = getDay(month, year);
	if (day <= tempDAY && day > 0)
	{
		return true;
	}
	else
		return false;
}

bool checkTime(int time)
{
	if (time <= HOUR && time >0)
	{
		return true;
	}
	else
		return false;
}