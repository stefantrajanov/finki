import java.util.HashMap;

public class JewelsAndStones {
}

class SolutionForJewelsAndStones {
    public int numJewelsInStones(String jewels, String stones) {
        HashMap<Integer, Character> map = new HashMap<>();

        int index = 0;
        for (char letter : jewels.toCharArray()) {
            map.put(index, letter);
            index++;
        }

        int counter = 0;
        for (char stone : stones.toCharArray()) {
            if (map.containsValue(stone)){
                counter++;
            }
        }

        return counter;
    }
}

// 	771 Jewels and Stones