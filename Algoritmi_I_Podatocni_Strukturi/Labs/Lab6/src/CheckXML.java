import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.NoSuchElementException;
import java.util.Stack;

public class CheckXML {

    public static int isValid(String[] tags) {
        if (tags[0].charAt(0) != '[' || (tags[0].charAt(0) == '[' && tags[0].charAt(1) == '/')) {
            return 0;
        }


        Stack<String> stack = new Stack<>();

        boolean first = true;
        for (String tag : tags) {
            if (first) {
                stack.push(tag);
                first = false;
                continue;
            }

            if (tag.charAt(0) == '[' && tag.charAt(1) == '/'){
                StringBuilder stringBuilder = new StringBuilder(tag);
                stringBuilder.deleteCharAt(0);
                stringBuilder.deleteCharAt(0);
                stringBuilder.deleteCharAt(stringBuilder.length() - 1);

                String compare = stack.pop();

                StringBuilder compareString = new StringBuilder(compare);
                compareString.deleteCharAt(0);
                compareString.deleteCharAt(compareString.length() - 1);

                if (compareString.compareTo(stringBuilder) == 0){
                    continue;
                }

                return 0;
            }


            if (tag.charAt(0) == '[') {
                stack.push(tag);
            }
        }

        if (stack.isEmpty()){
            return 1;
        }

        return 0;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int n = Integer.parseInt(s);
        String[] redovi = new String[n];

        for (int i = 0; i < n; i++)
            redovi[i] = br.readLine();

        int valid;

        // Vasiot kod tuka
        // Moze da koristite dopolnitelni funkcii ako vi se potrebni
        valid = isValid(redovi);

        System.out.println(valid);
        br.close();
    }
}