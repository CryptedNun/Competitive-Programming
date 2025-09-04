#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<long long> a(n);
        for(int i=0; i<n; i++) cin>>a[i];

        long long minimumOp = 0;
        for(int i=0; i<n; i++) {
            if((i+1)%2 == 0) {
                long long tertiarySum = a[i-1];
                if(i+1 < n) tertiarySum += a[i+1];

                if(a[i] < tertiarySum) {
                    long long difference = tertiarySum - a[i];
                    minimumOp += difference;
                    if(i+1 < n) {
                        if(difference >= a[i+1]) {
                            a[i+1] = 0;
                            difference -= a[i+1];
                            a[i-1] -= difference;
                        } else {
                            a[i+1] -= difference;
                        }
                    } else {
                        a[i-1] -= difference;
                    }
                }
            }
        }
        cout<<minimumOp<<endl;
    }
}