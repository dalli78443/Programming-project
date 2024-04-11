//prog71985-winter24-project-number1
// ansh dhunna
//appointment  program

#pragma once


#include <time.h>

#define MAX_DESCRIPTION_LENGTH 100
#define MAX_APPOINTMENTS 100

// Struct to represent an appointment
typedef struct {
    int id; // Unique identifier for the appointment
    char description[MAX_DESCRIPTION_LENGTH]; // Description of the appointment
    time_t date; // Date and time of the appointment
    // Add more fields as needed
} Appointment; // Define Appointment structure

// Function prototypes for appointment management
void Add_New_Appointment(Appointment appointments[], int* numAppointments); // Add a new appointment
void Delete_Appointment(Appointment appointments[], int* numAppointments); // Delete an appointment
void Update_Appointment(Appointment appointments[], int numAppointments); // Update an appointment
void Show_Single_Appointment(Appointment appointments[], int numAppointments); // Display a single appointment
void Show_All_Appointments(Appointment appointments[], int numAppointments); // Display all appointments
void Search_Appointments(Appointment appointments[], int numAppointments); // Search appointments
void Organize_Appointments(Appointment appointments[], int numAppointments); // Organize appointments

