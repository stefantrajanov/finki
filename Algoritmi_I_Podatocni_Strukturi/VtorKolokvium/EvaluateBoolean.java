import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class EvaluateBoolean {
}

class SolutionEvaluateBoolean {
    public boolean evaluateTree(TreeNode root) {
        if (root.left == null && root.right == null){
            return root.val == 1;
        }

        if (root.val == 2){
            return evaluateTree(root.left) || evaluateTree(root.right);
        }else{
            return evaluateTree(root.left) && evaluateTree(root.right);
        }
    }
}