#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.
struct TempatureRecord {
    int day;
    int tempature;
};


// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TempatureRecord temps[], int &size); // TODO: Fix the parameters
void printTemperatures(const TempatureRecord temps[], int size);
TemperatureRecord findMin(const TempatureRecord temps[], int size);
TemperatureRecord findMax(const TempatureRecord temps[], int size);
double findAverage(const TempatureRecord temps[], int size);

int main() {
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TempatureRecord temps[MAX_DAYS];
    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file

    // TODO: Step 4 - Print the temperatures

    // TODO: Step 5 - Compute and display min, max, and average temperature

    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void printTempatures(const TempatureRecord temps[], int& size) {
    ifstream inFile("temps.txt");
    if (!inFile) {
        cout << "Error, Could not open file." << endl;
    }
    size = 0;
    while (inFile >> temps[size].day >> temps[size].tempature) {
        size++;
        if (size >= 31) break;
    }
    inFile.close();
}
// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTempatures(const TempatureRecord temps[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << setw(2) << temps[i].day << setw(6) << temps[i].tempature << endl;
    }
}
// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature

// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature

// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
