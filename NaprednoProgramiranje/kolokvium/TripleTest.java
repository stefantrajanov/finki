import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Triple<T extends Comparable<T>> {
    T first;
    T second;
    T third;
    public Triple(T first, T second, T third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }

    public double max(){
        T max = first;

        if (max.compareTo(second) < 0){
            max = second;
        }

        if (max.compareTo(third) < 0){
            max = third;
        }

        return Double.parseDouble(max.toString());
    }

    public double average(){
        double first = Double.parseDouble(this.first.toString());
        double second = Double.parseDouble(this.second.toString());
        double third = Double.parseDouble(this.third.toString());

        double sum = first + second + third;

        return sum / 3.0;
    }

    public void sort(){
        List<T> list = new ArrayList<>();

        list.add(first);
        list.add(second);
        list.add(third);

        list.sort(T::compareTo);

        first = list.get(0);
        second = list.get(1);
        third = list.get(2);
    }

    @Override
    public String toString(){
        double first = Double.parseDouble(this.first.toString());
        double second = Double.parseDouble(this.second.toString());
        double third = Double.parseDouble(this.third.toString());


        return String.format("%.2f %.2f %.2f", first, second, third);
    }
}

public class TripleTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        Triple<Integer> tInt = new Triple<Integer>(a, b, c);
        System.out.printf("%.2f\n", tInt.max());
        System.out.printf("%.2f\n", tInt.average());
        tInt.sort();
        System.out.println(tInt);
        float fa = scanner.nextFloat();
        float fb = scanner.nextFloat();
        float fc = scanner.nextFloat();
        Triple<Float> tFloat = new Triple<Float>(fa, fb, fc);
        System.out.printf("%.2f\n", tFloat.max());
        System.out.printf("%.2f\n", tFloat.average());
        tFloat.sort();
        System.out.println(tFloat);
        double da = scanner.nextDouble();
        double db = scanner.nextDouble();
        double dc = scanner.nextDouble();
        Triple<Double> tDouble = new Triple<Double>(da, db, dc);
        System.out.printf("%.2f\n", tDouble.max());
        System.out.printf("%.2f\n", tDouble.average());
        tDouble.sort();
        System.out.println(tDouble);
    }
}
// vasiot kod ovde
// class Triple


