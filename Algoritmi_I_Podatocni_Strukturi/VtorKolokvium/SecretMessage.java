import java.util.HashMap;

public class SecretMessage {
    public static void main(String[] args) {
        String key = "the quick brown fox jumps over the lazy dog";
        String message = "vkbs bs t suepuv";
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        HashMap<Character, Character> map = new HashMap<>();

        for (int i = 0, index = 0; i < key.length(); i++, index++) {
            if (map.containsKey(key.charAt(i)) || key.charAt(i) == ' ') {
                index--;
                continue;
            }

            map.put(key.charAt(i), alphabet.charAt(index));
        }

        for (char letter : message.toCharArray()) {
            if (letter == ' '){
                System.out.print(" ");
                continue;
            }
            System.out.print(map.get(letter));
        }

    }
}

class SolutionSecretMessage {
    public String decodeMessage(String key, String message) {
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        HashMap<Character, Character> map = new HashMap<>();

        for (int i = 0, index = 0; i < key.length(); i++, index++) {
            if (map.containsKey(key.charAt(i)) || key.charAt(i) == ' ') {
                index--;
                continue;
            }

            map.put(key.charAt(i), alphabet.charAt(index));
        }

        StringBuilder builder = new StringBuilder();
        for (char letter : message.toCharArray()) {
            if (letter == ' '){
                builder.append(" ");
                continue;
            }
            builder.append(map.get(letter));
        }

        return builder.toString();
    }
}

///2325. Decode the Message