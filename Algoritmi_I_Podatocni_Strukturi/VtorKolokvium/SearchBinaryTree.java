import java.util.Stack;

public class SearchBinaryTree {
}

class SolutionSearchBinaryTree {
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null){
            return null;
        }

        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()){
            TreeNode currrent = stack.pop();
            if (currrent.val == val){
                return currrent;
            }

            if (currrent.val < val){
                if (currrent.right != null) {
                    stack.push(currrent.right);
                }
            }else{
                if (currrent.left != null) {
                    stack.push(currrent.left);
                }
            }
        }

        return null;
    }
}