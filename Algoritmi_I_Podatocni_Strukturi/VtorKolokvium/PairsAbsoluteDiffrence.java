public class PairsAbsoluteDiffrence {
}

class SolutionPairsAbsoluteDiffrence {
    public int countKDifference(int[] nums, int k) {
        int counter = 0;

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (Math.abs(nums[j] - nums[i]) == k){
                    counter++;
                }
            }
        }

        return counter;
    }
}

//2006. Count Number of Pairs With Absolute Difference K