#include <bits/stdc++.h>
using namespace std;

string s;
int pos;

pair<long long,long long> parseExpression();

pair<long long,long long> parseFactor() {
    if (s[pos] == '(') {
        pos++;
        auto res = parseExpression();
        pos++; 
        return res;
    }

    if (s[pos] == 'x') {
        pos++;
        return {1,0};
    }

    long long num = 0;
    while (pos < s.size() && isdigit(s[pos])) {
        num = num*10 + (s[pos]-'0');
        pos++;
    }
    return {0,num};
}

pair<long long,long long> parseTerm() {
    auto left = parseFactor();

    while (pos < s.size() && s[pos] == '*') {
        pos++;
        auto right = parseFactor();

        long long a = left.first*right.second + right.first*left.second;
        long long b = left.second*right.second;

        left = {a,b};
    }

    return left;
}

pair<long long,long long> parseExpression() {
    auto left = parseTerm();

    while (pos < s.size() && (s[pos]=='+' || s[pos]=='-')) {
        char op = s[pos++];
        auto right = parseTerm();

        if (op=='+') {
            left.first += right.first;
            left.second += right.second;
        } else {
            left.first -= right.first;
            left.second -= right.second;
        }
    }

    return left;
}

pair<long long,long long> solve(string expr) {
    s = expr;
    pos = 0;
    return parseExpression();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc=1; tc<=T; tc++) {
        string eq;
        cin >> eq;

        int p = eq.find('=');

        auto L = solve(eq.substr(0,p));
        auto R = solve(eq.substr(p+1));

        long long A = L.first - R.first;
        long long B = R.second - L.second;

        cout << "Case " << tc << ": ";

        if (A==0) {
            if (B==0) cout << "infinitely many solutions\n";
            else cout << "no solution\n";
        } else {
            long long g = gcd(llabs(B), llabs(A));
            B/=g;
            A/=g;

            if (A<0) {
                A=-A;
                B=-B;
            }

            if (A==1) cout << B << "\n";
            else cout << B << "/" << A << "\n";
        }
    }
}
