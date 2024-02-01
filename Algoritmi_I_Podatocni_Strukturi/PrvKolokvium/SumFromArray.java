import java.util.HashMap;
import java.util.Scanner;
import java.util.Vector;

public class SumFromArray {
    public static int findNumbers(int amount, int[] numbers, HashMap<Integer, Integer> map, int counter){
        if (amount == 0){
            return counter;
        }
        if (amount < 0){
            return counter;
        }

        if (map.containsKey(amount)){
            return map.get(amount);
        }


        for (int number :  numbers) {
            int diffAmount = amount - number;
            int result = findNumbers(diffAmount, numbers, map, counter + 1);
            map.put(amount, result);

        }
        int min = Integer.MAX_VALUE;
        for (int key : map.keySet()) {
            if (min > map.get(key)){
                min = map.get(key);
            }
        }


        return min;
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] array = new int[n];

        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
//            System.out.print(i + " ");
        }

        int number = scanner.nextInt();

        System.out.println(findNumbers(number, array, new HashMap<>(), -1));
    }
}
