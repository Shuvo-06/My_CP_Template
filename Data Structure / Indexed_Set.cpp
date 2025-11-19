#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
class pbds {
private:
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> xyz;

public:
    void insert(const T& val) {
        xyz.insert(val);
    }

    bool exists(const T& val) {
        return xyz.find(val) != xyz.end();
    }

    void erase(const T& val) {
        auto it = xyz.find(val);
        if (it != xyz.end()) xyz.erase(it);
    }

    T operator [] (int index) {
        auto it = xyz.find_by_order(index);
        if (it == xyz.end()) throw out_of_range("Index out of range");
        return *it;
    }

    int get_idx(const T& val) {
        return xyz.order_of_key(val);
    }

    int size() {
        return xyz.size();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> v(n);
    for (auto &x : v) cin >> x;

    pbds <pair <int, int>> s;

    for (int i = 0; i < n; i++) {
        s.insert({v[i], i});

        if (i >= k) s.erase({v[i - k], i - k});

        if (i >= k - 1) cout << s.at_index(k / 2).first << " ";
    }
    return 0;
}

