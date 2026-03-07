// ! MRBP OVERTHINK KOM KOR

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> arr;
bool isPresent[1000000 + 10];
bool isArrChecked[3010];

void reconstruct(vector <int>& a) {
    vector<int> replacement;
    for(auto& e : a) if(!isPresent[e]) replacement.push_back(e);

    a = replacement;
}

void solve() {
    memset(isPresent, false, sizeof(isPresent));
    memset(isArrChecked, false, sizeof(isArrChecked));

    int n; cin >> n; arr.resize(n);

    for(auto& a : arr) {
        int l; cin >> l; a.resize(l);
        for(auto& e : a) cin >> e;

        // ! only LAST OCC of each elem in original arr matters, last occ in original = first occ in reversed
        reverse(a.begin(), a.end());
        vector<int> replacement;
        for(auto& e : a) 
            if(!isPresent[e]) { 
                replacement.push_back(e);
                isPresent[e] = true;
            }
        for(auto& e : replacement) isPresent[e] = false;

        a = replacement;
    }


    vector<int> ans;
    for(int i = 0; i < n; i++) {
        // ! 1. GET LEXICO SMALLEST ARR
        int lexico_smallest = 0;
        while(isArrChecked[lexico_smallest]) lexico_smallest++;

        for(int j = 0; j < n; j++) 
            if(!isArrChecked[j] && arr[j] < arr[lexico_smallest]) 
                lexico_smallest = j;
        
        // ! 2. APPEND LEXICO_SMALLEST ARR TO ANS, MARK IT AS CHECKED, WHILE APPENDING, MARK SEEN ELEMS AS SEEN(isPresent[e] = true)
        for(auto& e : arr[lexico_smallest]) {
            ans.push_back(e);
            isPresent[e] = true;
        }
        isArrChecked[lexico_smallest] = true;

        // ! 3. RECONSTRUCT EACH ARR INPLACE, REMOVE ELEMS ALREADY SEEN BEFORE
        for(int j = 0; j < n; j++)
            if(!isArrChecked[j])
                reconstruct(arr[j]);
    }

    for(auto& e : ans) cout << e << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}