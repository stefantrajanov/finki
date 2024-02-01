public class UniValued {
}
class SolutionUniValued {
    public boolean helper(TreeNode root, int value){
        if (root == null){
            return true;
        }
        if (root.val != value){
            return false;
        }

        return helper(root.left, value) && helper(root.right, value);
    }
    public boolean isUnivalTree(TreeNode root) {
        return helper(root, root.val);
    }
}