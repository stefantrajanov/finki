import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PMCesticki {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine());

        CBHT<String, Integer> counter = new CBHT<>(500);
        CBHT<String, Float> polution = new CBHT<>(500);

        for (int i = 0; i < n; i++) {
            String[] current = reader.readLine().split(" ");
            String opshtina = current[0];
            current[1] = current[1].replaceAll(",", ".");
            float particles = Float.parseFloat(current[1]);

            if (!counter.containsKey(opshtina)) {
                counter.insert(opshtina, 1);
            } else {
                counter.replace(opshtina, counter.get(opshtina) + 1);
            }

            if (!polution.containsKey(opshtina)) {
                polution.insert(opshtina, particles);
            } else {
                polution.replace(opshtina, polution.get(opshtina) + particles);
            }

        }

        String opshtina = reader.readLine();

        System.out.println(polution.get(opshtina) / (float) counter.get(opshtina));
    }
}
