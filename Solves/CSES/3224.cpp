#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(auto& elem : arr) cin >> elem;

    set<pair<int, int>> freqpair; // {freq, -elem}
    map<int, int> freq; // {elemt, freq}

    // window init
    int l = 0, r = l + k - 1;
    for(int i = l; i <= r; i++) freq[arr[i]]++;
    for(auto& pair : freq) freqpair.insert(make_pair(pair.second, -pair.first));
    cout << -freqpair.rbegin() -> second << ' ';
    l++, r++;
    
    while(r < n) {
        freqpair.erase({freq[arr[l - 1]]--, -arr[l - 1]});
        freqpair.insert({freq[arr[l - 1]], -arr[l - 1]});

        freqpair.erase({freq[arr[r]]++, -arr[r]});
        freqpair.insert({freq[arr[r]], -arr[r]});

        cout << -freqpair.rbegin() -> second << ' ';
        l++, r++;
    }

    return 0;
}