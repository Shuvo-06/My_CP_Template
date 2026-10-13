#pragma once
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// All core interval functions use CLOSED / inclusive intervals [l, r].
// For half-open intervals [l, r), adapt endpoint comparisons and lengths.

// ---------- Basic interval operations ----------

struct Interval {
    ll l, r;

    Interval() : l(0), r(-1) {}
    Interval(ll left, ll right) : l(left), r(right) {}

    bool valid() const { return l <= r; }
    ll length() const { return valid() ? r - l + 1 : 0; } // integer points
};

inline bool byLeft(const Interval& a, const Interval& b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}

inline bool byRight(const Interval& a, const Interval& b) {
    if (a.r != b.r) return a.r < b.r;
    return a.l < b.l;
}

inline Interval normalize(ll a, ll b) {
    if (a > b) swap(a, b);
    return {a, b};
}

inline bool overlaps(const Interval& a, const Interval& b) {
    return a.valid() && b.valid() && max(a.l, b.l) <= min(a.r, b.r);
}

// True when intervals share an endpoint or integer points.
inline bool touchesOrOverlaps(const Interval& a, const Interval& b) {
    if (!a.valid() || !b.valid()) return false;
    if (overlaps(a, b)) return true;
    if (a.r != LLONG_MAX && a.r + 1 == b.l) return true;
    if (b.r != LLONG_MAX && b.r + 1 == a.l) return true;
    return false;
}

inline bool contains(const Interval& a, const Interval& b) {
    return a.valid() && b.valid() && a.l <= b.l && b.r <= a.r;
}

inline optional<Interval> intersection(const Interval& a, const Interval& b) {
    ll l = max(a.l, b.l), r = min(a.r, b.r);
    if (l > r) return nullopt;
    return Interval(l, r);
}

inline bool containsPoint(const Interval& a, ll x) {
    return a.valid() && a.l <= x && x <= a.r;
}

// ---------- Sorting and merging ----------

// Merge overlapping and adjacent integer intervals.
inline vector<Interval> mergeIntervals(vector<Interval> v) {
    v.erase(remove_if(v.begin(), v.end(),
                      [](const Interval& x) { return !x.valid(); }), v.end());
    sort(v.begin(), v.end(), byLeft);

    vector<Interval> ans;
    for (const auto& cur : v) {
        if (ans.empty() || (ans.back().r != LLONG_MAX && cur.l > ans.back().r + 1)) {
            ans.push_back(cur);
        } else {
            ans.back().r = max(ans.back().r, cur.r);
        }
    }
    return ans;
}

// Explicit alias: merge overlapping OR adjacent integer intervals.
inline vector<Interval> mergeTouchingIntervals(vector<Interval> v) {
    return mergeIntervals(move(v)); // mergeIntervals merges adjacency for integer intervals
}

// Insert one interval into a sorted, disjoint, adjacency-merged list.
inline vector<Interval> insertInterval(vector<Interval> v, Interval x) {
    if (!x.valid()) return v;
    v.push_back(x);
    return mergeIntervals(move(v));
}

// ---------- Union, intersection, subtraction, complement ----------

// Number of integer points in the union of intervals.
inline ll unionPointCount(vector<Interval> v) {
    ll ans = 0;
    for (const auto& x : mergeIntervals(move(v))) ans += x.length();
    return ans;
}

// Total real length of the union of half-open intervals [l, r).
// Input intervals are interpreted as half-open and zero/negative lengths are ignored.
inline ll unionLengthHalfOpen(vector<Interval> v) {
    v.erase(remove_if(v.begin(), v.end(),
                      [](const Interval& x) { return x.l >= x.r; }), v.end());
    sort(v.begin(), v.end(), byLeft);
    if (v.empty()) return 0;

    ll ans = 0, l = v[0].l, r = v[0].r;
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i].l > r) {
            ans += r - l;
            l = v[i].l;
            r = v[i].r;
        } else {
            r = max(r, v[i].r);
        }
    }
    return ans + r - l;
}

