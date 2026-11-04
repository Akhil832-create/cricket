
#include <stdio.h>
#include <string.h>

#define MAX 50

int main()
{
    char name[MAX][30];
    char key[30];

    int runs[MAX], balls[MAX];
    int count = 0;
    int choice, i, found;
    float sr;

    while (1)
    {
        printf("\n===== CRICKET PLAYER STATS TRACKER =====\n");
        printf("1. Add Player\n");
        printf("2. View All Players\n");
        printf("3. Search Player by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");

            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
            case 1:
                if (count >= MAX)
                {
                    printf("Storage is full! Cannot add more players.\n");
                    break;
                }

                printf("Enter player name: ");
                scanf(" %29[^\n]", name[count]);

                printf("Enter runs scored: ");
                scanf("%d", &runs[count]);

                printf("Enter balls faced: ");
                scanf("%d", &balls[count]);

                if (runs[count] < 0 || balls[count] < 0)
                {
                    printf("Runs and balls cannot be negative!\n");
                    break;
                }

                count++;

                printf("Player added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("No players added yet!\n");
                    break;
                }

                printf("\n---------------------------------------------------------------\n");
                printf("%-6s %-25s %-10s %-10s %-12s\n",
                       "S.No.", "Name", "Runs", "Balls", "Strike Rate");
                printf("---------------------------------------------------------------\n");

                for (i = 0; i < count; i++)
                {
                    if (balls[i] != 0)
                        sr = (runs[i] * 100.0) / balls[i];
                    else
                        sr = 0.0;

                    printf("%-6d %-25s %-10d %-10d %-12.2f\n",
                           i + 1, name[i], runs[i], balls[i], sr);
                }

                printf("---------------------------------------------------------------\n");
                break;

            case 3:
                if (count == 0)
                {
                    printf("No players added yet!\n");
                    break;
                }

                printf("Enter player name to search: ");
                scanf(" %29[^\n]", key);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (strcmp(name[i], key) == 0)
                    {
                        if (balls[i] != 0)
                            sr = (runs[i] * 100.0) / balls[i];
                        else
                            sr = 0.0;

                        printf("\n----- PLAYER DETAILS -----\n");
                        printf("S.No.        : %d\n", i + 1);
                        printf("Name         : %s\n", name[i]);
                        printf("Runs         : %d\n", runs[i]);
                        printf("Balls        : %d\n", balls[i]);
                        printf("Strike Rate  : %.2f\n", sr);

                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Player not found!\n");

                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please enter between 1 and 4.\n");
        }
    }

    return 0;
}
