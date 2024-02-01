import java.util.HashMap;

public class NumberOfArithmeticTriplets {
    public static void main(String[] args) {
        int diff = 1;
        int[] nums = {0,1,2};

        HashMap<Integer, Integer> map = new HashMap<>();
        HashMap<Integer, Integer> higher = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] <= diff){
                for (int j = i + 1; j < nums.length; j++) {
                    if (nums[j] - nums[i] == diff){
                        map.put(i, j);
                    }
                }
            }else{
                for (int j = i + 1; j < nums.length; j++) {
                    if (nums[j] - nums[i] == diff){
                        higher.put(i, j);
                    }
                }
            }
        }
        int counter = 0;

        for (int value : map.values()) {
            if (higher.containsKey(value)){
                counter++;
            }
        }

        for (int value : higher.values()) {
            if (higher.containsKey(value)){
                counter++;
            }
        }

        for (int value : map.values()) {
            if (map.containsKey(value)){
                counter++;
            }
        }

        System.out.println(counter);
        System.out.println(map.toString());
        System.out.println(higher.toString());
    }
}


class SolutionNumberOfArithmeticTriplets {
    public int arithmeticTriplets(int[] nums, int diff) {
        HashMap<Integer, Integer> map = new HashMap<>();
        HashMap<Integer, Integer> higher = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] <= diff){
                for (int j = i + 1; j < nums.length; j++) {
                    if (nums[j] - nums[i] == diff){
                        map.put(i, j);
                    }
                }
            }else{
                for (int j = i + 1; j < nums.length; j++) {
                    if (nums[j] - nums[i] == diff){
                        higher.put(i, j);
                    }
                }
            }
        }
        int counter = 0;

        for (int value : map.values()) {
            if (higher.containsKey(value)){
                counter++;
            }
        }

        for (int value : higher.values()) {
            if (higher.containsKey(value)){
                counter++;
            }
        }

        for (int value : map.values()) {
            if (map.containsKey(value)){
                counter++;
            }
        }

        return counter;
    }
}
//2367. Number of Arithmetic Triplets