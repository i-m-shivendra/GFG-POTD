class Solution {
   public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        //tc ->o(nlogn) sc->o(1)
        //min_amount ->k=2  any 2 maximum candies can take
        int buy=0;
        int free=prices.size()-1;
        sort(prices.begin(),prices.end());
        int min_price=0;
        while(buy<=free){
            min_price+=prices[buy];
            buy++;
            free-=k;
            
        }
        //buy in max_price and cancel the min_price of k [priced candies from beginning]to buy with max price
        buy=prices.size()-1;
        free=0;
        int max_price=0;
        while(free<=buy){
            max_price+=prices[buy];
            buy--;
            free+=k;
        }
        return {min_price,max_price};
    }
};