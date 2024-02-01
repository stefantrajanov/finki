public class RootEquals {
}

class SolutionRootEquals {
    public boolean checkTree(TreeNode root) {
        return (root.left.val + root.right.val == root.val);
    }
}