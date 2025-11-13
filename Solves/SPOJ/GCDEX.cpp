#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
vector<long long> phi(MAX + 1);
vector<long long> T(MAX + 1);
vector<long long> DP(MAX + 1);

// Time complexity: O(MAXloglogMAX)
void fillPhi() {
    for(int i = 0; i <= MAX; i++) phi[i] = i;

    for(int i = 2; i <= MAX; i++) {
        if(phi[i] == i) {
            for(int j = i; j <= MAX; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

// Time complexity: O(MAXlogMAX + MAX{negligible})
void fillT() {
    T[0] = 0;
    for (int d = 1; d <= MAX; d++)
        for (int m = d; m <= MAX; m += d)
            T[m] += d * phi[m/d];
}

// Time complexity: O(MAX)
void fillDP() {
    DP[0] = 0;
    for(int i = 1; i <= MAX; i++) DP[i] = DP[i - 1] + T[i] - i;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    fillPhi();
    fillT();
    fillDP();

    while(true) {
        int n; cin >> n;
        if(!n) return 0;

        cout << DP[n] << endl;
    }
}