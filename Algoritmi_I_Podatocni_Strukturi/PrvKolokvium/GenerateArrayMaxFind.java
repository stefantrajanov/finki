import java.util.Arrays;

public class GenerateArrayMaxFind {
    public static int getMaximumGenerated(int n) {
        int[] arr = new int[n + 1];
        if (n == 1 || n == 0){
            return n;
        }

        arr[0] = 0;
        arr[1] = 1;
        for (int i = 0; i <= n; i++) {
            if ((2 * i) <= n && (2 * i) >= 2) {
                arr[2 * i] = arr[i];
            }
        }

        for (int i = 0; i <= n; i++) {
            if ((2 * i + 1) <= n && (2 * i + 1) >= 2) {
                arr[2 * i + 1] = arr[i] + arr[i + 1];
            }
        }

        for (int i = 0; i <= n; i++) {
            if ((2 * i) <= n && (2 * i) >= 2) {
                arr[2 * i] = arr[i];
            }
        }

        for (int i = 0; i <= n; i++) {
            if ((2 * i + 1) <= n && (2 * i + 1) >= 2) {
                arr[2 * i + 1] = arr[i] + arr[i + 1];
            }
        }

        for (int i = 0; i <= n; i++) {
            if ((2 * i) <= n && (2 * i) >= 2) {
                arr[2 * i] = arr[i];
            }
        }

        for (int i = 0; i <= n; i++) {
            if ((2 * i + 1) <= n && (2 * i + 1) >= 2) {
                arr[2 * i + 1] = arr[i] + arr[i + 1];
            }
        }



        int max = arr[0];
        for (int number : arr) {
            max = Math.max(number, max);
        }

        System.out.println(Arrays.toString(arr));
        return max;
    }

    public static void main(String[] args) {
        System.out.println(getMaximumGenerated(43));
    }
}
