import javax.swing.plaf.IconUIResource;
import java.util.*;

public class GroupAnagrams {
    public static void main(String[] args) {
        String[] strs = {"ac","c"};
        List<List<String>> main = new ArrayList<>();
    }
}

class SolutionGroupAnagrams {
    public List<List<String>> groupAnagrams(String[] strs) {

        List<List<String>> main = new ArrayList<>();
        for (String word : strs) {
            Map<Character, Integer> set = new HashMap<>();
            for (char letter : word.toCharArray()) {
                if (!set.containsKey(letter)){
                    set.put(letter, 1);
                }else{
                    set.replace(letter, set.get(letter) + 1);
                }
            }
            if (word.compareTo("") == 0){
                set.put(' ', 1);
            }
            List<String> current = new ArrayList<>();

            for (String anagram : strs) {
                if (anagram.length() != word.length()){
                    continue;
                }

                Map<Character, Integer> currentMap = new HashMap<>();
                for (char letter : anagram.toCharArray()) {
                    if (!currentMap.containsKey(letter)){
                        currentMap.put(letter, 1);
                    }else{
                        currentMap.replace(letter, currentMap.get(letter) + 1);
                    }
                }

                current.add(anagram);
                if (anagram.compareTo("") == 0){
                    if (!set.containsKey(' ')){
                        current.remove(anagram);
                        continue;
                    }
                }

                for (char letter : anagram.toCharArray()) {
                    if (!set.containsKey(letter)){
                        current.remove(anagram);
                        break;
                    }else{
                        if (!Objects.equals(set.get(letter), currentMap.get(letter))){
                            current.remove(anagram);
                            break;
                        }
                    }
                }
            }

            if (!main.contains(current)) {
                main.add(current);
            }
//            System.out.println(main);

        }
        return main;
    }
}
//49. Group Anagrams