import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BinaryTreeSum {

    public static int sumRight(BNode<Integer> node, int value) {
        if (node == null) {
            return 0; // Base case: empty subtree has sum 0
        }

        int sum = 0;

        // If the current node's value is greater than the threshold, include it in the sum
        if (node.info > value) {
            sum += node.info;
        }

        // Recursively find the sum in the left and right subtrees
        sum += sumRight(node.left, value);
        sum += sumRight(node.right, value);

        return sum;
    }

    public static int sumLeft(BNode<Integer> node, int value) {
        if (node == null) {
            return 0; // Base case: empty subtree has sum 0
        }

        int sum = 0;

        // If the current node's value is greater than the threshold, include it in the sum
        if (node.info < value) {
            sum += node.info;
        }

        // Recursively find the sum in the left and right subtrees
        sum += sumLeft(node.left, value);
        sum += sumLeft(node.right, value);

        return sum;
    }

    public static BNode<Integer> searchRecursive(BNode<Integer> node, int value) {
        if (node == null || node.info == value) {
            return node;
        }

        // Search in the left subtree
        BNode<Integer> leftResult = searchRecursive(node.left, value);
        if (leftResult != null) {
            return leftResult;
        }

        // Search in the right subtree
        return searchRecursive(node.right, value);
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
        BNode<Integer> nodes[] = new BNode[N];
        BTree<Integer> tree = new BTree<Integer>();

        for (i = 0; i < N; i++)
            nodes[i] = new BNode<Integer>();

        for (i = 0; i < N; i++) {
            line = br.readLine();
            st = new StringTokenizer(line);
            index = Integer.parseInt(st.nextToken());
            nodes[index].info = Integer.parseInt(st.nextToken());
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

        int baranaVrednost = Integer.parseInt(br.readLine());

        br.close();

        // vasiot kod ovde   // your code here
        BNode<Integer> theElement = searchRecursive(tree.root, baranaVrednost);

        System.out.print(sumLeft(theElement.left, theElement.info) + " " + sumRight(theElement.right, theElement.info));
    }
}
