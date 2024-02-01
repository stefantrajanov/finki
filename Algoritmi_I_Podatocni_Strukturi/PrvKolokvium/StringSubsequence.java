public class StringSubsequence {

    public static String filterWord(String wordToFilter, String word){
        StringBuilder newWord = new StringBuilder();

        int lastIndex = 0;
        for (int i = 0; i < word.length(); i++) {
            char currentLetterToAdd = word.charAt(i);
            for (int j = lastIndex; j < wordToFilter.length(); j++) {
                if (wordToFilter.charAt(j) == currentLetterToAdd){
                    newWord.append(currentLetterToAdd);
                    lastIndex = ++j;
                    break;
                }
            }
        }

        return newWord.toString();
    }
    public static boolean isSubsequence(String s, String t) {
        String first = s;
        String second = t;

        second = filterWord(second, first);

        return first.compareTo(second) == 0;
    }

    public static void main(String[] args) {
        System.out.println(isSubsequence("abc", "ahbgdc"));
    }
}
