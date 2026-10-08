#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    gp_hash_table<int, int, custom_hash> mp;
    // gp_hash_table<int, int> mp; without hash function

    mp[5] = 10;
    mp[7] = 20;
    mp[5]++;

    cout << mp[5] << '\n';
    if (mp.find(7) != mp.end()) cout << "7 exists\n";
    mp.erase(7);
    cout << mp.size() << '\n';
    return 0;
}
