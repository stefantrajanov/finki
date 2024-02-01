import java.util.ArrayList;
import java.util.List;

public class LeafValueSequence {
}

class SolutionLeafValueSequence {

    private void getSequence(TreeNode root, List<Integer> builder){
        if (root == null){
            return;
        }

        if (root.left == null && root.right == null){
            builder.add(root.val);
        }
        getSequence(root.left, builder);
        getSequence(root.right, builder);
    }
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> first = new ArrayList<>();
        List<Integer>  second = new ArrayList<>();
        getSequence(root1, first);
        getSequence(root2, second);
        System.out.println(first);
        System.out.println(second);

        return first.toString().compareTo(second.toString()) == 0;
    }
}