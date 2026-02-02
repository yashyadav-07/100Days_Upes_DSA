#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int profit = 0;

    for (int i = 1; i < pricesSize; i++) {
        profit = MAX(profit, prices[i] - minPrice);
        minPrice = MIN(minPrice, prices[i]);
    }

    return profit;
}