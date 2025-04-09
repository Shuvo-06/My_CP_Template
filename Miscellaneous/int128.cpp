#include <bits/stdc++.h>
using namespace std;

using lll = __int128;

void cin_lll(lll &a) {
    string s;
    cin >> s;
    lll res = 0;
    bool neg = false;
    for (char c : s) {
        if (c == '-') neg = true;
        else res = res * 10 + (c - '0');
    }
    a = neg ? -res : res;
}

void cout_lll(lll x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    bool neg = false;
    if (x < 0) {
        neg = true;
        x = -x;
    }
    string s;
    while (x) {
        s += '0' + x % 10;
        x /= 10;
    }
    if (neg) s += '-';
    for (int i = s.size() - 1; i >= 0; i--) cout << s[i];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        lll a, b;
        cin_lll(a);
        cin_lll(b);
        cout_lll(a * b);
        cout << "\n";
    }
    return 0;
}
