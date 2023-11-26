#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100000

typedef struct HospitalManagementSystem {
    int MedicalRecordNumber;
    int Day_of_Entry;
    int Month_of_Entry;
    int Year_of_Entry;
    char Patient_First_Name[15];
    char Patient_Last_Name[20];
    char Patient_Father_First_Name[15];
    char Patient_Mother_First_Name[15];
    long long int Mobile_number;
    int age;
    char BloodGroup[6];
    char Gender[12];
    char Doctor_Name[15];
    char Doctor_Medical_Registration_Number[20];
    int Day_of_Exit;
    int Month_of_Exit;
    int Year_of_Exit;
} HMS;

HMS hospitalRecords[MAX_RECORDS];
int totalRecords = 0;

void LoadFromFile() {
    FILE *file = fopen("hospital_records.txt", "r");
    if (file == NULL) {
        printf("No saved records found.\n");
        return;
    }

    fscanf(file, "%d", &totalRecords);
    for (int i = 0; i < totalRecords; i++) {
        fscanf(file, "%d", &hospitalRecords[i].MedicalRecordNumber);
        fscanf(file, "%d", &hospitalRecords[i].Day_of_Entry);
        fscanf(file, "%d", &hospitalRecords[i].Month_of_Entry);
        fscanf(file, "%d", &hospitalRecords[i].Year_of_Entry);
        fscanf(file, "%s", hospitalRecords[i].Patient_First_Name);
        fscanf(file, "%s", hospitalRecords[i].Patient_Last_Name);
        fscanf(file, "%s", hospitalRecords[i].Patient_Father_First_Name);
        fscanf(file, "%s", hospitalRecords[i].Patient_Mother_First_Name);
        fscanf(file, "%lld", &hospitalRecords[i].Mobile_number);
        fscanf(file, "%d", &hospitalRecords[i].age);
        fscanf(file, "%s", hospitalRecords[i].BloodGroup);
        fscanf(file, "%s", hospitalRecords[i].Gender);
        fscanf(file, "%s", hospitalRecords[i].Doctor_Name);
        fscanf(file, "%s", hospitalRecords[i].Doctor_Medical_Registration_Number);
        fscanf(file, "%d", &hospitalRecords[i].Day_of_Exit);
        fscanf(file, "%d", &hospitalRecords[i].Month_of_Exit);
        fscanf(file, "%d", &hospitalRecords[i].Year_of_Exit);
    }

    fclose(file);
}

