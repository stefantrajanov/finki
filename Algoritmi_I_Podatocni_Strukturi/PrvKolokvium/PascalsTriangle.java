import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PascalsTriangle {
    public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pascal = new ArrayList<>();

        List<Integer> last = new ArrayList<>();
        last.add(1);
        pascal.add(last);
        last = new ArrayList<>();

        if (numRows == 1){
            return pascal;
        }

        last.add(1);
        last.add(1);
        pascal.add(last);

        for (int i = 2; i < numRows; i++) {
            int lastElement = last.get(0);
            List<Integer> newList = new ArrayList<>();
            newList.add(1);
            for (int j = 1; j < last.size(); j++) {
                int current = last.get(j);
                newList.add(lastElement + current);
                lastElement = current;
            }
            newList.add(1);

            pascal.add(newList);
            last = newList;
        }

        return pascal;
    }

    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> pascal = new ArrayList<>();
        pascal = generate(rowIndex + 1);

        return pascal.get(rowIndex);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println(generate(scanner.nextInt()));
    }
}
