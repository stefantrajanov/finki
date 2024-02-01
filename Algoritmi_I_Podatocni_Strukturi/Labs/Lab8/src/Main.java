import java.util.Iterator;
import java.util.NoSuchElementException;


public class Main {
    public static void main(String[] args) {
        SLLTree<String> tree = new SLLTree<>();

        // Make "root" the root of the tree
        tree.makeRoot("root");

        // Add children to the root
        Node<String> child1 = tree.addChild(tree.root(), "child1");
        Node<String> child2 = tree.addChild(tree.root(), "child2");

        // Add grandchildren to child1
        tree.addChild(child1, "grandchild1");
        tree.addChild(child1, "grandchild2");
        tree.addChild(child1, "grandchild5");
        tree.addChild(child1, "grandchild4");
        tree.addChild(child1, "grandchild6");
        tree.addChild(child1, "grandchild9");

        // Add a child to child2
        tree.addChild(child2, "grandchild3");
        tree.addChild(child2, "grandchild11");
        tree.addChild(child2, "grandchild1111");

        Node<String> test = tree.findNode("child2");

        System.out.println(test.getElement());

        // Print the tree structure
//        tree.printTree();
    }
}