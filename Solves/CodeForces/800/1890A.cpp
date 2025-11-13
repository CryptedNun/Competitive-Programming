#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a;
        unordered_map<int, int> freq;
        int uniqueElements = 0;
        for(int i = 0; i < n; i++) {
            int input; cin >> input;
            if(freq[input] == 0) a.push_back(input), uniqueElements++;
            freq[input]++;
        }
        
        if(uniqueElements > 2) cout << "NO" << endl;
        else {
            if(uniqueElements == 1) cout << "YES" << endl;
            else {
                if(n % 2 == 0) {
                    if(freq[a[0]] == n/2 && freq[a[1]] == n/2) cout << "YES" << endl;
                    else cout << "NO" << endl;
                } else {
                    if(freq[a[0]] == n/2 && freq[a[1]] == n/2 + 1) cout << "YES" << endl;
                    else if(freq[a[0]] == n/2 + 1 && freq[a[1]] == n/2) cout << "YES" << endl;
                    else cout << "NO" << endl;
                }
            }  
        }
    }
}