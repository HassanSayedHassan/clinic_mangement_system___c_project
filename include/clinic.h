
#ifndef CLINIC_H
#define CLINIC_H



/*Functions Of Admin mode*/
void checkAdminModePass();
void initializeAdminMode();
void insertNewPatient();
void updatePatient();
void reserveWithDoctor();
void cancelReservation();
/*Functions Of user mode*/
void initializeUserMode();
void viewPatientRecord();
void viewToDayReservations();
/* Some Helper Functions*/
void initializeSystem();
s16 getIndexFromId(u16 id);
s8 checkRepeatedId(u16 id);




#endif


