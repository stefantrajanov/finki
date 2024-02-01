import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class KthSmallestValue {
}
class SolutionKthSmallestValue {
    public void helper(TreeNode root, List<Integer> list){
        if (root == null){
            return;
        }
        list.add(root.val);
        helper(root.left, list);
        helper(root.right, list);
    }
    public int kthSmallest(TreeNode root, int k) {
        List<Integer> list = new ArrayList<>();
        helper(root, list);
        Collections.sort(list);

        return list.get(k - 1);
    }
}