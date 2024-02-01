public class StockSellBuy {
    public int maxProfit(int[] prices) {
        int max = 0;

        for (int i = 0; i < prices.length; i++) {
            int current = prices[i];
            for (int j = i + 1; j < prices.length; j++) {
                if ((prices[j] - current) < 0){
                    break;
                }

                if (max < prices[j] - current){
                    max = prices[j] - current;
                }
            }
        }

        return max;
    }
}
