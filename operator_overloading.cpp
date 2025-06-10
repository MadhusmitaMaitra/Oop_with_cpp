// Calculator using operator overloading and switch case
#include <iostream>
using namespace std;

// Calculator class definition
class Calculator {
private:
    double value;  // Stores the result or value

public:
    // Constructor with default value
    Calculator(double v = 0) : value(v) {}

    // Overload + operator
    Calculator operator+(const Calculator& obj) {
        return Calculator(value + obj.value);
    }

    // Overload - operator
    Calculator operator-(const Calculator& obj) {
        return Calculator(value - obj.value);
    }

    // Overload * operator
    Calculator operator*(const Calculator& obj) {
        return Calculator(value * obj.value);
    }

    // Overload / operator
    Calculator operator/(const Calculator& obj) {
        if (obj.value == 0) {
            cout << "Error: Division by zero!" << endl;
            return Calculator(0); // Return zero result on division by zero
        }
        return Calculator(value / obj.value);
    }

    // Display the result
    void display() const {
        cout << "Result: " << value << endl;
    }
};

int main() {
    double num1, num2;
    char op;

    // Get user input
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    // Create Calculator objects
    Calculator a(num1), b(num2), result;

    // Perform operation based on the chosen operator
    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        default:
            cout << "Invalid operator!" << endl;
            return 1; // Exit with error
    }

    // Display the result
    result.display();

    return 0;
}
