#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

struct Patient {
    char name[50];
    int age;
    char illness[50];
};

typedef struct Patient Patient;

Patient patients[MAX_PATIENTS];
int patient_count = 0;

void addPatient() {
    if (patient_count >= MAX_PATIENTS) {
        printf(RED "\nError: Maximum capacity reached.\n" RESET);
        return;
    }

    printf(CYAN "\nEnter Patient Name: " RESET);
    scanf(" %49[^\n]", patients[patient_count].name);
    printf(CYAN "Enter Patient Age: " RESET);
    scanf("%d", &patients[patient_count].age);
    printf(CYAN "Enter Illness: " RESET);
    scanf(" %49[^\n]", patients[patient_count].illness);

    patient_count++;
    printf(GREEN "\nPatient added successfully!\n" RESET);
}

void viewPatients() {
    if (patient_count == 0) {
        printf(RED "\nNo patients found.\n" RESET);
        return;
    }

    printf(GREEN "\nList of Patients:\n" RESET);
    for (int i = 0; i < patient_count; i++) {
        printf(CYAN "Name: %s, Age: %d, Illness: %s\n" RESET,
               patients[i].name, patients[i].age, patients[i].illness);
    }
}

void searchPatient() {
    if (patient_count == 0) {
        printf(RED "\nNo patients found.\n" RESET);
        return;
    }

    char name[50];
    printf(CYAN "\nEnter Patient Name to search: " RESET);
    scanf(" %49[^\n]", name);

    for (int i = 0; i < patient_count; i++) {
        if (strcmp(patients[i].name, name) == 0) {
            printf(GREEN "\nPatient Found:\n" RESET);
            printf(CYAN "Name: %s, Age: %d, Illness: %s\n" RESET,
                   patients[i].name, patients[i].age, patients[i].illness);
            return;
        }
    }
    printf(RED "\nPatient with name '%s' not found.\n" RESET, name);
}

void deletePatient() {
    if (patient_count == 0) {
        printf(RED "\nNo patients found.\n" RESET);
        return;
    }

    char name[50];
    printf(CYAN "\nEnter Patient Name to delete: " RESET);
    scanf(" %49[^\n]", name);

    int indexToDelete = -1;
    for (int i = 0; i < patient_count; i++) {
        if (strcmp(patients[i].name, name) == 0) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        printf(RED "\nPatient with name '%s' not found.\n" RESET, name);
        return;
    }

    for (int i = indexToDelete; i < patient_count - 1; i++) {
        patients[i] = patients[i + 1];
    }

    patient_count--;
    printf(GREEN "\nPatient '%s' deleted successfully!\n" RESET, name);
}

int main() {
    while (1) {
        printf(GREEN "\n=====================================\n" RESET);
        printf(CYAN "        Hospital Management System\n" RESET);
        printf(GREEN "=====================================\n" RESET);
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Search Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Exit\n");
        printf(CYAN "Enter your choice: " RESET);

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
                printf(GREEN "\nGoodbye!\n" RESET);
                exit(0);
            default:
                printf(RED "\nInvalid choice. Please try again.\n" RESET);
        }

        printf(CYAN "\nPress Enter to continue..." RESET);
        getchar();
        getchar();
    }

    return 0;
}