import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class SudokuSolver {
    public static List<HashSet<Character>> getSubBoxes(char[][] board) {
        List<List<Character>> main = new ArrayList<>();
        List<Character> temp = new ArrayList<>();

        int counter = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < 3; j++, counter++) {
                if (counter % 9 == 0) {
                    main.add(temp);
                    temp = new ArrayList<>();
                }
                temp.add(board[j][i]);
            }
        }
        main.add(temp);

        counter = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 3; j < 6; j++, counter++) {
                if (counter % 9 == 0) {
                    main.add(temp);
                    temp = new ArrayList<>();
                }
                temp.add(board[j][i]);
            }
        }
        main.add(temp);
        counter = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 6; j < 9; j++, counter++) {
                if (counter % 9 == 0) {
                    main.add(temp);
                    temp = new ArrayList<>();
                }
                temp.add(board[j][i]);
            }
        }
        main.add(temp);
        main.remove(0);
        main.remove(3);
        main.remove(6);


        List<HashSet<Character>> sets = new ArrayList<>();
        for (List<Character> row : main) {
            HashSet<Character> set = new HashSet<>();

            for (char letter : row) {
                if (letter != '.') {
                    if (!set.add(letter)) {
                        return new ArrayList<>();
                    }
                }
            }

            sets.add(set);
        }

