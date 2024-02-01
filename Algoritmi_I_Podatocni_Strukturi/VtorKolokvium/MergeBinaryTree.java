import java.util.Stack;

public class MergeBinaryTree {
    public static void main(String[] args) {
        TreeNode test = new TreeNode(1);

        TreeNode second = test.right;
        test.right = new TreeNode(3);
        System.out.println(test.val + " " + test.right.val);
    }
}


class SolutionMergeBinaryTree {

    private TreeNode mergeTrees(TreeNode first, TreeNode second, TreeNode merged){
        if (first == null && second == null){
            return merged;
        }
        System.out.print(merged.val + " ");

        if (first != null && second != null){
//            merged.val = first.val + second.val;

            if (first.left != null && second.left != null){
                merged.left = new TreeNode(first.left.val + second.left.val);
                return mergeTrees(first.left, second.left, merged.left);
            }

            if (first.right != null && second.right != null){
                merged.right = new TreeNode(first.right.val + second.right.val);
                return mergeTrees(first.right, second.right, merged.right);
            }

            if (first.left != null && second.left == null){
                merged.left = new TreeNode(first.left.val);
                return mergeTrees(first.left, second.left, merged.left);
            }

            if (first.right != null && second.right == null){
                merged.right = new TreeNode(first.right.val);
                return mergeTrees(first.right, second.right, merged.right);
            }

            if (first.left == null && second.left != null){
                merged.left = new TreeNode(second.left.val);
                return mergeTrees(first.left, second.left, merged.left);
            }

            if (first.right == null && second.right != null){
                merged.right = new TreeNode(second.right.val);
                return mergeTrees(first.right, second.right, merged.right);
            }
        }

        if (first != null && second == null){
            if (first.left != null){
                merged.left = new TreeNode(first.left.val);
                return mergeTrees(first.left, second, merged.left);
            }

            if (first.right != null){
                merged.right = new TreeNode(first.right.val);
                return mergeTrees(first.right, second, merged.right);
            }
        }

        if (first == null && second != null){
            if (second.left != null){
                merged.left = new TreeNode(second.left.val);
                return mergeTrees(first, second.left, merged.left);
            }

            if (second.right != null){
                merged.right = new TreeNode(second.right.val);
                return mergeTrees(first, second.right, merged.right);
            }
        }


        return merged;
    }
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        if (root1 == null){
            return root2;
        }
        if (root2 == null){
            return root1;
        }

        TreeNode merged = mergeTrees(root1, root2, new TreeNode());

        return merged;
    }
}