#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include "appointment.h"

void Save_Appointments_To_File(const char* filename, Appointment appointments[], int numAppointments);
void Load_Appointments_From_File(const char* filename, Appointment appointments[], int* numAppointments);

#endif /* FILE_HANDLING_H */