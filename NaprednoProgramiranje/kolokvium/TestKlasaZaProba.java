import java.util.ArrayList;
import java.util.Scanner;

public class TestKlasaZaProba {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        ArrayList<Integer> array = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            array.add(scanner.nextInt());
        }
        
        int counter = 0;
        int sum = 0;
        for (int element : array){
            sum+= element;
        }
        
        double average = (double) sum / array.size();

        for (int i = 0; i < array.size(); i++) {
            if (array.get(i) < average){
                counter++;
            }
        }

        for (int i = 0; true; i++) {
            if (counter < 0){
                break;
            }


            if (array.get(i) < average){
                array.remove(i);
                counter--;
                i--;
            }
        }

        System.out.println(array);
    }
}
