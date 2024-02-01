import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class StackBukvi {

    public static int solve(char[] string){
        Stack<Character> stack = new Stack<Character>();

        for (int i = string.length - 1; i >= 0; i--) {
            stack.push(string[i]);
        }

        int currentTCounter = 0;
        int TCoutner = 0;
        boolean flag = false;

        char currentLetter = 'T';

        while (currentLetter != 'S'){
            currentLetter = stack.pop();

            if (currentLetter == 'S'){
                char temp;
                while (true){
                    temp = stack.pop();
                    if (temp != 'T'){
                        stack.push(temp);
                        break;
                    }else {
                        TCoutner++;
                    }
                }
            }
        }

        while (!stack.empty()){
            currentLetter = stack.pop();
            currentTCounter = 0;

            if (currentLetter == 'S'){
                char temp;
                while (true){
                    try {
                        temp = stack.pop();
                    }catch (Exception ignored){
                        temp = 'S';
                    }
                    if (temp != 'T'){
                        break;
                    }else {
                        currentTCounter++;
                    }
                }
                if (currentTCounter != TCoutner){
                    return 0;
                }
            }
        }

        return 1;
    }

    public static String filterString(char[] string){
        StringBuilder result = new StringBuilder();

        for (char letter : string ) {
            if (letter == 'S' || letter == 'T'){
                result.append(letter);
            }
        }

        return result.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String string = reader.readLine();

        string = filterString(string.toCharArray());

        System.out.println(solve(string.toCharArray()));
    }
}
