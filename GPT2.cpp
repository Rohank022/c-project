#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


char password[20];



struct Record {
    char type[20];
    char date[20];
    char time[20];
    char title[100];
    char details[500];
    char name[50];
    char phone[20];
    char email[20];
    char address[50];
};

void addRecord();
void addNotes();
void addMeeting();
void addContact();
void viewRecord();
void editRecord();
void deleteRecord();
void editPassword();
void saveData();
void loadData();
void printLine(char ch, int n) {
    int j;
    for(j = 0; j < n; j++) {
        printf("%c", ch);
    }
    printf("\n");
}


struct Record records[100];
int numRecords = 0;

#include <stdio.h>

int main() {
    char option,option1;
    strcpy(password, "password");
    char inputPassword[20];
    
    printf("\n\n\n\n\n\t\t\t\t   WELCOME TO PERSONAL DIARY MANAGEMENT");
    printf("\n\n\n\n\n\t\t\t\t-------------------------------------------\n");
    
   do {
        printf("\n\n\n\n\n\t\t\t\t\t Enter Password : ");
        gets(inputPassword);

        if(strcmp(inputPassword, password) != 0) {
            printf("\n\t\t\t\tInvalid password!\n");
            printf("\n\t\t\t\tPress '1' to try again or '2' to exit :");

            do {
                option = getchar();
                fflush(stdin); // clear input buffer
            } while(option != '1' && option != '2');

            if(option == '2') {
                return 0;
                
                 }
            system("cls"); // clear screen for another try
        }
    } while (strcmp(inputPassword, password) != 0);

    
    system("cls");
    
    
    do {
        printf("\n\n\t*********************************************\n");
        printf("\t*             PERSONAL DIARY MENU             *\n");
        printf("\t*********************************************\n\n");
      
        printf("\t\t [1] ADD RECORD\n");
        printf("\t\t [2] VIEW RECORD\n");
        printf("\t\t [3] EDIT RECORD\n");
        printf("\t\t [4] DELETE RECORD\n");
        printf("\t\t [5] EDIT PASSWORD\n");
        printf("\t\t [6] EXIT\n\n");
        
        printf("\t\t Select Option : ");
        
        option = getch();
        printf("%c\n", option);
        
        switch(option) {
            case '1':
                system("cls");
                addRecord();
                break;
            case '2':
                system("cls");
                viewRecord();
                
                break;
            case '3':
                system("cls");
                editRecord();
                system("Cls");
                break;
            case '4':
                system("cls");
                deleteRecord();
                break;
            case '5':
                system("cls");
                editPassword();
                break;
            case '6':
                system("cls");
                printf("\nThank you for using Personal Diary Management System!\n");
                break;
            default:
                system("cls");
                printf("\nInvalid option! Please try again.\n");
                break;
        }
    } while(option != '6');
    
    saveData();
    
    return 0;
}


void addRecord() {
    char option;
    
    do {
        printf("\n\t*********************************************\n");
        printf("\t*               ADD RECORD MENU              *\n");
        printf("\t*********************************************\n\n");
        
        printf("\t Select a record type:\n");
        printf("\t [1] Notes\n");
        printf("\t [2] Meetings\n");
        printf("\t [3] Contacts\n");
        printf("\t [4] Back to main menu\n\n");
        
        printf("\tSelect Option : ");
        
        option = getch();
        printf("%c\n", option);
        
        switch(option) {
            case '1':
            	system("cls");
                addNotes();
                break;
            case '2':
            	system("cls");
                addMeeting();
                break;
            case '3':
            	system("cls");
                addContact();
                break;
            case '4':
            	system("cls");
                printf("\nReturning to main menu...\n");
                break;
            default:
            	system("cls");
                printf("\nInvalid option! Please try again.\n");
                break;
        }
        system("cls");
    } while(option != '4');
    
}


void addNotes() {
    struct Record newRecord;
    strcpy(newRecord.type, "Notes");
    
    printf("\n\t*********************************************\n");
    printf("\t*                  ADD NOTES                 *\n");
    printf("\t*********************************************\n\n");
    
    printf("\tEnter date (DD/MM/YYYY): ");
    gets(newRecord.date);
    
    printf("\tEnter time (HH:MM): ");
    gets(newRecord.time);
    
    printf("\tEnter title: ");
    gets(newRecord.title);
    
    printf("\tEnter details: ");
    gets(newRecord.details);
    
    records[numRecords] = newRecord;
    numRecords++;
    
    printf("\n\tRecord added successfully!\n");
    printf("\n\tPress any key to continue....");
    getchar();
}


