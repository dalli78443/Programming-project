//prog71985-winter24-project-number1
// ansh dhunna
//appointment  program

#pragma once


#include <time.h>

#define MAX_DESCRIPTION_LENGTH 100
#define MAX_APPOINTMENTS 100

// Struct to represent an appointment
typedef struct {
    int id;
    char description[MAX_DESCRIPTION_LENGTH];
    time_t date;
    // Add more fields as needed
}Appointment;

void Add_New_Appointment(Appointment appointments[], int* numAppointments);
void Delete_Appointment(Appointment appointments[], int* numAppointments);
void Update_Appointment(Appointment appointments[], int numAppointments);
void Show_Single_Appointment(Appointment appointments[], int numAppointments);
void Show_All_Appointments(Appointment appointments[], int numAppointments);
void Search_Appointments(Appointment appointments[], int numAppointments);
void Organize_Appointments(Appointment appointments[], int numAppointments);
