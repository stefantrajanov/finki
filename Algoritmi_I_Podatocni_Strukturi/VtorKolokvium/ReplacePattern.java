import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class ReplacePattern {
    public static void main(String[] args) {
        String[] words = {"abc","deq","mee","aqq","dkd","ccc"};
        String pattern = "abb";
        List<String> list = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            HashMap<Character, Character> mapPattern = new HashMap<>();
            for (int j = 0; j < pattern.length(); j++) {
                if (mapPattern.containsValue(words[i].charAt(j))){
                    continue;
                }

                mapPattern.put(pattern.charAt(j), words[i].charAt(j));
            }

            StringBuilder builder = new StringBuilder();

            for (char key : pattern.toCharArray()) {
                builder.append(mapPattern.get(key));
            }

            if (builder.toString().compareTo(words[i]) == 0){
                list.add(builder.toString());
            }

            builder = new StringBuilder();
            mapPattern.clear();
        }

        System.out.println(list.toString());

    }
}

class SolutionReplacePattern {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> list = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            HashMap<Character, Character> mapPattern = new HashMap<>();
            for (int j = 0; j < pattern.length(); j++) {
                if (mapPattern.containsValue(words[i].charAt(j))){
                    continue;
                }

                mapPattern.put(pattern.charAt(j), words[i].charAt(j));
            }

            StringBuilder builder = new StringBuilder();

            for (char key : pattern.toCharArray()) {
                builder.append(mapPattern.get(key));
            }

            if (builder.toString().compareTo(words[i]) == 0){
                list.add(builder.toString());
            }

            builder = new StringBuilder();
            mapPattern.clear();
        }


        return list;
    }
}

//890. Find and Replace Pattern