#include <bits/stdc++.h>
using namespace std;

// number divisor analysis 

// NOD function calculation 
// method 1 : from prime factorization 
int nod_pfact(vector <pair <int, int>> &v) {
    int res = 1;
    for (auto [p, exp] : v) res *= (exp + 1);
    return res;
}

// method 2 : looping until sqrt(n)
int nod_sqrtn(long long int n) {
    int res = 0;
    for (long long int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) res++;
            else res+=2;
        }
    }
    return res;
}

// method 3 : sieve style
// time complexity : O(nlogn)
vector <int> nod;
void init_nod(int n) {
    nod.assign(n + 1, 1);
    nod[0] = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            nod[j]++;
        }
    }
}




// SOD function calculation 
// method 1 : from prime factorization 
long long int sod_pfact(vector <pair <int, int>> &v) {
    long long int res = 1;
    for (auto [p, exp] : v) {
        long long int pn = 1;
        for (int i = 0; i <= exp; i++) pn *= 1LL * p;
        res *= (pn - 1) / (p - 1);
    }
    return res;
}

// method 2 : looping until sqrt(n)
long long int sod_sqrtn(long long int n) {
    long long int res = 0;
    for (long long int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) res += i;
            else res += i + n / i;
        }
    }
    return res;
}


// method 3 : sieve style
// time complexity : O(nlogn)
vector <long long int> sod;
void init_sod(int n) {
    sod.resize(n + 1, 0);
    for (long long int i = 1; i <= n; ++i) {
        for (long long int j = i; j <= n; j += i) {
            sod[j] += i;
        }
    }
}



int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    

    return 0;
}
