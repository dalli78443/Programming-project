// Group Project 
// PROG71985 - Winter24 
// Ansh Dhunna
// Alli Demilade
// Abhimanyu Rajeevan


// Creating a appointment manager with all the functions 
// all the header file starts with the pragma once 

#pragma once

// time libabary is used to perform funtions with time

#include <time.h>

// defining max description length with 100
// max appointments were 100

#define MAX_DESCRIPTION_LENGTH 100
#define MAX_APPOINTMENTS 100

// Struct to represent an appointment
// int value for storing the id number
// char descirption for storing the char value
//time_t using the time fucntion for the date
typedef struct {
    int id;
    char description[MAX_DESCRIPTION_LENGTH];
    time_t date;

}Appointment;

// write the functions name all used in the project
// add new function is used to create a new appointment
// delete appointment is used to delete an exiting appointment
// update appointment will update the appointment with the new data
// show single appointment will show ony one appointments
// show all apppointments will show all the appointments list
// search appointment is used to search a sepecifc appointment only
// organize appointment will orhganize the apointment

void Add_New_Appointment(Appointment appointments[], int* numAppointments);
void Delete_Appointment(Appointment appointments[], int* numAppointments);
void Update_Appointment(Appointment appointments[], int numAppointments);
void Show_Single_Appointment(Appointment appointments[], int numAppointments);
void Show_All_Appointments(Appointment appointments[], int numAppointments);
void Search_Appointments(Appointment appointments[], int numAppointments);
void Organize_Appointments(Appointment appointments[], int numAppointments);
