import java.util.*;

class InvalidPositionException extends Exception {
    public InvalidPositionException(int position) {
        super(String.format("Invalid position %d, alredy taken!", position));
    }
}

class Component {
    private String color;
    private int weight;
    public List<Component> components;
    private int position;

    public Component(String color, int weight) {
        this.color = color;
        this.weight = weight;
        components = new ArrayList<>();
        position = 0;
    }

    public void setPosition(int position) {
        this.position = position;
    }

    void addComponent(Component component) {
        this.components.add(component);
        this.components.sort(Comparator.comparingInt(Component::getWeight).thenComparing(Component::getColor));
    }

    public int getPosition() {
        return position;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public int getWeight() {
        return weight;
    }

    @Override
    public String toString() {
        return toStringHelper(1);
    }

    public String toStringHelper(int incrementor) {
        // Format the current component with indentation
        StringBuilder builder = new StringBuilder("---".repeat(incrementor) + String.format("%d:%s\n", weight, color));

        // Recurse over each subcomponent, increasing the indentation level
        for (Component component : components) {
            builder.append(component.toStringHelper(incrementor + 1));
        }

        return builder.toString();
    }
}

class Window {
    private String name;
    List<Component> components;

    public Window(String name) {
        this.name = name;
        this.components = new ArrayList<>();
        Collections.fill(this.components, null);
    }

    void addComponent(int position, Component component) throws InvalidPositionException {
        if (this.components.stream().anyMatch(component1 -> component1.getPosition() == position)) {
            throw new InvalidPositionException(position);
        }

        component.setPosition(position);
        this.components.add(component);
        this.components.sort(Comparator.comparingInt(Component::getPosition));
    }

    void changeColor(int weight, String color) {
        changeColorHelper(weight, color, this.components);
    }

    void changeColorHelper(int weight, String color, List<Component> components) {
        if (components.isEmpty()) {
            return;
        }
        for (Component component : components) {
            if (component.getWeight() < weight) {
                component.setColor(color);
            }
            changeColorHelper(weight, color, component.components);
        }
    }

    void swichComponents(int pos1, int pos2) {
        Component temp = this.components.stream().filter(component -> component.getPosition() == pos1).findFirst().get();
        Component temp2 = this.components.stream().filter(component -> component.getPosition() == pos2).findFirst().get();

        temp.setPosition(pos2);
        temp2.setPosition(pos1);
        this.components.sort(Comparator.comparingInt(Component::getPosition));
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder("WINDOW " + this.name).append("\n");

        this.components.forEach(component -> {
            builder.append(String.format("%d:%d:%s\n", component.getPosition(), component.getWeight(), component.getColor()));
            component.components.forEach(component1 -> builder.append(component1.toString()));
        });

        return builder.toString();
    }
}

public class ComponentTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String name = scanner.nextLine();
        Window window = new Window(name);
        Component prev = null;
        while (true) {
            try {
                int what = scanner.nextInt();
                scanner.nextLine();
                if (what == 0) {
                    int position = scanner.nextInt();
                    window.addComponent(position, prev);
                } else if (what == 1) {
                    String color = scanner.nextLine();
                    int weight = scanner.nextInt();
                    Component component = new Component(color, weight);
                    prev = component;
                } else if (what == 2) {
                    String color = scanner.nextLine();
                    int weight = scanner.nextInt();
                    Component component = new Component(color, weight);
                    prev.addComponent(component);
                    prev = component;
                } else if (what == 3) {
                    String color = scanner.nextLine();
                    int weight = scanner.nextInt();
                    Component component = new Component(color, weight);
                    prev.addComponent(component);
                } else if (what == 4) {
                    break;
                }

            } catch (InvalidPositionException e) {
                System.out.println(e.getMessage());
            }
            scanner.nextLine();
        }

        System.out.println("=== ORIGINAL WINDOW ===");
        System.out.println(window);
        int weight = scanner.nextInt();
        scanner.nextLine();
        String color = scanner.nextLine();
        window.changeColor(weight, color);
        System.out.println(String.format("=== CHANGED COLOR (%d, %s) ===", weight, color));
        System.out.println(window);
        int pos1 = scanner.nextInt();
        int pos2 = scanner.nextInt();
        System.out.println(String.format("=== SWITCHED COMPONENTS %d <-> %d ===", pos1, pos2));
        window.swichComponents(pos1, pos2);
        System.out.println(window);
    }
}

// вашиот код овде