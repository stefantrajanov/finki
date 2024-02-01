import java.util.HashSet;

public class ConsistentStrings {
}

class SolutionConsistentStrings {

    public boolean isValid(String word, HashSet<Character> map){
        for (char letter : word.toCharArray()) {
            if (!map.contains(letter)){
                return false;
            }
        }

        return true;
    }
    public int countConsistentStrings(String allowed, String[] words) {
        HashSet<Character> map = new HashSet<>();

        for (char letter : allowed.toCharArray()) {
            map.add(letter);
        }

        int counter = 0;
        for (String word : words) {
            if (isValid(word, map)){
                counter++;
            }
        }

        return counter;
    }
}

//1684. Count the Number of Consistent Strings