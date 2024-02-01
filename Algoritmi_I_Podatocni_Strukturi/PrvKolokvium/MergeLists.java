import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MergeLists {

    public static void mergeLists (DLL<Integer> firstList, DLL<Integer> secondList){
        // prva rastecka
        // vtora opagacka

        DLLNode<Integer> first = firstList.getLast();
        DLLNode<Integer> second = secondList.getFirst();

        DLL<Integer> mergedList = new DLL<>();


        while (first != null && second != null){
            if (first.element >= second.element){
                mergedList.insertLast(first.element);
                first = first.pred;
            }
            else{
                mergedList.insertLast(second.element);
                second = second.succ;
            }
        }

        while (first != null){
            mergedList.insertLast(first.element);
            first = first.pred;
        }

        while (second != null){
            mergedList.insertLast(second.element);
            second = second.succ;
        }


        System.out.println(mergedList.toString());
    }

    public static void main(String[] args) {
        DLL<Integer> list = new DLL<>();
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();


        for (int i = 0; i < n; i++) {
            int number = scanner.nextInt();
            list.insertLast(number);
        }


        DLL<Integer> listTwo = new DLL<>();
        for (int i = 0; i < m; i++) {
            int number = scanner.nextInt();
            listTwo.insertLast(number);
        }

        mergeLists(list, listTwo);
    }

    import java.util.ArrayList;
import java.util.List;

    public class LargestAscendingSubarray {
        public static void main(String[] args) {
            int[] array = {5, 1, 5, 2, 5, 3, 5, 5};

            List<Integer> largestAscendingSubarray = findLargestAscendingSubarray(array);

            System.out.println("Largest ascending subarray: " + largestAscendingSubarray);
        }

        private static List<Integer> findLargestAscendingSubarray(int[] array) {
            if (array == null || array.length == 0) {
                return new ArrayList<>();
            }

            List<Integer> current = new ArrayList<>();
            List<Integer> largetAsc = new ArrayList<>();
            
            for (int i = 0; i < array.length; i++) {
                if (current.isEmpty() || array[i] > current.get(current.size() - 1)) {
                    current.add(array[i]);
                } else {
                    if (current.size() > largetAsc.size()) {
                        largetAsc = new ArrayList<>(current);
                    }
                    current.clear();
                    current.add(array[i]);
                }
            }

            // Check one last time after loop ends
            if (current.size() > largetAsc.size()) {
                largetAsc = new ArrayList<>(current);
            }

            return largetAsc;
        }
    }

}
