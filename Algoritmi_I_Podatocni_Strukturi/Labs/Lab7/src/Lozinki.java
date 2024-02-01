import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Hashtable;
import java.util.Map;


public class Lozinki {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        Hashtable<String, String> hashtable = new Hashtable<>();
        for(int i=1;i<=N;i++){
            String imelozinka = br.readLine();
            String[] pom = imelozinka.split(" ");

            hashtable.put(pom[0], pom[1]);
        }

        while (true){
            String imelozinka = br.readLine();
            String[] pom = imelozinka.split(" ");

            if (imelozinka.compareTo("KRAJ") == 0){
                return;
            }

            if (hashtable.containsKey(pom[0])){
                String tempValue = hashtable.get(pom[0]);

                if (tempValue.compareTo(pom[1]) == 0){
                    System.out.println("Najaven");
                    return;
                }else{
                    System.out.println("Nenajaven");
                }
                continue;
            }

            System.out.println("Nenajaven");
        }
    }
}
