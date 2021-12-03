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

/* === Getter functions === */

// Get appointment year
char* getYear(APPT);

// Get appointment date
int getDate(APPT);

// Get appointment time
int getTime(APPT);

// Get appointment description
char* getDescription(APPT);

// Get address of next appointment
P_APPT getNext(APPT);

// Get address of previous appointment
P_APPT getPrevious(APPT);

// Set appointment year
void setYear(P_APPT, char[]);

/* === Setter functions === */

// Set appointment date
void setDate(P_APPT, int);

// Set appointment time
void setTime(P_APPT, int);

// Set appointment description
void setDescription(P_APPT, char[]);

// Set address of next appointment
void setNext(P_APPT, P_APPT);

// Set address of previous appointment
void setPrevious(P_APPT, P_APPT);