import java.io.*;
import java.time.Duration;
import java.time.LocalDate;
import java.time.LocalTime;
import java.time.temporal.Temporal;
import java.time.temporal.TemporalAmount;
import java.util.*;

class TeamRace{
    public static void findBestTeam (InputStream is, OutputStream os) throws IOException{
        try(BufferedReader reader = new BufferedReader(new InputStreamReader(is))){
            List<String[]> racers = new ArrayList<>();
            String line;
            while ((line = reader.readLine()) != null){
                String[] splited = line.split(" ");

                LocalTime start = LocalTime.parse(splited[1]);

                LocalTime end = LocalTime.parse(splited[2]);

                Duration elapsed = Duration.between(start, end);

                long hours = elapsed.toHours();
                long minutes = elapsed.toMinutes() % 60;
                long seconds = elapsed.getSeconds() % 60;
                String formatted = String.format("%02d:%02d:%02d", hours, minutes, seconds);


                racers.add(new String[]{splited[0], formatted});
            }

            for (int i = 0; i < racers.size(); i++) {
                int minIndex = i;
                for (int j = i + 1; j < racers.size(); j++) {
                    if (LocalTime.parse(racers.get(minIndex)[1]).isAfter(LocalTime.parse(racers.get(j)[1]))){
                        minIndex = j;
                    }
                }

                if (minIndex != i){
                    String[] temp = racers.get(minIndex);
                    racers.set(minIndex, racers.get(i));
                    racers.set(i, temp);
                }
            }

            int counter = 0;
            LocalTime sum = LocalTime.of(0,0,0);
            for (String[] string : racers){
                if (counter == 4){
                    System.out.println(sum);
                    break;
                }
                System.out.println(string[0] + " " + string[1]);
                LocalTime temp = LocalTime.parse(string[1]);

                sum = sum.plusMinutes(temp.getMinute()).plusSeconds(temp.getSecond());
                counter++;
            }
        }
    }
}

public class RaceTest {
    public static void main(String[] args) {
        try {
            TeamRace.findBestTeam(System.in, System.out);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}