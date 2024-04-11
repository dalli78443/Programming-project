//prog71985-winter24-project-number1
//alli demilade
//appointment  program
#include "file_handling.h"
#include <stdio.h>

void Save_Appointments_To_File(const char* filename, Appointment appointments[], int numAppointments) {
    FILE* file;
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numAppointments; i++) {
        fprintf(file, "%d,%s,%lld\n", appointments[i].id, appointments[i].description, (long long)appointments[i].date);
    }

    fclose(file);
    printf("Appointments saved to file successfully.\n");
}

void Load_Appointments_From_File(const char* filename, Appointment appointments[], int* numAppointments) {
    FILE* file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    // Clear existing appointments
    *numAppointments = 0;

    while (*numAppointments < MAX_APPOINTMENTS && fscanf(file, "%d,%[^,],%lld\n",
        &appointments[*numAppointments].id, appointments[*numAppointments].description,
        (long long*)&appointments[*numAppointments].date) == 3) {
        (*numAppointments)++;
    }

    fclose(file);
    printf("Appointments loaded from file successfully.\n");
}