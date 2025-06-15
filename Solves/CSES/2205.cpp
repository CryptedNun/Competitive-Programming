#include <bits/stdc++.h>
using namespace std;

int g (int n) {
    return n ^ (n >> 1);
}
    
string toBinary(int x, int bits) {
    string res;
    for (int i = bits - 1; i >= 0; --i) 
        res += ((x >> i) & 1) ? '1' : '0';

    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    int var = 1;
    for(int i=1; i<=n; i++) var*=2;
    
    for(int i=0; i<var; i++) cout<<toBinary(g(i), n)<<endl;
}