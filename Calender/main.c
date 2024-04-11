// Group Project 
// PROG71985 - Winter24 
// Ansh Dhunna
// Alli Demilade
// Abhimanyu Rajeevan

// Creating a appointment manager with all the functions

#include <stdio.h>
#include "menu.h"
#include "appointment.h"
#include "file_handling.h"

// write the name of all the libraries for the refences
// menu.h have the refrences for the menu shown in the output
// appointment.h have the appointmnts functions refrences
// file handling.h have the refrences for saving and loading data
// define max appointments upt 100


// to encounter the problems with the scanf,strcmp and strcpy
// _CRT_SECURE_NO_WARNINGS is used in by going to properties
// after going to properties going to the reprocessor and write
// _CRT_SECURE_NO_WARNINGS


#define MAX_APPOINTMENTS 100

// now start the function from int main


int main() {

    // Declare an array to store appointments
    // take a int variable and assign it with starting value 0

    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    // Load appointments from file 
    // that are saved prevously in the file name cslled
    // appointment.txt 

    Load_Appointments_From_File("appointments.txt", appointments, &numAppointments);

    // create a variable for storing the value inputed by the user
    // use do while statement for running the functions
    // now recall the print welcome funxtion, this will print the the top welcome output 
    // for better documentaion and out
    // Load appointments from file if any
    Load_Appointments_From_File("appointments.txt", appointments, &numAppointments);

    int choice;
    do {
        printWelcome();

        // display menu will show all the menu that is listed in the menu.c
        // use scanf to get the input from the user

        Display_Menu();
        scanf("%d", &choice);

        // use switch case to run a conditional statement

        switch (choice) {
        case 1:
            Add_New_Appointment(appointments, &numAppointments); // will add appointment
            break;
        case 2:
            Delete_Appointment(appointments, &numAppointments); // delete appointment
            break;
        case 3:
            Update_Appointment(appointments, numAppointments); // update appointment
            break;
        case 4:
            Show_Single_Appointment(appointments, numAppointments); // show single appointments
            break;
        case 5:
            Show_All_Appointments(appointments, numAppointments); // will show all appointments 
            break;
        case 6:
            Search_Appointments(appointments, numAppointments);  // will search a particular appointment 
            break;
        case 7:
            Save_Appointments_To_File("appointments.txt", appointments, numAppointments); // will save all the appointments into txt file
            break;
        case 8:
            Load_Appointments_From_File("appointments.txt", appointments, numAppointments);
            break;
        case 9:
            Organize_Appointments(appointments, numAppointments); //  will organize all the code into a particular manner
            break;
        case 0:
            printf("Exiting...\n"); // 0 will mean exiting the code  so use printf command to exit the code 
            break;
        default:
            printf("Invalid entry!  Please enter valid number\n"); // if not defsailt will show wrong input,
        }
    } while (choice != 0);

    return 0;
}