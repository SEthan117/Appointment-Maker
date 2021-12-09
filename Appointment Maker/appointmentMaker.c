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

P_APPT addAppt(P_APPT apptList)
{
	char date_time[MAXVAL];
	char description[MAXVAL];
	printf("Please insert date in numerical form:\n");
	fgets(date_time, MAXVAL, stdin);
	printf("Please input description:\n");
	fgets(description, MAXVAL, stdin);

	P_APPT anAppt = createAppointment(date_time, description);
	apptList = updateList(apptList, anAppt);
}

P_APPT updateList(P_APPT apptList, P_APPT nextAppt)
{
	if (apptList == NULL)
	{
		apptList = nextAppt;
	}
	else
	{
		P_APPT currentAppt = apptList;
		P_APPT prevAppt = apptList->prev;
		while (currentAppt->next != NULL)
		{
			currentAppt = currentAppt->next;
		}
		prevAppt = currentAppt;
		currentAppt->next = nextAppt;
		nextAppt->prev = prevAppt;
	}
	return apptList;
}

void saveAppt(P_APPT apptList)
{
	FILE* fp;
	fp = fopen("appointmentList.txt", "w+");
	P_APPT currentAppt = apptList;
	while (currentAppt != NULL)
	{
		fprintf(fp, "%s\n", currentAppt->date_time);
		fprintf(fp, "%s\n", currentAppt->description);
		currentAppt = currentAppt->next;
	}
	fclose(fp);
}

P_APPT readAppt(P_APPT apptList)
{
	FILE* fp;
	fp = fopen("appointmentList.txt", "r");
	char tempDATE_TIME[MAXVAL];
	char tempDESCRIPTION[MAXVAL];
	P_APPT tempAPPT;

	while (fgets(tempDATE_TIME, MAXVAL, fp) != NULL)
	{
		fgets(tempDATE_TIME, MAXVAL, fp);
		tempDATE_TIME[strlen(tempDATE_TIME) - 1] = '\0';
		fgets(tempDESCRIPTION, MAXVAL, fp);
		tempDESCRIPTION[strlen(tempDESCRIPTION) - 1] = '\0';
	}

	fclose(fp);

	return apptList;
}
