// Tail recursion for factorial

#include <stdio.h>
unsigned long long tailFactorial(int n, int long sol) {
    if (n == 0 || n == 1) {
        return sol;
    } else {
        return tailFactorial(n - 1, n * sol);
    }
}

int long factorial(int n) {
    return tailFactorial(n, 1);
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        unsigned long long result = factorial(num);
        printf("Factorial of %d is %ld\n", num, result);
    }

    return 0;
}
