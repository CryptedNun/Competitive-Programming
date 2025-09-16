#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        int numberOf1s = 0, numberOf0s = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '0') numberOf0s++;  
            else numberOf1s++;
        }

        if(numberOf1s == numberOf0s) {
            cout<<0<<endl;
        }
        else {
            // the lesser frequent bit is the limiting bit, as it'll not supply enough in the invertedBit
            // if lesserBitFrequency = fq, then we want the fq+1 - th occurence of that bit in invertedBit
            // OR we can say we want that bit's invert, but fq+1 - th occ in the original string
            
            for(int i=0; i<s.size(); i++) {
                if(numberOf1s != 0 && s[i] == '0') numberOf1s--;
                else if(numberOf0s != 0 && s[i] == '1') numberOf0s--;
                else {cout<< s.size() - i <<endl; break;}
            }
        }
    }
}