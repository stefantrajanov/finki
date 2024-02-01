public class InvertBinaryTree {
}

class SolutionInvertBinaryTree {
    public void invertIt(TreeNode root){
        if (root == null){
            return;
        }

        TreeNode left = root.left;
        TreeNode right = root.right;

        root.left = right;
        root.right = left;

        invertTree(root.left);
        invertTree(root.right);
    }
    public TreeNode invertTree(TreeNode root) {
        invertIt(root);
        return root;
    }
}