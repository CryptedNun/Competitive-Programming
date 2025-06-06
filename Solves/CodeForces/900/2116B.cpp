// ! Concept: Number Theory, Binary Exponentiation.

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

            long long a = p1[maxIndex1], b = p2[maxIndex2];
            int v1 = p2[i - maxIndex1];
            int v2 = p1[i - maxIndex2];

            long long res;
            if (a != b) {
                if (a > b) res = modbinpow(a) + modbinpow(v1);
                else res = modbinpow(b) + modbinpow(v2);
            } else {
                res = modbinpow(a) + modbinpow(max(v1, v2));
            }

            r[i] = res % MOD;
        }

        for(int i=0; i<n; i++) cout<<r[i]<<" ";
        cout<<endl;
    }
}