#include <bits/stdc++.h>
using namespace std;

template <int MOD>
struct modint {
    int value;
    modint(long long v = 0) : value((v % MOD + MOD) % MOD) {}

    modint& operator+=(const modint& o) { if ((value += o.value) >= MOD) value -= MOD; return *this; }
    modint& operator-=(const modint& o) { if ((value -= o.value) < 0) value += MOD; return *this; }
    modint& operator*=(const modint& o) { value = int(1LL * value * o.value % MOD); return *this; }
    modint& operator/=(const modint& o) { return *this *= o.inv(); }

    explicit operator bool() const { return value != 0; }
    bool operator==(const modint& o) const { return value == o.value; }
    bool operator!=(const modint& o) const { return value != o.value; }

    modint operator-() const { return modint(-value); }
    modint& operator++() { if (++value == MOD) value = 0; return *this; }
    modint operator++(int) { modint t = *this; ++*this; return t; }
    modint& operator--() { if (--value == -1) value = MOD - 1; return *this; }
    modint operator--(int) { modint t = *this; --*this; return t; }

    friend modint operator+(modint a, const modint& b) { return a += b; }
    friend modint operator-(modint a, const modint& b) { return a -= b; }
    friend modint operator*(modint a, const modint& b) { return a *= b; }
    friend modint operator/(modint a, const modint& b) { return a /= b; }

    modint pow(long long p) const {
        modint a = *this, r = 1;
        while (p) { if (p & 1) r *= a; a *= a; p >>= 1; }
        return r;
    }

    modint inv() const { return pow(MOD - 2); }
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

