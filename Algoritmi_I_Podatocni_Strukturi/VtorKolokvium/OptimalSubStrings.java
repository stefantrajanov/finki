import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class OptimalSubStrings {
    public static void main(String[] args) {
        String str = "ssssss";
        HashSet<Character> map = new HashSet<>();
        int counter = 1;

        for (char letter : str.toCharArray()) {
            if (!map.add(letter)){
                counter++;
                map.clear();;
                map.add(letter);
            }
        }

        System.out.println(counter);
    }
}

class SolutionOptimalSubStrings {
    public int partitionString(String str) {
        HashSet<Character> map = new HashSet<>();
        int counter = 1;

        for (char letter : str.toCharArray()) {
            if (!map.add(letter)){
                counter++;
                map.clear();;
                map.add(letter);
            }
        }

        return counter;
    }
}

//2405. Optimal Partition of String