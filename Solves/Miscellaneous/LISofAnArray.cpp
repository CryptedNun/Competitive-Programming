// * Time Complexity: O(nlogn) for both length of LIS and the LIS itself.
// * If multiple LIS is possible, it gets the one with the least possible end element
// ? O(n) is possible for just getting the LIS length, but this is more practical as it gives the LIS itself as well (O(n) approach doesn't), and the difference is negligible in competitions

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    
    // arr[i] = the element in the original array, this element is the smallest ending element possible of an Increasing Subsequence (NOT LIS) of length i+1
    // arr1[i] = the index of an element in the original array, this element is the smallest ending element possible of an Increasing Subsequence (NOT LIS) of length i+1 
    // An array can have many increasing subsequences, this will keep track of the minimum possible element of an increasing subsequence of length i+1
    // arr2[i] = the index of an element in the original array, this element is the previous element of an Increasing Subsequence that ends with a[i] (If an IS is possible that ends with a[i], otherwise it stores -1)
    
    vector<int> arr, arr1, arr2(n, -1);
    for(int i=0; i<n; i++) {
        // We binary search for the lowerBound of a[i] in arr1, 'position' is the index of that lB in arr1
        int position = lower_bound(arr.begin(), arr.end(), a[i]) - arr.begin();

        // if its lB is NOT present (lower_bound returns .end() if so), we pushback add it to arr & arr1
        // NOTE: If arr1 is empty, then return is still .end() but it's the same as .begin()
        if(position >= arr.size()) {
            arr.push_back(a[i]);
            arr1.push_back(i);
        } 

        // Otherwise we replace the found lB with a[i] & i 
        else {
            arr[position] = a[i];
            arr1[position] = i;
        }

        if(position > 0) arr2[i] = arr1[position - 1];
    }

    // arr or arr1, whichever's length gives the LIS length, since the back of arr has the LIS's last int
    int LIS_length = arr1.size();
    cout<<LIS_length<<endl;

    // 'index' here, is the index of the element that ends the LIS of the given array a.
    int index = arr1.back();

    vector<int> LIS;
    LIS.push_back(a[index]);

    // arr2[i] stores the element's index, which is before the IS ended by a[i]
    // so now arr2[index] returns the index of the prev element of the LIS's last element
    // We keep looping, until arr2[index] returns -1, this backtracks the LIS at each step
    while(arr2[index] != -1) {
        LIS.push_back(a[arr2[index]]);
        index = arr2[index];
    }
    reverse(LIS.begin(), LIS.end());
    for(int num : LIS) cout<<num<<" ";
}