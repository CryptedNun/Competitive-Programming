#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> vec, int k);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];

        if(check(v, k)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

bool check(vector<int> vec, int k) {
    int n = vec.size();
    vector<int> b(n);
    vector<int> bPref(n);
    vector<int> bSuff(n);

    //! b-array
    for (int i=0; i<n; i++) {
        if(vec[i] <= k) b[i] = 1;
        else b[i] = -1;
    }

    bPref[0] = b[0];
    for(int i=1; i<n; i++) {
        bPref[i] = bPref[i-1] + b[i];
    }

    bSuff[n-1] = b[n-1];
    for(int i=n-2; i>=0; i--) {
        bSuff[i] = bSuff[i+1] + b[i];
    }

    // Case 1: First two 
    int minPref = bPref[0] >= 0 ? bPref[0] : INT_MAX;
    for(int r=1; r<n; r++) {
        if(minPref != INT_MAX) {
            if(bPref[r] - minPref >= 0) {
                return true;
            }
        } 
        if(bPref[r] >=0 && bPref[r] < minPref) {
            minPref = bPref[r];
        }
    }

    // Case 2: Last Two
    int minSuff = bSuff[n-1] >= 0 ? bSuff[n-1] : INT_MAX;
    for(int r = n-2; r>=0; r--) {
        if(minSuff != INT_MAX) {
            if(bSuff[r] - minSuff >= 0) {
                return true;
            }
        }
        if(bSuff[r] >= 0 && bSuff[r] < minSuff) {
            minSuff = bSuff[r];
        }
    }

    // Case 3: First+Last
    //Check suff+pref earliest occ.
    int left = -1, right = -1;
    for(int i=0; i<n; i++) {
        if(bPref[i] >= 0) {
            left = i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--) {
        if(bSuff[i] >= 0) {
            right = i;
            break;
        }
    }
    if(left < right && (left != -1 && right != -1)) return true;
    return false;
}