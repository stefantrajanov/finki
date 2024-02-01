import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class LetterTilePossibilities {

    public static Set<String> generateAllSequences(String tiles) {
        Set<String> sequences = new HashSet<>();
        generateSequences("", tiles, sequences);
        return sequences;
    }

    private static void generateSequences(String current, String remaining, Set<String> sequences) {
        sequences.add(current);
        System.out.println(sequences);

        for (int i = 0; i < remaining.length(); i++) {
            char ch = remaining.charAt(i);
            String newCurrent = current + ch;
            String newRemaining = remaining.substring(0, i) + remaining.substring(i + 1);
            generateSequences(newCurrent, newRemaining, sequences);
        }
    }

    public static void main(String[] args) {
        String tiles = "AAB";
        //ABC
        //A -> ABC, ACB
        //B -> BAC, BCA
        //C -> CAB, CBA
        HashSet<String> subStrings = new HashSet<>();

        System.out.println(generateAllSequences(tiles).size());
    }
}

class SolutionLetterTilePossibilities {

    public int factoriel(int number) {
        int product = 1;
        for (int i = 1; i <= number; i++) {
            product *= i;
        }

        return product;
    }

    public int numTilePossibilities(String tiles) {
        int sum = 0;
        for (int i = 1; i <= tiles.length(); i++) {
            sum += (factoriel(tiles.length()) / factoriel(tiles.length() - i));
        }

        return sum;
    }
}
//1079. Letter Tile Possibilities