#include <stdio.h>

#define MAX 100

// Structure for package
struct Package
{
    int id;
    float value;
    float weight;
    float ratio;
};

// Function to calculate Value/Weight ratio
void calculateRatio(struct Package p[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        p[i].ratio = p[i].value / p[i].weight;
    }
}

// Function to sort packages by decreasing ratio
void sortPackages(struct Package p[], int n)
{
    int i, j;
    struct Package temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].ratio < p[j + 1].ratio)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// Function to display packages
void displayPackages(struct Package p[], int n)
{
    int i;

    printf("\n------------------------------------------------\n");
    printf("ID\tValue\tWeight\tValue/Weight\n");
    printf("------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               p[i].id, p[i].value, p[i].weight, p[i].ratio);
    }

    printf("------------------------------------------------\n");
}

// Function to solve Fractional Knapsack
void fractionalKnapsack(struct Package p[], int n, float capacity)
{
    int i;
    float remaining = capacity;
    float totalValue = 0;
    float fraction;

    printf("\nSelection Details:\n");
    printf("---------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        if (remaining == 0)
            break;

        // Complete package can fit
        if (p[i].weight <= remaining)
        {
            remaining = remaining - p[i].weight;
            totalValue = totalValue + p[i].value;

            printf("Package %d: 100%% selected, Value = %.2f\n",
                   p[i].id, p[i].value);
        }
        else
        {
            // Fractional package selection
            fraction = remaining / p[i].weight;
            totalValue = totalValue + (p[i].value * fraction);

            printf("Package %d: %.2f%% selected, Value = %.2f\n",
                   p[i].id,
                   fraction * 100,
                   p[i].value * fraction);

            remaining = 0;
        }
    }

    printf("---------------------------------------------\n");
    printf("Remaining Capacity = %.2f\n", remaining);
    printf("Maximum Value = %.2f\n", totalValue);
}

int main()
{
    struct Package p[MAX];
    int n, i, choice;
    float capacity;

    printf("=============================================\n");
    printf("       FRACTIONAL KNAPSACK PROBLEM\n");
    printf("=============================================\n");

    printf("\nEnter number of packages: ");
    scanf("%d", &n);

    printf("Enter vehicle capacity: ");
    scanf("%f", &capacity);

    // Input package details
    for (i = 0; i < n; i++)
    {
        p[i].id = i + 1;

        printf("\nEnter details for Package %d\n", i + 1);

        printf("Value  : ");
        scanf("%f", &p[i].value);

        printf("Weight : ");
        scanf("%f", &p[i].weight);
    }

    do
    {
        printf("\n\n========== MENU ==========\n");
        printf("1. Calculate Value/Weight Ratio\n");
        printf("2. Sort Packages by Ratio\n");
        printf("3. Display Packages\n");
        printf("4. Find Maximum Value\n");
        printf("5. Exit\n");
        printf("===========================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                calculateRatio(p, n);
                printf("\nValue/Weight ratio calculated successfully.\n");
                break;

            case 2:
                calculateRatio(p, n);
                sortPackages(p, n);
                printf("\nPackages sorted by decreasing Value/Weight ratio.\n");
                break;

            case 3:
                calculateRatio(p, n);
                displayPackages(p, n);
                break;

            case 4:
                calculateRatio(p, n);
                sortPackages(p, n);

                printf("\nPackages after sorting:\n");
                displayPackages(p, n);

                fractionalKnapsack(p, n, capacity);
                break;

            case 5:
                printf("\nProgram terminated.\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
