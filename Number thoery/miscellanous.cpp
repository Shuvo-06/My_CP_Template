#include <bits/stdc++.h>
using namespace std;

// finds total digits of n factorial
int digits_factorial(int n) {
    if (n < 0) return 0;
    if (n <= 1) return 1;
    double digits = 0;
    for (int i = 1; i <= n; i++) digits += log10(i);
    return floor(digits) + 1;
}

int main() {

}
