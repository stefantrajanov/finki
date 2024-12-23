import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.*;

class IrregularCanvasException extends Exception {
    public IrregularCanvasException(String id, double max) {
        super("Canvas " + id + " has a shape with area larger than " + max + "0");
    }
}

class ShapesApplicationTwo {
    private List<String> canvases;
    private double maxArea;

    ShapesApplicationTwo() {
        this.canvases = new ArrayList<>();
    }

    ShapesApplicationTwo(double maxArea) {
        this.maxArea = maxArea;
        this.canvases = new ArrayList<>();
    }

    public void readCanvases(InputStream inputStream) {
        Scanner scanner = new Scanner(inputStream);
        String line = "";
        while (line != null) {
            try {
                line = scanner.nextLine();
                String[] currentLine = line.split(" ");
                checkIfIsWithinMax(currentLine);
            } catch (Exception e) {
                if (e instanceof IrregularCanvasException) {
                    System.out.println(e.getMessage());
                    continue;
                }
                break;
            }

            canvases.add(line);
        }
    }

    void checkIfIsWithinMax(String[] canvas) throws IrregularCanvasException {
        for (int i = 2; i < canvas.length; i += 2) {
            String element = canvas[i];
            String type = canvas[i - 1];
            int number = Integer.parseInt(element);


            if (type.compareTo("C") == 0) {
                float area = (float) ((number * number) * Math.PI);
                if (area > this.maxArea) {
                    throw new IrregularCanvasException(canvas[0], this.maxArea);
                }
            } else {
                float area = (float) (number * number);
                if (area > this.maxArea) {
                    throw new IrregularCanvasException(canvas[0], this.maxArea);
                }
            }
        }
    }

    double[] canvasAreSum(String[] canvas) {
        double sum = 0;
        double minArea = Double.MAX_VALUE;
        double maxArea = Double.MIN_VALUE;

        for (int i = 2; i < canvas.length; i += 2) {
            String element = canvas[i];
            String type = canvas[i - 1];
            int number = Integer.parseInt(element);

            double area = 0;
            if (type.compareTo("C") == 0) {
                area = (number * number) * Math.PI;
            } else {
                area = (number * number);
            }

            if (maxArea < area){
                maxArea = area;
            }

            if (minArea > area){
                minArea = area;
            }

            sum += area;
        }

        double[] array = {sum, minArea, maxArea};

        return array;
    }

    int[] shapeCounter(String[] canvas) {
        int circle = 0;
        int square = 0;
        for (int i = 1; i < canvas.length; i++) {
            if (canvas[i].compareTo("C") == 0){
                circle++;
            }
            else if(canvas[i].compareTo("S") == 0) {
                square++;
            }
        }
        int[] array = {circle + square, circle, square};

        return array;
    }

    public void printCanvases(OutputStream outputStream) throws IOException {
        canvases.sort(Comparator.comparingDouble((String s) -> canvasAreSum(s.split(" "))[0]).reversed());

        for (String canvas : canvases) {
            String[] item = canvas.split(" ");
            int[] counts = shapeCounter(item);
            double[] sums = canvasAreSum(item);

            String output = String.format("%s %d %d %d %.2f %.2f %.2f\n", item[0], counts[0], counts[1], counts[2], sums[1], sums[2], sums[0] / counts[0]);

            outputStream.write(output.getBytes());
        }
    }

}

public class Shapes2Test {

    public static void main(String[] args) throws IOException {

        ShapesApplicationTwo shapesApplication = new ShapesApplicationTwo(10000);

        System.out.println("===READING CANVASES AND SHAPES FROM INPUT STREAM===");
        shapesApplication.readCanvases(System.in);

        System.out.println("===PRINTING SORTED CANVASES TO OUTPUT STREAM===");
        shapesApplication.printCanvases(System.out);

    }
}