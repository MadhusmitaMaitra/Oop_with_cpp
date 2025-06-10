// Exception handling in case of division by 0
#include <iostream>
using namespace std;
int main() {
  // Initialize two integer variables. 'a' is the numerator and 'b' is the denominator.
  int a = 10, b = 0;
  // Use a try-catch block to handle potential exceptions.
  try {
    // Check if the denominator 'b' is zero.
    if (b == 0) {
      // If 'b' is zero, throw an exception with a descriptive message.
      throw "Division by zero!"; 
    }
    // If 'b' is not zero, perform the division and print the result.
    cout << a / b;
  } 
  catch (const char* msg) {
    // Catch the exception if it's a 'const char*' type (which is what we threw).
    // Print an error message to the console, including the message from the exception.
    cout << "Error: " << msg << endl;
  }
  // The program exits normally.
  return 0;
}
