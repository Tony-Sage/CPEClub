#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 5

struct sinfo {
    char fname[50];
    char lname[50];  // Note: PDF has "Iname" but should be "lname" (last name)
    int roll;
    float cgpa;
    int cid[MAX_COURSES];
};

struct sinfo students[MAX_STUDENTS];
int student_count = 0;

// Function prototypes
void add_student();
void bulk_import();
void download_all();
void find_by_roll();
void find_by_firstname();
void delete_by_roll();
void display_menu();
void save_changes();

int main() {
    int choice;
    
    printf("=== Student Information Management System ===\n");
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline
        
        switch(choice) {
            case 1:
                add_student();
                break;
            case 2:
                bulk_import();
                break;
            case 3:
                download_all();
                break;
            case 4:
                find_by_roll();
                break;
            case 5:
                find_by_firstname();
                break;
            case 6:
                delete_by_roll();
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 7);
    
    return 0;
}

void display_menu() {
    printf("\n===== MENU =====\n");
    printf("1. Add Student Details (Manual Input)\n");
    printf("2. Bulk Import Students (Read from .txt)\n");
    printf("3. Download All Students (Write to .txt)\n");
    printf("4. Find Student by Roll Number\n");
    printf("5. Find Student by First Name\n");
    printf("6. Delete Student by Roll Number\n");
    printf("7. Exit\n");
}

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Database full! Cannot add more students.\n");
        return;
    }
    
    struct sinfo new_student;
    
    printf("\n--- Add New Student ---\n");
    printf("Enter First Name: ");
    fgets(new_student.fname, sizeof(new_student.fname), stdin);
    new_student.fname[strcspn(new_student.fname, "\n")] = 0; // Remove newline
    
    printf("Enter Last Name: ");
    fgets(new_student.lname, sizeof(new_student.lname), stdin);
    new_student.lname[strcspn(new_student.lname, "\n")] = 0;
    
    printf("Enter Roll Number: ");
    scanf("%d", &new_student.roll);
    
    printf("Enter CGPA: ");
    scanf("%f", &new_student.cgpa);
    
    printf("Enter 5 Course IDs:\n");
    for(int i = 0; i < MAX_COURSES; i++) {
        printf("Course %d: ", i+1);
        scanf("%d", &new_student.cid[i]);
    }
    getchar(); // Clear newline
    
    students[student_count] = new_student;
    student_count++;
    
    printf("Student added successfully!\n");
}

void bulk_import() {
    FILE *file = fopen("students.txt", "r");
    
    if (file == NULL) {
        printf("Error: Cannot open students.txt file!\n");
        printf("Make sure the file exists in the current directory.\n");
        return;
    }
    
    int imported = 0;
    
    while (student_count < MAX_STUDENTS && 
           fscanf(file, "%s %s %d %f %d %d %d %d %d",
                  students[student_count].fname,
                  students[student_count].lname,
                  &students[student_count].roll,
                  &students[student_count].cgpa,
                  &students[student_count].cid[0],
                  &students[student_count].cid[1],
                  &students[student_count].cid[2],
                  &students[student_count].cid[3],
                  &students[student_count].cid[4]) == 9) {
        imported++;
        student_count++;
    }
    
    fclose(file);
    
    if (imported > 0) {
        printf("Successfully imported %d students from students.txt\n", imported);
    } else {
        printf("No records imported. File might be empty or has invalid format.\n");
    }
}

void download_all() {
    if (student_count == 0) {
        printf("No student records to download!\n");
        return;
    }
    
    FILE *file = fopen("database_backup.txt", "w");
    
    if (file == NULL) {
        printf("Error: Cannot create database_backup.txt file!\n");
        return;
    }
    
    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%s %s %d %.2f %d %d %d %d %d\n",
                students[i].fname,
                students[i].lname,
                students[i].roll,
                students[i].cgpa,
                students[i].cid[0],
                students[i].cid[1],
                students[i].cid[2],
                students[i].cid[3],
                students[i].cid[4]);
    }
    
    fclose(file);
    printf("Successfully exported %d students to database_backup.txt\n", student_count);
}

void find_by_roll() {
    int roll, found = 0;
    
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll == roll) {
            printf("\n--- Student Found ---\n");
            printf("First Name: %s\n", students[i].fname);
            printf("Last Name: %s\n", students[i].lname);
            printf("Roll Number: %d\n", students[i].roll);
            printf("CGPA: %.2f\n", students[i].cgpa);
            printf("Course IDs: ");
            for (int j = 0; j < MAX_COURSES; j++) {
                printf("%d ", students[i].cid[j]);
            }
            printf("\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No student found with Roll Number %d\n", roll);
    }
}

void find_by_firstname() {
    char fname[50];
    int found = 0;
    
    printf("Enter First Name to search: ");
    scanf("%s", fname);
    
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].fname, fname) == 0) {
            printf("Name: %s %s | Roll: %d | CGPA: %.2f | Courses: %d %d %d %d %d\n",
                   students[i].fname, students[i].lname, students[i].roll,
                   students[i].cgpa, students[i].cid[0], students[i].cid[1],
                   students[i].cid[2], students[i].cid[3], students[i].cid[4]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No student found with First Name '%s'\n", fname);
    }
}

void delete_by_roll() {
    int roll, found = 0;
    
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll == roll) {
            // Shift all remaining students left
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            found = 1;
            printf("Student with Roll Number %d deleted successfully!\n", roll);
            break;
        }
    }
    
    if (!found) {
        printf("No student found with Roll Number %d\n", roll);
    }
}