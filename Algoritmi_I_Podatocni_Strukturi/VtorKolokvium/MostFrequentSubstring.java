import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

public class MostFrequentSubstring {

    public static List<String> getAllSubstrings(String input) {
        List<String> substrings = new ArrayList<>();

        for (int i = 0; i < input.length(); i++) {
            for (int j = i + 1; j <= input.length(); j++) {
                substrings.add(input.substring(i, j));
            }
        }

        return substrings;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String str = reader.readLine();
        List<String> subStrings = getAllSubstrings(str);
        Collections.sort(subStrings);

        CBHT<String, Integer> map = new CBHT<>(300);
        SLLNode<MapEntry<String, Integer>> max = new SLLNode<>(new MapEntry<>("max", 0), null);
        for (String string : subStrings) {
            SLLNode<MapEntry<String, Integer>> value = map.search(string);
            if (value == null) {
                map.insert(string, 0);
            }
        }

        for (String string : subStrings) {
            SLLNode<MapEntry<String, Integer>> value = map.search(string);
            if(value != null){
                value.element.value += 1;
                if (max.element.value < value.element.value){
                    max = value;
                }else if (max.element.value.equals(value.element.value)){
                    if (max.element.key.length() < value.element.key.length()){
                        max = value;
                    }else if (max.element.key.length() == value.element.key.length()){
                        if (max.element.key.compareTo(value.element.key) >= 0){
                            max = value;
                        }
                    }
                }
            }
        }

        System.out.println(max.element.key);
//        System.out.println(subStrings);
    }
}