void addMeeting() {
    struct Record newRecord;
    strcpy(newRecord.type, "Meetings");

    
    printf("\n\t*********************************************\n");
    printf("\t*                 ADD MEETING                *\n");
    printf("\t*********************************************\n\n");
    
    printf("\tEnter date (DD/MM/YYYY): ");
    gets(newRecord.date);
    
    printf("\tEnter time (HH:MM): ");
    gets(newRecord.time);
    
    printf("\tEnter title: ");
    gets(newRecord.title);
    
    printf("\tEnter details: ");
    gets(newRecord.details);
    
    printf("\tEnter phone number: ");
    gets(newRecord.phone);
    
     printf("\tEnter email address: ");
    gets(newRecord.email);

    printf("\tEnter home address: ");
    gets(newRecord.address);
    
    records[numRecords++] = newRecord;
    
    printf("\n\tMeeting added successfully!\n");
}


void addContact() {
    struct Record newRecord;
    strcpy(newRecord.type, "Contacts");


    printf("\n\t*********************************************\n");
    printf("\t*                 ADD CONTACT                *\n");
    printf("\t*********************************************\n\n");

    printf("\tEnter name: ");
    gets(newRecord.title);

    printf("\tEnter phone number: ");
    gets(newRecord.phone);

    printf("\tEnter email address: ");
    gets(newRecord.email);


    records[numRecords] = newRecord;
    numRecords++;

    printf("\n\tRecord added successfully!\n");
}



void viewRecord() {
    char option;
    loadData();
    do {
    	 printf("\n\t*********************************************\n");
         printf("\t*                 VIEW RECORD                *\n");
         printf("\t*********************************************\n\n");

        printf("\t Select a record type:\n");
        printf("\t [1] Notes\n");
        printf("\t [2] Meetings\n");
        printf("\t [3] Contacts\n");
        printf("\t [4] Back to main menu\n");
        printf("\t Select Option : ");
        option = getch();
        printf("%c\n", option);
        
        switch(option) 
		{
            case '1':
            	system("Cls");
                printf("\n\n\t\t\t--- Notes ---\n\n");
                for(int i = 0; i < numRecords; i++) {
                    if(strcmp(records[i].type, "Notes") == 0) {
                        printf("\tDate: %s\n", records[i].date);
                        printf("\tTime: %s\n", records[i].time);
                        printf("\tTitle: %s\n", records[i].title);
                        printf("\tDetails: %s\n", records[i].details);
                        printf("\n");
                    }
                }
                printf("\n\t Press any key to continue...... ");
                getchar();
                system("Cls");
                break;
            case '2':
            	system("Cls");
                printf("\n\n\t\t\t--- Meetings ---\n\n");
                for(int i = 0; i < numRecords; i++) {
                    if(strcmp(records[i].type, "Meetings") == 0) {
                        printf("\tDate: %s\n", records[i].date);
                        printf("\tTime: %s\n", records[i].time);
                        printf("\tTitle: %s\n", records[i].title);
                        printf("\tDetails: %s\n", records[i].details);
                        printf("\tPhone: %s\n", records[i].phone);
                        printf("\tEmail: %s\n", records[i].email);
                        printf("\tAddress: %s\n", records[i].address);
                        printf("\n");
                    }
                }
                printf("\n\t Press any key to continue...... ");
                getchar();
                system("Cls");
                break;
            case '3':
            	system("Cls");
                printf("\n\n\t\t\t--- Contacts ---\n\n");
                for(int i = 0; i < numRecords; i++) {
                    if(strcmp(records[i].type, "Contacts") == 0) {
                        printf("\tName: %s\n", records[i].title);
                        printf("\tPhone: %s\n", records[i].phone);
                        printf("\tEmail: %s\n", records[i].email);
                        printf("\n");
                    }
                }
                printf("\n\t Press any key to continue...... ");
                getchar();
                system("Cls");
                break;
            case '4':
                printf("\n\n\t\t\tReturning to main menu…\n\n");
                break;
            default:
                printf("\n\n\t\t\tInvalid option! Please try again.\n\n");
                
                
        
                
        }
        
        
        
    } while(option != '4');
    
    system("Cls");
}


