#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	bool apptProg = true;
	int option;
	printf("*****************************\n");
	printf("*                           *\n");
	printf("*     Appointment Maker     *\n");
	printf("*                           *\n");
	printf("*****************************\n");

	printf("Welcome to our appointment maker\n\n\n");

	
	

	while (apptProg)
	{
		printf("1. Add a new appointment\n");
		printf("2. Delete an appointment\n");
		printf("3. Update an existing appointment\n");
		printf("4. Display a single appointment\n");
		printf("5. Display appointment range\n");
		printf("6. Search for appointment\n");
		printf("7. Exit\n");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			printf("Add a new appointment selected\n");
			break;

		case 2:
			printf("Delete an appointment selected\n");
			break;

		case 3:
			printf("Update an existing appointment selected\n");
			break;

		case 4:
			printf("Display a single appointment selected\n");
			break;

		case 5:
			printf("Display appointment range selected\n");
			break;

		case 6:
			printf("Search for appointment selected\n");
			break;

		case 7:
			printf("Thank you, goodbye");
			apptProg = false;
			break;

		default:
			printf("1. Add a new appointment\n");
			printf("2. Delete an appointment\n");
			printf("3. Update an existing appointment\n");
			printf("4. Display a single appointment\n");
			printf("5. Display appointment range\n");
			printf("6. Search for appointment\n");
			printf("7. Exit\n");
			break;
		}
	}

	return 0;
}