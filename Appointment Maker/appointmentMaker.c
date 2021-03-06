#define _CRT_SECURE_NO_WARNINGS
#include "appointmentMaker.h"
#include "times.h"
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
	int year;
	int month;
	int day;
	int time;
	printf("Insert year:\n");
	scanf("%d", &year);
	printf("Insert month:\n");
	scanf("%d", &month);
	printf("Insert day:\n");
	scanf("%d", &day);
	printf("Insert time rounded to the nearest hour (in 24 hour format):\n");
	scanf("%d", &time);
	if (checkMonth(month) == false || checkDay(day, month, year) == false || checkTime(time) == false)
	{
		printf("That is invalid");
		exit(1);
	}
	else
	{
		char date_time[MAXVAL];
		char description[MAXVAL];
		sprintf(date_time, "%d-%d-%d-%d", year, month, day, time);
		printf("Please input description:\n");
		fgets(description, MAXVAL, stdin);
		while(description == "\n")
			fgets(description, MAXVAL, stdin);

		P_APPT anAppt = createAppointment(date_time, description);
		apptList = updateList(apptList, anAppt);
	}
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
		tempDATE_TIME[strlen(tempDATE_TIME) - 1] = '\0';
		fgets(tempDESCRIPTION, MAXVAL, fp);
		tempDESCRIPTION[strlen(tempDESCRIPTION) - 1] = '\0';
		tempAPPT = createAppointment(tempDATE_TIME, tempDESCRIPTION);
		apptList = updateList(apptList, tempAPPT);
	}

	fclose(fp);

	return apptList;
}

void addNewAppointment(P_APPT head)
{

}

void deleteAppointment(P_APPT head)
{

}

void updateAppointment(P_APPT head)
{

}

void displayAppointment(P_APPT head)
{
	char date[MAXVAL];
	printf("Please enter date of appointment to view: ");
	scanf_s("%s", &date, MAXVAL);

	P_APPT appt = searchAppointment(head, date);
	printf("%s\n", appt->date_time);
	printf("%s\n\n", appt->description);
}

void displayAppointmentRange(P_APPT head)
{

}

P_APPT searchAppointment(P_APPT apptList, char date_time[MAXVAL])
{
	if (apptList == NULL) {
		return NULL;
	}
	if (apptList->next == NULL) {
		if (strcmp(apptList->date_time, date_time) == 1) { 

			return apptList;
		}
		else {
			return NULL;

		}
	}

	P_APPT currentAppt = apptList;
	while (currentAppt->next != NULL) {
		if (!strcmp(currentAppt->date_time, date_time)) {

			return currentAppt;
		}
		else {
			currentAppt = currentAppt->next;

		}

	}

	return NULL;
}

P_APPT removeAppt(P_APPT apptList)
{
	char date[MAXVAL];
	printf("Please enter date of appointment to remove: ");
	scanf_s("%s", &date);
	P_APPT apptToRemove = searchAppointment(apptList, date);

	if (apptToRemove == NULL) {
		return apptList;
	}

	if (apptToRemove->prev == NULL) {
		apptList = apptList->next;
		apptList->prev = NULL;
	}
	else {
		apptToRemove->prev->next = apptToRemove->next;
		apptToRemove->next->prev = apptToRemove->prev;
	}
	free(apptToRemove);

	return apptList;
}
