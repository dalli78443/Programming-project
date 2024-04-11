//prog71985-winter24-project-number1
//alli demilade
//appointment  program
#pragma once

#include "appointment.h"

void Save_Appointments_To_File(const char* filename, Appointment appointments[], int numAppointments);
void Load_Appointments_From_File(const char* filename, Appointment appointments[], int* numAppointments);

