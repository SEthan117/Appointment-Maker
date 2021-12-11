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

// Constructor for appointment
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

void saveAppt(P_APPT);
P_APPT readAppt(P_APPT);
P_APPT addAppt(P_APPT);
P_APPT updateList(P_APPT, P_APPT);

/* === Main program options functions === */

// Add a new appointment to a list
void addNewAppointment(P_APPT);

// Update an existing appointment within a list
void updateAppointment(P_APPT);

// Display a single appointment within a list
void displayAppointment(P_APPT);

// Display a range of appointments within a list
void displayAppointmentRange(P_APPT);

// Search for an appointment within a list
P_APPT searchAppointment(P_APPT);

// Delete an appointment from a list
P_APPT removeAppt(P_APPT);