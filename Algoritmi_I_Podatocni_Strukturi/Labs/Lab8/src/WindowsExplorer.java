import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Iterator;
import java.util.NoSuchElementException;

interface Tree<E> {
    ////////////Accessors ////////////

    public Node<E> root();

    public Node<E> parent(Node<E> node);

    public int childCount(Node<E> node);

    ////////////Transformers ////////////
    public void makeRoot(E elem);

    public Node<E> addChild(Node<E> node, E elem);

    public void remove(Node<E> node);

    ////////////Iterator ////////////
    public Iterator<E> children(Node<E> node);

}

interface Node<E> {

    public E getElement();

    public void setElement(E elem);
}


class SLLTree<E> implements Tree<E> {

    public SLLNode<E> root;

    public SLLTree() {
        root = null;
    }

    public Node<E> root() {
        return root;
    }

    public Node<E> parent(Node<E> node) {
        return ((SLLNode<E>) node).parent;
    }

    public int childCount(Node<E> node) {
        SLLNode<E> tmp = ((SLLNode<E>) node).firstChild;
        int num = 0;
        while (tmp != null) {
            tmp = tmp.sibling;
            num++;
        }
        return num;
    }

    public void makeRoot(E elem) {
        root = new SLLNode<E>(elem);
    }

    public Node<E> addChild(Node<E> node, E elem) {
        SLLNode<E> tmp = new SLLNode<E>(elem);
        SLLNode<E> curr = (SLLNode<E>) node;
        tmp.sibling = curr.firstChild;
        curr.firstChild = tmp;
        tmp.parent = curr;
        return tmp;
    }

    public void remove(Node<E> node) {
        SLLNode<E> curr = (SLLNode<E>) node;
        if (curr.parent != null) {
            if (curr.parent.firstChild == curr) {
                // The node is the first child of its parent
                // Reconnect the parent to the next sibling
                curr.parent.firstChild = curr.sibling;
            } else {
                // The node is not the first child of its parent
                // Start from the first and search the node in the sibling list and remove it
                SLLNode<E> tmp = curr.parent.firstChild;
                while (tmp.sibling != curr) {
                    tmp = tmp.sibling;
                }
                tmp.sibling = curr.sibling;
            }
        } else {
            root = null;
        }
    }

    class SLLTreeIterator<T> implements Iterator<T> {

        SLLNode<T> start, current;

        public SLLTreeIterator(SLLNode<T> node) {
            start = node;
            current = node;
        }

        public boolean hasNext() {
            return (current != null);
        }

        public T next() throws NoSuchElementException {
            if (current != null) {
                SLLNode<T> tmp = current;
                current = current.sibling;
                return tmp.getElement();
            } else {
                throw new NoSuchElementException();
            }
        }

        public void remove() {
            if (current != null) {
                current = current.sibling;
            }
        }
    }

    public Iterator<E> children(Node<E> node) {
        return new SLLTreeIterator<E>(((SLLNode<E>) node).firstChild);
    }

    void printTreeRecursive(Node<E> node, int level) {
        if (node == null)
            return;
        int i;
        SLLNode<E> tmp;

        for (i=0;i<level;i++)
            System.out.print(" ");
        System.out.println(node.getElement().toString());
        tmp = ((SLLNode<E>)node).firstChild;
        while (tmp != null) {
            printTreeRecursive(tmp, level+1);
            tmp = tmp.sibling;
        }
    }

    public SLLNode<E> findNode(E value) {
        return findNodeRecursive(root, value);
    }

    // Recursive helper function to find a node in the tree
    private SLLNode<E> findNodeRecursive(SLLNode<E> currentNode, E value) {
        if (currentNode == null) {
            return null; // Node not found in the current subtree
        }

        if (currentNode.getElement().equals(value)) {
            return currentNode; // Node found
        }

        // Check if the current node has children
        SLLNode<E> childrenIterator = currentNode.firstChild;
        while (childrenIterator != null) {
            SLLNode<E> child = childrenIterator;
            SLLNode<E> result = findNodeRecursive(child, value);
            if (result != null) {
                return result; // Node found in the child's subtree
            }
            // Move to the next sibling
            childrenIterator = childrenIterator.sibling;
        }

        return null; // Node not found in the current subtree or its children
    }

    public void printTree() {
        printTreeRecursive(root, 0);
    }

}

class SLLNode<P> implements Node<P> {

    // Holds the links to the needed nodes
    public SLLNode<P> parent, sibling, firstChild;
    // Hold the data
    public P element;

    public SLLNode(P o) {
        element = o;
        parent = sibling = firstChild = null;
    }

    public P getElement() {
        return element;
    }

    public void setElement(P o) {
        element = o;
    }
}


public class WindowsExplorer {

    public static void main(String[] args) throws Exception {
        int i, j, k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String commands[] = new String[N];

        for (i = 0; i < N; i++)
            commands[i] = br.readLine();

        br.close();

        SLLTree<String> tree = new SLLTree<String>();
        tree.makeRoot("c:");

        // vasiot kod stoi ovde

        SLLNode<String> currentNode = tree.root;
        for (String command : commands) {
            String[] current = command.split(" ");

            if (current[0].compareTo("CREATE") == 0 || current[0].compareTo("OPEN") == 0 || current[0].compareTo("DELETE") == 0) {

                // create
                if (current[0].compareTo("CREATE") == 0) {
                    SLLNode<String> firstChild = currentNode.firstChild;
                    if (firstChild == null) {
                        tree.addChild(currentNode, current[1]);
                        continue;
                    }
                    tree.addChild(currentNode, current[1]);
                    firstChild = currentNode.firstChild;
                    ArrayList<SLLNode<String>> children = new ArrayList<>();
                    while (firstChild != null){
                        children.add(firstChild);
                        firstChild = firstChild.sibling;
                    }

                    Collections.sort(children, Comparator.comparing(node -> node.element));
                    currentNode.firstChild = children.get(0);

                    firstChild = currentNode.firstChild;
                    for (int l = 1; l < children.size(); l++) {
                        firstChild.sibling = children.get(l);
                        firstChild = firstChild.sibling;
                    }
                    firstChild.sibling = null;
                    continue;
                }

                // open
                if (current[0].compareTo("OPEN") == 0) {
                    SLLNode<String> child = currentNode.firstChild;

                    while (child.element.compareTo(current[1]) != 0){
                        child = child.sibling;
                    }

                    currentNode = child;
                    continue;

                }

                // remove
                if (current[0].compareTo("DELETE") == 0) {
                    SLLNode<String> child = currentNode.firstChild;

                    while (child.element.compareTo(current[1]) != 0){
                        child = child.sibling;
                    }

                    tree.remove(child);
                    continue;
                }

            } else {

                // print path
                if (current[0].compareTo("PATH") == 0) {
                    SLLNode<String> currentParent = currentNode;

                    StringBuilder builder = new StringBuilder();
                    Stack<SLLNode<String>> stack = new Stack<>();
                    while (currentParent != tree.root){
                        stack.push(currentParent);
                        currentParent = currentParent.parent;
                    }
                    builder.append("c:\\");
                    while (!stack.isEmpty()){
                        builder.append(stack.pop().element + "\\");
                    }

                    System.out.println(builder.toString());
                    continue;
                }

                // back
                if (current[0].compareTo("BACK") == 0) {
                    currentNode = currentNode.parent;
                    continue;
                }

                // print
                if (current[0].compareTo("PRINT") == 0) {
                    tree.printTree();
                    continue;
                }
            }
        }

    }

}
