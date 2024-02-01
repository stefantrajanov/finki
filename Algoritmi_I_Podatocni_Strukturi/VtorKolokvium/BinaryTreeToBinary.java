import java.util.ArrayList;
import java.util.List;

public class BinaryTreeToBinary {
}
class SolutionBinaryTreeToBinary {

    public int getMinDepth(TreeNode root){
        if (root == null){
            return 0;
        }

        if (root.left == null){
            return 1 + getMinDepth(root.right);
        }

        if (root.right == null){
            return 1 + getMinDepth(root.left);
        }

        int leftDepth = getMinDepth(root.left);
        int rightDepth = getMinDepth(root.right);

        return 1 + Math.min(leftDepth,rightDepth);
    }

    public void getNumbers(TreeNode root, List<String> list, StringBuilder builder){
        if (root == null){
            list.add(builder.toString());
            return;
        }
        builder.append(root.val);
        getNumbers(root.left, list, builder);

        getNumbers(root.right, list, builder);
        builder.deleteCharAt(builder.length() - 1);
    }

    private int helper(TreeNode node,int sum){
        if(node==null){
            return 0;
        }
        sum=(2*sum)+node.val;
        if(node.left==null && node.right==null){
            return sum;
        }
        return helper(node.left,sum)+helper(node.right,sum);
    }
    public int sumRootToLeaf(TreeNode root) {
        return helper(root, 0);
    }
}