// C++ program to print all prime factors
#include <bits/stdc++.h>
using namespace std;

// A function to print all prime
// factors of a given number n
void primeFactors(int q)
{
    for (int i = 2; i <= sqrt(q); i++) {
        while (q % i == 0) {
            cout << i << " ";
            q = q / i;
        }
    }

    if (q > 1)
        cout << q << " ";
}

/* Driver code */
int main()
{
    int n = 12;
    primeFactors(n);
    return 0;
}