import java.util.List;

public class SubArrayDistinctElements {
}

class SolutionSubArrayDistinctElements {

    public long factorial(int number){
        long product = 1;
        for (int i = 1; i <= number; i++) {
            product *= i;
        }

        return product;
    }
    public int sumCounts(List<Integer> nums) {
        int sum = 0;
        for (int i = 1; i <= nums.size(); i++) {
            long result = (factorial(nums.size()) / factorial(nums.size() - i));

            sum += (int)(Math.pow(i, 2) * result);
        }

        return 0;
    }
}