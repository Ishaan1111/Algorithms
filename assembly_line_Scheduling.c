#include <stdio.h>
#include <limits.h>
#define NUM_STATIONS 4
// Utility function to find the minimum of two numbers
int min(int a, int b)
{
    return a < b ? a : b;
}
// Function to find the minimum time to complete the car assembly
int carAssembly(int a[][NUM_STATIONS], int t[][NUM_STATIONS], int *e, int *x)
{
    int T1[NUM_STATIONS]; // Time taken to reach line 1 station i
    int T2[NUM_STATIONS]; // Time taken to reach line 2 station i
    int i;
    // Time taken to reach the first station of line 1 and line 2
    T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];
    // Calculate the time taken to reach each station in line 1 and line 2
    for (i = 1; i < NUM_STATIONS; ++i)
    {
        T1[i] = min(T1[i - 1] + a[0][i], T2[i - 1] + t[1][i] + a[0][i]);
        T2[i] = min(T2[i - 1] + a[1][i], T1[i - 1] + t[0][i] + a[1][i]);
    }
    // Return the minimum time to complete the car assembly
    return min(T1[NUM_STATIONS - 1] + x[0], T2[NUM_STATIONS - 1] + x[1]);
}
int main()
{
    int a[2][NUM_STATIONS] = {{4,5, 3, 2}, {2, 10, 1, 4}}; // Time taken at each station
    int t[2][NUM_STATIONS] = {{0,7, 4, 5}, {0, 9, 2, 8}}; // Time taken to switch lines
    int e[2] = {10, 12}; // Entry time for each line
    int x[2] = {18, 7}; // Exit time for each line
    printf("Minimum time to complete the car assembly: %d", carAssembly(a, t, e, x)); 
    return 0;
}