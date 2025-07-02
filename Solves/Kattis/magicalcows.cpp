//? A very standard DP Problem, a must-try for beginners to do on their own.
//! Time Complexity: O(m*n)

#include <bits/stdc++.h>
using namespace std;

long long arr[50+1][1000+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, N, M; cin>>C>>N>>M;
    vector<int> cows(N);
    vector<int> days(M);
    for(int i=0; i<N; i++) cin>>cows[i];
    for(int i=0; i<M; i++) cin>>days[i];

    int maxDay = *max_element(days.begin(), days.end());
    for(int i=0; i<N; i++) {
        arr[0][cows[i]]++;
    }
    
    for(int i=0; i<maxDay; i++) {
        for(int j=1; j<=C; j++) {
            if(j <= C/2) {
                arr[i+1][2*j] += arr[i][j];
            } else {
                arr[i+1][j] += 2*arr[i][j];
            }
        }
    }

    vector<long long> result(M, 0);
    cout<<"\n";
    for(int i=0; i<M; i++) {
        for(int j=0; j<=C; j++) {
            result[i] += arr[days[i]][j];
        }
        cout<<result[i]<<endl;
    }
}