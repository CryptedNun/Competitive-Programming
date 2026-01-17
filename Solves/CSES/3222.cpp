#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n ; i++) cin >> arr[i];

    map<int, int> freq;
    int dist = 0, l = 0, r = l + k -1;
    for(int i = l; i <= r; i++) if(++freq[arr[i]] == 1) dist++;
    cout << dist << " ";
    l++, r++;

    while(r < n) {
        if(--freq[arr[l - 1]] == 0) dist--;
        if(++freq[arr[r]] == 1) dist++;

        cout << dist << " ";
        l++, r++;
    }
}