void SaveToFile() {
    FILE *file = fopen("hospital_records.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    fprintf(file, "%d\n", totalRecords);
    for (int i = 0; i < totalRecords; i++) {
        fprintf(file, "%d %d %d %d %s %s %s %s %lld %d %s %s %s %s %d %d %d\n",
                hospitalRecords[i].MedicalRecordNumber,
                hospitalRecords[i].Day_of_Entry, hospitalRecords[i].Month_of_Entry, hospitalRecords[i].Year_of_Entry,
                hospitalRecords[i].Patient_First_Name, hospitalRecords[i].Patient_Last_Name,
                hospitalRecords[i].Patient_Father_First_Name, hospitalRecords[i].Patient_Mother_First_Name,
                hospitalRecords[i].Mobile_number, hospitalRecords[i].age,
                hospitalRecords[i].BloodGroup, hospitalRecords[i].Gender,
                hospitalRecords[i].Doctor_Name, hospitalRecords[i].Doctor_Medical_Registration_Number,
                hospitalRecords[i].Day_of_Exit, hospitalRecords[i].Month_of_Exit, hospitalRecords[i].Year_of_Exit);
    }

    fclose(file);
}


void New_Data() {
    int n;
    printf("\nNumber of Entries: ");
    scanf("%d", &n);

    for (int i = totalRecords; i < totalRecords + n; i++) {
        hospitalRecords[i].MedicalRecordNumber = i + 1;
        printf("\nEnter details of Record %d\n", hospitalRecords[i].MedicalRecordNumber);
        printf("Patient's First Name: ");
        scanf("%s", hospitalRecords[i].Patient_First_Name);
        printf("Patient's Last Name: ");
        scanf("%s", hospitalRecords[i].Patient_Last_Name);
        printf("Father's First Name: ");
        scanf("%s", hospitalRecords[i].Patient_Father_First_Name);
        printf("Mother's First Name: ");
        scanf("%s", hospitalRecords[i].Patient_Mother_First_Name);
        printf("Mobile Number: ");
        scanf("%lld", &hospitalRecords[i].Mobile_number);
        printf("Age: ");
        scanf("%d", &hospitalRecords[i].age);
        printf("Blood Group: ");
        scanf("%s", hospitalRecords[i].BloodGroup);
        printf("Gender: ");
        scanf("%s", hospitalRecords[i].Gender);
        printf("Doctor's Name: ");
        scanf("%s", hospitalRecords[i].Doctor_Name);
        printf("Doctor's Medical Registration Number: ");
        scanf("%s", hospitalRecords[i].Doctor_Medical_Registration_Number);
        printf("Enter Date Of Entry (Day Month Year): ");
        scanf("%d %d %d", &hospitalRecords[i].Day_of_Entry, &hospitalRecords[i].Month_of_Entry, &hospitalRecords[i].Year_of_Entry);
        printf("Enter Date Of Exit (Day Month Year): ");
        scanf("%d %d %d", &hospitalRecords[i].Day_of_Exit, &hospitalRecords[i].Month_of_Exit, &hospitalRecords[i].Year_of_Exit);
        
    }
    totalRecords += n;
}


void Search() {
    int searchChoice;
    printf("What would you like to search by:\n");
    printf("1. Search by name\n");
    printf("2. Search by Medical Record Number\n");
    printf("3. Search by Mobile Number\n");
    printf("Enter the assigned number accordingly: ");
    scanf("%d", &searchChoice);

    switch (searchChoice) {
        case 1: {
            char searchName[35];
            printf("Enter the name to search for: ");
            scanf("%s", searchName);
            
            int a = 0;
            printf("\nRecords matching the search for name '%s':\n", searchName);
            for (int i = 0; i < totalRecords; i++) {
                if (strstr(hospitalRecords[i].Patient_First_Name, searchName) != NULL ||
                    strstr(hospitalRecords[i].Patient_Last_Name, searchName) != NULL) {
                    printf("\nRecord %d:\n", hospitalRecords[i].MedicalRecordNumber);
                    printf("Patient's Name: %s %s\n", hospitalRecords[i].Patient_First_Name, hospitalRecords[i].Patient_Last_Name);
                    printf("Father's Name: %s\n", hospitalRecords[i].Patient_Father_First_Name);
                    printf("Mother's Name: %s\n", hospitalRecords[i].Patient_Mother_First_Name);
                    printf("Mobile Number: %lld\n", hospitalRecords[i].Mobile_number);
                    printf("Age: %d\n", hospitalRecords[i].age);
                    printf("Blood Group: %s\n", hospitalRecords[i].BloodGroup);
                    printf("Gender: %s\n", hospitalRecords[i].Gender);
                    printf("Doctor's Name: %s\n", hospitalRecords[i].Doctor_Name);
                    printf("Doctor's Registration Number: %s\n", hospitalRecords[i].Doctor_Medical_Registration_Number);
                    printf("Date of Entry: %d-%d-%d\n", hospitalRecords[i].Day_of_Entry,
                           hospitalRecords[i].Month_of_Entry, hospitalRecords[i].Year_of_Entry);
                    printf("Date of Exit: %d-%d-%d\n", hospitalRecords[i].Day_of_Exit,
                           hospitalRecords[i].Month_of_Exit, hospitalRecords[i].Year_of_Exit);
                }
                else{
                    a++;
                }

                if(a == totalRecords){
                    printf("There is no record for name of %s", searchName);
                }
            }
            break;
        }
        case 2: {
            int searchMRN;
            printf("Enter the Medical Record Number to search: ");
            scanf("%d", &searchMRN);

            printf("\nRecord matching the search for Medical Record Number '%d':\n", searchMRN);
            for (int i = 0; i < totalRecords; i++) {
                if (hospitalRecords[i].MedicalRecordNumber == searchMRN) {
                    printf("\nRecord %d:\n", hospitalRecords[i].MedicalRecordNumber);
                    printf("Patient's Name: %s %s\n", hospitalRecords[i].Patient_First_Name, hospitalRecords[i].Patient_Last_Name);
                    printf("Father's Name: %s\n", hospitalRecords[i].Patient_Father_First_Name);
                    printf("Mother's Name: %s\n", hospitalRecords[i].Patient_Mother_First_Name);
                    printf("Mobile Number: %lld\n", hospitalRecords[i].Mobile_number);
                    printf("Age: %d\n", hospitalRecords[i].age);
                    printf("Blood Group: %s\n", hospitalRecords[i].BloodGroup);
                    printf("Gender: %s\n", hospitalRecords[i].Gender);
                    printf("Doctor's Name: %s\n", hospitalRecords[i].Doctor_Name);
                    printf("Doctor's Registration Number: %s\n", hospitalRecords[i].Doctor_Medical_Registration_Number);
                    printf("Date of Entry: %d-%d-%d\n", hospitalRecords[i].Day_of_Entry,
                           hospitalRecords[i].Month_of_Entry, hospitalRecords[i].Year_of_Entry);
                    printf("Date of Exit: %d-%d-%d\n", hospitalRecords[i].Day_of_Exit,
                           hospitalRecords[i].Month_of_Exit, hospitalRecords[i].Year_of_Exit);
                    break;
                }
            }
            break;
        }
        case 3: {
            long long int searchMobile;
            printf("Enter the Mobile Number to search: ");
            scanf("%lld", &searchMobile);

            printf("\nRecord matching the search for Mobile Number '%lld':\n", searchMobile);
            for (int i = 0; i < totalRecords; i++) {
                if (hospitalRecords[i].Mobile_number == searchMobile) {
                    printf("\nRecord %d:\n", hospitalRecords[i].MedicalRecordNumber);
                    printf("Patient's Name: %s %s\n", hospitalRecords[i].Patient_First_Name, hospitalRecords[i].Patient_Last_Name);
                    printf("Father's Name: %s\n", hospitalRecords[i].Patient_Father_First_Name);
                    printf("Mother's Name: %s\n", hospitalRecords[i].Patient_Mother_First_Name);
                    printf("Mobile Number: %lld\n", hospitalRecords[i].Mobile_number);
                    printf("Age: %d\n", hospitalRecords[i].age);
                    printf("Blood Group: %s\n", hospitalRecords[i].BloodGroup);
                    printf("Gender: %s\n", hospitalRecords[i].Gender);
                    printf("Doctor's Name: %s\n", hospitalRecords[i].Doctor_Name);
                    printf("Doctor's Registration Number: %s\n", hospitalRecords[i].Doctor_Medical_Registration_Number);
                    printf("Date of Entry: %d-%d-%d\n", hospitalRecords[i].Day_of_Entry,
                           hospitalRecords[i].Month_of_Entry, hospitalRecords[i].Year_of_Entry);
                    printf("Date of Exit: %d-%d-%d\n", hospitalRecords[i].Day_of_Exit,
                           hospitalRecords[i].Month_of_Exit, hospitalRecords[i].Year_of_Exit);
                    break;
                }
            }
            break;
        }
        default:
            printf("Invalid search choice.\n");
            break;
    }
}


void Edit_Data() {
    int recordNumber;
    printf("Enter the Medical Record Number for which you want to EDIT the data: ");
    scanf("%d", &recordNumber);

    int index = -1;
    for (int i = 0; i < totalRecords; i++) {
        if (hospitalRecords[i].MedicalRecordNumber == recordNumber) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("\nEnter new details for Record %d\n", recordNumber);
        printf("Patient's First Name: ");
        scanf("%s", hospitalRecords[index].Patient_First_Name);
        printf("Patient's Last Name: ");
        scanf("%s", hospitalRecords[index].Patient_Last_Name);
        printf("Father's First Name: ");
        scanf("%s", hospitalRecords[index].Patient_Father_First_Name);
        printf("Mother's First Name: ");
        scanf("%s", hospitalRecords[index].Patient_Mother_First_Name);
        printf("Mobile Number: ");
        scanf("%lld", &hospitalRecords[index].Mobile_number);
        printf("Age: ");
        scanf("%d", &hospitalRecords[index].age);
        printf("Blood Group: ");
        scanf("%s", hospitalRecords[index].BloodGroup);
        printf("Gender: ");
        scanf("%s", hospitalRecords[index].Gender);
        printf("Doctor's Name: ");
        scanf("%s", hospitalRecords[index].Doctor_Name);
        printf("Doctor's Medical Registration Number: ");
        scanf("%s", hospitalRecords[index].Doctor_Medical_Registration_Number);
        printf("Enter Date Of Entry (Day Month Year): ");
        scanf("%d %d %d", &hospitalRecords[index].Day_of_Entry, 
               &hospitalRecords[index].Month_of_Entry, &hospitalRecords[index].Year_of_Entry);
        printf("Enter Date Of Exit (Day Month Year): ");
        scanf("%d %d %d", &hospitalRecords[index].Day_of_Exit, 
               &hospitalRecords[index].Month_of_Exit, &hospitalRecords[index].Year_of_Exit);

        printf("Record %d has been updated.\n", recordNumber);
    } else {
        printf("Record not found.\n");
    }
}


void Delete_Data() {
    int recordNumber;
    printf("Enter the Medical Record Number to DELETE the data: ");
    scanf("%d", &recordNumber);

    int index = -1;
    for (int i = 0; i < totalRecords; i++) {
        if (hospitalRecords[i].MedicalRecordNumber == recordNumber) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < totalRecords - 1; i++) {
            hospitalRecords[i] = hospitalRecords[i + 1];
        }
        totalRecords--;
        printf("Record %d has been deleted.\n", recordNumber);
    } else {
        printf("Record not found.\n");
    }
}


