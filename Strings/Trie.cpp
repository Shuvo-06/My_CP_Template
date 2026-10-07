#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        int nxt[26];
        bool end = false;

        Node() {
            fill(nxt, nxt + 26, -1);
        }
    };

    vector<Node> t = {Node()};

    void insert(string s) {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) {
                t[u].nxt[x] = t.size();
                t.push_back(Node());
            }
            u = t[u].nxt[x];
        }
        t[u].end = true;
    }

    bool find(string s) {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) return false;
            u = t[u].nxt[x];
        }
        return t[u].end;
    }
};

int main() {}