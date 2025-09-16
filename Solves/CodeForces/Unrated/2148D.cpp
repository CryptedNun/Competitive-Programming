#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];

        long long allEvens = 0;
        vector<int> allOdds;
        for(int i=0; i<n; i++) {
            if(a[i] & 1) allOdds.push_back(a[i]);
            else allEvens += a[i];
        }
        sort(allOdds.begin(), allOdds.end(), greater<int>());

        long long allOddSum = 0;
        if(allOdds.size() & 1) {
            for(int i=0; i<=allOdds.size()/2; i++) {
                allOddSum += allOdds[i];
            }
        } else {
            for(int i=0; i< allOdds.size()/2; i++) {
                allOddSum += allOdds[i];
            }
        }

        if(allOdds.size() != 0) cout<< allEvens + allOddSum <<endl;
        else cout<<0<<endl;
    }
}