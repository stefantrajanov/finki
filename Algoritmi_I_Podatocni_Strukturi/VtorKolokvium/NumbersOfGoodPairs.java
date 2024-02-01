import java.util.HashMap;
import java.util.Map;

public class NumbersOfGoodPairs {
}


class SolutionForNumbersOfGoodPairs {
//    public int numIdenticalPairs(int[] nums) {
//        int counter = 0;
//
//        for (int i = 0; i < nums.length; i++) {
//            for (int j = 0; j < nums.length; j++) {
//                if (nums[i] == nums[j] && i < j){
//                    counter++;
//                }
//            }
//        }
//
//        return counter;
//    }

    public int numIdenticalPairs(int[] nums) {
        Map<Integer, Integer> numFreqMp = new HashMap<>();
        int answer = 0;
        for(var num : nums){
            answer += numFreqMp.getOrDefault(num, 0);
            numFreqMp.put(num, numFreqMp.getOrDefault(num, 0) + 1);
        }
        return answer;
    }
}

//1512 Number of Good Pairs