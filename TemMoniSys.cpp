#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Constants for the program
const int days_in_month = 30;
const int min_day_temp = 70;
const int max_day_temp = 80;
const int min_night_temp = 60;
const int max_night_temp = 62;
const int min_fluctuation = 10;
const int max_fluctuation = 15;

// Function Prototypes
void storeTemperatures(float x[], float y[]);
void calculateFluctuations(const float x[], const float y[], float fluctuations[]);
void displayDailyFluctuations(const float fluctuations[]);
void calculateAverageTemps(const float x[], const float y[]);
void findMaxMinTemps(const float x[], const float y[]);
float celsiusToFahrenheit(float c);
float fahrenheitToCelsius(float f);
void analyzeTemperatureSuitability(const float x[], const float y[], const float fluctuations[]);

int main() {
    float x[days_in_month], y[days_in_month], fluctuations[days_in_month];
    int choice;
   
    do {
        cout << "\n--- Orchid Temperature Monitoring System ---\n";
        cout << "1. Store Temperatures (Daytime & Nighttime)\n";
        cout << "2. Calculate Daily Fluctuation\n";
        cout << "3. Calculate Average Daytime & Nighttime Temperatures\n";
        cout << "4. Find Max/Min Temperatures\n";
        cout << "5. Convert Temperature (Centigrade to Fahrenheit)\n";
        cout << "6. Analyze Temperature Suitability\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
       
        switch (choice) {
            case 1:
                storeTemperatures(x, y);
                break;
            case 2:
                calculateFluctuations(x, y, fluctuations);
                displayDailyFluctuations(fluctuations);
                break;
            case 3:
                calculateAverageTemps(x, y);
                break;
            case 4:
                findMaxMinTemps(x, y);
                break;
            case 5:
                float c, f;
                cout << "Enter temperature in Celsius: ";
                cin >> c;
                f = celsiusToFahrenheit(c);
                cout << fixed << setprecision(2) << "Temperature in Fahrenheit: " << f << " °F\n";
                break;
            case 6:
                calculateFluctuations(x, y, fluctuations);
                analyzeTemperatureSuitability(x, y, fluctuations);
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please choose again.\n";
                break;
        }
    } while (choice != 7);
   
    return 0;
}

// Store daily temperatures for the month
void storeTemperatures(float x[], float y[]) {
    for (int i = 0; i < days_in_month; i++) {
        cout << "Enter daytime temperature for day " << i+1 << ": ";
        cin >> x[i];
        cout << "Enter nighttime temperature for day " << i+1 << ": ";
        cin >> y[i];
    }
    cout << "Temperatures stored successfully!\n";
}

// Calculate daily temperature fluctuations
void calculateFluctuations(const float x[], const float y[], float fluctuations[]) {
    for (int i = 0; i < days_in_month; i++) {
        fluctuations[i] = x[i] - y[i];
    }
    cout << "Daily fluctuations calculated successfully!\n";
}

// Display daily temperature fluctuations
void displayDailyFluctuations(const float fluctuations[]) {
    for (int i = 0; i < days_in_month; i++) {
        cout << "Day " << i+1 << ": " << fluctuations[i] << " °F\n";
    }
}

// Calculate average daytime and nighttime temperatures for the month
void calculateAverageTemps(const float x[], const float y[]) {
    float totalDayTemp = 0, totalNightTemp = 0;
   
    for (int i = 0; i < days_in_month; i++) {
        totalDayTemp += x[i];
        totalNightTemp += y[i];
    }
   
    cout << fixed << setprecision(2);
    cout << "Average Daytime Temperature: " << totalDayTemp / days_in_month << " °F\n";
    cout << "Average Nighttime Temperature: " << totalNightTemp / days_in_month << " °F\n";
}

// Find maximum and minimum temperatures of the month
void findMaxMinTemps(const float x[], const float y[]) {
    float maxDay = x[0], minDay = x[0];
    float maxNight = y[0], minNight = y[0];
   
    for (int i = 1; i < days_in_month; i++) {
        if (x[i] > maxDay) maxDay = x[i];
        if (x[i] < minDay) minDay = x[i];
        if (y[i] > maxNight) maxNight = y[i];
        if (y[i] < minNight) minNight = y[i];
    }
   
    cout << fixed << setprecision(2);
    cout << "Max Daytime Temp: " << maxDay << " °F, Min Daytime Temp: " << minDay << " °F\n";
    cout << "Max Nighttime Temp: " << maxNight << " °F, Min Nighttime Temp: " << minNight << " °F\n";
}

// Convert Celsius to Fahrenheit
float celsiusToFahrenheit(float c) {
    return (c * 9/5) + 32;
}

// Analyze if the temperature is suitable for orchids
void analyzeTemperatureSuitability(const float x[], const float y[], const float fluctuations[]) {
    bool suitable = true;
    for (int i = 0; i < days_in_month; i++) {
        if (x[i] < min_day_temp || x[i] > max_day_temp ||
            y[i] < min_night_temp || y[i] > max_night_temp ||
            fluctuations[i] < min_fluctuation || fluctuations[i] > max_fluctuation) {
            suitable = false;
            break;
        }
    }
   
    if (suitable)
        cout << "The temperature conditions are suitable for orchid growth.\n";
    else
        cout << "The temperature conditions are not suitable for orchid growth.\n";
}

