import java.util.*;

public class MaximumDepthNarry {
}

class SolutionMaximumDepthNarry {

    public int helper(Node root, int depth, int max){
        if (root.children.isEmpty()){
            return depth;
        }

        for (Node node : root.children) {
            int currentDepth = helper(node, depth + 1, max);
            if (max < currentDepth){
                max = currentDepth;
            }
        }

        return max;
    }

    public int maxDepth(Node root) {
        if (root == null) {
            return 0;
        }
        if (root.children.isEmpty()) {
            return 1;
        }


        return helper(root, 1, 1);
    }
}