import java.util.ArrayList;
import java.util.HashMap;
import java.util.Objects;

public class RemoveLetter {
    public static boolean checkMap(HashMap<Character, Integer> map, int maxDiff){
        for (Character key : map.keySet()) {
            int keyValue = map.get(key);
            boolean flag = true;

            for (Character compare : map.keySet()) {
                int compareValue = map.get(compare);
                if (key == compare){
                    continue;
                }

                if (map.get(key) - 1 == 0){
                    if (map.get(compare) != (map.get(key) + maxDiff) ){
                        flag = false;
                        break;
                    }

                    continue;
                }

                if (map.get(compare) != (map.get(key) - 1) ){
                    flag = false;
                    break;
                }
            }

            if (flag){
                return true;
            }

        }

        return false;
    }

    public static boolean testIfAllDiffrent(String word){
        for (int i = 0; i < word.length(); i++) {
            char letter = word.charAt(i);

            for (int j = i + 1; j < word.length(); j++) {
                if (letter == word.charAt(j)){
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean testAllEqual(String word){
        char letter = word.charAt(0);

        for (char ch : word.toCharArray()) {
            if (letter != ch){
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        String word = "cccd";
        HashMap<Character, Integer> map = new HashMap<>();
        if (testIfAllDiffrent(word) || testAllEqual(word)){
            System.out.println("true");
            return;
        }

        for (char letter : word.toCharArray()) {
            if (!map.containsKey(letter)) {
                map.put(letter, 1);
            } else {
                int value = map.get(letter) + 1;
                map.replace(letter, value);
            }
        }

        int maxDif = Integer.MIN_VALUE;
        int max = Integer.MIN_VALUE;
        for (int value : map.values()) {
            if (max < value){
                max = value;
            }

            for (int number : map.values()) {
                if (maxDif < Math.abs(value - number)){
                    maxDif = Math.abs(value - number);
                }
            }
        }
        System.out.println(map.toString());
        System.out.println("Max Value " + max);
        System.out.println("Diff: " + maxDif);

        if (maxDif == 0){
            System.out.println("false");
            return;
        }


        System.out.println(checkMap(map, maxDif));
    }
}


class SolutionRemoveLetter {
    public boolean checkMap(HashMap<Character, Integer> map, int maxDiff){
        for (Character key : map.keySet()) {
            int keyValue = map.get(key);
            boolean flag = true;

            for (Character compare : map.keySet()) {
                int compareValue = map.get(compare);
                if (key == compare){
                    continue;
                }

                if (map.get(key) - 1 == 0){
                    if (map.get(compare) != (map.get(key) + maxDiff) ){
                        flag = false;
                        break;
                    }

                    continue;
                }

                if (map.get(compare) != (map.get(key) - 1) ){
                    flag = false;
                    break;
                }
            }

            if (flag){
                return true;
            }

        }

        return false;
    }

    public static boolean testIfAllDiffrent(String word){
        for (int i = 0; i < word.length(); i++) {
            char letter = word.charAt(i);

            for (int j = i + 1; j < word.length(); j++) {
                if (letter == word.charAt(j)){
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean testAllEqual(String word){
        char letter = word.charAt(0);

        for (char ch : word.toCharArray()) {
            if (letter != ch){
                return false;
            }
        }

        return true;
    }

    public boolean equalFrequency(String word) {
        HashMap<Character, Integer> map = new HashMap<>();
        if (testIfAllDiffrent(word) || testAllEqual(word)){
            return true;
        }

        for (char letter : word.toCharArray()) {
            if (!map.containsKey(letter)) {
                map.put(letter, 1);
            } else {
                int value = map.get(letter) + 1;
                map.replace(letter, value);
            }
        }

        int maxDif = Integer.MIN_VALUE;
        int max = Integer.MIN_VALUE;
        for (int value : map.values()) {
            if (max < value){
                max = value;
            }

            for (int number : map.values()) {
                if (maxDif < Math.abs(value - number)){
                    maxDif = Math.abs(value - number);
                }
            }
        }
        System.out.println(map.toString());
        System.out.println("Max Value " + max);
        System.out.println("Diff: " + maxDif);

        if (maxDif == 0){
            return false;
        }


        return checkMap(map, maxDif);
    }
}

//2423. Remove Letter To Equalize Frequency