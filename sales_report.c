#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 12

// Function prototypes
void readSalesFromFile(double sales[]);
void printSalesReport(double sales[]);
void printSummary(double sales[]);
void printMovingAverages(double sales[]);
void printSalesDescendingOrder(double sales[]);

int main() {
    double sales[MONTHS];
    readSalesFromFile(sales);
    printf("Monthly sales report for 2022:\n");
    printSalesReport(sales);
    printf("\nSales summary:\n");
    printSummary(sales);
    printf("\nSix-Month Moving Average Report:\n");
    printMovingAverages(sales);
    printf("\nSales Report (Highest to Lowest):\n");
    printSalesDescendingOrder(sales);
    return 0;
}

void readSalesFromFile(double sales[]) {
    FILE *file = fopen("sales.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%lf", &sales[i]);
    }
    fclose(file);
}

void printSalesReport(double sales[]) {
    const char *months[] = {"January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2lf\n", months[i], sales[i]);
    }
}

void printSummary(double sales[]) {
    double min = sales[0], max = sales[0], total = 0;
    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min) min = sales[i];
        if (sales[i] > max) max = sales[i];
        total += sales[i];
    }
    double average = total / MONTHS;
    printf("Minimum sales: $%.2lf (January)\n", min);
    printf("Maximum sales: $%.2lf (December)\n", max);
    printf("Average sales: $%.2lf\n", average);
}

void printMovingAverages(double sales[]) {
    printf("Month Range\tAverage\n");
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        double average = sum / 6;
        printf("%s - %s\t$%.2lf\n", MONTHS[i], MONTHS[i + 5], average);
    }
}

void printSalesDescendingOrder(double sales[]) {
    const char *months[] = {"January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};
    printf("Month\tSales\n");
    double sortedSales[MONTHS];
    memcpy(sortedSales, sales, sizeof(double) * MONTHS);
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (sortedSales[i] < sortedSales[j]) {
                double temp = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = temp;
                const char *tempMonth = months[i];
                months[i] = months[j];
                months[j] = tempMonth;
            }
        }
    }
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2lf\n", months[i], sortedSales[i]);
    }
}
