#include <bits/stdc++.h>
using namespace std;

template <int MOD>
struct modint {
    int value;

    modint(long long v = 0) {
        value = int(v % MOD);
        if (value < 0) value += MOD;
    }

    modint& operator+=(const modint& other) {
        if ((value += other.value) >= MOD) value -= MOD;
        return *this;
    }

    modint& operator-=(const modint& other) {
        if ((value -= other.value) < 0) value += MOD;
        return *this;
    }

    modint& operator*=(const modint& other) {
        value = int((1LL * value * other.value) % MOD);
        return *this;
    }

    modint& operator/=(const modint& other) {
        return *this *= other.inv();
    }

    friend modint operator+(modint a, const modint& b) { return a += b; }
    friend modint operator-(modint a, const modint& b) { return a -= b; }
    friend modint operator*(modint a, const modint& b) { return a *= b; }
    friend modint operator/(modint a, const modint& b) { return a /= b; }

    modint pow(long long p) const {
        modint a = *this, result = 1;
        while (p > 0) {
            if (p & 1) result *= a;
            a *= a;
            p >>= 1;
        }
        return result;
    }

    modint inv() const {
        return this->pow(MOD - 2);
    }

    int val() const { return value; }
};

using mint97 = modint<1000000007>;
using mint99 = modint<998244353>;

int main() {
    mint97 a = 2, b = 5;
    cout << (a.pow(10) + b).val() << '\n';
    cout << a.val() << "\n";

    return;
}

