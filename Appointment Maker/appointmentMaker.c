#define _CRT_SECURE_NO_WARNINGS
#include "appointmentMaker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

P_APPT createAppointment(char year[], int date, int time, char description[])
{
	P_APPT newAppt = (P_APPT)malloc(sizeof(APPT));

	strcpy(newAppt->year, year);
	newAppt->date = date;
	newAppt->time = time;
	strcpy(newAppt->description, description);

	newAppt->next = NULL;
	newAppt->prev = NULL;

	return newAppt;
}