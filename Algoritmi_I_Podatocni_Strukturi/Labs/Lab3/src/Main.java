import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {

    public static boolean onlyPlus(String equation) {
        for (char symbol : equation.toCharArray()) {
            if (symbol == '-') {
                return false;
            }
        }
        return true;
    }

    public static double evaluateExpression(String expression) throws ScriptException {
        ScriptEngineManager manager = new ScriptEngineManager();
        ScriptEngine engine = manager.getEngineByName("JavaScript");
        return (double) engine.eval(expression);
    }

    public static int calculateEquation(String equation) {
        if (onlyPlus(equation)) {
            int sum = 0;
            for (char symbol : equation.toCharArray()) {
                if (Character.isDigit(symbol)) {
                    sum += Character.getNumericValue(symbol);
                }
            }

            return sum;
        }

        try {
            double result = evaluateExpression(equation);
            System.out.println("Result: " + result);
        } catch (ScriptException e) {
            e.printStackTrace();
        }

        return 0;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String equation = reader.readLine();

        System.out.println(calculateEquation(equation));
    }
}