#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template<class T>
    size_t operator()(T x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(uint64_t(x) + FIXED_RANDOM);
    }

    template<class A, class B>
    size_t operator()(const pair<A,B>& p) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t h1 = splitmix64(uint64_t(p.first) + FIXED_RANDOM);
        uint64_t h2 = splitmix64(uint64_t(p.second) + FIXED_RANDOM + 0x9e3779b97f4a7c15);
        return h1 ^ (h2 >> 1);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    unordered_map <pair <int, int>, int, custom_hash> mp;

    return 0;
}
