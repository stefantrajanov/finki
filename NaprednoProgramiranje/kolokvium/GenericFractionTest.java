import java.util.Scanner;

class ZeroDenominatorException extends Exception {
    public ZeroDenominatorException() {
        super("Denominator cannot be zero");
    }
}

class GenericFraction<T extends Number, K extends Number> {
    private T numerator;
    private K denominator;

    public GenericFraction(T numerator, K denominator) throws ZeroDenominatorException {
        this.numerator = numerator;

        if (denominator.doubleValue() == 0) {
            throw new ZeroDenominatorException();
        }


        this.denominator = denominator;
    }

    public GenericFraction<Double, Double> add(GenericFraction<? extends Number, ? extends Number> gf) throws ZeroDenominatorException {
        if (this.denominator.doubleValue() == gf.denominator.doubleValue()) {

            double[] temp = strip(this.numerator.doubleValue() + gf.numerator.doubleValue(), this.denominator.doubleValue());

            return new GenericFraction<>(temp[0], temp[1]);
        }

        double newDenom = this.denominator.doubleValue() * gf.denominator.doubleValue();

        double newLeft = gf.denominator.doubleValue() * this.numerator.doubleValue();

        double newRight = this.denominator.doubleValue() * gf.numerator.doubleValue();

        double newNumerator = newLeft + newRight;

        double[] temp = strip(newNumerator, newDenom);

        return new GenericFraction<>(temp[0], temp[1]);
    }

    public double toDouble() {

        return this.numerator.doubleValue() / this.denominator.doubleValue();
    }

    public double[] strip(double left, double right) {
        double start = Math.max(left, right);
        for (double i = start; i >= 2; i--) {
            if (left % i == 0 && right % i == 0) {
                left /= i;
                right /= i;
            }
        }

        return new double[]{left, right};
    }

    @Override
    public String toString() {
        return String.format("%.2f / %.2f", Double.parseDouble(this.numerator.toString()), Double.parseDouble(this.denominator.toString()));
    }
}

public class GenericFractionTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double n1 = scanner.nextDouble();
        double d1 = scanner.nextDouble();
        float n2 = scanner.nextFloat();
        float d2 = scanner.nextFloat();
        int n3 = scanner.nextInt();
        int d3 = scanner.nextInt();
        try {
            GenericFraction<Double, Double> gfDouble = new GenericFraction<Double, Double>(n1, d1);
            GenericFraction<Float, Float> gfFloat = new GenericFraction<Float, Float>(n2, d2);
            GenericFraction<Integer, Integer> gfInt = new GenericFraction<Integer, Integer>(n3, d3);
            System.out.printf("%.2f\n", gfDouble.toDouble());
            System.out.println(gfDouble.add(gfFloat));
            System.out.println(gfInt.add(gfFloat));
            System.out.println(gfDouble.add(gfInt));
            gfInt = new GenericFraction<Integer, Integer>(n3, 0);
        } catch (ZeroDenominatorException e) {
            System.out.println(e.getMessage());
        }

        scanner.close();
    }

}

// вашиот код овде
