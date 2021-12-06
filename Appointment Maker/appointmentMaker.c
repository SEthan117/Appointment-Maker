#define _CRT_SECURE_NO_WARNINGS
#include "appointmentMaker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

P_APPT createAppointment(int year, int date, int time, char description[])
{
	P_APPT newAppt = (P_APPT)malloc(sizeof(APPT));

	setYear(newAppt, year);
	setDate(newAppt, date);
	setTime(newAppt, time);
	setDescription(newAppt, description);

	setNext(newAppt, NULL);
	setPrevious(newAppt, NULL);

	return newAppt;
}

int getYear(APPT appointment)
{
	return appointment.year;
}

int getDate(APPT appointment)
{
	return appointment.date;
}

int getTime(APPT appointment)
{
	return appointment.time;
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

void setYear(P_APPT p_appointment, int year)
{
	p_appointment->year = year;
}

void setDate(P_APPT p_appointment, int date)
{
	p_appointment->date = date;
}

void setTime(P_APPT p_appointment, int time)
{
	p_appointment->time = time;
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