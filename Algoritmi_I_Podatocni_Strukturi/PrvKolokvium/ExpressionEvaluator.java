import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class ExpressionEvaluator {

    public static int toNumber(String string){
        return Integer.parseInt(string);
    }

    public static int evaluateExpression(String expression){
        Stack<Integer> stack = new Stack<>();
        expression += ' ';

        StringBuilder number = new StringBuilder();
        boolean multiply = false;
        for (char symbol : expression.toCharArray()) {

            if (Character.isDigit(symbol)){
                number.append(symbol);
            }else if (!multiply){
                stack.push(toNumber(number.toString()));
                number = new StringBuilder();

                if (symbol == '*'){
                    multiply = true;
                }
            }else{
                int currentNumber = toNumber(number.toString());
                int lastNumber = stack.pop();

                stack.push(currentNumber * lastNumber);

                if (symbol != '*'){
                    multiply = false;
                }
                number = new StringBuilder();
            }
        }

        int sum = 0;
        while (!stack.isEmpty()){
            sum += stack.pop();
        }

        return sum;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
        System.out.println(evaluateExpression(input.readLine()));
    }

}