// Intersection of two sorted, disjoint interval lists.
inline vector<Interval> intersectIntervalLists(const vector<Interval>& a,
                                                const vector<Interval>& b) {
    vector<Interval> ans;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        ll l = max(a[i].l, b[j].l);
        ll r = min(a[i].r, b[j].r);
        if (l <= r) ans.emplace_back(l, r);
        if (a[i].r < b[j].r) ++i;
        else ++j;
    }
    return ans;
}

// Subtract one closed interval b from closed interval a; returns 0, 1, or 2 pieces.
inline vector<Interval> subtractInterval(const Interval& a, const Interval& b) {
    if (!overlaps(a, b)) return a.valid() ? vector<Interval>{a} : vector<Interval>{};
    vector<Interval> ans;
    if (a.l < b.l) ans.emplace_back(a.l, b.l - 1);
    if (b.r < a.r) ans.emplace_back(b.r + 1, a.r);
    return ans;
}

// A \ B for interval lists. Inputs may be arbitrary; they are normalized by merging.
inline vector<Interval> subtractIntervalLists(vector<Interval> a, vector<Interval> b) {
    a = mergeIntervals(move(a));
    b = mergeIntervals(move(b));
    vector<Interval> ans;
    size_t j = 0;

    for (const auto& x : a) {
        ll cur = x.l;
        bool exhausted = false;
        while (j < b.size() && b[j].r < cur) ++j;

        size_t k = j;
        while (k < b.size() && b[k].l <= x.r) {
            if (b[k].l > cur) ans.emplace_back(cur, b[k].l - 1);
            if (b[k].r >= x.r) {
                exhausted = true;
                break;
            }
            if (b[k].r == LLONG_MAX) {
                exhausted = true;
                break;
            }
            cur = max(cur, b[k].r + 1);
            ++k;
        }
        if (!exhausted && cur <= x.r) ans.emplace_back(cur, x.r);
    }
    return ans;
}

// Complement of covered closed integer intervals inside domain [L, R].
inline vector<Interval> complementIntervals(vector<Interval> v, ll L, ll R) {
    if (L > R) return {};
    v = mergeIntervals(move(v));
    vector<Interval> ans;
    ll cur = L;

    for (const auto& x : v) {
        if (x.r < L) continue;
        if (x.l > R) break;
        ll l = max(x.l, L), r = min(x.r, R);
        if (cur < l) ans.emplace_back(cur, l - 1);
        if (r == LLONG_MAX) return ans;
        cur = max(cur, r + 1);
        if (cur > R) return ans;
    }
    if (cur <= R) ans.emplace_back(cur, R);
    return ans;
}

// ---------- Sweep line ----------

struct Event {
    ll x, delta;
    bool operator<(const Event& other) const {
        if (x != other.x) return x < other.x;
        return delta < other.delta;
    }
};

// Count integer points covered by at least one closed interval.
inline ll coveredIntegerPoints(const vector<Interval>& v) {
    vector<Interval> good;
    for (auto x : v) if (x.valid()) good.push_back(x);
    return unionPointCount(move(good));
}

// Maximum number of closed intervals covering any integer point.
inline ll maximumOverlapClosed(const vector<Interval>& v) {
    vector<Event> ev;
    for (const auto& x : v) {
        if (!x.valid()) continue;
        ev.push_back({x.l, +1});
        if (x.r != LLONG_MAX) ev.push_back({x.r + 1, -1});
    }
    sort(ev.begin(), ev.end());
    ll curr = 0, best = 0;
    for (const auto& e : ev) {
        curr += e.delta;
        best = max(best, curr);
    }
    return best;
}

// Length of the union of real intervals interpreted as closed endpoints;
// endpoint-only overlaps do not affect length. Uses long long coordinate differences.
inline ll coveredLength(const vector<Interval>& v) {
    return unionLengthHalfOpen(v);
}

