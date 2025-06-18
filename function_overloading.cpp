// Area Calculator using Function Overloading
#include <iostream>
using namespace std;

// Function to calculate area of a circle
float area(float radius) {
    return 3.14f * radius * radius;
}

// Function to calculate area of a rectangle
float area(float length, float breadth) {
    return length * breadth;
}

// Function to calculate area of a square
int area(int side) {
    return side * side;
}

int main() {
    char choice;
    cout << "Choose the shape to calculate area:\n";
    cout << "c - Circle\nr - Rectangle\ns - Square\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 'c': {
            float r;
            cout << "Enter the radius of the circle: ";
            cin >> r;
            cout << "Area of the circle is: " << area(r) << endl;
            break;
        }

        case 'r': {
            float l, b;
            cout << "Enter the length and breadth of the rectangle:\n";
            cout << "Length: ";
            cin >> l;
            cout << "Breadth: ";
            cin >> b;
            cout << "Area of the rectangle is: " << area(l, b) << endl;
            break;
        }

        case 's': {
            int s;
            cout << "Enter the side of the square: ";
            cin >> s;
            cout << "Area of the square is: " << area(s) << endl;
            break;
        }

        default:
            cout << "Invalid choice! Please enter 'c', 'r', or 's'." << endl;
    }

    return 0;
}
