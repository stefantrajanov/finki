public class StepCost {

    public int minCostClimbingStairs(int[] cost) {
        int sum = 0;
        for (int i = cost.length - 1; i > 0; i--) {
            int current = cost[i];
            int next = cost[i - 1];

            if (current < next){
                sum += current;
            }else {
                sum += next;
                i--;
            }
        }

        int secondSum = 0;
        for (int i = 0; i < cost.length - 1; i++) {
            int current = cost[i];
            int next = cost[i + 1];

            if (current < next){
                secondSum += current;
            }else {
                secondSum += next;
                i++;
            }
        }

        if (secondSum < sum){
            sum = secondSum;
        }

        return sum;
    }
}