// Coverage count at every event segment [x_i, x_{i+1}) for half-open intervals.
// Returns sorted (coordinate, active_count_after_processing_coordinate) pairs.
inline vector<pair<ll, ll>> sweepCoverageHalfOpen(const vector<Interval>& v) {
    vector<Event> ev;
    for (const auto& x : v) {
        if (x.l >= x.r) continue;
        ev.push_back({x.l, +1});
        ev.push_back({x.r, -1});
    }
    sort(ev.begin(), ev.end());

    vector<pair<ll, ll>> ans;
    ll active = 0;
    for (size_t i = 0; i < ev.size();) {
        ll x = ev[i].x, delta = 0;
        while (i < ev.size() && ev[i].x == x) delta += ev[i++].delta;
        active += delta;
        ans.emplace_back(x, active);
    }
    return ans;
}

// ---------- Greedy interval scheduling ----------

// Maximum number of mutually non-overlapping closed intervals.
inline int maxNonOverlapping(vector<Interval> v) {
    v.erase(remove_if(v.begin(), v.end(),
                      [](const Interval& x) { return !x.valid(); }), v.end());
    sort(v.begin(), v.end(), byRight);
    int ans = 0;
    ll lastRight = 0;
    bool chosen = false;

    for (const auto& x : v) {
        if (!chosen || x.l > lastRight) {
            ++ans;
            lastRight = x.r;
            chosen = true;
        }
    }
    return ans;
}

// Minimum number of intervals to remove to make the rest non-overlapping.
inline int minIntervalsToRemove(vector<Interval> v) {
    return (int)v.size() - maxNonOverlapping(move(v));
}

// Minimum number of groups/resources needed for closed intervals.
// Intervals sharing an endpoint overlap, so release when end < next start.
inline int minGroupsClosed(vector<Interval> v) {
    v.erase(remove_if(v.begin(), v.end(),
                      [](const Interval& x) { return !x.valid(); }), v.end());
    sort(v.begin(), v.end(), byLeft);

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int groups = 0;
    for (const auto& x : v) {
        while (!pq.empty() && pq.top() < x.l) pq.pop();
        pq.push(x.r);
        groups = max(groups, (int)pq.size());
    }
    return groups;
}

// ---------- Binary-search helpers ----------

// Requires intervals sorted by left endpoint.
inline int firstIntervalWithRightAtLeast(const vector<Interval>& v, ll x) {
    int lo = 0, hi = (int)v.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid].r < x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// Count intervals in a sorted-by-left list whose left endpoint is <= x.
inline int countStartsAtMost(const vector<Interval>& v, ll x) {
    return (int)(upper_bound(v.begin(), v.end(), x,
        [](ll value, const Interval& in) { return value < in.l; }) - v.begin());
}

// ---------- Difference array for bounded integer coordinates ----------

// Add +1 on each closed interval [l, r] using a difference array.
// Coordinates must satisfy 0 <= l <= r < n.
inline void addClosedInterval(vector<ll>& diff, int l, int r, ll value = 1) {
    if (l < 0 || r < l || r + 1 >= (int)diff.size()) {
        throw out_of_range("addClosedInterval: expected 0 <= l <= r < diff.size()-1");
    }
    diff[l] += value;
    diff[r + 1] -= value;
}

// Convert a difference array of size n+1 into coverage values for positions [0, n).
inline vector<ll> buildCoverage(const vector<ll>& diff) {
    if (diff.empty()) return {};
    vector<ll> ans(diff.size() - 1);
    ll curr = 0;
    for (size_t i = 0; i + 1 < diff.size(); ++i) {
        curr += diff[i];
        ans[i] = curr;
    }
    return ans;
}

/*
Quick reminders:
1) Closed integer interval [l, r]: length = r - l + 1.
2) Half-open interval [l, r): length = r - l.
3) Closed intervals overlap iff max(l1, l2) <= min(r1, r2).
4) To sweep closed integer intervals, use events (l, +1), (r + 1, -1).
5) To sweep half-open intervals, use events (l, +1), (r, -1).
6) For closed intervals, [1, 3] and [3, 5] overlap.
7) For integer coverage, [1, 3] and [4, 6] are adjacent; mergeIntervals merges them.
*/
