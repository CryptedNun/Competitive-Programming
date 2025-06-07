#include <bits/stdc++.h>
using namespace std;
vector<int> permute(vector<int> source, vector<int> permutation);
vector<int> repeatedPermute(vector<int> source, vector<int> permutation, int number);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin>>n>>k;
    vector<int> arr(n), permutation(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n; i++) cin>>permutation[i];

    vector<int> result = repeatedPermute(arr, permutation, k);
    for(int& num: result) cout<<num<<" ";
}

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

// ! Method of Mapping: Source --> Destination
// ! Permutation Array Element = Source Index
// ! Permutation Array Index   = Destination Index