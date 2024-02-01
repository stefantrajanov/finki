import java.util.Arrays;
import java.util.HashSet;

public class FindPrefixCommonArray {
    public static void main(String[] args) {
        int[] A = {1,3,2,4};
        int[] B = {3,1,2,4};

        int[] anwser = new int[A.length];

        for (int i = 0; i < A.length; i++) {
            HashSet<Integer> setA = new HashSet<>();
            HashSet<Integer> setB = new HashSet<>();
            HashSet<Integer> set = new HashSet<>();


            for (int j = i; j >= 0; j--) {
                setA.add(A[j]);
                set.add(A[j]);
            }

            for (int j = i; j >= 0; j--) {
                setB.add(B[j]);
                set.add(B[j]);
            }

            HashSet<Integer> anwserSet = new HashSet<>();
            for (int value : set) {
                if (setB.contains(value) && setA.contains(value)){
                    anwserSet.add(value);
                }
            }

            anwser[i] = anwserSet.size();
        }

        System.out.println(Arrays.toString(anwser));
    }
}
class SolutionFindPrefixCommonArray {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int[] anwser = new int[A.length];

        for (int i = 0; i < A.length; i++) {
            HashSet<Integer> setA = new HashSet<>();
            HashSet<Integer> setB = new HashSet<>();
            HashSet<Integer> set = new HashSet<>();


            for (int j = i; j >= 0; j--) {
                setA.add(A[j]);
                set.add(A[j]);

                setB.add(B[j]);
                set.add(B[j]);
            }

            HashSet<Integer> anwserSet = new HashSet<>();
            for (int value : set) {
                if (setB.contains(value) && setA.contains(value)){
                    anwserSet.add(value);
                }
            }

            anwser[i] = anwserSet.size();
        }

        return anwser;
    }
}

//2657. Find the Prefix Common Array of Two Arrays