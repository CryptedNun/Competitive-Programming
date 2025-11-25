#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);  
        for(int i = 0; i < n; i++) cin >> a[i];

        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++) freq[a[i]]++;

        int answer = 0;
        for(auto& [key, count] : freq) {
            if(count < key) answer += count;
            else if(count > key) answer += count - key;
        }

        cout << answer << endl;
    }
}