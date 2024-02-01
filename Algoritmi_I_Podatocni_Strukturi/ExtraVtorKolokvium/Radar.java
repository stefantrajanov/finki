import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.ParseException;
import java.util.*;
import java.text.SimpleDateFormat;

class Vozac{
    String ime;
    Date time;

    public Vozac(String ime ,Date time) {
        this.ime = ime;
        this.time = time;
    }

    public Date getTime() {
        return time;
    }

    @Override
    public String toString() {
        return ime;
    }
}

public class Radar {
    public static void main(String[] args) throws IOException, ParseException {
        HashMap<String,String> map = new HashMap<String, String>();
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(bf.readLine());

        for (int i = 0; i < N; i++) {
            String[] current = bf.readLine().split(" ");

            map.put(current[0], current[1] + " " + current[2]);
        }

        int speedLimit = Integer.parseInt(bf.readLine());

        String dailyData = bf.readLine();

        String[] data = dailyData.split(" ");

        int counter = 1;
        List<String> events = new ArrayList<>();
        StringBuilder builder = new StringBuilder();
        for (String info : data) {
            builder.append(info).append(" ");
            if (counter % 3 == 0){
                events.add(builder.toString());
                builder = new StringBuilder();
                counter = 1;
                continue;
            }
            counter++;
        }
        for (String event : events) {
            String[] current = event.split(" ");
            SimpleDateFormat date = new SimpleDateFormat(current[2]);

        }

        List<Vozac> fined = new ArrayList<>();

        for (String event : events) {
            String[] current = event.split(" ");

            int speed = Integer.parseInt(current[1]);

            if (speed > speedLimit){
                String[] time = current[2].split(":");

                Date date = new Date(2024, 1, 1, Integer.parseInt(time[0]), Integer.parseInt(time[1]), Integer.parseInt(time[2]));
                Vozac vozac = new Vozac(map.get(current[0]), date);
                fined.add(vozac);
            }
        }

        Collections.sort(fined, new Comparator<Vozac>(){

            @Override
            public int compare(Vozac o1, Vozac o2) {
                return o1.time.compareTo(o2.time);
            }
        });

//        for (int i = 0; i < fined.size(); i++) {
//            int min = i;
//            for (int j = i + 1; j < fined.size(); j++) {
//                if (fined.get(min).time.compareTo(fined.get(j).time) > 0){
//                    min = j;
//                }
//            }
//
//            if (min != i){
//                Vozac temp = fined.get(i);
//                fined.set(i, fined.get(min));
//                fined.set(min, temp);
//            }
//        }

        for (Vozac fine : fined) {
            System.out.println(fine);
        }
    }
}
