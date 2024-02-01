public class StringConstructionFromBinaryTree {
}

class SolutionStringConstructionFromBinaryTree {
    private void helper(TreeNode root, StringBuilder builder) {
        if (root == null) {
            return;
        }
        builder.append(root.val);

        if (root.left != null){
            builder.append("(");
            helper(root.left, builder);
            builder.append(")");
        }

        if (root.left == null && root.right != null){
            builder.append("()");
        }

        if (root.right != null){
            builder.append("(");
            helper(root.right, builder);
            builder.append(")");
        }
    }

    public String tree2str(TreeNode root) {
        StringBuilder string = new StringBuilder();
        helper(root, string);
//        string.deleteCharAt(0);
        return string.toString();
    }
}