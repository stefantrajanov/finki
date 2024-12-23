import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

enum Color {
    RED, GREEN, BLUE
}

interface Scalable {
    void scale(float scaleFactor);
}

interface Stackable {
    float weight();
}

abstract class Shape implements Scalable, Stackable {
    protected String id;
    protected Color color;

    public String getId() {
        return this.id;
    }
}

class Circle extends Shape {
    public float radius;

    public Circle(String id, Color color, float radius) {
        this.id = id;
        this.color = color;
        this.radius = radius;
    }

    @Override
    public void scale(float scaleFactor) {
        this.radius *= scaleFactor;
    }

    @Override
    public float weight() {
        return (float) this.radius * (float) this.radius * (float) Math.PI;
    }

    @Override
    public String toString() {
        return "C: ";
    }
}

class Rectangle extends Shape {
    public float width;
    public float height;

    public Rectangle(String id, Color color, float width, float height) {
        this.id = id;
        this.color = color;
        this.width = width;
        this.height = height;
    }

    @Override
    public void scale(float scaleFactor) {
        this.width *= scaleFactor;
        this.height *= scaleFactor;
    }

    @Override
    public float weight() {
        return this.height * this.width;
    }

    @Override
    public String toString() {
        return "R: ";
    }
}

class Canvas {
    List<Shape> shapes;

    Canvas() {
        this.shapes = new ArrayList<>();
    }

    public void add(String id, Color color, float width, float height) {
        Rectangle newShape = new Rectangle(id, color, width, height);

        if (shapes.isEmpty()) {
            shapes.add(newShape);

            return;
        }

        float currentWeight = newShape.weight();

        for (int i = 0; i < shapes.size(); i++) {
            if (currentWeight >= shapes.get(i).weight()) {
                if (i == 0){
                    shapes.add(0, newShape);
                    return;
                }

                shapes.add(i, newShape);
                return;
            }else if (currentWeight == shapes.get(i).weight()) {
                shapes.add(i+1, newShape);
                return;
            }
        }

        shapes.add(newShape);
//        shapes.sort(Comparator.comparing(Shape::weight).reversed());
    }

    void goRight(int index) {

    }

    void goLeft(int index) {

    }

    public void add(String id, Color color, float radius) {
        Circle newShape = new Circle(id, color, radius);

        if (shapes.isEmpty()) {
            shapes.add(newShape);
            return;
        }

        float currentWeight = newShape.weight();

        for (int i = 0; i < shapes.size(); i++) {
            if (currentWeight >= shapes.get(i).weight()) {
                if (i == 0){
                    shapes.add(0, newShape);
                    return;
                }

                shapes.add(i, newShape);
                return;
            }else if (currentWeight == shapes.get(i).weight()) {
                shapes.add(i+1, newShape);
                return;
            }
        }

        shapes.add(newShape);
//        shapes.sort(Comparator.comparing(Shape::weight).reversed());
    }

    public void scale(String id, float scaleFactor) {
        Shape selectedShape = shapes.stream().filter(shape -> shape.getId().compareTo(id) == 0).findFirst().get();
        selectedShape.scale(scaleFactor);

        this.shapes.remove(selectedShape);

        float currentWeight = selectedShape.weight();

        for (int i = 0; i < shapes.size(); i++) {
            if (currentWeight > shapes.get(i).weight()) {
                if (i == 0){
                    shapes.add(0, selectedShape);
                    return;
                }

                shapes.add(i, selectedShape);
                return;
            }else if (currentWeight == shapes.get(i).weight()) {
                shapes.add(i+1, selectedShape);
                return;
            }
        }

        shapes.add(selectedShape);
    }


    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        for (Shape shape : this.shapes) {
            builder.append(shape.toString()).append(String.format("%-4s %-6s %13.2f%n", shape.id, shape.color, shape.weight()));
        }

        return builder.toString();
    }

}

public class ShapesTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Canvas canvas = new Canvas();
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            String[] parts = line.split(" ");
            int type = Integer.parseInt(parts[0]);
            String id = parts[1];
            if (type == 1) {
                Color color = Color.valueOf(parts[2]);
                float radius = Float.parseFloat(parts[3]);
                canvas.add(id, color, radius);
            } else if (type == 2) {
                Color color = Color.valueOf(parts[2]);
                float width = Float.parseFloat(parts[3]);
                float height = Float.parseFloat(parts[4]);
                canvas.add(id, color, width, height);
            } else if (type == 3) {
                float scaleFactor = Float.parseFloat(parts[2]);
                System.out.println("ORIGNAL:");
                System.out.print(canvas);
                canvas.scale(id, scaleFactor);
                System.out.printf("AFTER SCALING: %s %.2f\n", id, scaleFactor);
                System.out.print(canvas);
            }

        }
    }
}

