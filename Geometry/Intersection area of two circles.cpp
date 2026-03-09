#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
const double PI = acos(-1.0);
#define double long double

double circle_circle_area(double x1, double y1, double r1, double x2, double y2, double r2) {
    double d = sqrtl((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    if(r1 + r2 < d + eps) return 0;
    if(r1 + d < r2 + eps) return PI * r1 * r1;
    if(r2 + d < r1 + eps) return PI * r2 * r2;

    double theta_1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    double theta_2 = acos((r2 * r2 + d * d - r1 * r1)/(2 * r2 * d));

    return r1 * r1 * (theta_1 - sin(2 * theta_1)/2.) + r2 * r2 * (theta_2 - sin(2 * theta_2)/2.);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    double x1, y1,r1;
    cin >> x1 >> y1 >> r1;

    double x2, y2, r2;
    cin >> x2 >> y2 >> r2;

    cout << fixed << setprecision(10) << circle_circle_area(x1, y1, r1, x2, y2, r2) << "\n";
    return 0;
}


// Problem link : https://codeforces.com/contest/600/problem/D
