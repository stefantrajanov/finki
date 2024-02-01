import java.util.Arrays;
import java.util.HashSet;

public class NumberOfDistincIntegers {
    public static void main(String[] args) {
        int[] nums = {1,13,10,12,31};

        StringBuilder builder = new StringBuilder();
        HashSet<Integer> map = new HashSet<>();

        for (int number : nums) {
            builder.append(number + ",");
            map.add(number);
        }

        String[] split = builder.reverse().deleteCharAt(0).toString().split(",");

        for (String element : split) {
            map.add(Integer.parseInt(element));
        }

        System.out.println(map.size());
    }
}

class SolutionNumberOfDistincIntegers {
    public int countDistinctIntegers(int[] nums) {
        StringBuilder builder = new StringBuilder();
        HashSet<Integer> map = new HashSet<>();

        for (int number : nums) {
            builder.append(number + ",");
            map.add(number);
        }

        String[] split = builder.reverse().deleteCharAt(0).toString().split(",");

        for (String element : split) {
            map.add(Integer.parseInt(element));
        }

        return map.size();
    }
}
//2442. Count Number of Distinct Integers After Reverse Operations