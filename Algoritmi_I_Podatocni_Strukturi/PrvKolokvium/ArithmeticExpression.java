import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;

public class ArithmeticExpression {

    // funkcija za presmetuvanje na izrazot pocnuvajki
    // od indeks l, zavrsuvajki vo indeks r
    static int presmetaj(char[] str, int l, int r) {
        Stack<Character> bracketStack = new Stack<>();
        Stack<Character> signStack = new Stack<>();
        Stack<Integer> numberStack = new Stack<>();

        for (char symbol : str) {
            if (symbol == '('){
                bracketStack.push(symbol);
            }else if (symbol == '+' || symbol == '-'){
                signStack.push(symbol);
            }else if(Character.isDigit(symbol)){
                numberStack.push(Integer.parseInt(Character.toString(symbol)));
            }
            else{
                bracketStack.pop();
                char sign = signStack.pop();
                int first = numberStack.pop();
                int second = numberStack.pop();

                if (sign == '+'){
                    numberStack.push(second + first);
                }else{
                    numberStack.push(second - first);
                }
            }
        }

        return numberStack.pop();
    }

    public static void main(String[] args) throws Exception {
        int i,j,k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String expression = br.readLine();
        char exp[] = expression.toCharArray();

        int rez = presmetaj(exp, 0, exp.length-1);
        System.out.println(rez);

        br.close();

    }

}
