#include <stdio.h>

#define MAX 100
#define CATEGORIES 4

void addExpense(float amount[], int category[], int *count)
{
    if (*count >= MAX) 
    {
        printf("Expense limit reached.\n");
        return;
    }

    printf("Enter expense amount: ");
    scanf("%f", &amount[*count]);

    if (amount[*count] <= 0)
    {
        printf("Invalid amount.\n");
        return;
    }

    printf("Select category:\n");
    printf("1. Food\n");
    printf("2. Travel\n");
    printf("3. Books\n");
    printf("4. Entertainment\n");
    printf("Enter category: ");
    scanf("%d", &category[*count]);

    if (category[*count] < 1 || category[*count] > 4)
    {
        printf("Invalid category.\n");
        return;
    }

    (*count)++;
    printf("Expense added successfully.\n");
}

void displaySummary(float amount[], int category[], int count, float budget)
{
    float categoryTotal[CATEGORIES] = {0};
    float total = 0;
    float remaining;
    int i, highest = 0;

    for (i = 0; i < count; i++)
    {
        total = total + amount[i];
        categoryTotal[category[i] - 1] =
            categoryTotal[category[i] - 1] + amount[i];
    }

    for (i = 1; i < CATEGORIES; i++)  //finds which category has the highest spending
    {
        if (categoryTotal[i] > categoryTotal[highest])
        {
            highest = i;
        }
    }

    remaining = budget - total;

    printf("\n===== Expense Summary =====\n");
    printf("Monthly Budget: %.2f\n", budget);
    printf("Total Spending: %.2f\n", total);
    printf("Remaining Budget: %.2f\n", remaining);

    printf("\n===== Category-wise Totals =====\n");
    printf("Food: %.2f\n", categoryTotal[0]);
    printf("Travel: %.2f\n", categoryTotal[1]);
    printf("Books: %.2f\n", categoryTotal[2]);
    printf("Entertainment: %.2f\n", categoryTotal[3]);

    printf("\nHighest Expenditure Category: ");

    if (highest == 0)
        printf("Food\n");
    else if (highest == 1)
        printf("Travel\n");
    else if (highest == 2)
        printf("Books\n");
    else
        printf("Entertainment\n");

    if (remaining < 0)
        printf("Warning: Budget exceeded by %.2f\n", -remaining);
    else
        printf("Budget Status: Within budget\n");
}

int main()
{
    float amount[MAX];
    int category[MAX];
    int count = 0;
    int choice;
    float budget;

    printf("Enter your monthly budget: ");
    scanf("%f", &budget);

    do
    {
        printf("\n===== Personal Expense Tracker =====\n");
        printf("1. Add Expense\n");
        printf("2. Display Expense Summary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addExpense(amount, category, &count);
        }
        else if (choice == 2)
        {
            displaySummary(amount, category, count, budget);
        }
        else if (choice == 3)
        {
            printf("Thank you for using the tracker.\n");
        }
        else
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}
