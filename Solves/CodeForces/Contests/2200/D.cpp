#include <bits/stdc++.h>
using namespace std;

vector<int> fastSmallestShift(vector<int>& a) {
    int n = a.size();
    vector<int> b = a;
    b.insert(b.end(), a.begin(), a.end()); 

    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        int a_idx = b[i + k];
        int b_idx = b[j + k];
        
        if (a_idx == b_idx) k++;
        else {
            if (a_idx > b_idx) i += k + 1; 
            else j += k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    
    int start = min(i, j);
    vector<int> res;
    for (int idx = 0; idx < n; idx++) res.push_back(a[(start + idx) % n]);
    return res;
}

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> p(n);
    for(auto& e : p) cin >> e;

    // ! Inner subarr [x, y-1], get its Lexico smallest circular perm
    vector<int> inner;
    for(int i = x; i < y; i++) inner.push_back(p[i]);
    inner = fastSmallestShift(inner);

    // ! Get outer joint subarr
    vector<int> outer;
    for(int i = 0; i < n; i++) {
        if(i >= x && i < y) continue;
        outer.push_back(p[i]);
    }

    if (inner.empty()) {
        for (int e : outer) cout << e << " ";
        cout << endl;
        return;
    }

    int ptr = -1;
    while(ptr + 1 < (int)outer.size() && outer[ptr + 1] < inner[0]) 
        ptr++;

    for(int i = 0; i <= ptr; i++) cout << outer[i] << " ";
    for(auto& e : inner) cout << e << " ";
    for(int i = ptr + 1; i < outer.size(); i++) cout << outer[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}