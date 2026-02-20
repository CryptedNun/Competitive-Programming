#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> x(n);
    for(auto& e : x) cin >> e;

    set<pair<int, int>> leftSet, rightSet;
    ll left_sum = 0, right_sum = 0;

    // ? EDGE CASE FOR K = 1, 2
    if(k == 1) {
        while(n--) cout << 0 << " ";
        return 0;
    } else if(k == 2) {
        for(int i = 1; i < n; i++) cout << abs(x[i] - x[i - 1]) << " ";
        return 0;
    }

    vector<pair<int, int>> initWindow; 
    for(int i = 0; i < k; i++) initWindow.push_back({x[i], i});
    sort(initWindow.begin(), initWindow.end());

    // * >> leftSet has k/2 + k%2 elems, rightSet has remaining. Left has more when odd, both equal when even. Median is leftSet.rbegin()
    for(int i = 0; i < k/2 + (k%2); i++) {
        leftSet.insert(initWindow[i]); 
        left_sum += initWindow[i].first;
    }
    for(int i = k/2 + (k%2); i < k; i++) { 
        rightSet.insert(initWindow[i]); 
        right_sum += initWindow[i].first;
    
    }
    int median = leftSet.rbegin()->first;
    cout << leftSet.size() * median - left_sum
            + right_sum - rightSet.size() * median 
            << " ";

    for(int j = 1; j < n - k + 1; j++) {
        // !! UPDATE OUTGOING ELEM FROM SETS
        if(leftSet.count( {x[j - 1], j - 1} )) {
            leftSet.erase( {x[j - 1], j - 1} );
            left_sum -= x[j - 1];
        } else {
            rightSet.erase( {x[j - 1], j - 1} );
            right_sum -= x[j - 1];
        }

        // !! UPDATE INGOING ELEM INTO SETS
        if(*(leftSet.rbegin()) < make_pair(x[j - 1 + k], j - 1 + k)) {
            rightSet.insert( {x[j - 1 + k], j - 1 + k} );
            right_sum += x[j - 1 + k];
        } else {
            leftSet.insert( {x[j - 1 + k], j - 1 + k} );
            left_sum += x[j - 1 + k];
        }

        // ! REBALANCE THE LEFT & RIGHT SETS
        while(leftSet.size() < k/2 + (k%2)) {
            pair<int, int> taken = *(rightSet.begin());

            leftSet.insert(taken);
            left_sum += taken.first;

            rightSet.erase(taken);
            right_sum -= taken.first;
        }
        while(leftSet.size() > k/2 + (k%2)) {
            pair<int, int> taken = *(leftSet.rbegin());

            rightSet.insert(taken);
            right_sum += taken.first;

            leftSet.erase(taken);
            left_sum -= taken.first;
        }

        median = leftSet.rbegin()->first;
        cout << leftSet.size() * median - left_sum
            + right_sum - rightSet.size() * median 
            << " ";
    }
}