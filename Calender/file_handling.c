// Group Project 
// PROG71985 - Winter24 
// Ansh Dhunna
// Alli Demilade
// Abhimanyu Rajeevan


// Creating a appointment manager with all the functions 
// all the header file starts with the pragma once 

#include "file_handling.h"
#include <stdio.h>

// file_handling.h library is used to take refrence from the header file

// save appointments to file will save all the data into the function
// it will take char pointer as a file name
// f open is used to open the file
// file name is specified in the main.c that is appointments.txt
// w means writing , it will writw thw data into the file 
// also run a if statement to check wather the data is null or have no value 
// so it will print error opening the file
// if its also unable to open the file


void Save_Appointments_To_File(const char* filename, Appointment appointments[], int numAppointments) {
    FILE* file;
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // if there is no errors then it will start a for loop adnd save all the data int the filr
    // fprintf will print the data into the file


    for (int i = 0; i < numAppointments; i++) {
        fprintf(file, "%d,%s,%lld\n", appointments[i].id, appointments[i].description, (long long)appointments[i].date);
    }

    // after all this fclose will close the files
    // and prnt that all the appointments have been saved to file sucessfully

    fclose(file);
    printf("Appointments saved to file successfully.\n");
}

// load appointment from file will load all the appointmens from the previous data from the file 
// // f open is used to open the file
// file name is specified in the main.c that is appointments.txt
// r means readingcthe data 
// also run a if statement to check wather the data is null or have no value 
// so it will print error opening the file
// if its also unable to open the file

void Load_Appointments_From_File(const char* filename, Appointment appointments[], int* numAppointments) {
    FILE* file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    // Clear existing appointments
    *numAppointments = 0;

    // now while statement will get all the data from the file and print on the screen
    // max appointments will check weather the appointments are in the limit
    // && this act as a and conditioner
    // lld means very long integer
    // ir will asign the id, description, date and assign all the values 
    // and load it frommthe file with incrementing it

    while (*numAppointments < MAX_APPOINTMENTS && fscanf(file, "%d,%[^,],%lld\n",
        &appointments[*numAppointments].id, appointments[*numAppointments].description,
        (long long*)&appointments[*numAppointments].date) == 3) {
        (*numAppointments)++;
    }
    // use fclose to close all the files
    // prinyf wll show that files were created succesfully

    fclose(file);
    printf("Appointments loaded from file successfully.\n");
}