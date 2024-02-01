import java.util.HashMap;

public class RingRoads {
}


class SolutionRingRoads {
    public int countPoints(String rings) {
        HashMap<Integer, StringBuilder> map = new HashMap<>();

        StringBuilder temp = new StringBuilder(rings);
        temp.reverse();
        String ringsReversed = temp.toString();

        int lastRod = 0;
        for (char letter : ringsReversed.toCharArray()) {
            if (Character.isDigit(letter)){
                lastRod = Integer.parseInt(Character.toString(letter));

                if (!map.containsKey(lastRod)) {
                    map.put(lastRod, new StringBuilder());
                }
            }else{
                map.get(lastRod).append(letter);
            }
        }

        int counter = 0;
        for (StringBuilder value : map.values()) {
            if (value.toString().contains("R") && value.toString().contains("G") && value.toString().contains("B")){
                counter++;
            }
        }

        return counter;
    }
}

// 2103. Rings and Rods