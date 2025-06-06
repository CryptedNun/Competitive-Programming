// ! Concept: Number Theory

#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long modbinpow(int power) {
    long long basell = 2;
    long long result = 1;
    while(power>0) {
        if(power & 1) result = result * basell % MOD;
        basell = basell * basell % MOD;
        power >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> p1(n), p2(n), r(n);
        for(int i=0; i<n;i++) cin>>p1[i];
        for(int i=0; i<n;i++) cin>>p2[i];

        int maxIndex1 = 0, maxIndex2 = 0;

        for(int i=0; i<n; i++) {
            if(i>0) {                                                   // * Updating index of each arr's max
                if(p1[i] > p1[maxIndex1]) maxIndex1 = i;
                if(p2[i] > p2[maxIndex2]) maxIndex2 = i;
            }

            long long res;
            if (p1[maxIndex1] != p2[maxIndex2]) {
                if (p1[maxIndex1] > p2[maxIndex2]) {
                    int idx = i - maxIndex1;
                    int val = (idx >= 0) ? p2[idx] : 0;
                    res = modbinpow(p1[maxIndex1]) + modbinpow(val);
                } else {
                    int idx = i - maxIndex2;
                    int val = (idx >= 0) ? p1[idx] : 0;
                    res = modbinpow(p2[maxIndex2]) + modbinpow(val);
                }
            } else {
                int idx1 = i - maxIndex1;
                int idx2 = i - maxIndex2;
                int val1 = (idx1 >= 0) ? p2[idx1] : 0;
                int val2 = (idx2 >= 0) ? p1[idx2] : 0;
                res = modbinpow(p1[maxIndex1]) + modbinpow(max(val1, val2));
            }

            r[i] = res % MOD;
        }

        for(int i=0; i<n; i++) cout<<r[i]<<" ";
        cout<<endl;
    }
}