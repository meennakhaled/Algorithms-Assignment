#include <iostream>
using namespace std;

// =====================
// Recursive Approach
// =====================
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// =====================
// Dynamic Programming Approach (Iterative)
// =====================
int fibonacciDP(int n) {
    if (n <= 1)
        return n;

    int prev1 = 1, prev0 = 0, current;
    for (int i = 2; i <= n; i++) {
        current = prev0 + prev1;
        prev0 = prev1;
        prev1 = current;
    }
    return current;
}

// =====================
// Matrix Multiplication Helper
// =====================
void multiply(int a[2][2], int b[2][2]) {
    int temp[2][2];
    temp[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    temp[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    temp[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    temp[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

    // Copy results back into 'a'
    a[0][0] = temp[0][0];
    a[0][1] = temp[0][1];
    a[1][0] = temp[1][0];
    a[1][1] = temp[1][1];
}

// =====================
// Matrix Exponentiation (Divide and Conquer)
// =====================
void powerMatrix(int matrix[2][2], int n) {
    if (n <= 1)
        return;

    powerMatrix(matrix, n / 2);  // Divide step
    multiply(matrix, matrix);    // Conquer step (square)

    // If n is odd, multiply one more time by the base matrix
    if (n % 2 != 0) {
        int base[2][2] = {{1, 1}, {1, 0}};
        multiply(matrix, base);
    }
}

int fibonacciMatrix(int n) {
    if (n == 0)
        return 0;

    int matrix[2][2] = {{1, 1}, {1, 0}};
    powerMatrix(matrix, n - 1);
    return matrix[0][0];
}

// =====================
// Main Program
// =====================
int main() {
    int n, choice;
    cout << "Enter the position of the Fibonacci number to compute: ";
    cin >> n;

    cout << "\nChoose the computation method:\n";
    cout << "1. Recursive\n";
    cout << "2. Matrix Exponentiation (Divide and Conquer)\n";
    cout << "3. Dynamic Programming (Iterative)\n";
    cout << "Enter choice (1, 2, or 3): ";
    cin >> choice;

    int result;
    if (choice == 1) {
        result = fibonacciRecursive(n);
        cout << "\nFibonacci number at position " << n << " using recursion: " << result << endl;
    } else if (choice == 2) {
        result = fibonacciMatrix(n);
        cout << "\nFibonacci number at position " << n << " using matrix exponentiation: " << result << endl;
    }else if (choice == 3) {
        result = fibonacciDP(n);
        cout << "\nFibonacci number at position " << n << " using dynamic programming: " << result << endl;
    }else  cout << "\nInvalid choice. Please enter 1, 2, or 3." << endl;


    return 0;
}
