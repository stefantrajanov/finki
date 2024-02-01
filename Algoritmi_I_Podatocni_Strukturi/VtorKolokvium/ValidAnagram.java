import java.util.HashMap;
import java.util.HashSet;
import java.util.Objects;

public class ValidAnagram {
    public static void main(String[] args) {
        String s="";
        String t="";

        if (s.length() != t.length()){
            System.out.println("false");
            return;
        }

        HashMap<Character, Integer> map = new HashMap<>();

        for (char letter : s.toCharArray()) {
            if (!map.containsKey(letter)){
                map.put(letter, 1);
            }else{
                map.replace(letter, map.get(letter) + 1);
            }
        }

        HashMap<Character, Integer> secondMap = new HashMap<>();

        for (char letter : t.toCharArray()) {
            if (!secondMap.containsKey(letter)){
                secondMap.put(letter, 1);
            }else{
                secondMap.replace(letter, secondMap.get(letter) + 1);
            }
        }

        if (map.size() != secondMap.size()){
            System.out.println("false");
            return;
        }

        for (char key : map.keySet()) {
            if (!secondMap.containsKey(key)){
                System.out.println("false");
                return;

            }else{
                int first = map.get(key);
                int second = secondMap.get(key);
                if (!Objects.equals(first, second)){
                    System.out.println("false");
                    return ;
                }
            }
        }

        System.out.println("true");
    }
}

class SolutionValidAnagram {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()){
            return false;
        }

        HashMap<Character, Integer> map = new HashMap<>();

        for (char letter : s.toCharArray()) {
            if (!map.containsKey(letter)){
                map.put(letter, 1);
            }else{
                map.replace(letter, map.get(letter) + 1);
            }
        }

        HashMap<Character, Integer> secondMap = new HashMap<>();

        for (char letter : t.toCharArray()) {
            if (!secondMap.containsKey(letter)){
                secondMap.put(letter, 1);
            }else{
                secondMap.replace(letter, secondMap.get(letter) + 1);
            }
        }

        if (map.size() != secondMap.size()){
            return false;
        }

        for (char key : map.keySet()) {
            if (!secondMap.containsKey(key)){
                return false;
            }else{
                int first = map.get(key);
                int second = secondMap.get(key);
                if (!Objects.equals(first, second)){
                    return false;
                }
            }
        }

        return true;
    }
}
//242. Valid Anagram