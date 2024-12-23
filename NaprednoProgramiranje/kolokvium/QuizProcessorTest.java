import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

class QuizError extends Exception {
    public QuizError() {
        super("A quiz must have same number of correct and selected answers");
    }
}

class QuizProcessor {

    public static Map<String, Double> processAnswers(InputStream inputStream) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        Map<String, Double> resultMap = new TreeMap<>();
        try {
            String line = "";
            while ((line = reader.readLine()) != null) {
                String[] split = line.split(";");
                String index = split[0];
                String[] questionAnswers = split[1].split(", ");
                String[] studentAnswers = split[2].split(", ");

                try {
                    if (questionAnswers.length != studentAnswers.length) {
                        throw new QuizError();
                    }
                } catch (QuizError exp) {
                    System.out.println(exp.getMessage());
                    continue;
                }

                resultMap.putIfAbsent(index, calculatePoints(questionAnswers, studentAnswers));
            }
        } catch (IOException e) {

        }

        return resultMap;
    }

    static double calculatePoints(String[] questionAnswers, String[] studentAnswers) {
        double sum = 0;
        for (int i = 0; i < questionAnswers.length; i++) {
            if (questionAnswers[i].contentEquals(studentAnswers[i])) {
                sum += 1;
            }else{
                sum -= 0.25;
            }
        }
        return sum;
    }
}

public class QuizProcessorTest {
    public static void main(String[] args) {
        QuizProcessor.processAnswers(System.in).forEach((k, v) -> System.out.printf("%s -> %.2f%n", k, v));
    }
}