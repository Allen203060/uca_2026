#include <stdio.h>

long long fibBruteHelper(long long a, long long b, long long n) {
    long long nextFib = a + b;

    if (nextFib > n) return 0;

    long long currVal = 0;

    if (nextFib % 2 == 0) {
        currVal = nextFib;
    }

    return currVal + fibBruteHelper(b, nextFib, n);
}

// brute force for even sun fibonacci series

long long fibEvenSumBrute(long long n) {

    return fibBruteHelper(1, 1, n);
}

//optimised approach - logn

long long fibEvenSumOpt(long long n) {
    if (n < 2) {
        return 0;
    }

    long long e1 = 0;
    long long e2 = 2;
    long long sum = 0;
    long long e3;

    while (e2 <= n) {
        sum += e2;
        // get the next even Fibonacci number 
        e3 = 4 * e2 + e1;
        e1 = e2;
        e2 = e3;
    }
    return sum;
}


int main() {
    long long test_case[] = {10, 50, 144};
    int num_cases = sizeof(test_case) / sizeof(test_case[0]);
    
    for (int i = 0; i < num_cases; i++) {
        long long n = test_case[i];
        printf("For n = %lld:\n", n);
        printf("Recursive Brute Force Sum: %lld\n", fibEvenSumBrute(n));
        printf("Optimized Sum: %lld\n\n", fibEvenSumOpt(n));
    }
    
    return 0;
}