void editRecord() {
    int option, i, count = 0;
    
    printf("\n\t*********************************************\n");
    printf("\t*             EDITING RECORD                *\n");
    printf("\t*********************************************\n\n");
    
    printf("\tSelect the record type to edit:\n");
    printf("\t [1] Notes\n");
    printf("\t [2] Meetings\n");
    printf("\t [3] Contacts\n");
    
    printf("\t Enter your choice (1-3): ");
    scanf("%d", &option);
    
    if(option < 1 || option > 3) {
        printf("\t Invalid option selected!\n");
        return;
    }
    
    char type[20];
    
    switch(option) 
	{
        case 1:
            strcpy(type, "Notes");
            break;
        case 2:
            strcpy(type, "Meetings");
            break;
        case 3:
            strcpy(type, "Contacts");
            break;
            
    }


    
    for(i = 0; i < numRecords; i++) {
        if(strcmp(records[i].type, type) == 0) {
            count++;
            printf("\tRecord #%d\n", count);
            printf("\tType: %s\n", records[i].type);
            printf("\tDate: %s\n", records[i].date);
            printf("\tTime: %s\n", records[i].time);
            printf("\tTitle: %s\n", records[i].title);
            if(strcmp(type, "Notes") == 0) {
                printf("\tDetails: %s\n", records[i].details);
            } else if(strcmp(type, "Meetings") == 0) {
                printf("\tDetails: %s\n", records[i].details);
                printf("\tPhone: %s\n", records[i].phone);
                printf("\tEmail: %s\n", records[i].email);
                printf("\tAddress: %s\n", records[i].address);
            } else if(strcmp(type, "Contacts") == 0) {
                printf("\tPhone: %s\n", records[i].phone);
                printf("\tEmail: %s\n", records[i].email);
            }
        }
    }
    
    if(count == 0) {
        printf("\tNo records found for %s.\n", type);
     
     system("Cls");
    }
    
    int recordNumber;
    
    do {
        printf("\tEnter the record number to edit (1-%d): ", count);
        scanf("%d", &recordNumber);
        fflush(stdin);
        
        if(recordNumber < 1 || recordNumber > count) {
            printf("\tInvalid record number! Please try again.\n");
        }
    } while(recordNumber < 1 || recordNumber > count);
    
    int index = 0;
    
    for(i = 0; i < numRecords; i++) {
        if(strcmp(records[i].type, type) == 0) {
            index++;
        }
        if(index == recordNumber) {
            printf("\tEnter updated information for the record:\n");
            printf("\tEnter date (DD/MM/YYYY): ");
            gets(records[i].date);
            printf("\tEnter time (HH:MM): ");
            gets(records[i].time);
            printf("\tEnter title: ");
            gets(records[i].title);
            if(strcmp(type, "Notes") == 0) {
                printf("\tEnter details: ");
                gets(records[i].details);
            } else if(strcmp(type, "Meetings") == 0) {
                printf("\tEnter details: ");
                gets(records[i].details);
                printf("\tEnter phone: ");
                gets(records[i].phone);
                printf("\tEnter email: ");
                gets(records[i].email);
                printf("\tEnter address: ");
                gets(records[i].address);
            } else if(strcmp(type, "Contacts") == 0) {
                printf("\tEnter phone: ");
                gets(records[i].phone);
                printf("\tEnter email: ");
                gets(records[i].email);
            }
            printf("\tRecord updated successfully.\n");
            break;
            
            
        }
        system("Cls");
    }
}



