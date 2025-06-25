#include <bits/stdc++.h>
using namespace std;

bool isStrictlyIncreasing(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i)
        if (arr[i] <= arr[i - 1])
            return false;
    return true;
}

bool isStrictlyDecreasing(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i)
        if (arr[i] >= arr[i - 1])
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> v(n);
        for(int& num:v) cin>>num;

        // TODO : Check whether the array is already beautiful, if so, next testcase.
        bool flag = false;
        for(int i=1; i<n; i++) {
            if(abs(v[i] - v[i-1]) <= 1) {
                cout << 0 << endl;
                flag = true;
                break;
            }
        }
        if(flag) continue;

        // TODO : Check if the array is unsorted/fluctuating, then 1, otherwise -1.
        bool isAscending = isStrictlyIncreasing(v);
        bool isDescending = isStrictlyDecreasing(v);

        if(!isAscending && !isDescending) cout << 1 << endl;
        else cout << -1 << endl;
    }
}