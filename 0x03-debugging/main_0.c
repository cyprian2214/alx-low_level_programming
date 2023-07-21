#include <stdio.h>

/* Function prototypes */
int convert_day(int month, int day);
void print_remaining_days(int month, int day, int year);

int main()
{
    int month, day, year;

    printf("Enter date (mm dd yyyy): ");
    scanf("%d %d %d", &month, &day, &year);

    /* Call the function to convert day of the month to day of the year */
    day = convert_day(month, day);

    /* Call the function to print remaining days in the year */
    print_remaining_days(month, day, year);

    return 0;
}

int convert_day(int month, int day)
{
    /* Your implementation of the convert_day function goes here */
    /* Make sure to handle leap years correctly */
    /* This function should return the day of the year */
}

void print_remaining_days(int month, int day, int year)
{
    /* Your implementation of the print_remaining_days function goes here */
    /* Make sure to handle leap years correctly */
    /* This function should print the day of the year and the number of remaining days */
}
