#define _CRT_SECURE_NO_WARNINGS
#include "appointmentMaker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

P_APPT createAppointment(char date_time[], char description[])
{
	P_APPT newAppt = (P_APPT)malloc(sizeof(APPT));

	setDateTime(newAppt, date_time);
	setDescription(newAppt, description);

	setNext(newAppt, NULL);
	setPrevious(newAppt, NULL);

	return newAppt;
}

char* getDateTime(APPT appointment)
{
	return appointment.date_time;
}

char* getDescription(APPT appointment)
{
	return appointment.description;
}

P_APPT getNext(APPT appointment)
{
	return appointment.next;
}

P_APPT getPrevious(APPT appointment)
{
	return appointment.prev;
}

void setDateTime(P_APPT p_appointment, char date_time[])
{
	strcpy(p_appointment->date_time, date_time);
}

void setDescription(P_APPT p_appointment, char description[])
{
	strcpy(p_appointment->description, description);
}

void setNext(P_APPT p_appointment, P_APPT next)
{
	p_appointment->next = next;
}

void setPrevious(P_APPT p_appointment, P_APPT prev)
{
	p_appointment->prev = prev;
}