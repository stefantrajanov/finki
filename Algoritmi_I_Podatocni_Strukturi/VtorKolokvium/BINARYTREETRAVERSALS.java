import java.util.Stack;

public class BINARYTREETRAVERSALS {
    public void inorderTraversalIterative(TreeNode root) {
        if (root == null) {
            return;
        }

        Stack<TreeNode> stack = new Stack<>();
        TreeNode current = root;

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }

            current = stack.pop();
            System.out.print(current.val + " ");
            current = current.right;
        }
    }

    public static void preorderTraversal(TreeNode root) {
        if (root == null) {
            return;
        }

        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode current = stack.pop();
            System.out.print(current.val + " ");

            // Push right child first, so it gets processed after left
            if (current.right != null) {
                stack.push(current.right);
            }

            // Push left child
            if (current.left != null) {
                stack.push(current.left);
            }
        }
    }

    public static void postorderTraversal(TreeNode root) {
        if (root == null) {
            return;
        }

        Stack<TreeNode> stack = new Stack<>();
        Stack<TreeNode> output = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode current = stack.pop();
            output.push(current);

            // Push left child first, so it gets processed after right
            if (current.left != null) {
                stack.push(current.left);
            }

            // Push right child
            if (current.right != null) {
                stack.push(current.right);
            }
        }

        while (!output.isEmpty()) {
            System.out.print(output.pop().val + " ");
        }
    }
}
