#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.
struct TemperatureRecord {
    int day;
    int temperature;
};


// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord temps[], int &size); // TODO: Fix the parameters
void printTemperatures(const TemperatureRecord temps[], int size);
TemperatureRecord findMin(const TemperatureRecord temps[], int size);
TemperatureRecord findMax(const TemperatureRecord temps[], int size);
double findAverage(const TemperatureRecord temps[], int size);

int main() {
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TemperatureRecord temps[MAX_DAYS];
    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file
    readTemperatures(temps, size);
    // TODO: Step 4 - Print the temperatures
    printTemperatures(temps, size);
    // TODO: Step 5 - Compute and display min, max, and average temperature

    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void readTemperatures(const TemperatureRecord temps[], int& size) {
    ifstream inFile("temps.txt");
    if (!inFile) {
        cout << "Error, Could not open file." << endl;
    }
    size = 0;
    while (inFile >> temps[size].day >> temps[size].temperature) {
        size++;
        if (size >= 31) break;
    }
    inFile.close();
}
// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTemperatures(const TemperatureRecord temps[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << setw(2) << temps[i].day << setw(6) << temps[i].temperature << endl;
    }
}
// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature
TemperatureRecord findMin(const TemperatureRecord temps[], int size) {
    TemperatureRecord min = { 0,0 };
    if (size == 0) return min;

    min = temps[0];

    for (int i = 1; i < size; ++i) {
        if (temps[i].temperature < min.temperature) {
            min = temps[i];
        }
    }
}
// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature
TemperatureRecord findMax(const TemperatureRecord temps[], int size) {
    TemperatureRecord max = { 0, 0 };
    if (size == 0) return max;
    max = temps[0];

    for (int i = 1; i < size; i++) {
        if (temps[i].temperature > max.temperature) {
            max = temps[i];
        }
    }
    return max;
}
// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
double findAverage(const TemperatureRecord temps[], int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += temps[i].temperature;
    }
    return static_cast<double>(total) / size;
}