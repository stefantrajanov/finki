import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class PostFixNotacation {
    public static void solve(char[] expression){
        Stack<Integer> stack = new Stack<Integer>();

        StringBuilder lastNumber = new StringBuilder();
        for (char symbol : expression) {
            if (Character.isDigit(symbol)){
                lastNumber.append(symbol);
            } else if (symbol == ' ') {
                if (lastNumber.toString().isEmpty()){
                    continue;
                }

                int temp = Integer.parseInt(lastNumber.toString());
                lastNumber = new StringBuilder();
                stack.push(temp);
            }
            else if (symbol == '+'){
               int first = stack.pop();
               int second = stack.pop();

               stack.push(first + second);
            }
            else if (symbol == '-'){
                int first = stack.pop();
                int second = stack.pop();

                stack.push(first - second);
            }
            else if (symbol == '*'){
                int first = stack.pop();
                int second = stack.pop();

                stack.push(first * second);
            }
            else if (symbol == '/'){
                int first = stack.pop();
                int second = stack.pop();

                stack.push(first / second);
            }
        }


        System.out.println(stack.pop());
    }

    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String expression = reader.readLine();
        reader.close();

        char[] exp = expression.toCharArray();

        solve(exp);
    }
}
