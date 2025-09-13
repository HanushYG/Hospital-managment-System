#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PATIENTS 100

struct Patient{
    char name[50];
    int age;
    char illness[50];
};

typedef struct Patient Patient;

Patient patients[MAX_PATIENTS];
int patient_count = 0;

void addPatient() {
    if (patient_count >= MAX_PATIENTS) {
        printf("\nError: Maximum capacity reached.\n");
        return;
    }

    printf("\nEnter Patient Name: ");
    scanf(" %49[^\n]", patients[patient_count].name);
    printf("Enter Patient Age: ");
    scanf("%d", &patients[patient_count].age);
    printf("Enter Illness: ");
    scanf(" %49[^\n]", patients[patient_count].illness);

    patient_count++;
    printf("\nPatient added successfully!\n");
}

void viewPatients() {
    if (patient_count == 0) {
        printf("\nNo patients found.\n");
        return;
    }

    printf("\nList of Patients:\n");
    for (int i = 0; i < patient_count; i++) {
        printf("Name: %s, Age: %d, Illness: %s\n", patients[i].name, patients[i].age, patients[i].illness);
    }
}

void searchPatient() {
    if (patient_count == 0) {
        printf("\nNo patients found.\n");
        return;
    }

    char name[50];
    printf("\nEnter Patient Name to search: ");
    scanf(" %49[^\n]", name);

    for (int i = 0; i < patient_count; i++) {
        if (strcmp(patients[i].name, name) == 0) {
            printf("\nPatient Found:\nName: %s, Age: %d, Illness: %s\n", patients[i].name, patients[i].age, patients[i].illness);
            return;
        }
    }
    printf("\nPatient with name '%s' not found.\n", name);
}

void deletePatient() {
    if (patient_count == 0) {
        printf("\nNo patients found.\n");
        return;
    }

    char name[50];
    printf("\nEnter Patient Name to delete: ");
    scanf(" %49[^\n]", name);

    int indexToDelete = -1;
    for (int i = 0; i < patient_count; i++) {
        if (strcmp(patients[i].name, name) == 0) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        printf("\nPatient with name '%s' not found.\n", name);
        return;
    }

    // Shift all patients after the deleted one to the left
    for (int i = indexToDelete; i < patient_count - 1; i++) {
        patients[i] = patients[i + 1];
    }

    patient_count--;
    printf("\nPatient '%s' deleted successfully!\n", name);
}

int main() {
    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Search Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                deletePatient();
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}