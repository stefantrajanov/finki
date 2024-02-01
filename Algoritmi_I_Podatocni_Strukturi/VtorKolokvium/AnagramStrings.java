import java.util.HashMap;
import java.util.HashSet;

public class AnagramStrings {
    public static void main(String[] args) {
        String first = "leetcode";
        String second = "practice";

        HashMap<Character, Integer> firstMap= new HashMap<>();
        HashMap<Character, Integer> secondMap = new HashMap<>();


        for (int i = 0; i < first.length(); i++) {
            if (!firstMap.containsKey(first.charAt(i))){
                firstMap.put(first.charAt(i), 1);
            }else{
                firstMap.replace(first.charAt(i), firstMap.get(first.charAt(i)) + 1);
            }

            if (!secondMap.containsKey(second.charAt(i))){
                secondMap.put(second.charAt(i), 1);
            }else{
                secondMap.replace(second.charAt(i), secondMap.get(second.charAt(i)) + 1);
            }

            if (!secondMap.containsKey(first.charAt(i))){
                secondMap.put(first.charAt(i), 0);
            }
            if (!firstMap.containsKey(second.charAt(i))){
                firstMap.put(second.charAt(i), 0);
            }

        }

        System.out.println(firstMap);
        System.out.println(secondMap);
        System.out.println();
        int steps = 0;
        for (char key : firstMap.keySet()) {
            steps += Math.abs(firstMap.get(key) - secondMap.get(key));
            secondMap.replace(key, firstMap.get(key));
        }

        System.out.println(firstMap);
        System.out.println(secondMap);

        System.out.println(steps/2);

    }
}

class SolutionAnagramStrings {
    public int minSteps(String first, String second) {

        HashMap<Character, Integer> firstMap= new HashMap<>();
        HashMap<Character, Integer> secondMap = new HashMap<>();


        for (int i = 0; i < first.length(); i++) {
            if (!firstMap.containsKey(first.charAt(i))){
                firstMap.put(first.charAt(i), 1);
            }else{
                firstMap.replace(first.charAt(i), firstMap.get(first.charAt(i)) + 1);
            }

            if (!secondMap.containsKey(second.charAt(i))){
                secondMap.put(second.charAt(i), 1);
            }else{
                secondMap.replace(second.charAt(i), secondMap.get(second.charAt(i)) + 1);
            }

            if (!secondMap.containsKey(first.charAt(i))){
                secondMap.put(first.charAt(i), 0);
            }
            if (!firstMap.containsKey(second.charAt(i))){
                firstMap.put(second.charAt(i), 0);
            }

        }

        int steps = 0;
        for (char key : firstMap.keySet()) {
            steps += Math.abs(firstMap.get(key) - secondMap.get(key));
            secondMap.replace(key, firstMap.get(key));
        }

        return (steps/2);
    }
}

//1347. Minimum Number of Steps to Make Two Strings Anagram