import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.NoSuchElementException;

class BNode<E> {

    public E info;
    public BNode<E> left;
    public BNode<E> right;

    static int LEFT = 1;
    static int RIGHT = 2;

    public BNode(E info) {
        this.info = info;
        left = null;
        right = null;
    }

    public BNode() {
        this.info = null;
        left = null;
        right = null;
    }

    public BNode(E info, BNode<E> left, BNode<E> right) {
        this.info = info;
        this.left = left;
        this.right = right;
    }

    @Override
    public String toString() {
        return ""+info;
    }
}

class BTree<E> {

    public BNode<E> root;

    public BTree() {
        root = null;
    }

    public BTree(E info) {
        root = new BNode<E>(info);
    }

    public void makeRoot(E elem) {
        root = new BNode<>(elem);
    }

    public void makeRootNode(BNode<E> node) {
        root = node;
    }

    public BNode<E> addChild(BNode<E> node, int where, E elem) {

        BNode<E> tmp = new BNode<E>(elem);

        if (where == BNode.LEFT) {
            if (node.left != null)  // veke postoi element
                return null;
            node.left = tmp;
        } else {
            if (node.right != null) // veke postoi element
                return null;
            node.right = tmp;
        }

        return tmp;
    }

    public BNode<E> addChildNode(BNode<E> node, int where, BNode<E> tmp) {

        if (where == BNode.LEFT) {
            if (node.left != null)  // veke postoi element
                return null;
            node.left = tmp;
        } else {
            if (node.right != null) // veke postoi element
                return null;
            node.right = tmp;
        }

        return tmp;
    }

    public HashSet<E> values(){
        Stack<BNode<E>> stack = new Stack<>();
        BNode<E> temp = root;
        stack.push(root);

        HashSet<E> set = new HashSet<>();
        while (!stack.isEmpty()){
            BNode<E> current = stack.pop();
            set.add(current.info);

            if (current.right != null){
                stack.push(current.right);
            }

            if (current.left != null){
                stack.push(current.left);
            }
        }

        return set;
    }

    public void printTreeHelper(BNode<E> root){
        if (root == null){
            return;
        }
        System.out.println(root.info);
        printTreeHelper(root.left);
        printTreeHelper(root.right);
    }

    public void printTree(){
        printTreeHelper(root);
    }

}


public class NodeDistance {

    public static int findDistance(BNode<String> root, String val, int distance){
        if (root == null){
            return -1;
        }
        if (root.info.compareTo(val) == 0){
            return distance;
        }
        int leftDistance = findDistance(root.left, val, distance + 1);
        int rightDistance = findDistance(root.right, val, distance + 1);


        return Math.max(leftDistance,rightDistance);
    }

    public static BNode<String> findNode(BNode<String> root, String val, BNode<String> lastNode){
        if (root == null){
            return null;
        }
        if (root.info.compareTo(val) == 0){
            return lastNode;
        }
        lastNode = root;

        BNode<String> left = findNode(root.left, val, lastNode);
        if (left != null){
            return left;
        }

        BNode<String> right = findNode(root.right, val, lastNode);
        if (right != null){
            return right;
        }

        return null;
    }
    public static void main(String[] args) throws Exception {
        int i, j, k;
        int index;
        String action;

        String line;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        @SuppressWarnings("unchecked")
        BNode<String>[] nodes = new BNode[N];
        BTree<String> tree = new BTree<String>();

        for (i=0;i<N;i++)
            nodes[i] = new BNode<String>();

        for (i = 0; i < N; i++) {
            line = br.readLine();
            st = new StringTokenizer(line);
            index = Integer.parseInt(st.nextToken());
            nodes[index].info = st.nextToken();
            action = st.nextToken();
            if (action.equals("LEFT")) {
                tree.addChildNode(nodes[Integer.parseInt(st.nextToken())], BNode.LEFT, nodes[index]);
            } else if (action.equals("RIGHT")) {
                tree.addChildNode(nodes[Integer.parseInt(st.nextToken())], BNode.RIGHT, nodes[index]);
            } else {
                // this node is the root
                tree.makeRootNode(nodes[index]);
            }
        }

        HashSet<String> values = tree.values();

        int cases = Integer.parseInt(br.readLine());
        for (int l = 0; l < cases; l++) {
            String split[] = br.readLine().split(" +");
            String from = split[0];
            String to = split[1];

            // Vasiot kod ovde
            if (!values.contains(from) || !values.contains(to)){
                System.out.println("ERROR");
                continue;
            }
            if (from.compareTo(to) == 0){
                System.out.println("0");
                continue;
            }

            BNode<String> fromNode = findNode(tree.root, from, tree.root);
            BNode<String> toNode = findNode(tree.root, to, tree.root);

//            System.out.print(findDistance() + " || ");
            boolean toNodeFlag = false;
            boolean fromNodeFlag = false;
            if (fromNode.info.compareTo(toNode.info) != 0){
                int depthFrom = findDistance(tree.root, fromNode.info, 0);
                int depthTo = findDistance(tree.root, toNode.info, 0);


                while (fromNode.info.compareTo(toNode.info) != 0){
                    if (toNode.info.compareTo(from) == 0){
                        toNodeFlag = true;
                        break;
                    }

                    if (fromNode.info.compareTo(to) == 0){
                        fromNodeFlag = true;
                        break;
                    }

                    if (depthFrom < depthTo){
                        toNode = findNode(tree.root, toNode.info, tree.root);
                        depthTo = findDistance(tree.root, toNode.info, 0);
                    }else if (depthFrom > depthTo){
                        fromNode = findNode(tree.root, fromNode.info, tree.root);
                        depthFrom = findDistance(tree.root, fromNode.info, 0);
                    }else{
                        fromNode = findNode(tree.root, fromNode.info, tree.root);
                        toNode = findNode(tree.root, toNode.info, tree.root);


                        depthFrom = findDistance(tree.root, fromNode.info, 0);
                        depthTo = findDistance(tree.root, toNode.info, 0);
                    }
                }
            }

//            System.out.print(fromNode.info + " " + toNode.info + " | ");

//            System.out.println(findDistance(tree.root, from,0) + " " + findDistance(tree.root, to,0));

            int result;

            if (toNodeFlag){
                result = findDistance(tree.root, from,0)  + findDistance(tree.root, to,0) - (2*findDistance(tree.root, toNode.info, 0));
            }else if (fromNodeFlag){
                result = findDistance(tree.root, from,0)  + findDistance(tree.root, to,0) - (2*findDistance(tree.root, fromNode.info, 0));
            }else{
                result = findDistance(tree.root, from,0)  + findDistance(tree.root, to,0) - (2*findDistance(tree.root, fromNode.info, 0));
            }



            System.out.println(result * 2);
        }
        br.close();

//        tree.printTree();
    }

}
