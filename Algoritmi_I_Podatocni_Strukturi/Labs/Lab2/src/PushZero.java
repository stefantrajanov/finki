import java.util.Scanner;

public class PushZero {
    static void pushZerosToBeginning(int arr[], int n) {
        int safeIndex = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0 && i != 0) {
                for (int j = i - 1; j >= safeIndex; j--) {
                    int temp = arr[j];
                    arr[j] = 0;
                    arr[j + 1] = temp;
                }
                safeIndex++;
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.println("Transformiranata niza e:");
        pushZerosToBeginning(arr, n);

    }
}