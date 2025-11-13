// ! Method of Mapping: Source --> Destination
#include <bits/stdc++.h>
using namespace std;

// * Permute function: O(n) where n is the size of the input array.
vector<int> permute(vector<int> source, vector<int> permutation) {
    int size = source.size();
    vector<int> result(size);

    for(int i=0; i<size; i++) {
        result[i] = source[permutation[i]];
    }

    return result;
}

// * Repeated Permute function: O(nlogm) where n is the array size and m is the number.
vector<int> repeatedPermute(vector<int> source, vector<int> permutation, int number) {
    while(number > 0) {
        if(number&1) source = permute(source, permutation);
        permutation = permute(permutation, permutation);
        number >>= 1;
    }

    return source;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        vector<int> arr(n);
        vector<int> perm(n);

        for(int i=0; i<n; i++) {
            arr[i] = i+1;
            if(i < n/2) perm[i] = (2*i + 1) - 1;    // ! -1 offset for 0-based indexing
            else perm[i] = 2*(i - n/2 + 1) - 1;     // ! -1 offset for 0-based indexing
        }

        vector<int> result = repeatedPermute(arr, perm, k);
        for(int& num: result) cout<<num<<" ";
        cout<<endl;
    }
}