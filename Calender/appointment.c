#include "appointment.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to add a new appointment
void Add_New_Appointment(Appointment appointments[], int* numAppointments) {
    if (*numAppointments >= MAX_APPOINTMENTS) {
        printf("Appointment limit Reached \n");
        return;
    }

    printf("Enter appointment Index Number: ");
    scanf(" %[^\n]", appointments[*numAppointments].description); // Read entire line including spaces

    // Validating date and time input
    bool validDateTime = false;
    do {
        printf("Enter appointment date and time (YYYY-MM-DD HH:MM): ");
        int year, month, day, hour, minute;
        if (scanf("%d-%d-%d %d:%d", &year, &month, &day, &hour, &minute) == 5) {
            if (year >= 2000 && year <= 9999 &&
                month >= 1 && month <= 12 &&
                day >= 1 && day <= 31 &&
                hour >= 0 && hour <= 23 &&
                minute >= 0 && minute <= 59) {
                validDateTime = true;
                struct tm tmDateTime = { 0 };
                tmDateTime.tm_year = year - 1900;
                tmDateTime.tm_mon = month - 1;
                tmDateTime.tm_mday = day;
                tmDateTime.tm_hour = hour;
                tmDateTime.tm_min = minute;
                appointments[*numAppointments].date = mktime(&tmDateTime);
            }
            else {
                printf("Invalid date or time format. Please enter again.\n");
            }
        }
        else {
            printf("Invalid input format. Please enter again.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    } while (!validDateTime);

    appointments[*numAppointments].id = *numAppointments + 1; // Assign unique ID
    (*numAppointments)++;
    printf("Appointment added successfully.\n");
}

// Other functions remain unchanged...


// Function to delete an appointment by ID
void Delete_Appointment(Appointment appointments[], int* numAppointments) {
    int id;
    printf("Enter appointment ID to delete: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < *numAppointments; i++) {
        if (appointments[i].id == id) {
            found = 1;
            for (int j = i; j < *numAppointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            (*numAppointments)--;
            printf("Appointment with Index Number %d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Appointment with Index Number %d not found.\n", id);
    }
}

// Function to update an appointment by ID
void Update_Appointment(Appointment appointments[], int numAppointments) {
    int id;
    printf("Enter appointment Index Number to update: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < numAppointments; i++) {
        if (appointments[i].id == id) {
            found = 1;
            printf("Enter new Index Number for appointment %d: ", id);
            scanf(" %[^\n]", appointments[i].description);
            printf("Enter new date and time for appointment %d (YYYY-MM-DD HH:MM): ", id);
            scanf("%lld", (long long*)&appointments[i].date);
            printf("Appointment with Index Number %d updated successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Appointment with Index Number %d not found.\n", id);
    }
}

// Function to display a single appointment by ID
void Show_Single_Appointment(Appointment appointments[], int numAppointments) {
    int id;
    printf("Enter appointment Index Number to display: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < numAppointments; i++) {
        if (appointments[i].id == id) {
            found = 1;
            printf("Appointment ID: %d\nIndex Number: %s\nDate and Time: %s\n",
                appointments[i].id, appointments[i].description, ctime(&appointments[i].date));
            break;
        }
    }
    if (!found) {
        printf("Appointment with Index Number %d not found.\n", id);
    }
}

// Function to display all appointments
void Show_All_Appointments(Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("No appointments to display.\n");
        return;
    }
    printf("All Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Appointment ID: %d\nIndex number: %s\nDate and Time: %s\n",
            appointments[i].id, appointments[i].description, ctime(&appointments[i].date));
    }
}

// Function to search appointments by keyword in description
void Search_Appointments(Appointment appointments[], int numAppointments) {
    char keyword[MAX_DESCRIPTION_LENGTH];
    printf("Enter keyword to search: ");
    scanf(" %[^\n]", keyword);
    int found = 0;
    printf("Search Results:\n");
    for (int i = 0; i < numAppointments; i++) {
        if (strstr(appointments[i].description, keyword) != NULL) {
            found = 1;
            printf("Appointment ID: %d\nIndex Number: %s\nDate and Time: %s\n",
                appointments[i].id, appointments[i].description, ctime(&appointments[i].date));
        }
    }
    if (!found) {
        printf("No appointments found matching the keyword \"%s\".\n", keyword);
    }
}

// Function to sort appointments by date and time
void Organize_Appointments(Appointment appointments[], int numAppointments) {
    // Sorting appointments by date and time
    for (int i = 0; i < numAppointments - 1; i++) {
        for (int j = 0; j < numAppointments - i - 1; j++) {
            if (appointments[j].date > appointments[j + 1].date) {
                Appointment temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }
    printf("Appointments sorted successfully.\n");
}