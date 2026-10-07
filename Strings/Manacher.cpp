#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(string s) {
    string t = "^";
    for (char c : s) t += "#" + string(1, c);
    t += "#$";

    int n = t.size(), l = 0, r = 0;
    vector<int> p(n);

    for (int i = 1; i < n - 1; i++) {
        int mir = l + r - i;
        if (i < r) p[i] = min(r - i, p[mir]);
        while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }

    return p;
}

int main() {
    string s;
    cin >> s;
    vector<int> p = manacher(s);

    int mx = 0, pos = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] > mx) mx = p[i], pos = i;
    }

    cout << "Longest palindrome length: " << mx << '\n';
    cout << "Palindrome: " << s.substr((pos - mx) / 2, mx) << '\n';
}