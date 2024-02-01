public class HowManyNumbersAreSmaller {
}


class SolutionHowManyNumbersAreSmaller {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] counters = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (i != j){
                    if (nums[i] > nums[j]){
                        counters[i]++;
                    }
                }
            }
        }

        return counters;
    }
}