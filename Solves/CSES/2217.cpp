#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ----------------------------------------- //
    int n, m; cin >> n >> m;

    vector<int> x(n + 1); 
    x[0] = 0;
    for(int i = 1; i <= n; i++) 
        cin >> x[i];

    vector<pair<int, int>> swaps(m);
    for(int i = 0; i < m; i++) 
        cin >> swaps[i].first >> swaps[i].second;
    // ------------------------------------------ //

    // Step - 1: Make an idx vector
    vector<int> idx(n + 1);
    idx[0] = 0;
    for(int i = 1; i <= n; i++) 
        idx[x[i]] = i;

    // Step - 2: Count inversions
    int rounds = 1;
    for(int i = 1; i <= n; i++) {
        if(idx[i] > idx[i + 1] && i != n) 
            rounds++;
    }

    // Step - 3: Parse the swaps individually
    // Since only the adjacent value pairs, of the 2 values that got swapped, matter. 
    // The other values' inversion states remain the same.
    for(int i = 0; i < m; i++) {
        int l = swaps[i].first,
            r = swaps[i].second,
            lval = x[l],
            rval = x[r];

        set<pair<int, int>> pairs;
        if(lval - 1 >= 1) 
            pairs.insert({lval - 1, lval});
        if(lval + 1 <= n)
            pairs.insert({lval, lval + 1});
        if(rval - 1 >= 1) 
            pairs.insert({rval - 1, rval});
        if(rval + 1 <= n)
            pairs.insert({rval, rval + 1});

        // Core logic:
        // For each pair,
        // If there was no inversion before but there is now, we add 1 for the new sequence
        // else if there was inversion before but not now, we subtract one 1 for the old sequence
        // else as it was, no change

        // So first subtract 1 if we find inversion BEFORE SWAP
        // Then add 1 if we find inversion AFTER SWAP

        for(auto& element : pairs) 
            rounds -= (idx[element.first] > idx[element.second]);
        
        // Update array information
        swap(x[l], x[r]);
        idx[x[l]] = l;
        idx[x[r]] = r;

        for(auto& element : pairs) 
            rounds += (idx[element.first] > idx[element.second]);
        
        cout << rounds << endl;
    }

}