
#include <stdio.h>
//prog71985-winter24-project-number1
// alli demilade
//appointment  program


#include "menu.h"
#include "appointment.h"
#include "file_handling.h"

#define MAX_APPOINTMENTS 100

int main() {
    // Declare an array to store appointments
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    // Load appointments from file if any
    Load_Appointments_From_File("appointments.txt", appointments, &numAppointments);

    // Main menu
    int choice;
    do {
        printWelcome();

        Display_Menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            Add_New_Appointment(appointments, &numAppointments);
            break;
        case 2:
            Delete_Appointment(appointments, &numAppointments);
            break;
        case 3:
            Update_Appointment(appointments, numAppointments);
            break;
        case 4:
            Show_Single_Appointment(appointments, numAppointments);
            break;
        case 5:
            Show_All_Appointments(appointments, numAppointments);
            break;
        case 6:
            Search_Appointments(appointments, numAppointments);
            break;
        case 7:
            Save_Appointments_To_File("appointments.txt", appointments, numAppointments);
            break;
        case 8:
            Load_Appointments_From_File("appointments.txt", appointments, &numAppointments);
            break;
        case 9:
            Organize_Appointments(appointments, numAppointments);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid entry!  Please enter valid number\n");
        }
    } while (choice != 0);

    return 0;
}