//        for (HashSet<Character> set : sets) {
//            System.out.println(set);
//        }

        return sets;
    }

    public static HashSet<Character> getRowNumbers(char[] row) {
        HashSet<Character> set = new HashSet<>();

        for (char number : row) {
            if (number == '.') {
                continue;
            }

            set.add(number);
        }

        return set;
    }

    public static HashSet<Character> getColumnNumbers(char[][] board, int i) {
        HashSet<Character> set = new HashSet<>();

        for (int j = 0; j < board.length; j++) {
            if (board[j][i] == '.') {
                continue;
            }

            set.add(board[j][i]);
        }

        return set;
    }

    public static HashSet<Character> getSubBox(List<HashSet<Character>> subBoxes, int i, int j) {
        HashSet<Character> set = new HashSet<>();

        if (i <= 2 && j <= 2) {
            return subBoxes.get(0);
        }

        if (i <= 2 && (j > 2 && j <= 5)) {
            return subBoxes.get(1);
        }

        if (i <= 2 && (j > 5 && j <= 8)) {
            return subBoxes.get(2);
        }
        /////

        if ((i > 2 && i <= 5) && (j <= 2)) {
            return subBoxes.get(3);
        }

        if ((i > 2 && i <= 5) && (j > 2 && j <= 5)) {
            return subBoxes.get(4);
        }

        if ((i > 2 && i <= 5) && (j > 5 && j <= 8)) {
            return subBoxes.get(5);
        }

        //

        if ((i > 5 && i <= 8) && (j <= 2)) {
            return subBoxes.get(6);
        }

        if ((i > 5 && i <= 8) && (j > 2 && j <= 5)) {
            return subBoxes.get(7);
        }

        if ((i > 5 && i <= 8) && (j > 5 && j <= 8)) {
            return subBoxes.get(8);
        }

        return null;
    }

    public static HashSet<Character> combineSets(HashSet<Character> first, HashSet<Character> second, HashSet<Character> third) {
        HashSet<Character> combined = new HashSet<>();

        combined.addAll(first);
        combined.addAll(second);
        combined.addAll(third);

        return combined;
    }

    public static void printBoard(char[][] board) {
        System.out.print("[[");
        int i = 0;

        for (char[] row : board) {
            int j = 0;
            for (char number : row) {
                if (j == 8) {
                    System.out.print("\"" + number + "\"");
                    continue;
                }
                j++;

                System.out.print("\"" + number + "\",");
            }
            if (i == 8) {
                System.out.print("]]");
                continue;
            }
            i++;
            System.out.print("],");
            System.out.println();
            System.out.print("[");
        }

//        System.out.print("]]");
    }

    public static boolean isSolved(char[][] board){
        for (char[] row : board) {
            for (char number : row) {
                if (number == '.'){
                    return false;
                }
            }
        }

        return true;
    }


    public static void main(String[] args) {
        char[][] board =
                {{'.','.','9','7','4','8','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'.','2','.','1','.','9','.','.','.'},{'.','.','7','.','.','.','2','4','.'},{'.','6','4','.','1','.','5','9','.'},{'.','9','8','.','.','.','3','.','.'},{'.','.','.','8','.','3','.','2','.'},{'.','.','.','.','.','.','.','.','6'},{'.','.','.','2','7','5','9','.','.'}};

        System.out.println();
//        List<HashSet<Character>> subBoxes = getSubBoxes(board);

//        System.out.println();
//        System.out.println(getRowNumbers(board[7]));
//        System.out.println(getColumnNumbers(board, 7));
//        System.out.println(getSubBox(subBoxes, 7, 7));
//        System.out.println(combineSets(getRowNumbers(board[7]), getColumnNumbers(board, 7), getSubBox(subBoxes, 7, 7)));;
//        System.out.println(Integer.toString(6).charAt(0))
        while (true) {
            boolean changed = false;
            boolean problem = false;
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board[i].length; j++) {
                    if (board[i][j] != '.') {
                        continue;
                    }
                    List<HashSet<Character>> subBoxes = getSubBoxes(board);

                    HashSet<Character> rowNumbers = getRowNumbers(board[i]);
                    HashSet<Character> colNumbers = getColumnNumbers(board, j);
                    HashSet<Character> subBoxNumbers = getSubBox(subBoxes, i, j);

                    HashSet<Character> combined = combineSets(rowNumbers, colNumbers, subBoxNumbers);

                    if (combined.size() == 8) {
                        for (int k = 1; k <= 9; k++) {
                            if (!combined.contains(Integer.toString(k).charAt(0))) {
                                board[i][j] = Integer.toString(k).charAt(0);
                                changed = true;
                                break;
                            }
                        }
                        continue;
                    }

                    if (problem){
                        for (int k = 1; k <= 9; k++) {
                            if (!combined.contains(Integer.toString(k).charAt(0)) && Integer.toString(k).charAt(0) != board[i][j]) {
                                board[i][j] = Integer.toString(k).charAt(0);
                                changed = true;
                                break;
                            }
                        }
                        problem = false;
                        continue;
                    }

                    for (int k = 1; k <= 9; k++) {
                        if (!combined.contains(Integer.toString(k).charAt(0))) {
                            board[i][j] = Integer.toString(k).charAt(0);
                            changed = true;
                            break;
                        }
                    }
                }
                if (!changed) {
                    if (isSolved(board)){
                        break;
                    }else {
                        problem = true;
                    }
                }
            }

            if (isSolved(board)){
                break;
            }
        }

        printBoard(board);
    }
}

class SolutionSodokuSolver {
    public static List<HashSet<Character>> getSubBoxes(char[][] board) {
        List<List<Character>> main = new ArrayList<>();
        List<Character> temp = new ArrayList<>();

        int counter = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < 3; j++, counter++) {
                if (counter % 9 == 0) {
                    main.add(temp);
                    temp = new ArrayList<>();
                }
                temp.add(board[j][i]);
            }
        }
        main.add(temp);

        counter = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 3; j < 6; j++, counter++) {
                if (counter % 9 == 0) {
                    main.add(temp);
                    temp = new ArrayList<>();
                }
                temp.add(board[j][i]);
            }
        }
        main.add(temp);
        counter = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 6; j < 9; j++, counter++) {
                if (counter % 9 == 0) {
                    main.add(temp);
                    temp = new ArrayList<>();
                }
                temp.add(board[j][i]);
            }
        }
        main.add(temp);
        main.remove(0);
        main.remove(3);
        main.remove(6);


        List<HashSet<Character>> sets = new ArrayList<>();
        for (List<Character> row : main) {
            HashSet<Character> set = new HashSet<>();

            for (char letter : row) {
                if (letter != '.') {
                    if (!set.add(letter)) {
                        return new ArrayList<>();
                    }
                }
            }

            sets.add(set);
        }

