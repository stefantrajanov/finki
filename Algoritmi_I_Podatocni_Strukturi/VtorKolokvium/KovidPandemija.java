import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class KovidPandemija {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine());

        CBHT<String,Integer> positive = new CBHT<>(500);
        CBHT<String,Integer> negative = new CBHT<>(500);

//        HashMap<String, Integer> positive = new HashMap<>();
//        HashMap<String, Integer> negative = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String[] current = reader.readLine().split(" ");
            boolean coronaTestIsPositive = current[2].compareTo("позитивен") == 0;

            if (coronaTestIsPositive) {
                if (!positive.containsKey(current[0])) {
                    positive.insert(current[0], 1);
                    if (!negative.containsKey(current[0])) {
                        negative.insert(current[0], 0);
                    }
                } else {
                    positive.replace(current[0], positive.get(current
                            [0]) + 1);
                }
            } else {
                if (!negative.containsKey(current[0])) {
                    negative.insert(current[0], 1);
                    if (!positive.containsKey(current[0])) {
                        positive.insert(current[0], 0);
                    }
                } else {
                    negative.replace(current[0], negative.get(current
                            [0]) + 1);
                }
            }
        }

        String opshtina = reader.readLine();


        float factor = ( (float) (positive.get(opshtina)) / (float)(negative.get(opshtina) + positive.get(opshtina)) );

        System.out.printf("%.2f", factor);
    }
}
