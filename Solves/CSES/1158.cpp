#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin>>n>>x;
    vector<pair<int, int>> pricepage(n);
    for(int i=0; i<n; i++) cin>>pricepage[i].first;
    for(int i=0; i<n; i++) cin>>pricepage[i].second;

    // dp[i][j] = max pages I can get, with using first i many books, with price less than or equal to j
    // We want dp[n][x]
    // base case dp[0][j] = dp[i][0] = 0 for all j and i respectively
    
    // dp[j] = max pages achieved with at least x money
    // we want dp[x]
    // initially all dp elements will be 0 {No books purchased yet}

    // DP Transition: Let's assume we want to know dp[i], meaning max pages with budget-price less than or equal to i 
    // Then, when checking for books for that budget, we need to know if we pick a specific book for that or not, then break it to smaller problems as such
    // Case - Not picking a book of index j: Then, the dp[i] value remains as is, considering we calculated for the books before index j
    // Case - Picking book of index j: Then price_j <= i since we cannot afford a book with price above budget i, 
    // Considering these two cases, dp[i] = max(dp[i], dp[i - price_j] + pages_j); for all j such that price_j <= i
    // Meaning, we pick the max value of dp[i], dp[i - price_j] + pages_j for all j such that price_j <= i

    // Notice one condition, that once one specific book is chosen, it cannot used again.
    // That means we need to iterate the loop and structure the code such that one book is used only once
    // for getting the dp[] value
    // in this case, if the inner loop ran thru the books and the outer thru the budget, then we have a risk of choosing one book
    // more than once, then we have a risk of choosing a same book in more than once in dp[] value

    // for example: we have two books with price 2 page 10, price 3 page 20
    //              outerloop(budget:= 1->x)
    //              innerloop(books:= book_1 to book_n)
    // when budget = 2, then dp[2] = max(dp[budget], dp[budget-2] + 10) = 10
    // then when budget = 4, dp[4] = max(dp[budget], dp[budget-2] + 10) = 20 {LOOK, BOOK WITH PRICE = 2 CONSIDERED TWICE FOR dp[4]}

    // hence, outerloop will iterate thru books, innerloop thru budgets.
    // Then, also one point is that the budgets will go from higher to lower. From lower to higher has the same risk of overcount
    // suppose I am at an outer loop iteration where book price = 2, page 10, no other book has price 1 2 3 or 4
    // then dp[2] = 10,
    // then we go to dp[4] = max(dp[4] = 0, dp[4 - 2] + 10 = 20) = 20 {Price = 2 book overcounted again}
    // if we went higher -> lower, then dp[4] = max(dp[4], dp[4-2] + 10) = 10
    // dp[2] = max(dp[2], dp[2-2] + 10) = 10 

    // ! This seems really counter-intuitive, since we are breaking the problem into smaller problems, 
    // ! it's only natural to refer to the smaller problem that's readily calculated, but here the code structure is not immediately intuitive
    
    long long dp[x+1];
    for(int i=0; i<=x; i++) dp[i] = 0;
    for(int i=0; i<n; i++) {
        for(int j=x; j>=pricepage[i].first; j--) {
            dp[j] = max(dp[j], dp[j - pricepage[i].first] + pricepage[i].second);
        }
    }

    cout<<dp[x]<<endl;
}