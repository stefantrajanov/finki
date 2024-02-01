import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class FindDuplicates {
}

class SolutionFindDuplicates {
    public List<Integer> findDuplicates(int[] nums) {
        HashSet<Integer> map = new HashSet<>();
        List<Integer> anwser = new ArrayList<>();
        for (int number : nums) {
            if (!map.add(number)){
                anwser.add(number);
            }
        }

        return anwser;
    }
}
//442. Find All Duplicates in an Array