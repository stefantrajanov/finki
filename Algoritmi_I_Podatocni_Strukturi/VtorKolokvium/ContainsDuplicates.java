import java.util.HashSet;

public class ContainsDuplicates {
}

class SolutionContainsDuplicates {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> check = new HashSet<>();

        for (int num : nums) {
            if (!check.add(num)){
                return true;
            }
        }

        return false;
    }
}
//217. Contains Duplicate