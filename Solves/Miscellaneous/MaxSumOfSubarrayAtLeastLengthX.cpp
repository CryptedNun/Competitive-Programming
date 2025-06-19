//? We are given an array of length n.
//? We are to find the maximum possible floored average acquired from a subarray of length at least x

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

bool doesSubArrayExist(vector<int> source, int target, int size) {
    vector<long long> prefixSum;
    long long sum = 0;
    for(int i=0; i<source.size(); i++) {
        sum += (source[i] - target);
        prefixSum.push_back(sum);
    }

    long long minimum = 0;
    for(int i=size-1; i<prefixSum.size(); i++) {
        if(prefixSum[i] >= minimum) 
            return true;
        minimum = min(minimum, prefixSum[i-(size-1)]);
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin>>n>>x;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    int answer;

    int left = *min_element(v.begin(), v.end());
    int right = *max_element(v.begin(), v.end());
    int mid;
    while(left <= right) {
        mid = left + (right-left)/2;
        bool condition = doesSubArrayExist(v, mid, x);

        if(condition) {
            answer = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    cout<<answer<<endl;
}

//! Divide into two major sub-parts:

//* 1: Finding the Binary Search Space and its Monotonous Predicate:
//? The possible average sum candidates are within the range [a_min, a_max], all integers.
//? We can see if we can do binary search in this space.

//? 1.1: Proposing The Monotonous Predicate within range [a_min, a_max]: 
//? Goal: We want to find a subarray that has floored average of value m or greater. {a_min <= m <= a_max}
//?     If there is no such subarray, then we can conclude that getting floored average sum greater than or equal to m is impossible
//?     BUT if there is such a subarray, then we can also conclude that getting a floored average sum LESS THAN m is possible. But we are looking for MAXIMUM.
//?     THEREFORE, if we find such a subarray, we can discard looking for subarrays with average less than m. We want maximum, so we are not worried about them.
//?     IF WE DON'T, we can discard looking for subarrays with average greater than m. Because they don't exist.

//? Conclusion: Do Binary Search between [a_min, a_max], and look for a subarray that has average value between this range.

//* 2: Looking for the target subarray:
//? We can start calculating the sum and then the average of each possible subarray
//? We can use sliding window and prefix sum array to calculate the sum of a window in O(1) time.
//? prefix[r] - prefix[l-1] = sum of a window between l and r. {Which we want to find whether its average is equal to m or greater}
//? Even then, the rigorous method for this is O(n^2), because we are trying to find all possible subarrays, which is too big for large inputs.
//? HOWEVER, NOTICE that we want to FIND WHETHER such a subarray exists or not! We should not be worried about the calculation too much.

//? 2.1: The Mathematical Intuition:
//? Goal: Finding the subarray with average at least m.
//?     The Average Sum = All Elements within window/number of elements {Which we want to search if it's possible to be >= m}
//?     So the search condition is: All Elements sum within window/number of elements >= m;
//?                                 All Elements sum >= (# of elements)*m;
//?                                 All Elements sum - (# of elements)*m >= 0;
//?                                 (Each Element - m) + (...) + (...) >= 0;
//?     So notice, we transformed the search condition to check whether a sum of new elements is non-negative. Where these new elements are all the previous elements of the window just subtracted by m.
//?     We can now do prefix sum here, this new prefix sum array will be of the whole array shifted back by m.
//?     Then we can write the new sum form as:
//?                                 PrefixNew[r] - PrefixNew[l-1] >= 0;  ---(*)
//?                                 PrefixNew[r] >= PrefixNew[l-1];
//? Now NOTICE, that the lesser the PrefixNew[l-1], the more the sum will be. 
//? THIS IS THE TRICK, to transform the O(n^2) time to O(n), since we only want to check for the LEAST possible PrefixNew[l-1] for a given r.
//? So we maintain a least possible PrefixNew[l-1] for each r, and then iterate over all r in the new subarray.