#include <bits/stdc++.h>
using namespace std;

long long binpow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)
            result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int k;
        long long x; 
        cin>>k>>x;
        if(x == 0 || binpow(2, k) == x) {
            cout<<0<<endl;
            continue;
        }

        pair<long long, long long> start = make_pair(binpow(2, k), binpow(2, k));
        pair<long long, long long> target = make_pair(x, binpow(2, k+1) - x);
        // (2^k, 2^k) -> (x, 2^k+1 - x)

        vector<int> moveSet;
        while(target.first != start.first) {
            if(target.first < target.second) {
                moveSet.push_back(1);
                target.second -= target.first;
                target.first *= 2;
            } else {
                moveSet.push_back(2);
                target.first -= target.second;
                target.second *= 2;
            }
        }

        reverse(moveSet.begin(), moveSet.end());
        cout<<moveSet.size()<<endl;
        for(int x : moveSet) cout<<x<<" ";
        cout<<endl;
    }
}