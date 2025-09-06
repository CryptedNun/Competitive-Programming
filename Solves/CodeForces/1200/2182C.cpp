#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> b(n);
        for(int i=0; i<n; i++) cin>>b[i];

        int minima = b[0];
        bool isPossible = true;
        for(int i=1; i<n; i++) {
            if(!(b[i] < 2*minima)) isPossible = false;
            minima = min(minima, b[i]); 
        }

        if(isPossible) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

/*
Calculation:
-   Suppose we successfully constructed the target array b,
    therefore on its last operation if we assume some number x was added to some a_i, which then became b_i, meaning b_i = a_i + x
    Therefore we can say that, x <= min(a_1, a_2,...a_i-1) == min(b_1, b_2... b_i-1) {Equal, because only a_i was operated on, the previous ones remain as is}
    
[   For realising this, notice that if there existed any smallest indexed element before b_i such that b_thatsmallestindex < x, then we couldn't operate as such.
    The contrapositive form: If we could operate as such, there existed no such element, or in other words,
                             If we could operate as such, for all b element before b_i, b >= x
    Then this conclusion can be written more compactly like this: x <= min(b_1, b_2... b_i-1)
    OR you can also say that since iff for all b before b_i, b >= x, then min(all b) >= x {DIY, it's easy and intuitive}
]

    Also, a_i < x {Required condition as per problem statement}
    Therefore, for b_i = a_i + x 
                       < x + x
                       < 2x 
                       < 2*min(b_1, b_2,...b_i-1) [Since x <= min(..)]
    this can be said for when x is added at any point while making the array, not just at the end.
    Hence proven that, if constructing an array b with thess conditions is possible, then for any b_i, b_i < 2*min(from b_1 to b_i-1)
    If from this deduction, we can prove that this implication is a biconditional, then we can verify easily assuming this conclusion as a hypothesis, that the construction of array b is possible

-   Now for proving the converse of this implication, let us assume the aforementioned implication's converse's hypothesis is true. 
    That is, if for each b_i, b_i < 2*min(from b_1 to b_i-1), then constructing the array b with the conditions is possible.
    Let's assume the very first operation when the array is initially all 0s, then we can easily add b_1,
    thereafter, when adding b_2, since b_2 < 2*min == 2*b_1
                                       b_2 - b_1 < b_1
    So we can operate with b_2 - b_1 first {Since b_2 - b_1 < b_1}, which puts it at the second index. Then we can add b_1.
    However, if b_2 - b_1 were less than 0, meaning b_2 < b_1, then we can directly add b_2 as per this condition.
    Now if we consider that from b_1 to b_i-1 is constructed, to add next b_i, 
    if b_i < min(all from 1 to i-1) then we can directly add b_i,
    otherwise, we know since b_i < 2*min(...) OR b_i - min < min, we can add first b_i - min, then we can add min, since min > b_i - min and min = minimum(from b_1 to b_i-1) so min cannot be added there.
    As per this procedure, we CAN construct the array from left to right, assuming the hypothesis as true. There it's proven.
*/