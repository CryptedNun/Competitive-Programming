#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int score = 0;
        for(int i=0; i<n; i++) {
            int input; cin>>input;
            score += input == 0 ? 1 : input;
        }
        cout<<score<<endl;
    }
}