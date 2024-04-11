// Group Project 
// PROG71985 - Winter24 
// Ansh Dhunna
// Alli Demilade
// Abhimanyu Rajeevan


// Creating a appointment manager with all the functions 

#include "menu.h"
#include <stdio.h>

// all c files start with the stdio.h
// menu.h will hve all the refrences for the functions


// in welcome function
// it will be dislayed to the user
// to increase the experience

void printWelcome() {
    printf(" **********************\n");
    printf("**     Welcome to     **\n");
    printf("**   Appointment Manager  **\n");
    printf(" **********************\n");
}


void Display_Menu() {

    // write the numbering that will be used to run case statement in the main.c
    // add new function is used to create a new appointment 
    // delete appointment is used to delete an exiting appointment
    // update appointment will update the appointment with the new data
    // show single appointment will show ony one appointments
    // show all apppointments will show all the appointments list
    // search appointment is used to search a sepecifc appointment only
    // organize appointment will orhganize the apointment
     // make sure the numbering is coorect

    printf("1. Add New Appointment\n");
    printf("2. Delete Appointment\n");
    printf("3. Update Appointment\n");
    printf("4. Show Single Appointment\n");
    printf("5. Show All Appointments\n");
    printf("6. Search Appointments\n");
    printf("7. Save Appointments to File\n");
    printf("8. Load Appointments from File\n");
    printf("9. Organize Appointments\n");
    printf("0. Exit the program\n\n");
    printf("Enter your choice: ");
}