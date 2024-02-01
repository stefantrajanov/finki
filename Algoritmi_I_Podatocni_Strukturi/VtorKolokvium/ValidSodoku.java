//import java.util.ArrayList;
//import java.util.HashSet;
//import java.util.List;
//
//public class ValidSodoku {
//
//    public static void main(String[] args) {
//        char[][] board =
//                {{'5','3','.','.','7','.','.','.','.'}
//                ,{'6','.','.','1','9','5','.','.','.'}
//                ,{'.','9','8','.','.','.','.','6','.'}
//                ,{'8','.','.','.','6','.','.','.','3'}
//                ,{'4','.','.','8','.','3','.','.','1'}
//                ,{'7','.','.','.','2','.','.','.','6'}
//                ,{'.','6','.','.','.','.','2','8','.'}
//                ,{'.','.','.','4','1','9','.','.','5'}
//                ,{'.','.','.','.','8','.','.','7','9'}};
//
//        System.out.println();
//        List<HashSet<Character>> subBoxes = getSubBoxes(board);
//        if (subBoxes.isEmpty()){
//            System.out.println("false");
//            return;
//        }
//
//        for (HashSet<Character> box : subBoxes) {
//            System.out.println(box);
//        }
//
//        for (char[] row : board) {
//            HashSet<Character> cheker = new HashSet<>();
//            for (char number : row) {
//                if(number == '.'){
//                    continue;
//                }
//
//                if(!cheker.add(number)){
//                    System.out.println("false");
//                    return;
//                }
//            }
//        }
//
//        for (int i = 0; i < board.length; i++) {
//            HashSet<Character> cheker = new HashSet<>();
//
//            for (int j = 0; j < board[i].length; j++) {
//                char number = board[j][i];
//                if(number == '.'){
//                    continue;
//                }
//
//                if(!cheker.add(number)){
//                    System.out.println("false");
//                    return;
//                }
//            }
//        }
//
//        System.out.println("true");
//    }
//}
//
//class SolutionValidSodoku {
//    public static List<HashSet<Character>> getSubBoxes(char[][] board){
//        List<List<Character>> main = new ArrayList<>();
//        List<Character> temp = new ArrayList<>();
//
//        int counter = 0;
//        for (int i = 0; i < board.length; i++) {
//            for (int j = 0; j < 3; j++, counter++) {
//                if (counter % 9 == 0){
//                    main.add(temp);
//                    temp = new ArrayList<>();
//                }
//                temp.add(board[j][i]);
//            }
//        }
//        main.add(temp);
//
//        counter = 0;
//        for (int i = 0; i < board.length; i++) {
//            for (int j = 3; j < 6; j++, counter++) {
//                if (counter % 9 == 0){
//                    main.add(temp);
//                    temp = new ArrayList<>();
//                }
//                temp.add(board[j][i]);
//            }
//        }
//        main.add(temp);
//        counter = 0;
//        for (int i = 0; i < board.length; i++) {
//            for (int j = 6; j < 9; j++, counter++) {
//                if (counter % 9 == 0){
//                    main.add(temp);
//                    temp = new ArrayList<>();
//                }
//                temp.add(board[j][i]);
//            }
//        }
//        main.add(temp);
//        main.remove(0);
//        main.remove(3);
//        main.remove(6);
//
//
//        List<HashSet<Character>> sets = new ArrayList<>();
//        for (List<Character> row : main) {
//            HashSet<Character> set = new HashSet<>();
//
//            for (char letter : row) {
//                if (letter != '.') {
//                    if(!set.add(letter)){
//                        return new ArrayList<>();
//                    }
//                }
//            }
//
//            sets.add(set);
//        }
//
//        return sets;
//    }
//
//    public boolean isValidSudoku(char[][] board) {
//
//
//        List<HashSet<Character>> subBoxes = getSubBoxes(board);
//        if (subBoxes.isEmpty()){
//            return false;
//        }
//
//        for (HashSet<Character> box : subBoxes) {
//            System.out.println(box);
//        }
//
//        for (char[] row : board) {
//            HashSet<Character> cheker = new HashSet<>();
//            for (char number : row) {
//                if(number == '.'){
//                    continue;
//                }
//
//                if(!cheker.add(number)){
//                    System.out.println("false");
//                    return false;
//                }
//            }
//        }
//
//        for (int i = 0; i < board.length; i++) {
//            HashSet<Character> cheker = new HashSet<>();
//
//            for (int j = 0; j < board[i].length; j++) {
//                char number = board[j][i];
//                if(number == '.'){
//                    continue;
//                }
//
//                if(!cheker.add(number)){
//                    System.out.println("false");
//                    return false;
//                }
//            }
//        }
//
//        return true;
//    }
//}
////36. Valid Sudoku