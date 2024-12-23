import java.io.*;
import java.sql.Time;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class UnsupportedFormatException extends Exception {
    UnsupportedFormatException(String time) {
        super(time);
    }
}

class InvalidTimeException extends Exception {
    InvalidTimeException(String time) {
        super(time);
    }
}

class TimeTable {
    private List<LocalTime> times;

    TimeTable() {
        times = new ArrayList<>();
    }

    void readTimes(InputStream inputStream) throws UnsupportedFormatException, InvalidTimeException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream))) {
            String line;
            while ((line = reader.readLine()) != null && !line.isEmpty()) {
                line = line.replace(".", ":");
                String[] allTimes = line.split(" ");

                for (String curTime : allTimes){
                    String[] temp = curTime.split(":");

                    if (!curTime.contains(":")) {
                        throw new UnsupportedFormatException(curTime);
                    } else if (curTime.contains(":")) {
                        int left = Integer.parseInt(temp[0]);
                        int right = Integer.parseInt(temp[1]);

                        if (left < 0 || left > 23) {
                            throw new InvalidTimeException(curTime);
                        }

                        if (right < 0 || right > 59) {
                            throw new InvalidTimeException(curTime);
                        }
                    }

                    if (temp[0].length() == 1){
                        curTime = new StringBuilder("0" + curTime).toString();
                    }

                    times.add(LocalTime.parse(curTime));
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    void writeTimes(OutputStream outputStream, TimeFormat format) {
        times.sort(LocalTime::compareTo);

        if (format == TimeFormat.FORMAT_24){
            for (LocalTime time : times){
                String[] currentTime = time.toString().split(":");

                StringBuilder builder = new StringBuilder();
                if (Integer.parseInt(currentTime[0]) <= 9) {
                    builder = new StringBuilder(" " + Integer.parseInt(currentTime[0]) + ":" + currentTime[1] + '\n');
                } else{
                    builder = new StringBuilder(time.toString() + '\n');
                }
                try {
                    outputStream.write(builder.toString().getBytes());
                }
                catch (IOException e){

                }
            }
        }

        if (format != TimeFormat.FORMAT_AMPM) {
            return;
        }

        for (LocalTime time : times) {
            String[] split = time.toString().split(":");
            int left = Integer.parseInt(split[0]);
            int right = Integer.parseInt(split[1]);

            if (left == 0) {
                left += 12;
                StringBuilder builder;
                StringBuilder temp = new StringBuilder(Integer.toString(right));
                if (right < 10){
                    temp = new StringBuilder("0" + right);
                }
                if (left < 10) {
                    builder = new StringBuilder(String.format("%2d:%2s AM\n", left, temp.toString()));
                }else{
                    builder = new StringBuilder(String.format("%2d:%2s AM\n", left, temp.toString()));
                }
                try {
                    outputStream.write(builder.toString().getBytes());
                } catch (IOException e) {

                }
                continue;
            }

            if (left >= 1 && left < 12) {
                StringBuilder builder = new StringBuilder();
                StringBuilder temp = new StringBuilder(Integer.toString(right));
                if (right < 10){
                    temp = new StringBuilder("0" + right);
                }
                if (left < 10) {
                    builder = new StringBuilder(String.format("%2d:%2s AM\n", left, temp.toString()));
                }else{
                    builder = new StringBuilder(String.format("%2d:%2s AM\n", left, temp.toString()));
                }
                try {
                    outputStream.write(builder.toString().getBytes());
                } catch (IOException e) {

                }
                continue;
            }

            if (left == 12) {
                StringBuilder temp = new StringBuilder(Integer.toString(right));

                if (right < 10){
                    temp = new StringBuilder("0" + right);
                }
                StringBuilder builder = new StringBuilder(String.format("%2d:%2s PM\n", left, temp.toString()));
                try {
                    outputStream.write(builder.toString().getBytes());
                } catch (IOException e) {

                }
                continue;
            }

            if (left >= 13 && left <= 23) {
                left -= 12;
                StringBuilder builder = new StringBuilder();
                StringBuilder temp = new StringBuilder(Integer.toString(right));


                if (right < 10){
                     temp = new StringBuilder("0" + right);
                }

                if (left < 10) {
                    builder = new StringBuilder(String.format("%2d:%2s PM\n", left, temp.toString()));
                }else{
                    builder = new StringBuilder(String.format("%2d:%2s PM\n", left, temp.toString()));
                }
                try {
                    outputStream.write(builder.toString().getBytes());
                } catch (IOException e) {

                }
                continue;
            }
        }
    }

//    void sort() {
//        for (int i = 0; i < this.times.size(); i++) {
//
//            int minIndex = i;
//            String[] minTime = this.times.get(i).split(":");
//            int minLeft = Integer.parseInt(minTime[0]);
//            int minRight = Integer.parseInt(minTime[1]);
//
//            for (int j = i + 1; j < this.times.size(); j++) {
//                String[] currentTime = this.times.get(j).split(":");
//                int currentLeft = Integer.parseInt(currentTime[0]);
//                int currentRight = Integer.parseInt(currentTime[1]);
//                if (minLeft > currentLeft) {
//                    minIndex = j;
//                } else if (minLeft == currentLeft) {
//                    if (minRight > currentRight) {
//                        minIndex = j;
//                    }
//                }
//            }
//
//            if (minIndex != i) {
//                String temp = this.times.get(minIndex);
//                this.times.set(minIndex, this.times.get(i));
//                this.times.set(i, temp);
//            }
//        }
//    }
}

public class TimesTest {

    public static void main(String[] args) {
        TimeTable timeTable = new TimeTable();
        try {
            timeTable.readTimes(System.in);
        } catch (UnsupportedFormatException e) {
            System.out.println("UnsupportedFormatException: " + e.getMessage());
        } catch (InvalidTimeException e) {
            System.out.println("InvalidTimeException: " + e.getMessage());
        }
        System.out.println("24 HOUR FORMAT");
        timeTable.writeTimes(System.out, TimeFormat.FORMAT_24);
        System.out.println("AM/PM FORMAT");
        timeTable.writeTimes(System.out, TimeFormat.FORMAT_AMPM);
    }

}

enum TimeFormat {
    FORMAT_24, FORMAT_AMPM
}