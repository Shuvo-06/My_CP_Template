#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
class pbds {
private:
    tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update> xyz;

public:
    void insert(T val) {
        xyz.insert(val);
    }

    void erase(T val) {
        xyz.erase(xyz.find(val));
    }

    T at_idx(int index) {
        auto it = xyz.find_by_order(index);
        if (it == xyz.end()) throw out_of_range("Index out of range");
        return *it;
    }

    int get_idx(T val) {
        return xyz.order_of_key(val);
    }

    bool exists(T val) {
        return xyz.find(val) != xyz.end();
    }

    void print() {
        for (auto val : xyz) cout << val << " ";
        cout << "\n";
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
