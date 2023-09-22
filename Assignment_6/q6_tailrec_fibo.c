// Tail recursion for fibonacci series

#include <stdio.h>
// Tail-recursive Fibonacci function
long int tailFibonacci(int n, long int prev, long int x) {
    if (n == 0) {
        return prev;
    } else {
        return tailFibonacci(n - 1, x, prev + x);
    }
}

// Wrapper function to start tail recursion
unsigned long long fibonacci(int n) {
    return tailFibonacci(n, 0, 1);
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Fibonacci sequence declined.\n");
    } else {
        long int result = fibonacci(num);
        printf("Fibonacci number at position %d is %llu\n", num, result);
    }

    return 0;
}
