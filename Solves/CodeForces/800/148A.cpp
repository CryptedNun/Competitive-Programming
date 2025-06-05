// ! Concept: Sieve of Eratosthenes

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr(4);
    for(int i=0; i<4; i++) cin>>arr[i];

    int d; cin>>d;
    vector<bool> harm_status(d+1, false);

    for(int i=0; i<4; i++) {
        harm_status[arr[i]] = true;

        for(int j=2; j*arr[i]<=d; j++)          
            harm_status[j*arr[i]] = true;
    }

    int sum = 0;
    for(int i=1; i<=d; i++) {
        if(harm_status[i] == true) sum++;
    }

    cout<<sum<<endl;
}