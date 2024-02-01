import java.util.HashMap;

public class fibonnaci {

    public int fib(int n){
        return fib(n, new HashMap<>());
    }
    public int fib(int n, HashMap<Integer,Integer> map) {
        if (n == 0 || n == 1){
            return n;
        }
        if (map.containsKey(n)){
            return map.get(n);
        }

        int result = fib(n-1, map) + fib(n-2, map);
        map.put(n, result);
        return result;
    }

    public static void main(String[] args) {

    }
}
