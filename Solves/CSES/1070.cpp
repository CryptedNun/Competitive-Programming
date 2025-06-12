#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    if(n <= 3 && n != 1) {
        cout<<"NO SOLUTION";
    } else {
        for(int copy = n-1; copy > 0; copy -= 2) {
            cout<<copy<<" ";
        }

        for(int copy = n; copy > 0; copy -= 2) {
            cout<<copy<<" ";
        }
    }
}