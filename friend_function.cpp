// Compare two temperatures using friend function and conversion logic
#include <iostream>
using namespace std;

// Forward declaration
class C2;

// Temperature converter utility class
class Converter {
public:
    static float fahrenheitToCelsius(float f) {
        return (f - 32) * 5.0 / 9.0;
    }

    static float celsiusToFahrenheit(float c) {
        return (c * 9.0 / 5.0) + 32;
    }
};

// Celsius temperature class
class C1 {
    float temp; // in Celsius

public:
    C1(float t) {
        temp = t;
    }

    ~C1() {} // No dynamic allocation, so destructor is simple

    float getTemp() const {
        return temp;
    }

    friend float compare(const C1&, const C2&, char);
};

// Fahrenheit temperature class
class C2 {
    float temp; // in Fahrenheit

public:
    C2(float t) {
        temp = t;
    }

    ~C2() {}

    float getTemp() const {
        return temp;
    }

    friend float compare(const C1&, const C2&, char);
};

// Friend function to compare and return larger temperature
// 'o' = output format: 'c' = Celsius, 'f' = Fahrenheit
float compare(const C1& c1, const C2& c2, char outputFormat) {
    float tempC = c1.temp;
    float tempF = c2.temp;

    float c2inC = Converter::fahrenheitToCelsius(tempF);
    float c1inF = Converter::celsiusToFahrenheit(tempC);

    if (outputFormat == 'c') {
        cout << "Celsius Temp: " << tempC << "°C\n";
        cout << "Fahrenheit Temp (converted to °C): " << c2inC << "°C\n";
        return (tempC > c2inC) ? tempC : c2inC;
    } else {
        cout << "Fahrenheit Temp: " << tempF << "°F\n";
        cout << "Celsius Temp (converted to °F): " << c1inF << "°F\n";
        return (tempF > c1inF) ? tempF : c1inF;
    }
}

int main() {
    float celsius, fahrenheit;
    char outputChoice;

    // Input with validation
    cout << "Enter temperature in Celsius: ";
    while (!(cin >> celsius)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a valid number for Celsius: ";
    }

    cout << "Enter temperature in Fahrenheit: ";
    while (!(cin >> fahrenheit)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a valid number for Fahrenheit: ";
    }

    cout << "Choose output unit: 'c' for Celsius, 'f' for Fahrenheit: ";
    cin >> outputChoice;
    while (outputChoice != 'c' && outputChoice != 'f') {
        cout << "Invalid choice. Enter 'c' or 'f': ";
        cin >> outputChoice;
    }

    // Object creation
    C1 tempC(celsius);
    C2 tempF(fahrenheit);

    // Compare and display result
    float result = compare(tempC, tempF, outputChoice);

    if (outputChoice == 'c') {
        cout << "Larger temperature is: " << result << "°C" << endl;
    } else {
        cout << "Larger temperature is: " << result << "°F" << endl;
    }

    return 0;
}
