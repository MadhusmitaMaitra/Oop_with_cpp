// Q. Create a generic class to dynamically allocate an array 
// and check whether a particular element is present in the array or not.

#include <iostream>
#include <string>
using namespace std;

// Template class to handle a generic array
template <class T>
class Arr {
    T* a;   // Pointer to dynamically allocated array
    int n;  // Size of the array

public:
    Arr(int);         // Constructor: allocates memory
    ~Arr();           // Destructor: frees memory
    void in();        // Function to take array input
    bool has(T val);  // Function to search for an element
};

// Constructor
template <class T>
Arr<T>::Arr(int s) {
    n = s;
    a = new T[n];
}

// Destructor
template <class T>
Arr<T>::~Arr() {
    delete[] a;
}

// Function to input elements
template <class T>
void Arr<T>::in() {
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

// Function to search for an element
template <class T>
bool Arr<T>::has(T val) {
    for (int i = 0; i < n; i++) {
        if (a[i] == val)
            return true;
    }
    return false;
}

// Main function to test with int and string arrays
int main() {
    // Integer array example
    int n;
    cout << "Enter number of integers: ";
    cin >> n;

    Arr<int> intArr(n);
    cout << "Enter " << n << " integer values:\n";
    intArr.in();

    int x;
    cout << "Enter an integer to search: ";
    cin >> x;

    cout << (intArr.has(x) ? "Yes" : "No") << endl;

    // String array example
    cout << "\nEnter number of strings: ";
    cin >> n;
    cin.ignore(); // Clear newline from buffer before string input

    Arr<string> strArr(n);
    cout << "Enter " << n << " strings:\n";
    strArr.in();

    string key;
    cout << "Enter a string to search: ";
    getline(cin, key);

    cout << (strArr.has(key) ? "Yes" : "No") << endl;

    return 0;
}
