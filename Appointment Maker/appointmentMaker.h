#pragma once
#define MAXVAL  100
//#define MAXYEAR  10

typedef struct appointment
{
	char date_time[MAXVAL];
	char description[MAXVAL];

	struct appointment* next;
	struct appointment* prev;
}APPT, * P_APPT;

P_APPT createAppointment(char[], char[]);

/* === Getter functions === */

// Get date/time string
char* getDateTime(APPT);

// Get appointment description
char* getDescription(APPT);

// Get address of next appointment
P_APPT getNext(APPT);

// Get address of previous appointment
P_APPT getPrevious(APPT);

/* === Setter functions === */

// Set appointment date/time (yyyy-mm-ddThh:mm)
void setDateTime(P_APPT, char[]);

// Set appointment description
void setDescription(P_APPT, char[]);

// Set address of next appointment
void setNext(P_APPT, P_APPT);

// Set address of previous appointment
void setPrevious(P_APPT, P_APPT);