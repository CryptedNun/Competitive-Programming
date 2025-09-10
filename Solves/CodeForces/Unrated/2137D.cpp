#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> b(n);
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++) {
            cin>>b[i];
            freq[b[i]]++;
        }

        // ! Check if it's possible:
        // Too lazy to optimize this, although it's possible and recommended
        bool isPossible = true;
        for(int i=0; i<n; i++) 
            if(freq[b[i]] % b[i] != 0) {
                isPossible = false;
                break;
            }
        if(!isPossible) {
            cout<<-1<<endl;
            continue;
        }
        // -------------------------

        vector<bool> isMarked(n+1, false); // serves as knowing whether a freq b_i is marked, isMarked[b[i]] = T/F
        vector<vector<int>> indexList(n+1);
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            indexList[b[i]].push_back(i);
        }

        
        for(int i=0, currElement = 1; i<n; i++) {
            if(!isMarked[b[i]]) {
                int count = 0;
                for(int idx : indexList[b[i]]) {
                    ans[idx] = currElement;
                    count++;
                    if(count % b[i] == 0) currElement++;
                }
                isMarked[b[i]] = true;
            }
        }

        for(int i=0; i<n; i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}