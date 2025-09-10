#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string s;
        cin>>s;


        int i=n-1;
        while(s[i] == '1') i--;

        int numberOf1s = 0;
        for(int j = i; j>=0; j--) {
            if(s[j] == '1') numberOf1s++;
        }
        
        int ans = 0;
        for(int k=1; k<=numberOf1s; k++) {
            if(s[i] == '0') ans++;
            i--;
        }

        cout<<ans<<endl;
    }
}