#ifndef GLOBAL_VARIABLE
#define GLOBAL_VARIABLE

typedef struct Patient{             /// struct for all data of patient
    char name[50];                  /// note for arranging element in descending order to overcome the problem of padding in memory
    char reservationTime[20];
    char gender[10];
    int ID;
    u8 age;
}patient;

patient* AllPatients;               /// pointer to dynamic array of allPatient
                                        /// Don't forger to initialize the pointer
s16 currIndex=-1;                    /// index to count and access array elements

char *availableAppointments[]=
        {"2pm to 2:30pm","2:30pm to 3pm","3pm to 3:30pm","4pm to 4:30pm","4:30pm to 5pm"};



#endif