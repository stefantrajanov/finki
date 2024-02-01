import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ZigZagSequence {

    static int najdiNajdolgaCikCak(int[] arr) {
        int max = 0;

        for (int i = 0; i < arr.length; i++) {
            int counter = 1;
            int lastElement = arr[i];
            for (int j = i + 1; j < arr.length; j++) {
                if ((lastElement > 0) && (arr[j] < 0)){
                    counter++;
                    lastElement = arr[j];
                }else if ((lastElement < 0) && (arr[j] > 0)){
                    counter++;
                    lastElement = arr[j];
                }else{
                    break;
                }
            }

            if (max < counter){
                max = counter;
            }
        }

        return max;
    }

    public static void main(String[] args) throws Exception {
        int i,j,k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int a[] = new int[N];
        for (i=0;i<N;i++)
            a[i] = Integer.parseInt(br.readLine());

        int rez = najdiNajdolgaCikCak(a);
        System.out.println(rez);

        br.close();

    }

}
