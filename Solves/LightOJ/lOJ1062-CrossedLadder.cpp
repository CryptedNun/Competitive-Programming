#include <bits/stdc++.h>
using namespace std;

double func(double x, double y, double c, double w) {
    double firstTerm = 1/sqrt(x*x - w*w);
   double secondTerm = 1/sqrt(y*y - w*w);
   double thirdTerm = 1/c;

   return firstTerm + secondTerm - thirdTerm;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double epsilon = 1e-10;
    int t; cin>>t;
    for(int i=1; i<=t; i++) {
        double x, y, c; cin>>x>>y>>c;

        double left = 0;
        double right = min(x, y);
        double w, answer;

        //! This loop condition ensures the error margin is at most epsilon, making w accurate upto 9~10 decimal points (1e-10)
        while(right - left > epsilon) {
            w = left + (right - left)/2;
            answer = func(x, y, c, w);

            if(answer < 0) left = w;
            else right = w;
        }

        cout<<"Case "<<i<<": "<<fixed<<setprecision(10)<<w<<endl;
    }
}