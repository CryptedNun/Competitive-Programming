#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};
    
    // ways[i] = The number of COMBINATIONSSS possible to get sum upto i
    vector<int> ways(201, 0);
    ways[0] = 1;

    for(int coin : coins) {
        for(int i=coin; i<201; i++){
            ways[i] += ways[i-coin];
        }
    }

    cout<<ways[200]<<endl;
}