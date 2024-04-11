// Group Project 
// PROG71985 - Winter24 
// Ansh Dhunna
// Alli Demilade
// Abhimanyu Rajeevan


// Creating a appointment manager with all the functions 


#include "appointment.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// appointment.h is used to take refrence fromm the header file
// string used to use functions like strcmp  , strcpy
// stdbool fr using bool statments


// writing a function for adding a new appointment
// first run the if statementnto to ceck weather the appointments are up to dste
// amd the max appointments are 100 defined in header file , if its more tha that
// shows appointment limit reach 

void Add_New_Appointment(Appointment appointments[], int* numAppointments) {
    if (*numAppointments >= MAX_APPOINTMENTS) {
        printf("Max Appointment limit Reached!! Sorry\n");
        return;
    }
    // now enter the apppointment index number or the desciption so that you can also use it for other tasks
    // use scanf cmmand and save that into the description variable 

    printf("Enter appointment Index Number: ");
    scanf(" %[^\n]", appointments[*numAppointments].description);

    // Validating date and time input

    bool validDateTime = false;

    // running a do while statement for getting input and creating an appointment
    // take all variables input ttpe for performing th function

    do {
        printf("Enter appointment date and time (YYYY-MM-DD HH:MM): ");
        int year, month, day, hour, minute;

        // take if statementnto make sure that if all the input are in the same pattern 
        // and all 5 are assigned in the value it will save the appointment
        // use another if command for checking rather the input are valid and are in the particular range
        // year alueis puuted in 2000 year so appointment before 2000 will not acce[pted
        // and the ,ax is 9999 means 4 digit numbers
        // in month it should be between 1-12
        // days must should be 1-31
        // hours must be 1-23
        // minutes must be 0-59
        // set time function is used to set the timings
        // it use time.h libarray refrred in the appointment.h
        // if all the statements are valid it will create a new appointment

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

            // else it will printf that it is invalid and try agabn

            else {
                printf("Invalid date or time format. Please enter again.\n");
            }
        }  // if the format is not coorect it will
        // ahow you to enter the details again
        else {
            printf("Invalid input format. Please enter again.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    } while (!validDateTime);

    // if all this perfomed well then it will print appointment added successfully

    appointments[*numAppointments].id = *numAppointments + 1; // Assign unique ID
    (*numAppointments)++;
    printf("Appointment added successfully.\n");
}


// Function to delete an appointment by ID
// first enter the appointment id or the input that was saved in the decription file so that
// it could be used for the deleting
// use printf and scanf to get user input
// creae a for loo[ for deleting an appointment
// create a local varible matched and assign it with value 0
// it will check that id matched if matched it will
// then over write it and delete
// by using another for loop
// and will print deleted successfully

void Delete_Appointment(Appointment appointments[], int* numAppointments) {
    int id;
    printf("Enter appointment ID to delete: ");
    scanf("%d", &id);
    int matched = 0;
    for (int i = 0; i < *numAppointments; i++) {
        if (appointments[i].id == id) {
            matched = 1;
            for (int j = i; j < *numAppointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            (*numAppointments)--;
            printf("Appointment with Index Number %d deleted successfully.\n", id);
            break;
        }
    }
    // if it do not matched then it will print
    // not found error
    if (!matched) {
        printf("Appointment with Index Number %d is not in appointment list\n", id);
    }
}

// Function to update an appointment by ID
// first enter the appointment id or the input that was saved in the decription file so that
// it could be used for the updating
// use printf and scanf to get user input
// creae a for loo[ for updating an appointment
// create a local varible matched and assign it with value 0
// it will check that id matched if matched it will
// then over write it and update
// now it will ask for the new index number or the desciption number
// enter the new date and time
// now it will save that data and update it
// sjowing thatnnew data is updated

void Update_Appointment(Appointment appointments[], int numAppointments) {
    int id;
    printf("Enter appointment Index Number to update: ");
    scanf("%d", &id);
    int matched = 0;
    for (int i = 0; i < numAppointments; i++) {
        if (appointments[i].id == id) {
            matched = 1;
            printf("Enter new Index Number for appointment %d: ", id);
            scanf(" %[^\n]", appointments[i].description);
            printf("Enter new date and time for appointment %d (YYYY-MM-DD HH:MM): ", id);
            scanf("%lld", (long long*)&appointments[i].date);
            printf("Appointment with Index Number %d is now updated.\n", id);
            break;
        }
    }

    // if it do not match then shows that no appointment found
    if (!matched) {
        printf("There is no appoin", id);
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
        printf("Appointment with Index Number %d is not in appointment list\n", id);
    }
}

// Function to display all appointments
// first create a if statement for checking rather there are the appointments to display
// if the num of appointment is 0 shows that there is no appointments in the list 

void Show_All_Appointments(Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("There is no appointments in the list.\n");
        return;
    }

    // if not, it means there are appointments to print
    // then use printf and for loop commands for printing
    // incrementing the i++ ,and assing it with the appointments
    // after sing prntf to print everthing
    printf("All Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Appointment ID: %d\nIndex number: %s\nDate and Time: %s\n",
            appointments[i].id, appointments[i].description, ctime(&appointments[i].date));
    }
}

// Function to search appointments by keyword in description
// it will be used to search an appointent
// make sure that the decription length is within the limits
// take printf and scanf commands to input the value from the user
// use integer match to check if there is the same id number in the appointment list
// if there is appointment, then it will search results
// now use for loop for getting the value for the date and time
// and will print

void Search_Appointments(Appointment appointments[], int numAppointments) {
    char keyword[MAX_DESCRIPTION_LENGTH];
    printf("Enter keyword to search: ");
    scanf(" %[^\n]", keyword);
    int matched = 0;
    printf("Search Results:\n");
    for (int i = 0; i < numAppointments; i++) {
        if (strstr(appointments[i].description, keyword) != NULL) {
            matched = 1;
            printf("Appointment ID: %d\nIndex Number: %s\nDate and Time: %s\n",
                appointments[i].id, appointments[i].description, ctime(&appointments[i].date));
        }
    }

    // if it is not matched then show error in finding appointment
    if (!matched) {
        printf("Appointment with Index Number %d is not in appointment list \"%s\".\n", keyword);
    }
}

// Function to sort appointments by date and time
// create a for loop to sort all the appointments 
// create another loop and now create a temp varible for giing the value of j
// now incremenet it for getting another input
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

    // after all the statements runs succesffully it shows
    // appointments sorted succesfully

    printf("Appointments sorted successfully.\n");
}
