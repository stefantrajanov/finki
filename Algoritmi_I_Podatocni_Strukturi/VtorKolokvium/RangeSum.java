import com.sun.source.tree.Tree;

import java.util.Stack;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}


public class RangeSum {
    public static void main(String[] args) {


    }


}

class SolutionRangeSum {
    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null){
            return 0;
        }

        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        int sum = 0;

        while (!stack.isEmpty()){
            TreeNode current = stack.pop();
            if (current.val >= low && current.val <= high){
                sum += current.val;
            }

            if (current.right != null){
                stack.push(current.right);
            }

            if (current.left != null){
                stack.push(current.left);
            }
        }

        return sum;
    }

}