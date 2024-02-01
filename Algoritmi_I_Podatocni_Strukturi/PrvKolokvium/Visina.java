import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Visina {

    public static int findMaxNumber(int first, int second, int third){
        if (first == second && second == third){
            return 0;
        }

        int max = first;
        if (max < second){
            max = second;
        }
        if (max < third){
            max = third;
        }

        if (max == first){
            return 1;
        }
        if (max == second){
            return 2;
        }

        return 3;
    }

    public static int findMaxHeight(int[] listOne, int[] listTwo, int[] listThree){
        int firstStackSum = Arrays.stream(listOne).sum();
        int secondStackSum = Arrays.stream(listTwo).sum();
        int thirdStackSum = Arrays.stream(listThree).sum();


        if (firstStackSum == secondStackSum && secondStackSum == thirdStackSum){
            return firstStackSum;
        }

        Stack<Integer> firstStack = new Stack<Integer>();
        Stack<Integer> secondStack = new Stack<Integer>();
        Stack<Integer> thirdStack = new Stack<Integer>();

        for (int i = listOne.length - 1; i >= 0; i--) {
            firstStack.push(listOne[i]);
        }

        for (int i = listTwo.length - 1; i >= 0; i--) {
            secondStack.push(listTwo[i]);
        }

        for (int i = listThree.length - 1; i >= 0; i--) {
            thirdStack.push(listThree[i]);
        }


        while (true){
            int check = findMaxNumber(firstStackSum, secondStackSum, thirdStackSum);

            if (check == 1){
                int temp = firstStack.pop();
                firstStackSum -= temp;
            }else if (check == 2){
                int temp = secondStack.pop();
                secondStackSum -= temp;
            }else if (check == 3){
                int temp= thirdStack.pop();
                thirdStackSum -= temp;
            }else if (check == 0){
                break;
            }
        }

        return firstStackSum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int first = scanner.nextInt();
        int second = scanner.nextInt();
        int third = scanner.nextInt();

        int[] listOne = new int[first];
        int[] listTwo = new int[first];
        int[] listThird = new int[first];

        for (int i = 0; i < first; i++) {
            listOne[i] = scanner.nextInt();
        }

        for (int i = 0; i < second; i++) {
            listTwo[i] = scanner.nextInt();
        }

        for (int i = 0; i < third; i++) {
            listThird[i] = scanner.nextInt();
        }

        System.out.println(findMaxHeight(listOne, listTwo, listThird));
    }
}
