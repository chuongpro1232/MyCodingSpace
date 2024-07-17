#include <stdio.h>
#define ARRSIZE 4

// Define time data-type
typedef struct
{
    int hour;
    int min;
    int sec;
} time;

// Function to convert to total hours of a given time
float total_hours(time t)
{
    return t.hour + (float)t.min / 60 + (float)t.sec / 3600;
}

int main()
{

    // Qa. Time difference
    time t1, t2;
    printf("Enter the first time point: ");
    scanf("%d:%d:%d", &t1.hour, &t1.min, &t1.sec); // e.g. 17:08:40

    printf("Enter the second time point: ");
    scanf("%d:%d:%d", &t2.hour, &t2.min, &t2.sec);

    float dif = total_hours(t1) - total_hours(t2);
    printf("Time difference: %.2f hours\n", dif);

    // Qb. Array of time points
    time arr[ARRSIZE];

    // Input all values
    for (int i = 0; i < ARRSIZE; i++)
    {
        printf("Enter the time point %d: ", i);
        scanf("%d:%d:%d", &arr[i].hour, &arr[i].min, &arr[i].sec);
    }

    // Find latest time
    time latest = arr[0]; // assume the first one is latest
    for (int i = 1; i < ARRSIZE; i++)
    { // compare with others
        if (total_hours(arr[i]) > total_hours(latest))
        {
            latest = arr[i];
        }
    }

    printf("Latest time is %2d:%2d:%2d \n",
           latest.hour, latest.min, latest.sec);

    return 0;
}