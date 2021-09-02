#ifndef FUNCTIONS_BODY
#define FUNCTIONS_BODY

/*Functions Of Admin mode*/
void checkAdminModePass()
{
    u8 tryNum=3;
    system("cls");
    tryAgain:
    printf("\t Please Enter Password For Admin :");
    u16 pass;
    scanf("%hd",&pass);
    if(pass==1234)
    {
        system("cls");
        initializeAdminMode();
    }
    else if(tryNum!=1)
    {
        printf("\tInvalid password ,tryAgain[%d]\n",--tryNum);
        goto tryAgain;
    }
    else
    {
        printf("No more Try");
        system("exit");
    }
}
void initializeAdminMode()
{
    system("cls");
    if(currIndex!=-1)
    {
        for (int i = 0; i <= currIndex; i++)
        {
            printf("Id of index %d = %d\n", i, AllPatients[i].age);
        }
    }
    u8 choose;
    printf("\t\t \n Welcome Admin \n");
    printf("\t\t 1] Add new patient record  \n");
    printf("\t\t 2] Edit patient record \n");
    printf("\t\t 3] Reserve a slot with the doctor \n");
    printf("\t\t 4] Cancel reservation \n");
    printf("\t\t 5] Return To Home Page \n");
    printf("\t\t 6] Exit From Program \n");
    printf("\t\t  What you Want to do ?? : ");
    scanf("%d",&choose);
    switch (choose) {
        case 1:
            insertNewPatient();
            break;
        case 2:
            updatePatient();
            break;
        case 3:
            reserveWithDoctor();
            break;
        case 4:
            cancelReservation();
            break;
        case 5:
            initializeSystem();
            break;
        case 6:
            system("cls");
            printf("\n\t\tThanks For Using Our Program");
            system("exit");
            break;
        default:
            printf("\t\t Invalid Input");
            initializeAdminMode();
    }
}
void insertNewPatient()
{
    system("cls");
    patient *temp=(patient *) realloc(AllPatients,_msize(AllPatients)+1+sizeof(patient) );
    if(temp==NULL)
    {
        printf("\nError NO Memory Available");
        system("exit");
    }
    else
    {
        AllPatients=temp;
        printf("size  now is %llu", _msize(AllPatients));

        int ID=0;
        char stopVar;

        repeatedId:
        printf("\n\t Enter Patient Id: ");
        scanf("%d", &ID);
    //    printf("Id of inserted %d \n",ID);
        /// Check if id is repeated;
        if (checkRepeatedId(ID))
        {
            printf("\t \t This id is exist please enter unique one\n");
            goto repeatedId;
        }

        currIndex++;
        AllPatients[currIndex].ID=ID;
        strcpy(AllPatients[currIndex].reservationTime,"");
        printf("\t Enter Patient name: ");
        scanf("%s",AllPatients[currIndex].name);

        printf("\t Enter Patient gender: ");
        scanf("%s",AllPatients[currIndex].gender);

        printf("\t Enter Patient age: ");
        scanf("%s", &AllPatients[currIndex].age);

        printf("\n\t Patient Created Successfully\n");
        printf("\t press any Key to Return");
        scanf("%c",&stopVar);
        scanf("%c",&stopVar);
        initializeAdminMode();
    }
}
void updatePatient()
{
    system("cls");
    char stop;
    int id ;
    printf("\n\t Enter Patient Id: ");
    scanf("%d", &id);
    int index= getIndexFromId(id);
    if (index==-1)
    {
        printf("\t Sorry not Correct Id\n");
        printf("\tPress Any Key To Return :");
        scanf("%c",&stop);
        scanf("%c",&stop);
        initializeAdminMode();
    }
    else
    {
        printf("\t Enter Patient name: ");
        scanf("%s",AllPatients[index].name);
        printf("\t Enter Patient gender: ");
        scanf("%s",AllPatients[index].gender);

        printf("\t Enter Patient age: ");
        scanf("%s", &AllPatients[index].age);
        printf("\n\t Patient Updated Successfully\n");
        printf("\t press any Key to Return");
        scanf("%c",&stop);
        scanf("%c",&stop);
        initializeAdminMode();

    }

}
void reserveWithDoctor()
{
    system("cls");
    u16 id;
    char stop;
    printf("\t\n please Enter Patient ID:");
    scanf("%hd",&id);
    s16 index=getIndexFromId(id);
    if(index!=-1)
    {
        for (int i =0; i<=4;i++)
        {
            if (strcmp(availableAppointments[i], "")) {
                printf(" press [%d] to reserve at  %s \n", i + 1, availableAppointments[i]);
            }
        }
            int app;
            scanf("%d",&app);
            switch (app) {
                case 1:
                    if(strcmp(availableAppointments[0], ""))
                    {
                        strcpy(AllPatients[index].reservationTime,availableAppointments[0]);
                        availableAppointments[0]="";
                        printf("\t Reserved Successfully\n");
                    }
                    break;
                case 2:
                    if(strcmp(availableAppointments[1], ""))
                    {
                        strcpy(AllPatients[index].reservationTime,availableAppointments[1]);
                        availableAppointments[1]="";
                        printf("\t Reserved Successfully\n");
                    }
                    break;
                case 3:
                    if(strcmp(availableAppointments[2], ""))
                    {
                        strcpy(AllPatients[index].reservationTime,availableAppointments[2]);
                        availableAppointments[2]="";
                        printf("\t Reserved Successfully\n");
                    }
                    break;
                case 4:
                    if(strcmp(availableAppointments[3], ""))
                    {
                        strcpy(AllPatients[index].reservationTime,availableAppointments[3]);
                        availableAppointments[3]="";
                        printf("\t Reserved Successfully\n");
                    }
                    break;
                case 5:
                    if(strcmp(availableAppointments[4], ""))
                    {
                        strcpy(AllPatients[index].reservationTime,availableAppointments[4]);
                        availableAppointments[4]="";
                        printf("\t Reserved Successfully\n");
                    }
                    break;
                default:
                    printf("\t\t \n Invalid chosse");
                    printf("\tPress Any Key To Return :");
                    scanf("%c",&stop);
                    scanf("%c",&stop);
                    initializeAdminMode();

        }

        printf("\tPress Any Key To Return :");
        scanf("%c",&stop);
        scanf("%c",&stop);
        initializeAdminMode();
    }
    else
    {
        printf("\t Sorry not Correct Id\n");
        printf("\tPress Any Key To Return :");
        scanf("%c",&stop);
        scanf("%c",&stop);
        initializeAdminMode();
    }

}
void cancelReservation()
{
    system("cls");
    u16 id;
    char stop;
    printf("\t\n please Enter Patient ID:");
    scanf("%hd",&id);
    s16 index=getIndexFromId(id);
    if(index!=-1)
    {
        if(!strcmp(AllPatients[index].reservationTime,"2pm to 2:30pm"))
        {
            availableAppointments[0]="2pm to 2:30pm";
            strcpy(AllPatients[index].reservationTime,"");
        }
        else if(!strcmp(AllPatients[index].reservationTime,"2:30pm to 3pm"))
        {
            availableAppointments[1]="2:30pm to 3pm";
            strcpy(AllPatients[index].reservationTime,"");
        }
        else if(!strcmp(AllPatients[index].reservationTime,"3pm to 3:30pm"))
        {
            availableAppointments[2]="3pm to 3:30pm";
            strcpy(AllPatients[index].reservationTime,"");
        }
        else if(!strcmp(AllPatients[index].reservationTime,"4pm to 4:30pm"))
        {
            availableAppointments[3]="4pm to 4:30pm";
            strcpy(AllPatients[index].reservationTime,"");
        }
        else if(!strcmp(AllPatients[index].reservationTime,"4:30pm to 5pm"))
        {
            availableAppointments[4]="4:30pm to 5pm";
            strcpy(AllPatients[index].reservationTime,"");
        }
        else
        {
            printf("\t this user has not any  Reservation \n");
            printf("\tPress Any Key To Return :");
            scanf("%c",&stop);
            scanf("%c",&stop);
            initializeAdminMode();
        }

        printf("\t Reservation Canceled Successfully \n");
        printf("\tPress Any Key To Return :");
        scanf("%c",&stop);
        scanf("%c",&stop);
        initializeAdminMode();
    }
    else
    {
        printf("\t Sorry not Correct Id\n");
        printf("\tPress Any Key To Return :");
        scanf("%c",&stop);
        scanf("%c",&stop);
        initializeAdminMode();
    }
}

