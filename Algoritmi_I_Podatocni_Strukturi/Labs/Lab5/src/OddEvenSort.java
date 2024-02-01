import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class OddEvenSort {

    static void oddEvenSort(int arr[], int n)
    {
        int index = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 2 != 0){
                int temp = i;
                while (temp > index){
                    int safe = arr[temp - 1];
                    arr[temp - 1] = arr[temp];
                    arr[temp] = safe;
                    temp--;
                }
            }
        }


        int nextStart = 0;
        for (int i = 0; i < arr.length; i++) {
            int minIndex = i;

            for (int j = i; j < arr.length; j++) {
                if (arr[j] % 2 != 0){
                    if (arr[minIndex] > arr[j]) {
                        minIndex = j;
                    }
                }
            }
            if (i != minIndex) {
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }

        for (int element : arr) {
            if (element % 2 == 0){
                break;
            }
            nextStart++;
        }

        for (int i = nextStart; i < arr.length; i++) {
            int maxIndex = i;

            for (int j = i; j < arr.length; j++) {
                if (arr[maxIndex] < arr[j]) {
                    maxIndex = j;
                }
            }

            if (i != maxIndex) {
                int temp = arr[i];
                arr[i] = arr[maxIndex];
                arr[maxIndex] = temp;
            }
        }
    }

    public static void poarnoResenie(int[] arr){
        ArrayList<Integer> odd = new ArrayList<>();
        ArrayList<Integer> even = new ArrayList<>();

        for (int element : arr) {
            if (element % 2 == 0){
                even.add(element);
            }else{
                odd.add(element);
            }
        }
        Collections.sort(odd);
        Collections.sort(even);

        for (int i = even.size() - 1; i >= 0; i--) {
            odd.add(even.get(i));
        }

        System.out.println(odd);
    }

    public static void main(String[] args) throws IOException{
        int i;
        BufferedReader stdin = new BufferedReader( new InputStreamReader(System.in));
        String s = stdin.readLine();
        int n = Integer.parseInt(s);

        s = stdin.readLine();
        String [] pom = s.split(" ");
        int [] a = new int[n];
        for(i=0;i<n;i++)
            a[i]=Integer.parseInt(pom[i]);
        poarnoResenie(a);
        for(i=0;i<n-1;i++)
            System.out.print(a[i]+" ");
        System.out.print(a[i]);
    }
}