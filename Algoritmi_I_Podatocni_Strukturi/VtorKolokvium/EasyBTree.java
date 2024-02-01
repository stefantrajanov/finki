import java.util.Scanner;
import java.util.TreeMap;


public class EasyBTree {
    public static void main(String[] args) {
        BinarySearchTree<Integer> tree = new BinarySearchTree<>();
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            tree.insert(scanner.nextInt());
        }

        tree.printTree();;
    }
}
