#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

using Matrix = vector<vector<int>>;

Matrix multiply(Matrix a, Matrix b) {
    int n = a.size();
    Matrix c(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            if (a[i][k])
                for (int j = 0; j < n; j++)
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;

    return c;
}

Matrix power(Matrix a, int n) {
    int sz = a.size();
    Matrix res(sz, vector<int>(sz));

    for (int i = 0; i < sz; i++)
        res[i][i] = 1;

    while (n) {
        if (n & 1)
            res = multiply(res, a);

        a = multiply(a, a);
        n >>= 1;
    }

    return res;
}

signed main() {
    Matrix a = {
        {1, 1},
        {1, 0}
    };

    int n;
    cin >> n;

    cout << power(a, n)[0][1] << '\n';
}
