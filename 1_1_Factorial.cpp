#include <iostream>
using namespace std;

// Function to calculate factorial
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Factorial calculation
    cout << "Factorial of " << num << " is " << factorial(num) << endl;

    return 0;
}
