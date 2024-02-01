import java.util.HashMap;

public class CountingBits {
    public static int[] countBits(int n) {
        int[] bits = new int[n+1];
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i <= n; i++) {
            int counter = 0;
            int number = i;
            while (number >= 1){
                if (map.containsKey(number)){
                    counter += map.get(number);
                    break;
                }

                if (number % 2 == 1){
                    counter++;
                }
                number /= 2;
            }
            bits[i] = counter;
            map.put(i,counter);
        }

        return bits;
    }

    public static void main(String[] args) {

    }
}