//        for (HashSet<Character> set : sets) {
//            System.out.println(set);
//        }

        return sets;
    }

    public static HashSet<Character> getRowNumbers(char[] row) {
        HashSet<Character> set = new HashSet<>();

        for (char number : row) {
            if (number == '.') {
                continue;
            }

            set.add(number);
        }

        return set;
    }

    public static HashSet<Character> getColumnNumbers(char[][] board, int i) {
        HashSet<Character> set = new HashSet<>();

        for (int j = 0; j < board.length; j++) {
            if (board[j][i] == '.') {
                continue;
            }

            set.add(board[j][i]);
        }

        return set;
    }

    public static HashSet<Character> getSubBox(List<HashSet<Character>> subBoxes, int i, int j) {
        HashSet<Character> set = new HashSet<>();

        if (i <= 2 && j <= 2) {
            return subBoxes.get(0);
        }

        if (i <= 2 && (j > 2 && j <= 5)) {
            return subBoxes.get(1);
        }

        if (i <= 2 && (j > 5 && j <= 8)) {
            return subBoxes.get(2);
        }
        /////

        if ((i > 2 && i <= 5) && (j <= 2)) {
            return subBoxes.get(3);
        }

        if ((i > 2 && i <= 5) && (j > 2 && j <= 5)) {
            return subBoxes.get(4);
        }

        if ((i > 2 && i <= 5) && (j > 5 && j <= 8)) {
            return subBoxes.get(5);
        }

        //

        if ((i > 5 && i <= 8) && (j <= 2)) {
            return subBoxes.get(6);
        }

        if ((i > 5 && i <= 8) && (j > 2 && j <= 5)) {
            return subBoxes.get(7);
        }

        if ((i > 5 && i <= 8) && (j > 5 && j <= 8)) {
            return subBoxes.get(8);
        }

        return null;
    }

    public static HashSet<Character> combineSets(HashSet<Character> first, HashSet<Character> second, HashSet<Character> third) {
        HashSet<Character> combined = new HashSet<>();

        combined.addAll(first);
        combined.addAll(second);
        combined.addAll(third);

        return combined;
    }

    public static void printBoard(char[][] board) {
        System.out.print("[[");
        int i = 0;

        for (char[] row : board) {
            int j = 0;
            for (char number : row) {
                if (j == 8) {
                    System.out.print("\"" + number + "\"");
                    continue;
                }
                j++;

                System.out.print("\"" + number + "\",");
            }
            if (i == 8) {
                System.out.print("]]");
                continue;
            }
            i++;
            System.out.print("],");
            System.out.println();
            System.out.print("[");
        }

//        System.out.print("]]");
    }

    public void solveSudoku(char[][] board) {
        while (true) {
            boolean changed = false;
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board[i].length; j++) {
                    if (board[i][j] != '.') {
                        continue;
                    }
                    List<HashSet<Character>> subBoxes = getSubBoxes(board);

                    HashSet<Character> rowNumbers = getRowNumbers(board[i]);
                    HashSet<Character> colNumbers = getColumnNumbers(board, j);
                    HashSet<Character> subBoxNumbers = getSubBox(subBoxes, i, j);

                    HashSet<Character> combined = combineSets(rowNumbers, colNumbers, subBoxNumbers);

                    if (combined.size() != 8) {
                        continue;
                    }

                    for (int k = 1; k <= 9; k++) {
                        if (!combined.contains(Integer.toString(k).charAt(0))) {
                            board[i][j] = Integer.toString(k).charAt(0);
                            changed = true;
                            break;
                        }
                    }
                }
            }

            if (!changed) {
                break;
            }
        }

//        printBoard(board);
    }
}

//37. Sudoku Solver