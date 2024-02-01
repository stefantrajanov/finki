import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class CheckXML {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int n = Integer.parseInt(s);
        String[] redovi = new String[n];

        for (int i = 0; i < n; i++)
            redovi[i] = br.readLine();

        int valid;

        if (isValid(redovi))
            System.out.println(1);
        else
            System.out.println(0);
        br.close();
    }

    private static boolean isValid(String[] tags) {
        Stack<String> stack = new Stack<>();

        char dash = '/';
        char bracket = '[';
        if (tags[0].contains(String.valueOf(dash))){
            return false;
        }


        for (String tag: tags) {

            if (tag.contains(String.valueOf(dash))){
                String currentPeek = stack.peek();
                stack.push(tag);

                String filteredPeek = currentPeek.replace(String.valueOf('['), "");
                filteredPeek = filteredPeek.replace(String.valueOf(']'), "");

                String temp = "[/" + filteredPeek + "]";

                if (tag.equals(temp)){
                    stack.pop();
                    stack.pop();
                }
            }else if (tag.contains(String.valueOf(bracket))) {
                stack.push(tag);
            }
        }

        return stack.empty();
    }
}
