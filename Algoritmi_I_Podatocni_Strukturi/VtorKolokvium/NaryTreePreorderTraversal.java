import java.util.ArrayList;
import java.util.List;

class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }

};


public class NaryTreePreorderTraversal {
}

class SolutionNaryTreePreorderTraversal {
    public void print(Node root, List<Integer> list){
        if (root != null){
            if (!root.children.isEmpty()) {
                System.out.print(root.children.get(0).val + " ");
                list.add(root.children.get(0).val);
                print(root.children.get(0), list);
            }
            for (int i = 1; i < root.children.size(); i++) {
                System.out.print(root.children.get(i).val + " ");
                list.add(root.children.get(i).val);
                print(root.children.get(i), list);
            }
        }
    }
    public List<Integer> preorder(Node root) {
        List<Integer> list = new ArrayList<>();
        if (root == null){
            return list;
        }

        list.add(root.val);
        print(root, list);



        return list;
    }
}