import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class InorderTraversal {
}
class SolutionInorderTraversal {
    public List<Integer> inorderTraversal(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        Stack<TreeNode> stack = new Stack<>();
        TreeNode current = root;
        List<Integer> list = new ArrayList<>();

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }

            current = stack.pop();
            list.add(current.val);
            current = current.right;
        }

        return list;
    }
}