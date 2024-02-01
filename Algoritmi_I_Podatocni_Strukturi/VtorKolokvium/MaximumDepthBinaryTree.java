import java.util.Stack;

public class MaximumDepthBinaryTree {
}

class SolutionMaximumDepthBinaryTree {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int maxLeft = maxDepth(root.left);
        int maxRigt = maxDepth(root.right);

        return Math.max(maxLeft, maxRigt) + 1;
    }
}