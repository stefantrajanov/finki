import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class ShapesApplication {
    private List<String> canvases;
    private double maxArea;

    ShapesApplication() {
        this.canvases = new ArrayList<>();
    }

    ShapesApplication(double maxArea) {
        this.maxArea = maxArea;
    }

    public int readCanvases(InputStream inputStream) {
        Scanner scanner = new Scanner(inputStream);
        String line = "";
        while (line != null) {
            try {
                line = scanner.nextLine();
            } catch (Exception e) {
                break;
            }

            canvases.add(line);
        }

        int counter = 0;
        for (String canvas : canvases) {
            String[] item = canvas.split(" ");
            counter += item.length - 1;
        }

        return counter;
    }

    public void printLargestCanvasTo(OutputStream outputStream) {

        int max = 0;
        String id = "";
        int count = 0;
        for (String canvas : canvases) {
            String[] item = canvas.split(" ");

            int sum = 0;
            for (int i = 1; i < item.length; i++) {
                int number = Integer.parseInt(item[i]);
                sum += (number * 4);
            }

            if (max < sum) {
                max = sum;
                id = item[0];
                count = item.length - 1;
            }
        }
        try {
            String output = id + " " + count + " " + max;
            byte[] data = output.getBytes();

            outputStream.write(data);
        } catch (IOException e) {

        }
    }

    public void printCanvases(OutputStream outputStream) {

    }

}

public class Shapes1Test {

    public static void main(String[] args) {
        ShapesApplication shapesApplication = new ShapesApplication();

        System.out.println("===READING SQUARES FROM INPUT STREAM===");
        System.out.println(shapesApplication.readCanvases(System.in));
        System.out.println("===PRINTING LARGEST CANVAS TO OUTPUT STREAM===");
        shapesApplication.printLargestCanvasTo(System.out);

    }
}