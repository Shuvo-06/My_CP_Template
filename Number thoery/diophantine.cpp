#include <bits/stdc++.h>
using namespace std;

int extgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1; y = 0;
        return a;
    }

    int x1, y1;
    int g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

bool diophantine(int a, int b, int c, int &x, int &y) {
    int x0, y0;
    int g = extgcd(abs(a), abs(b), x0, y0);

    if (c % g) return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    x = x0;
    y = y0;
    return true;
}

void shift(int &x, int &y, int a, int b, int k) {
    x += k * b;
    y -= k * a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int x, y;

    if (!diophantine(a, b, c, x, y)) {
        cout << "No solution\n";
        return 0;
    }

    cout << "One solution: " << x << ' ' << y << '\n';

    // All solutions:
    // x = x + k * (b / g)
    // y = y - k * (a / g)

    int g = gcd(abs(a), abs(b));

    cout << "General solution:\n";
    cout << "x = " << x << " + k * " << b / g << '\n';
    cout << "y = " << y << " - k * " << a / g << '\n';
}
