import java.util.HashMap;
import java.util.Scanner;

public class Tribonnaci {
    public static int tribonacci(int n) {
        return trib(n, new HashMap<>());
    }

    public static int trib(int n, HashMap<Integer, Integer> map){
        if (n == 0 || n == 1){
            return 0;
        }
        if (n == 2){
            return 1;
        }

        if (map.containsKey(n)){
            return map.get(n);
        }


        int result = trib(n-1, map) + trib(n-2, map) + trib(n-3, map);
        map.put(n, result);

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        System.out.println(tribonacci(n));
    }
}
