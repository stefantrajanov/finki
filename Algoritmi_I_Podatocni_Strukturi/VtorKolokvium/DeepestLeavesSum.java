public class DeepestLeavesSum {
}
class SolutionDeepestLeavesSum {

    public int depth(TreeNode root){
        if (root == null){
            return 0;
        }

        int left = depth(root.left);
        int right = depth(root.right);

        return 1 + Math.max(left, right);
    }

    public int helper(TreeNode root, int sum, int counter, int depth){
        if (root == null){
            return sum;
        }
//        System.out.print(root.val + "|" + counter + " ");
        if (counter == depth){
//            sum = sum + root.val;
            System.out.print(root.val + "|" + counter + " " + " " + sum);

            return helper(root.left, sum + root.val, counter + 1, depth) + helper(root.right, sum + root.val, counter + 1, depth);
        }
        return helper(root.left, sum, counter + 1, depth) + helper(root.right, sum, counter + 1, depth);
    }
    public int deepestLeavesSum(TreeNode root) {
        System.out.println(depth(root));
//        int sum = 0;
        int sum = helper(root, 0, 1, depth(root)) / 2;

        return sum;
    }
}