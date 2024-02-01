import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class ReverseWord {

    public static void printReversed(String word) {
        StringBuilder stringBuilder = new StringBuilder();

        stringBuilder.append(word);

        System.out.println(stringBuilder.reverse().toString());
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine());


        for (int i = 0; i < n; i++) {
            String string = reader.readLine();
            printReversed(string);
        }
    }
}
