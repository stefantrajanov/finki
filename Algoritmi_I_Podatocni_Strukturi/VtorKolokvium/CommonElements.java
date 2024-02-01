import java.util.HashSet;

public class CommonElements {
}

class SolutionCommonElements {
    public int[] findIntersectionValues(int[] nums1, int[] nums2) {
        HashSet<Integer> set1 = new HashSet<>();
        HashSet<Integer> set2 = new HashSet<>();

        int counter1 = 0;
        int counter2 = 0;

        for (int number : nums1) {
           set1.add(number);
        }

        for (int number : nums2) {
           set2.add(number);
        }

        for (int number : nums1) {
            if (set2.contains(number)){
                counter1++;
            }
        }

        for (int number : nums2) {
            if (set1.contains(number)){
                counter2++;
            }
        }


        return new int[]{counter1, counter2};
    }
}

//2956. Find Common Elements Between Two Arrays