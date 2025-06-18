// Program to overload >> and << operators using friend functions

#include <iostream>  // For cin, cout, istream, ostream
using namespace std;

class Test {
    int m; // Private data member

public:
    // Declare friend functions to access private members
    friend istream& operator>>(istream& in, Test& t);   // Overload >> operator
    friend ostream& operator<<(ostream& out, const Test& t); // Overload << operator
};

// Definition of overloaded >> operator (input)
istream& operator>>(istream& in, Test& t) {
    cout << "Enter an integer: ";
    in >> t.m;
    return in; // Return the input stream
}

// Definition of overloaded << operator (output)
ostream& operator<<(ostream& out, const Test& t) {
    out << "Value entered: " << t.m << endl;
    return out; // Return the output stream
}

int main() {
    Test t; // Create an object of Test class

    // Use overloaded >> operator to input value
    cin >> t;

    // Use overloaded << operator to display value
    cout << t;

    return 0;
}
