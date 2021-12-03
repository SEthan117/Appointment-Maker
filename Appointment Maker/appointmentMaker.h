#pragma once
#define MAXVAL  100
#define MAXYEAR  10

typedef struct appointment
{
	char year[MAXYEAR];
	int date;
	int time;
	char description[MAXVAL];

	struct appointment* next;
	struct appointment* prev;
}APPT, *P_APPT;

P_APPT createAppointment(char[], int, int, char[]);