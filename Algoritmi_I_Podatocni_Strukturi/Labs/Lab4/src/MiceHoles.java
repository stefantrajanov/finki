import java.util.Arrays;
import java.util.Scanner;

public class MiceHoles {

    //TODO: implement function
    public static int minTime(int[] mice, int[] holes) {
        mice = Arrays.stream(mice).sorted().toArray();
        holes = Arrays.stream(holes).sorted().toArray();

        int max = 0;
        for (int i = 0; i < mice.length; i++) {
            int temp = Math.abs(mice[i] - holes[i]);

            if (max < temp){
                max = temp;
            }
        }

        return max;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String line = input.nextLine();
        String parts[] = line.split(" ");
        int mice[] = new int[parts.length];
        for(int i=0;i<parts.length;i++) {
            mice[i] = Integer.parseInt(parts[i]);
        }

        line = input.nextLine();
        parts = line.split(" ");
        int holes[] = new int[parts.length];
        for(int i=0;i<parts.length;i++) {
            holes[i] = Integer.parseInt(parts[i]);
        }

        System.out.println(minTime(mice, holes));
    }
}