void View() {
    printf("\nHospital Records:\n");
    for (int i = 0; i < totalRecords; i++) {
        printf("\nRecord %d:\n", hospitalRecords[i].MedicalRecordNumber);
        printf("Patient's Name: %s %s\n", hospitalRecords[i].Patient_First_Name, hospitalRecords[i].Patient_Last_Name);
        printf("Father's Name: %s\n", hospitalRecords[i].Patient_Father_First_Name);
        printf("Mother's Name: %s\n", hospitalRecords[i].Patient_Mother_First_Name);
        printf("Mobile Number: %lld\n", hospitalRecords[i].Mobile_number);
        printf("Age: %d\n", hospitalRecords[i].age);
        printf("Blood Group: %s\n", hospitalRecords[i].BloodGroup);
        printf("Gender: %s\n", hospitalRecords[i].Gender);
        printf("Doctor's Name: %s\n", hospitalRecords[i].Doctor_Name);
        printf("Doctor's Registration Number: %s\n", hospitalRecords[i].Doctor_Medical_Registration_Number);
        printf("Date of Entry: %d-%d-%d\n", hospitalRecords[i].Day_of_Entry,
               hospitalRecords[i].Month_of_Entry, hospitalRecords[i].Year_of_Entry);
        printf("Date of Exit: %d-%d-%d\n", hospitalRecords[i].Day_of_Exit,
               hospitalRecords[i].Month_of_Exit, hospitalRecords[i].Year_of_Exit);
    }
}


int main() {
    LoadFromFile();

    int choice;
    do {
        printf("\n1. New Data\n");
        printf("2. Search\n");
        printf("3. Edit Data\n");
        printf("4. Delete Data\n");
        printf("5. View Data\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);   

        switch (choice) {
            case 1:
                New_Data();
                break;
            case 2:
                Search();
                break;
            case 3:
                Edit_Data();
                break;
            case 4:
                Delete_Data();
                break;
            case 5:
                View();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    SaveToFile();

    return 0;
}
