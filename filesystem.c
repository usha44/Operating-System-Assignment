#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char user[20], pass[20];
    int choice;
    FILE *fp;
    char text[100], ch;

    // User Authentication
    printf("Username: ");
    scanf("%19s", user);

    printf("Password: ");
    scanf("%19s", pass);

    if (strcmp(user, "admin") != 0 || strcmp(pass, "1234") != 0) {
        printf("Access Denied!\n");
        return 0;
    }

    printf("\nLogin Successful!\n");

    do {
        printf("\n===== Secure File Management =====\n");
        printf("1. Create Files\n");
        printf("2. Write to notes.txt\n");
        printf("3. Read notes.txt\n");
        printf("4. Read report.txt\n");
        printf("5. Show File Permissions\n");
        printf("6. Delete Files\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            // Read & Write File
            fp = fopen("notes.txt", "w");
            fprintf(fp, "Notes File (Read & Write)\n");
            fclose(fp);
            chmod("notes.txt", 0644);

            // Read Only File
            fp = fopen("report.txt", "w");
            fprintf(fp, "Report File (Read Only)\n");
            fclose(fp);
            chmod("report.txt", 0444);

            printf("\nFiles Created Successfully.\n");
            break;

        case 2:
            getchar();

            printf("Enter text: ");
            fgets(text, sizeof(text), stdin);

            fp = fopen("notes.txt", "a");

            if (fp == NULL) {
                printf("Create files first!\n");
                break;
            }

            fprintf(fp, "%s", text);
            fclose(fp);

            printf("Data written to notes.txt\n");
            break;

        case 3:
            fp = fopen("notes.txt", "r");

            if (fp == NULL) {
                printf("notes.txt not found!\n");
                break;
            }

            printf("\n----- notes.txt -----\n");

            while((ch=fgetc(fp))!=EOF)
                putchar(ch);

            fclose(fp);
            break;

        case 4:
            fp = fopen("report.txt", "r");

            if (fp == NULL) {
                printf("report.txt not found!\n");
                break;
            }

            printf("\n----- report.txt -----\n");

            while((ch=fgetc(fp))!=EOF)
                putchar(ch);

            fclose(fp);
            break;

        case 5:
            printf("\nFile Permissions\n");
            printf("------------------------------\n");
            printf("notes.txt  : 0644 (Owner: Read/Write, Group: Read, Others: Read)\n");
            printf("report.txt : 0444 (Owner: Read, Group: Read, Others: Read)\n");
            printf("\nreport.txt cannot be modified because it is Read Only.\n");
            break;

        case 6:
            remove("notes.txt");
            remove("report.txt");
            printf("Files Deleted Successfully.\n");
            break;

        case 7:
            printf("Program Closed.\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while(choice != 7);

    return 0;
}
