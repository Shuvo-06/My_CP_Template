#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define nl << "\n"
#define ll long long int
#define forl(i, st, en) for (int i = st; i < en; i++)
#define testcase(tt) int tt; cin >> tt; for (tno = 1; tno <= tt; tno++) solve();
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sp(abaca) fixed << setprecision(abaca)
#define rounded(a,b) ((a + (b / 2)) / b)
#define ceiled(a,b) ((a + b - 1) / b)
#define to_rad(x) (x * (acos(-1.0) / 180))
#define to_deg(x) (x * (180 / acos(-1.0)))
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";

// --- Constants ---
const double pi = acos(-1.0);
const long long inf = 1e18;
long long int MOD = 998244353;
int tno;

// --- Debugging ---
#ifdef SUBLIME
    #ifdef _WIN32
        #define byte win_byte_override
        #define _NO_RPCNDR_BYTE_
        #include <windows.h>
        #include <psapi.h>
    #endif

    void printMemoryUsage() {
        #ifdef _WIN32
            PROCESS_MEMORY_COUNTERS memInfo;
            GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
            SIZE_T physMemUsed = memInfo.WorkingSetSize;
            std::cerr << "Memory Usage: " << physMemUsed / 1024.0 / 1024.0 << " MB\n";
        #endif
    }

    #define db(x) cerr << #x << " -> " << x << "\n";
    #define dbp(x) cerr << #x << " -> " << x.first << ", " << x.second << "\n";
    #define view(p) cerr << #p << " -> "; for (auto it = p.begin(); it != p.end(); ++it) cerr << *it << " \n"[it == p.end() - 1];
    #define viewr(p) cerr << #p << " -> "; for (auto it = p.rbegin(); it != p.rend(); it++) cerr << *it << " \n"[it == p.begin()];
    #define viewp(p) cerr << #p << " -> \n"; for (auto x : p) cerr << x.first << ", " << x.second << "\n";
#endif

// --- PBDS ---
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define indexed_set tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define at_index find_by_order
#define index_of_new_element order_of_key

// --- Bit Functions ---
int set_bit(int n, int i) { return (n | (1LL << i)); }
int clear_bit(int n, int i) { return (n & ~(1 << i)); }
int flip_bit(int n, int i) { return n ^ (1 << i); }
int check_bit(long long int n, int i) {return (n >> i) & 1ULL;}

// --- Math ---
ll __lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }

template <int MOD>
struct modint {
    int value;
    modint(long long v = 0) : value((v % MOD + MOD) % MOD) {}

    modint& operator+=(const modint& o) { if ((value += o.value) >= MOD) value -= MOD; return *this; }
    modint& operator-=(const modint& o) { if ((value -= o.value) < 0) value += MOD; return *this; }
    modint& operator*=(const modint& o) { value = int(1LL * value * o.value % MOD); return *this; }
    modint& operator/=(const modint& o) { return *this *= o.inv(); }

    explicit operator bool() const { return value != 0; }
    bool operator==(const modint& o) const { return value == o.value; }
    bool operator!=(const modint& o) const { return value != o.value; }

    modint operator-() const { return modint(-value); }
    modint& operator++() { if (++value == MOD) value = 0; return *this; }
    modint operator++(int) { modint t = *this; ++*this; return t; }
    modint& operator--() { if (--value == -1) value = MOD - 1; return *this; }
    modint operator--(int) { modint t = *this; --*this; return t; }

    friend modint operator+(modint a, const modint& b) { return a += b; }
    friend modint operator-(modint a, const modint& b) { return a -= b; }
    friend modint operator*(modint a, const modint& b) { return a *= b; }
    friend modint operator/(modint a, const modint& b) { return a /= b; }

    modint pow(long long p) const {
        modint a = *this, r = 1;
        while (p) { if (p & 1) r *= a; a *= a; p >>= 1; }
        return r;
    }

    modint inv() const { return pow(MOD - 2); }
    int val() const { return value; }
};
using mint97 = modint<1000000007>;
using mint99 = modint<998244353>;

// --- Miscellanous ---
int cir(vector<int>& vec, int lo, int hi) {
    return upper_bound(vec.begin(), vec.end(), hi) - lower_bound(vec.begin(), vec.end(), lo);
}

// --- Grid Movement ---
#define in_bound(x, y, n, m) (x >= 0 && x < n && y >= 0 && y < m)
vector<pair<int, int>> moves4 = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; string moves4c = "UDLR";
vector<pair<int, int>> moves8 = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
vector<pair<int, int>> knight = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};



void precalc() {

}

void solve() {
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef SUBLIME
        clock_t tStart = clock();
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
    precalc();

    solve();
    // testcase(tt);

    #ifdef SUBLIME
        cerr << fixed << setprecision(10);
        cerr << "\nRuntime: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << " seconds\n";
        printMemoryUsage();
    #endif

    return 0;
}
