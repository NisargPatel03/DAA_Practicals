#include <iostream>
using namespace std;

// Function to print Fibonacci sequence up to n
void fibonacci(int n) {
    int a = 0, b = 1, next;
    cout << "Fibonacci sequence: ";
    while (a <= n) {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Fibonacci sequence
    fibonacci(num);

    return 0;
}
