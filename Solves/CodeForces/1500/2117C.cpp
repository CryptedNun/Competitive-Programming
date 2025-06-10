// ! O(n), fastest possible method without using sets which causes a logn overhead
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> v(n);
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++) {
            cin>>v[i];
            freq[v[i]]++;
        }

        int segment = 1;
        int distinctElementPrev = 1;
        int distinctElementCurr = 0;
        unordered_map<int, int> prev, curr;
        prev[v[0]]++;

        for(int i=1; i<n; i++) {
            if(curr.find(v[i]) == curr.end()) {
                curr[v[i]]++;
                distinctElementCurr++;
            }
            

            if(prev.find(v[i]) != prev.end() && prev[v[i]] != 0) {
                prev[v[i]]--;
                if(prev[v[i]] == 0) distinctElementPrev--;
            }

            if(distinctElementPrev == 0) {
                segment++;

                swap(distinctElementPrev, distinctElementCurr);

                swap(prev, curr);
                curr.clear();
            }

        }

        cout<<segment<<endl;
    }
}