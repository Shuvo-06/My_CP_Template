#include <bits/stdc++.h>
using namespace std;

template <int MOD>
struct modint {
    int value;
    modint(long long v = 0) : value((v % MOD + MOD) % MOD) {}

    friend istream& operator>>(istream& in, modint& a) { long long x; return in >> x, a = modint(x), in; }
    friend ostream& operator<<(ostream& out, const modint& a) { return out << a.value; }

    modint& operator+=(const modint& o) { if ((value += o.value) >= MOD) value -= MOD; return *this; }
    modint& operator-=(const modint& o) { if ((value -= o.value) < 0) value += MOD; return *this; }
    modint& operator*=(const modint& o) { value = int(1LL * value * o.value % MOD); return *this; }
    modint& operator/=(const modint& o) { return *this *= o.inverse_of_number(); }

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

    int val() const { return value; }

    modint pow(long long p) const {
        modint a = *this, r = 1;
        while (p) { if (p & 1) r *= a; a *= a; p >>= 1; }
        return r;
    }
    modint inverse_of_number() const { return pow(MOD - 2); }
};
using mint97 = modint<1000000007>;
using mint99 = modint<998244353>;

int main() {
    mint97 a, b;
    cin >> a >> b;
    cout << a * b << "\n";  
    
    return;
}

