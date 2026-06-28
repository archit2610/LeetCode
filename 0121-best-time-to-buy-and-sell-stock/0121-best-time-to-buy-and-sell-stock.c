int maxProfit(int* prices, int pricesSize) {
    int low = prices[0];
    int maxProfit = 0;
    for (int i = 0;i < pricesSize;++i){
        if (prices[i] < low){
            low = prices[i];
        }
        int temp = prices[i] - low;
        if (temp > maxProfit){
            maxProfit = temp;
        }
    }
    return maxProfit;

}