#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n; cin >> x >> n;
    vector<int> p(n);
    for(auto& p_i: p) cin >> p_i;

    set<pair<int, int>> intervals;
    multiset<int> lengths;
    intervals.insert(make_pair(0, x));
    lengths.insert(x - 0);

    // Set DS will keep the intervals in lexicographic order.
    // To do binary search for a particular element p's interval, since each interval is non-overlapping,
    // we can find the interval that has the highest leftbound and is less than p. 
    // We will use lowerbound() to find the interval with the lowest leftbound and is >= p.
    // The interval before that is our desired interval.

    for(auto& p_i : p) {
        auto it = intervals.lower_bound({p_i, 0});
        it--;

        int left = (*it).first;
        int right = (*it).second;
        int length = right - left;
        
        intervals.erase(it);
        auto lit = lengths.find(length);
        lengths.erase(lit);

        intervals.insert({left, p_i});
        intervals.insert({p_i, right});
        lengths.insert(p_i - left);
        lengths.insert(right - p_i);

        auto itMax = prev(lengths.end());
        cout << *itMax << ' ';
    }
}