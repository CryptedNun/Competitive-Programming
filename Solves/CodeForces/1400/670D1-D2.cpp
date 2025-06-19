#include <bits/stdc++.h>
using namespace std;

bool searchFunc(vector<long long> a, vector<long long> b, long long k, long long x) {
    long long extra = 0;
    for(long long i=0; i<a.size(); i++) {
        extra += max(0LL, x*a[i] - b[i]);
        if(extra > k) return false;         //! This check is here so that we check extra before it overflows by any chance
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k; cin>>n>>k;
    vector<long long> a(n), b(n);
    for(long long i=0; i<n; i++) cin>>a[i];
    for(long long i=0; i<n; i++) cin>>b[i];

    long long left = 0, right = 2e9, mid, answer = 0;
    while(left <= right) {
        mid = left + (right-left)/2;
        bool condition = searchFunc(a, b, k, mid);

        if(condition) {
            answer = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    cout<<answer<<endl;
}