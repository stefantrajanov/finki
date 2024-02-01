import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Bus {

    public static void main(String[] args) throws Exception {
        int i,j,k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        br.close();

        // Vasiot kod tuka
        int max;
        int min;

        if (m == 1 || m == 0){
            max = (n * 100);
            min = max;
            System.out.println(min);
            System.out.println(max);
            return;
        }




        if (m > n) {
            max = (n * 100) + ((m - 1) * 100);
            min = max - (max - ((m) * 100));
        }else{
            max = (n * 100) + ((m - 1) * 100);
            min = max - ((m - 1) * 100);
        }
        System.out.println(min);
        System.out.println(max);



    }

}
