#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

int size(string);
void print_chars(string);
void print_chars_reverse(string);
int factorial(int);
double power(double, int);
int gcd(int, int);
int factorial_iter(int);
int fibonacci(int);
int fibonacci_start(int);
int fibo(int, int, int);

#define ECHO(x) cout << #x << " == " << (x) << endl;

int main() {
  ECHO(size("xyz"));
  cout << "print_chars(\"xyz\")" << endl;
  print_chars("xyz");
  cout << "print_chars_reverse(\"xyz\")" << endl;
  print_chars_reverse("xyz");
  ECHO(factorial(6));
  ECHO(power(2.0, 5));
  ECHO(power(2.0, -5));
  ECHO(gcd(123, 456));
  ECHO(factorial_iter(6));
  ECHO(fibonacci(10));
  ECHO(fibonacci_start(10));
}

/** Recursive function size (in Recursive_Functions.cpp).
    @param str The string
    @return The length of the string
*/
int size(string str) {
  if (str == "")
    return 0;
  else
    return 1 + size(str.substr(1));
}

/** Recursive function print_chars (in Recursive_Functions.cpp).
    post: The argument string is displayed, one character per line.
    @param str The string
*/
void print_chars(string str) {
  if (str == "") {
    return;
  } else {
    cout << str.at(0) << endl;
    print_chars(str.substr(1));
  }
}

/** Recursive function print_chars_reverse (in Recursive_Functions.cpp).
    post: The argument string is displayed in reverse,
          one character per line.
    @param str The string
*/
void print_chars_reverse(string str) {
  if (str == "") {
    return;
  } else {
    print_chars_reverse(str.substr(1));
    cout << str.at(0) << endl;
  }
}

/** Recursive factorial function (in Recursive_Functions.cpp).
    pre: n >= 0
    @param n The integer whose factorial is being computed
    @return n!
*/
int factorial(int n) {
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}


/** Recursive power function (in Recursive_Functions.cpp).
    @param x The number being raised to a power
    @param n The exponent
    @return x raised to the power n
*/
double power(double x, int n) {
  if (n == 0)
    return 1;
  else if (n > 0)
    return x * power(x, n - 1);
  else
    return 1.0 / power(x, -n);
}

/** Recursive gcd function (in Recursive_Functions.cpp).
    pre: m > 0 and n > 0
    @param m The larger number 
    @param n The smaller number
    @return Greatest common divisor of m and n
*/
int gcd(int m, int n) {
  if (m % n == 0)
    return n;
  else if (m < n)
    return gcd(n, m);   // Transpose arguments.
  else
    return gcd(n, m % n);
}

/** Iterative factorial function. 
    pre: n >= 0
    @param n The integer whose factorial is being computed
    @return n!
*/
int factorial_iter(int n) {
  int result = 1;
  for (int k = 1; k <= n; k++)
    result = result * k;
  return result;
}

/** Recursive function to calculate Fibonacci numbers
    (in Recursive_Functions.cpp).
    pre: n >= 1.
    @param n The position of the Fibonacci number being calculated
    @return The Fibonacci number
*/
int fibonacci(int n) {
  if (n <= 2)
    return 1;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/** Wrapper function for calculating Fibonacci numbers
    (in Recursive_Functions.cpp).
    pre: n >= 1
    @param n The position of the desired Fibonacci number
    @return The value of the nth Fibonacci number
*/
int fibonacci_start(int n) {
  return fibo(1, 0, n);
}

/** Recursive O(n) function to calculate Fibonacci numbers
    (in Recursive_Functions.cpp).
    pre: n >= 1
    @param fib_current The current Fibonacci number
    @param fib_previous The previous Fibonacci number
    @param n The count of Fibonacci numbers left to calculate
    @return The value of the Fibonacci number calculated so far
*/
int fibo(int fib_current, int fib_previous, int n) {
  if (n == 1)
    return fib_current;
  else
return fibo(fib_current + fib_previous, fib_current, n - 1);
}



