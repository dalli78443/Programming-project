// Group Project 
// PROG71985 - Winter24 
// Ansh Dhunna
// Alli Demilade
// Abhimanyu Rajeevan


// Creating a appointment manager with all the functions 
// all the header file starts with the pragma once 

#pragma once

// file handling file is linked to the appointment file
// as it has the load and sve function which will save the data into the file
// so we will write the libary here


#include "appointment.h"

// write the functions used 
// save appointments to file will save the appointments to file
// load appointments tfrom file will load all the appointments to file

void Save_Appointments_To_File(const char* filename, Appointment appointments[], int numAppointments);
void Load_Appointments_From_File(const char* filename, Appointment appointments[], int* numAppointments);