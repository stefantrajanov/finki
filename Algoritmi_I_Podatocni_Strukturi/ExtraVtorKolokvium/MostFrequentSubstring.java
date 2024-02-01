import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class MostFrequentSubstring {

    public static List<String> getSubstrings(String str){
        List<String> list = new ArrayList<>();

        for (int i = 0; i < str.length(); i++) {
            for (int j = i + 1; j <= str.length(); j++) {
                list.add(str.substring(i,j));
            }
        }

        return list;
    }

    public static void main (String[] args) throws IOException {
        CBHT<String,Integer> map = new CBHT<String,Integer>(300);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String word = br.readLine().trim();
        /////////////////////////////////////
        List<String> subStrings = getSubstrings(word);

        for (String subString : subStrings) {
            if (!map.containsKey(subString)){
                map.insert(subString, 1);
            }else{
                map.getEntry(subString).value = map.get(subString) + 1;
            }
        }

        int max = 0;
        String maxString = "";
        for (String substring : subStrings) {
            if (max < map.get(substring)){
                max = map.get(substring);
                maxString = substring;
            }else if (max == map.get(substring)){
                if (maxString.length() < substring.length()){
                    maxString = substring;
                }else if (maxString.length() == substring.length()){
                    if (maxString.compareTo(substring) > 0){
                        maxString = substring;
                    }
                }
            }
        }

        System.out.println(map.getBuckets());
        System.out.println(map);

        System.out.println(maxString);
    }
}
