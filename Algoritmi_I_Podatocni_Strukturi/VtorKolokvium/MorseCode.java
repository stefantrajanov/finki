import java.util.ArrayList;
import java.util.HashMap;

public class MorseCode {
}

class SolutionMorseCode {
    public String morseCode(String word, HashMap<Character, String> map){
        StringBuilder builder = new StringBuilder();
        for (char letter : word.toCharArray()) {
            builder.append(map.get(letter));
        }

        return builder.toString();
    }
    public int uniqueMorseRepresentations(String[] words) {
        String[] transformations = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        String alphabet = "abcdefghijklmnopqrstuvwxyz";

        HashMap<Character, String> map = new HashMap<>();

        int index = 0;
        for (char letter : alphabet.toCharArray()) {
            map.put(letter, transformations[index]);
            index++;
        }

        HashMap<String, Integer> checker = new HashMap<>();

        for (String word : words) {
            String morse = morseCode(word, map);

            if (!checker.containsKey(morse)){
                checker.put(morse, 0);
            }
        }

        return checker.size();
    }
}

//804. Unique Morse Code Words