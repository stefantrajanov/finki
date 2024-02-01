import java.io.*;
        import java.math.*;
        import java.security.*;
        import java.text.*;
        import java.util.*;
        import java.util.concurrent.*;
        import java.util.function.*;
        import java.util.regex.*;
        import java.util.stream.*;
        import static java.util.stream.Collectors.joining;
        import static java.util.stream.Collectors.toList;

class testtas {

    /*
     * Complete the 'poisonousPlants' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY p as parameter.
     */

    public static int poisonousPlants(List<Integer> plants) {

        int counter = 0;
        while (true){
            int lastLength = plants.size();
            if (plants.isEmpty()){
                return counter;
            }

            int lastPlant = plants.get(0);
            for (int i = 1; i < plants.size(); i++) {
                int currentPlant = plants.get(i);

                if (lastPlant < currentPlant){
                    lastPlant = currentPlant;
                    plants.remove(i);
                    i--;
                    continue;
                }

                lastPlant = currentPlant;
            }

            if (lastLength == plants.size()){
                return counter;
            }
            counter++;

        }
    }

}

public class test {
    public static int simple_computer(int[] x, int n){
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += 2*i*x[i];
        }

        return sum;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        Vector<Integer> list = new Vector<>();

        for (int i = 0; i < n; i++) {
            list.add(scanner.nextInt());
        }

        System.out.println(Result.poisonousPlants(list));
    }
}