void deleteRecord() {
    char type[20];
    int i, j;
    int deleteIndex = -1;
    char confirm;
    
    int option, count = 0;
    
    printf("\n\t*********************************************\n");
    printf("\t*              DELETE RECORD                  *\n");
    printf("\t*********************************************\n\n");
    
    printf("\tSelect the record type to edit:\n");
    printf("\t [1] Notes\n");
    printf("\t [2] Meetings\n");
    printf("\t [3] Contacts\n");
    
    printf("\t Enter your choice (1-3): ");
    scanf("%d", &option);
    
    if(option < 1 || option > 3) {
        printf("\t Invalid option selected!\n");
        return;
    }
    
    
    switch(option) 
	{
        case 1:
            strcpy(type, "Notes");
            break;
        case 2:
            strcpy(type, "Meetings");
            break;
        case 3:
            strcpy(type, "Contacts");
            break;
            
    }
    
    for(i = 0; i < numRecords; i++) {
        if(strcmp(records[i].type, type) == 0) {
            count++;
            printf("\tRecord #%d\n", count);
            printf("\tType: %s\n", records[i].type);
            printf("\tDate: %s\n", records[i].date);
            printf("\tTime: %s\n", records[i].time);
            printf("\tTitle: %s\n", records[i].title);
            if(strcmp(type, "Notes") == 0) {
                printf("\tDetails: %s\n", records[i].details);
            } else if(strcmp(type, "Meetings") == 0) {
                printf("\tDetails: %s\n", records[i].details);
                printf("\tPhone: %s\n", records[i].phone);
                printf("\tEmail: %s\n", records[i].email);
                printf("\tAddress: %s\n", records[i].address);
            } else if(strcmp(type, "Contacts") == 0) {
                printf("\tPhone: %s\n", records[i].phone);
                printf("\tEmail: %s\n", records[i].email);
            }
            
            printf("\n");
        }
    }
    
    if(count == 0) {
        printf("\tNo records found for %s.\n", type);
        return;
    }
    
    
    do {
        printf("\tEnter the number of the record to delete: ");
        scanf("%d", &deleteIndex);
        getchar();
        
        if(deleteIndex < 1 || deleteIndex > numRecords) {
            printf("\tInvalid record number! Please try again.\n");
        }
    } while(deleteIndex < 1 || deleteIndex > numRecords);
    
    printf("\tAre you sure you want to delete record '%s'? (Y/N): ", records[deleteIndex-1].title);
    confirm = getch();
    
    if(confirm == 'Y' || confirm == 'y')
	 {
        for(i = deleteIndex-1; i < numRecords-1; i++) {
            strcpy(records[i].type, records[i+1].type);
            strcpy(records[i].date, records[i+1].date);
            strcpy(records[i].time, records[i+1].time);
            strcpy(records[i].title, records[i+1].title);
            strcpy(records[i].details, records[i+1].details);
            strcpy(records[i].phone, records[i+1].phone);
            strcpy(records[i].email, records[i+1].email);
            strcpy(records[i].address, records[i+1].address);
        }
        numRecords--;
        printf("\n\tRecord deleted successfully!\n");
    } 
	else {
        printf("\n\tRecord not deleted.\n");
    }
    
    printf("\n\t Press any key to continue......");
    getchar();
}


void editPassword() {
    char oldPassword[20];
    char newPassword[20];
    char confirmPassword[20];
    int option;
    
    printf("\n\t*********************************************\n");
    printf("\t*               EDIT PASSWORD                  *\n");
    printf("\t*********************************************\n\n");
    
    do {
        printf("\tEnter old password: ");
        gets(oldPassword);
        
        if (strcmp(oldPassword, password) != 0) {
            printf("\tInvalid password!\n");
            printf("\t1) Try again\n");
            printf("\t2) Go back to previous menu\n");
            printf("\tChoose an option: ");
            scanf("%d", &option);
            fflush(stdin);
            
            if (option == 2) {
            	system("cls");
                return;
            }
        }
    } while(strcmp(oldPassword, password) != 0);
    
    printf("\n\tEnter new password: ");
    gets(newPassword);
    
    printf("\n\tConfirm new password: ");
    gets(confirmPassword);
    
    if (strcmp(newPassword, confirmPassword) != 0) {
        printf("\n\tPasswords do not match!\n");
        return;
    }
    
    strcpy(password, newPassword);
    
    printf("\n\tPassword changed successfully!\n");
    
    
     printf("\n\t Press any key to go back to previous menu ");
     getchar();
     system("Cls");
}

void saveData() {
    FILE *file;
    file = fopen("records.txt", "a");
    if(file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }
    
   
    fprintf(file, "%d\n", numRecords);
    for(int i = 0; i < numRecords; i++) {
        fprintf(file, "%s\n", records[i].type);
        fprintf(file, "%s\n", records[i].date);
        fprintf(file, "%s\n", records[i].time);
        fprintf(file, "%s\n", records[i].title);
        fprintf(file, "%s\n", records[i].details);
        fprintf(file, "%s\n", records[i].phone);
        fprintf(file, "%s\n", records[i].email);
        fprintf(file, "%s\n", records[i].address);
    }
    
    fclose(file);
    printf("\nData saved successfully.\n");
}

void loadData() {
    FILE *fp = fopen("records.", "r");
    if(fp == NULL) {
        printf("Error: Unable to open file for loading data!\n");
        return;
    }
    
    fread(&numRecords, sizeof(numRecords), 1, fp);
    fread(records, sizeof(records), 1, fp);
    fclose(fp);
}