/*Functions Of user mode*/
void initializeUserMode()
{
    system("cls");
    u8 choose;
    printf("\t\t \n Welcome User \n");
    printf("\t\t 1] View patient record  \n");
    printf("\t\t 2] View today reservations \n");
    printf("\t\t 3] Return To Home Page \n");
    printf("\t\t 4] Exit From Program \n");
    printf("\t\t  What you Want to do ?? : ");
    scanf("%d",&choose);
    switch (choose) {
        case 1:
            viewPatientRecord();
            break;
        case 2:
             viewToDayReservations();
            break;

        case 3:
            initializeSystem();
            break;
        case 4:
            system("cls");
            printf("\n\t\tThanks For Using Our Program");
            system("exit");
            break;
        default:
            printf("\t\t Invalid Input");
            initializeAdminMode();
    }
}
void viewPatientRecord()
{
    system("cls");
    int id,flag=0;
    printf("\t\tPlease Enter your Id \n");
    scanf("%d",&id);
    for (int i =0; i<=currIndex;i++)
    {
        if (AllPatients[i].ID==id)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        char stop;
        printf("\t Error The id not found \n");
        printf("\tPress Any Key To Return :");
        scanf("%c",&stop);
        scanf("%c",&stop);
        initializeUserMode();
    }
    else
    {
        int index=getIndexFromId(id);
        char stop;
        printf("\t\t Welcome %s , Your information is : \n",AllPatients[index].name);
        printf("\t\t Name: %s : \n",AllPatients[index].name);
        printf("\t\t ID : %d   \n",AllPatients[index].ID);
        printf("\t\t gender: %s   \n",AllPatients[index].gender);
        printf("\t\t age : %d   \n",AllPatients[index].age);
        printf("\t\t reservationTime: %s  \n",AllPatients[index].reservationTime);

        printf("\tPress Any Key To Return :");
        scanf("%c",&stop);
        scanf("%c",&stop);
        initializeUserMode();
    }
}
void viewToDayReservations()
{
    system("cls");
    char stop;
    for (int i =0; i<=currIndex;i++)
    {
    //    printf("current %s \n",AllPatients[i].reservationTime);
        if (strcmp(AllPatients[i].reservationTime,""))
        {
            printf("Patient with id = %d has Reservation at %s \n",AllPatients[i].ID,AllPatients[i].reservationTime);

        }
    }
    printf("\t \nPress Any Key To Return :");
    scanf("%c",&stop);
    scanf("%c",&stop);
    initializeUserMode();
}


/* Some Helper Functions*/
void initializeSystem()
{
    system("cls");
    int mode;
    printf("\n\t\t\t Welcome in Clinic Management System App\n");
    tryChooseMod:
    printf("\t1] Admin Mode\n");
    printf("\t2] User Mode\n");
    printf("\tplease Enter Mode: ");
    scanf("%d",&mode);

    if(mode==1)
    {
        checkAdminModePass();
    }
    else if(mode==2)
    {
        initializeUserMode();
    }
    else
    {
        system("cls");
        printf("\tinvalid input \n");
        goto tryChooseMod;
    }



}

s16 getIndexFromId(u16 id)
{
    for (u16 i =0; i<=currIndex;i++)
    {
        if(AllPatients[i].ID==id)
        {
            return i;
        }
    }
    printf("Id not found \n");
    return  -1;

}
s8 checkRepeatedId(u16 id)
{
/*    for(int i=0;i<=currIndex;++i)
    {
        printf("Id of index %d = %d\n",i,AllPatients[i].ID);
    }*/
    for (int i =0; i<=currIndex;i++)
    {
        if(AllPatients[i].ID==id)
        {
            return 1;
        }
    }
    return  0;
}



#endif
