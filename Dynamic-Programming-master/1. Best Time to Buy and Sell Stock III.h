/*
Design an algorithm to find the maximum profit. You may complete at most two transactions.

The maximum of if we've just buy 1st stock, if we've just sold 1nd stock, if we've just buy 2nd stock, if we've just sold 2nd stock. 
Very simple code too and work well. I have to say the logic is simple than those in Single Number II.



*/

#include "include.h"
//#define DEBUG

using namespace std;

class best_time_to_buy_and_sell_stock_III {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int sell1 = 0, sell2 = 0, buy1 = INT_MIN, buy2 = INT_MIN;
        for(int i = 0; i < n; i++) {
            buy1 =  max (buy1,   -prices[i]);     //max of -prices[i] will find the min of +prices[i]
            sell1 = max (sell1,  buy1 + prices[i]);
            buy2 =  max (buy2,   sell1 - prices[i]);  //here is to find the new buying point.
            sell2 = max (sell2,  buy2 + prices[i]);
#ifdef DEBUG
			cout<<"at "<<i<<" : "<<buy1<<" "<<sell1<<" "<<buy2<<" "<<sell2<<endl;
#endif
        }
        return sell2;
    }
	void test(){
		cout<<endl<<"In stock"<<endl;
		vector<int> input;
		input.push_back(1);
		input.push_back(2);
		//input.push_back(2);
		//input.push_back(0);
		//input.push_back(1);
		cout<<"result is: "<<maxProfit(input)<<endl;
	}
};
