import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class card_trick {
    public static int count(int N){
        Stack<Integer> flippedNumbers = new Stack<>();
        Vector<Integer> vector = new Vector<>();

        String[] array = new String[5];



        for (int i = 1; i <= 51; i++) {
            vector.add(i);
        }

        int counter = 0;
        while (true) {
            if (vector.firstElement() == N){
                return counter;
            }

            for (int i = 0; i < 7; i++) {
                flippedNumbers.push(vector.firstElement());
                vector.remove(0);
            }

            while (!flippedNumbers.isEmpty()){
                vector.add(flippedNumbers.pop());
                vector.add(vector.firstElement());
                vector.remove(vector.firstElement());
            }
            counter++;
        }

    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );
        System.out.println(count(Integer.parseInt(br.readLine())));
    }

}
