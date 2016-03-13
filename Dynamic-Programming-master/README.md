# DP

####In stock IV
    DP is used to calculate the max profit of the k times of trasaction
    Below is how we use DP to solve the problem:
    buys[j] =  max(buys[j],  sells[j-1] - prices[i]);
    sells[j]=  max(sells[j], buys[j] + prices[i]);
