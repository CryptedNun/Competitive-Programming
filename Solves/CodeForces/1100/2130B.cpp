#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n, s; cin>>n>>s;
        unordered_map<int, int> given;
        int sum = 0;
        for(int i=0; i<n; i++) {
            int input; cin>>input;
            sum += input;
            given[input]++;
        }

        if(s < sum) {
            // impossible to get s in any way, since sum_a is just too big. So the default array in whatever permutation makes Bob win.

            while(given[0]--) cout<< 0 <<" ";
            while(given[2]--) cout<< 2 <<" ";
            while(given[1]--) cout<< 1 <<" ";
            cout<<endl;
            
        } else if(s == sum) {
            // default array, whatever permutation makes Alice win. Impossible for Bob.

            cout<< -1 <<endl;
        } else if(s - sum == 1) {
            // block all 0, 1 instances by putting 2 in the middle [Main challenge]
            // This is actually quite trivial, just get all 0s at first, then putting at least one 2 is necessary afterwards, then put all 1s.
            
            while(given[0]--) cout<< 0 <<" ";
            while(given[2]--) cout<< 2 <<" ";
            while(given[1]--) cout<< 1 <<" ";
            cout<<endl;
        } else {
            // impossible for Bob
            
            cout<< -1 <<endl;
        }
    }
}