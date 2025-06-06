#include <iostream>
using namespace std;

// Class to store personal details of a student
class PersonalInfo {
    string name;
    int roll;

protected:
    void show();  // Display personal info

public:
    PersonalInfo(string, int);  // Parameterized constructor
    ~PersonalInfo();            // Destructor
};

// Class to store academic marks
class AcademicInfo {
    int m1, m2;

protected:
    void show();        // Display academic info
    int getMarks();     // Return total academic marks

public:
    AcademicInfo(int, int);  // Parameterized constructor
    ~AcademicInfo();         // Destructor
};

// CCA class inherits from both PersonalInfo and AcademicInfo
class CCA : public PersonalInfo, public AcademicInfo {
    int marks;      // CCA marks
    string events;  // CCA event name

protected:
    int total;      // Combined total

public:
    CCA(string, int, string, int, int, int);  // Constructor
    ~CCA();                                   // Destructor
    void getTotal();                          // Calculate total marks
    void show();                              // Display all details
};

// ----------- Definitions ------------

// Constructor for PersonalInfo
inline PersonalInfo::PersonalInfo(string n, int r) {
    name = n;
    roll = r;
}

// Destructor for PersonalInfo
inline PersonalInfo::~PersonalInfo() {}

// Display personal info
inline void PersonalInfo::show() {
    cout << "Name: " << name << endl;
    cout << "Roll No.: " << roll << endl;
}

// Constructor for AcademicInfo
inline AcademicInfo::AcademicInfo(int a, int b) {
    m1 = a;
    m2 = b;
}

// Destructor for AcademicInfo
inline AcademicInfo::~AcademicInfo() {}

// Return sum of academic marks
inline int AcademicInfo::getMarks() {
    return m1 + m2;
}

// Display academic marks
inline void AcademicInfo::show() {
    cout << "Marks in Subject 1: " << m1 << endl;
    cout << "Marks in Subject 2: " << m2 << endl;
}

// Constructor for CCA using initialization list
inline CCA::CCA(string e, int m, string n, int r, int a, int b)
    : PersonalInfo(n, r), AcademicInfo(a, b) {
    events = e;
    marks = m;
}

// Destructor for CCA
inline CCA::~CCA() {}

// Calculate total marks
void CCA::getTotal() {
    total = marks + getMarks();  // Get academic marks + CCA marks
}

// Display all information
void CCA::show() {
    PersonalInfo::show();
    AcademicInfo::show();
    getTotal();
    cout << "CCA Event: " << events << endl;
    cout << "CCA Marks: " << marks << endl;
    cout << "Total Marks (Academic + CCA): " << total << endl;
}

// ---------- Main Function ----------
int main() {
    // Create object with: Event, CCA marks, Name, Roll, Marks1, Marks2
    CCA obj("Dance", 92, "Alice", 546, 90, 96);
    obj.show();

    return 0;
}
