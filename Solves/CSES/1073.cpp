#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n; 
    vector<int> k(n);
    for(int i = 0; i < n; i++) cin >> k[i];

    multiset<int> towerTops;
    for(int i = 0; i < n; i++) {
        auto it = towerTops.upper_bound(k[i]);

        if(it != towerTops.end()) towerTops.erase(it);
        towerTops.insert(k[i]);
    }

    cout << towerTops.size() <<endl;
}