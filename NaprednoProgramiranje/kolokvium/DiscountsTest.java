import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

class Store{
    public String name;
    public List<String> prices;

    public Store(String name, List<String> prices) {
        this.name = name;
        this.prices = prices;
    }

    public double averageDiscount(){
        double average = 0;
        for (String price : prices){
            String[] split = price.split(":");
            average += calculatePercentage(Integer.parseInt(split[0]), Integer.parseInt(split[1]));
        }
        return average / this.prices.size();
    }

    public int totalDiscount(){
        int sum = 0;
        for (String price : prices){
            String[] split = price.split(":");
            sum += Integer.parseInt(split[1]) - Integer.parseInt(split[0]);
        }
        return sum;
    }

    public int calculatePercentage(int discount, int price){
        return (int) (100 - (((double)discount/(double)price) * 100.0));
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder(String.format("%s\nAverage discount: %.1f%%\nTotal discount: %d\n", this.name, this.averageDiscount(), this.totalDiscount()));
        // Sort by discount percentage first, lexicographically second
        this.prices.sort(Comparator.comparing((String price) -> {
            String[] split = price.split(":");
            return this.calculatePercentage(
                    Integer.parseInt(split[0]), Integer.parseInt(split[1])
            );
        }).thenComparing((String price) -> {
            String[] split = price.split(":");
            return Integer.parseInt(split[1]) - Integer.parseInt(split[0]);
        }).reversed());

        for (String price : prices){
            String[] split = price.split(":");
            builder.append(String.format("%2d%% %s\n", (int)this.calculatePercentage(Integer.parseInt(split[0]), Integer.parseInt(split[1])), price.replace(":", "/")));
        }
        builder.deleteCharAt(builder.length() - 1);
        return builder.toString();
    }
}

class Discounts{
    public List<Store> stores;

    public Discounts() {
        this.stores = new ArrayList<>();
    }

    public int readStores(InputStream inputStream){
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));

        try {
            String line = "";
            while ((line = reader.readLine()) != null){
                if (line.contentEquals("STOP")){
                    break;
                }

                String[] split = line.split("  ");
                String name = split[0].split(" ")[0];
                boolean first = true;

                List<String> temp = new ArrayList<>();
                for (String price : split){
                    if (first){
                        first = false;
                        temp.add(split[0].split(" ")[1]);
                        continue;
                    }

                    temp.add(price);
                }

                this.stores.add(new Store(name, temp));
            }
        }catch (IOException e){

        }

        return this.stores.size();
    }

    public List<Store> byAverageDiscount(){
        this.stores.sort(Comparator.comparing(Store::averageDiscount).thenComparing(Store::getName).reversed());
        return this.stores.subList(0, 3);
    }

    public List<Store> byTotalDiscount(){
        this.stores.sort(Comparator.comparing(Store::totalDiscount).thenComparing(Store::getName));
        return this.stores.subList(0, 3);
    }
}

public class DiscountsTest {
    public static void main(String[] args) {
        Discounts discounts = new Discounts();
        int stores = discounts.readStores(System.in);
        System.out.println("Stores read: " + stores);
        System.out.println("=== By average discount ===");
        discounts.byAverageDiscount().forEach(System.out::println);
        System.out.println("=== By total discount ===");
        discounts.byTotalDiscount().forEach(System.out::println);
    }
}

// Vashiot kod ovde