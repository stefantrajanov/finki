import java.util.HashMap;
import java.util.Stack;

public class Pangram {
}


class SolutionPangram {
    public boolean checkIfPangram(String sentence) {
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        HashMap<Character, Integer> map = new HashMap<>();
        Stack<Integer> stack = new Stack<>();

        for (char letter : alphabet.toCharArray()) {
            stack.push(0);
        }

        for (char letter : sentence.toCharArray()) {
            if (!map.containsKey(letter)){
                map.put(letter, 0);
                stack.pop();
            }
        }

        return stack.isEmpty();
    }
}

//804. Unique Morse Code Words