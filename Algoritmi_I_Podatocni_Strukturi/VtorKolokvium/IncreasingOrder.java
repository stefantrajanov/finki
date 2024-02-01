import com.sun.source.tree.Tree;

import java.util.*;

public class IncreasingOrder {
}

class SolutionIncreasingOrder {
    public TreeNode increasingBST(TreeNode root) {
        if (root == null){
            return null;
        }

        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        List<Integer> list = new ArrayList<>();

        while (!stack.isEmpty()){
            TreeNode current = stack.pop();
            list.add(current.val);

            if (current.right != null){
                stack.push(current.right);
            }

            if (current.left != null){
                stack.push(current.left);
            }
        }

        Collections.sort(list);

        TreeNode merged = new TreeNode(list.get(0));
        TreeNode root_safe = merged;

        for (int i = 1; i < list.size(); i++) {
            merged.right = new TreeNode(list.get(i));
            merged = merged.right;
        }

        return root_safe;
    }
}