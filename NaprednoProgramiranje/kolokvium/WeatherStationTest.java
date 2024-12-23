import java.awt.*;
import java.sql.Array;
import java.sql.Time;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.*;
import java.util.List;
@SuppressWarnings("deprecation")

class DayWeatherMetrics{
    public float temperature;
    public float participation;
    public float wind;
    public float visibility;
    public Date time;

    public DayWeatherMetrics(float temperature,  float wind, float participation, float visibility, Date time) {
        this.temperature = temperature;
        this.participation = participation;
        this.wind = wind;
        this.visibility = visibility;
        this.time = time;
    }

    @Override
    public String toString(){
        return String.format("%.1f %.1f km/h %.1f%% %.1f km %s", temperature, wind, participation,visibility, time.toGMTString());
    }

    public int compareTo(Date date){
        return time.compareTo(date);
    }
}

class WeatherStation {
    private List<DayWeatherMetrics> dayMetrics;
    private int days;
    WeatherStation(int days){
        dayMetrics = new ArrayList<>();
        this.days = days;
    }


    public void addMeasurment(float temperature, float wind, float humidity, float visibility, Date date){
        DayWeatherMetrics newDay = new DayWeatherMetrics(temperature, wind, humidity, visibility, date);

        int day = Integer.parseInt(newDay.time.toString().split(" ")[2]);

        for (int i = 0; i < dayMetrics.size(); i++) {
            int currentDay = Integer.parseInt(dayMetrics.get(i).time.toString().split(" ")[2]);
            if (day - currentDay >= days) {
                dayMetrics.remove(i);
                i = 0;
            }
        }

        LocalTime newDayMinutes = LocalTime.parse(newDay.time.toString().split(" ")[3]);
        for (DayWeatherMetrics metric : dayMetrics) {
            LocalTime currentDayMinutes = LocalTime.parse(metric.time.toString().split(" ")[3]);
            float value = (float)currentDayMinutes.getMinute() - (float)newDayMinutes.getMinute();
            if (value <= 2.5 && value >= -2.5){
                return;
             }
        }



        this.dayMetrics.add(newDay);
    }

    public int total(){
        return dayMetrics.size();
    }
    public void status(Date from, Date to){
//        for (int i = 0; i < dayMetrics.size(); i++) {
//            int minIndex = i;
//            for (int j = 1; j < dayMetrics.size(); j++) {
//                if (dayMetrics.get(minIndex).time.after(dayMetrics.get(j).time)){
//                    minIndex = j;
//                }
//            }
//            if (minIndex != i){
//                DayWeatherMetrics temp = dayMetrics.get(minIndex);
//                this.dayMetrics.set(minIndex, this.dayMetrics.get(i));
//                this.dayMetrics.set(i, temp);
//            }
//        }

        this.dayMetrics.sort(Comparator.comparing(day -> day.time));

        float averageTemp = 0;
        int counter = 0;
        for (DayWeatherMetrics metric : dayMetrics) {
            if (metric.time.before(from) || metric.time.after(to)){
                continue;
            }

            System.out.println(metric.toString());
            counter++;
            averageTemp +=metric.temperature;
        }

        if (counter == 0){
            throw new RuntimeException();
        }

        System.out.println(String.format("Average temperature: %.2f",averageTemp / counter));
    }

}

public class WeatherStationTest {
    public static void main(String[] args) throws ParseException {
        Scanner scanner = new Scanner(System.in);
        DateFormat df = new SimpleDateFormat("dd.MM.yyyy HH:mm:ss");
        int n = scanner.nextInt();
        scanner.nextLine();
        WeatherStation ws = new WeatherStation(n);
        while (true) {
            String line = scanner.nextLine();
            if (line.equals("=====")) {
                break;
            }
            String[] parts = line.split(" ");
            float temp = Float.parseFloat(parts[0]);
            float wind = Float.parseFloat(parts[1]);
            float hum = Float.parseFloat(parts[2]);
            float vis = Float.parseFloat(parts[3]);
            line = scanner.nextLine();
            Date date = df.parse(line);
            ws.addMeasurment(temp, wind, hum, vis, date);
        }
        String line = scanner.nextLine();
        Date from = df.parse(line);
        line = scanner.nextLine();
        Date to = df.parse(line);
        scanner.close();
        System.out.println(ws.total());
        try {
            ws.status(from, to);
        } catch (RuntimeException e) {
            System.out.println(e);
        }
    }
}

// vashiot kod ovde