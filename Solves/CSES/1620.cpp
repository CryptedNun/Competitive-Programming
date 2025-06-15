#include <bits/stdc++.h>
using namespace std;

long long binarySearchTime(vector<int>& a, long long t) {
    long long low = 0, high = 1e18, ans = -1;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long items = 0;

        for (int& time : a) {
            items += mid / time;
            if (items >= t) break; // Optional optimization
        }

        if (items >= t) {
            ans = mid;
            high = mid - 1; // try smaller time
        } else {
            low = mid + 1; // need more time
        }
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t; cin>>n>>t;
    vector<int> arr(n);
    for(int& num:arr) cin>>num;

    cout<<binarySearchTime(arr, t)<<endl;
}