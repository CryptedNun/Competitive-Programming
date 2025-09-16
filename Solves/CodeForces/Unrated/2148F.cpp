#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<vector<int>> a(n);
        for(auto& vec : a) {
            int k; cin>>k;
            vec.resize(k);
            for(auto& element : vec) cin>>element;
        }

        sort(a.begin(), a.end(), [](vector<int>& a, vector<int>& b) {
            return a.size() < b.size();
        });

        int m = a.back().size();
        vector<int> ans(m, 1e9);
        vector<pair<int, int>> blocks;
        
        for(int i=0; i<n; i++) {
            if(i==0) blocks.push_back(make_pair(0, a[i].size() - 1));
            else if(a[i].size() > a[i-1].size()) blocks.push_back(make_pair(a[i-1].size(), a[i].size() - 1));
            
            int k = a[i].size();
            int startingBlockIdx = -1;

            for(int j=0; j < blocks.size(); j++) {
                int l = blocks[j].first, r = blocks[j].second;
                for(int p=l; p<=r; p++) {
                    if(ans[p] < a[i][p]) break;
                    if(ans[p] > a[i][p]) {startingBlockIdx = j; break;}
                }
                if(startingBlockIdx != -1) break;
            }

            if(startingBlockIdx != -1) {
                for(int idx = blocks[startingBlockIdx].first; idx < k; idx++) {
                    ans[idx] = a[i][idx];
                }
                blocks[startingBlockIdx].second = k-1;
                while(blocks.back().first != blocks[startingBlockIdx].first || blocks.back().second != blocks[startingBlockIdx].second) blocks.pop_back();
                // while(! (blockback.first == block_i.first && blockback.second == block_i.second)) 
                // Essentially De-Morgan's Law
            }
        }

        for(auto& answer : ans) cout<<answer<<" ";
        cout<<endl;
    }
}