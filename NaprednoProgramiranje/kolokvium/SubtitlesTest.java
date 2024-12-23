import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Subtitles {
    private List<String> subtiles;
    private List<String> originalSubs;

    Subtitles() {
        subtiles = new ArrayList<>();
        originalSubs = new ArrayList<>();
    }

    int loadSubtitles(InputStream inputStream) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
            String line = "";
            StringBuilder builder = new StringBuilder();
            StringBuilder helperBuilder = new StringBuilder();
            while ((line = reader.readLine()) != null) {
                if (line.compareTo("") == 0 || line == null) {
                    subtiles.add(builder.toString());
                    originalSubs.add(helperBuilder.toString());
                    helperBuilder = new StringBuilder();
                    builder = new StringBuilder();
                    continue;
                }

                helperBuilder.append(line).append("\n");
                builder.append(line).append(" ");
            }

            subtiles.add(builder.toString());
            originalSubs.add(helperBuilder.toString());
        } catch (Exception e) {

        }



        return subtiles.size();
    }

    void print() {
        for (int i = 0; i < this.originalSubs.size(); i++) {
            String[] split = this.subtiles.get(i).split(" ");
            String[] orignalSubsSplit = this.originalSubs.get(i).split("\n");


        ///     [17, 00:01:53,468 --> 00:01:54,745, All right.]
        ///     [17, 00:01:53,468, -->, 00:01:54,745, All, right.]

            String[] temp = orignalSubsSplit[1].split(" ");
            temp[0] = split[1];
            temp[2] = split[3];

            orignalSubsSplit[1] = String.join(" ", temp);

            System.out.println(String.join("\n", orignalSubsSplit));
            System.out.println();
        }
    }

    void shift(int shiftInMS) {
        for (int i = 0; i < this.subtiles.size(); i ++) {
            String[] split = this.subtiles.get(i).split(" ");

            LocalTime left = LocalTime.parse(split[1].replace(",", "."));
            LocalTime right = LocalTime.parse(split[3].replace(",", "."));

            if (shiftInMS < 0) {
                left = left.minusNanos(shiftInMS * -1000000L);
                right = right.minusNanos(shiftInMS  * -1000000L);
            } else {
                left = left.plusNanos(shiftInMS  * 1000000L);
                right = right.plusNanos(shiftInMS  * 1000000L);
            }

            split[1] = left.toString().replace(".", ",");
            split[3] = right.toString().replace(".", ",");

            this.subtiles.set(i, String.join(" ", split));
        }
    }
}

public class SubtitlesTest {
    public static void main(String[] args) {
        Subtitles subtitles = new Subtitles();
        int n = subtitles.loadSubtitles(System.in);
        System.out.println("+++++ ORIGINIAL SUBTITLES +++++");
        subtitles.print();
        int shift = n * 37;
        shift = (shift % 2 == 1) ? -shift : shift;
        System.out.println(String.format("SHIFT FOR %d ms", shift));
        subtitles.shift(shift);
        System.out.println("+++++ SHIFTED SUBTITLES +++++");
        subtitles.print();
    }
}

// Вашиот код овде
