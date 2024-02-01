import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SumOfAbsoluteDifferences {
    private static int solve(int numbers[], int n, int k) {
        // vasiot kod ovde
        // mozete da napisete i drugi funkcii dokolku vi se potrebni
        int []bestNums= new int[k];


        int counter = 0;
        for (int i = 0; i < n; i+=2) {
            // for max
            int max = -1;
            int maxIndex = -1;
            for (int j = 0; j < n; j++) {
                if (max < numbers[j]){
                    max = numbers[j];
                    maxIndex = j;
                }
            }

            // for min
            int min = -1;
            int minIndex = -1;
            for (int j = 0; j < n; j++) {
                if (min == -1 && (numbers[j] != (-2))){
                    min = numbers[j];
                    minIndex = j;
                    continue;
                }

                if ( (min > numbers[j]) && (numbers[j] != (-2)) ){
                    min = numbers[j];
                    minIndex = j;
                }
            }

            // turi u novata niza
            if (counter < k) {
                if ((counter + 1) < k) {
                    bestNums[i] = min;
                    bestNums[i + 1] = max;
                    counter+=2;

                }else{
                    bestNums[i] = min;
                    counter++;
                }
            }


            if (counter >= k){
                break;
            }
            // izbrisi na kraj
            numbers[maxIndex] = -2;
            numbers[minIndex] = -2;

        }

        int sum = 0;
        for (int i = 0; i < k - 1; i++) {
            int currentSum = Math.abs(bestNums[i+1] - bestNums[i]);
            sum += currentSum;
        }

        for (int i = 0; i < k; i++) {
            System.out.print(bestNums[i] + " ");
        }

        return sum;
    }

    public static void main(String[] args) throws Exception {
        int i,j,k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int numbers[] = new int[N];

        st = new StringTokenizer(br.readLine());
        for (i=0;i<N;i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }

        int res = solve(numbers, N, K);
        System.out.println(res);

        br.close();

    }
}
