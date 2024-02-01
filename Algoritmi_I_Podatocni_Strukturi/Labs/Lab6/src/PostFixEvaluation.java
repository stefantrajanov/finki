import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.NoSuchElementException;
import java.util.Stack;
//interface Stack<E> {
//
//    // Elementi na stekot se objekti od proizvolen tip.
//
//    // Metodi za pristap:
//
//    public boolean isEmpty ();
//    // Vrakja true ako i samo ako stekot e prazen.
//
//    public E peek ();
//    // Go vrakja elementot na vrvot od stekot.
//
//    // Metodi za transformacija:
//
//    public void clear ();
//    // Go prazni stekot.
//
//    public void push (E x);
//    // Go dodava x na vrvot na stekot.
//
//    public E pop ();
//    // Go otstranuva i vrakja elementot shto e na vrvot na stekot.
//}

//class ArrayStack<E> implements Stack<E> {
//    private E[] elems;
//    private int depth;
//
//    @SuppressWarnings("unchecked")
//    public ArrayStack (int maxDepth) {
//        // Konstrukcija na nov, prazen stek.
//        elems = (E[]) new Object[maxDepth];
//        depth = 0;
//    }
//
//
//    public boolean isEmpty () {
//        // Vrakja true ako i samo ako stekot e prazen.
//        return (depth == 0);
//    }
//
//
//    public E peek () {
//        // Go vrakja elementot na vrvot od stekot.
//        if (depth == 0)
//            throw new NoSuchElementException();
//        return elems[depth-1];
//    }
//
//
//    public void clear () {
//        // Go prazni stekot.
//        for (int i = 0; i < depth; i++)  elems[i] = null;
//        depth = 0;
//    }
//
//
//    public void push (E x) {
//        // Go dodava x na vrvot na stekot.
//        elems[depth++] = x;
//    }
//
//
//    public E pop () {
//        // Go otstranuva i vrakja elementot shto e na vrvot na stekot.
//        if (depth == 0)
//            throw new NoSuchElementException();
//        E topmost = elems[--depth];
//        elems[depth] = null;
//        return topmost;
//    }
//}

public class PostFixEvaluation {

    static int evaluatePostfix(char [] izraz, int n) {
        Stack<Integer> stack = new Stack<>();

        StringBuilder stringBuilder = new StringBuilder();
        for (char symbol : izraz) {
            if (Character.isDigit(symbol)){
                stringBuilder.append(symbol);
            }else if (symbol == ' '){
                try {
                    stack.push(Integer.parseInt(stringBuilder.toString()));
                    stringBuilder = new StringBuilder();
                }catch (Exception exp){
                    stringBuilder = new StringBuilder();
                    // no harm done
                }
            }else {
                int first = stack.pop();
                int second = stack.pop();

                if (symbol == '*'){
                    stack.push(first * second);
                }else if (symbol == '+'){
                    stack.push(first + second);
                }else if (symbol == '/'){
                    stack.push(second / first);
                }else {
                    stack.push(second - first);
                }
            }
        }

        return stack.pop();
    }

    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String expression = br.readLine();
        char exp[] = expression.toCharArray();

        int rez = evaluatePostfix(exp, exp.length);
        System.out.println(rez);

        br.close();

    }

}