import java.util.*;
import java.util.stream.Stream;

public class FoodTables {
    public static void main(String[] args) {

    }
}
class SolutionFoodTables {
    public List<List<String>> displayTable(List<List<String>> orders) {
        HashMap<Integer, HashMap<String, Integer>> tablesMap = new HashMap<>();
        HashSet<String> hashedOrders = new HashSet<>();

        for (List<String> order : orders) {
            int tableNumber = Integer.parseInt(order.get(1));
            String food = order.get(2);

            hashedOrders.add(food);

            if (!tablesMap.containsKey(tableNumber)){
                HashMap<String, Integer> map = new HashMap<>();
                map.put(food, 1);

                tablesMap.put(tableNumber, map);
            }else{
                HashMap<String, Integer> map = tablesMap.get(tableNumber);

                if (!map.containsKey(food)){
                    map.put(food, 1);
                }else{
                    map.replace(food, map.get(food) + 1);
                }

                tablesMap.replace(tableNumber, map);
            }
        }
        List<String> sortedOrders = new ArrayList<>(hashedOrders.stream().toList());
        Collections.sort(sortedOrders);
        sortedOrders.add(0, "Table");
        List<List<String>> main = new ArrayList<>();
        main.add(sortedOrders);

        List<Integer> sortedKeys = new ArrayList<>(tablesMap.keySet().stream().toList());
        Collections.sort(sortedKeys);

        for (int key : sortedKeys) {
            List<String> table = new ArrayList<>();
            for (String food : sortedOrders) {
                if (food.compareTo("Table") == 0){
                    table.add(Integer.toString(key));
                    continue;
                }
                HashMap<String, Integer> map = tablesMap.get(key);

                if (map.containsKey(food)){
                    table.add(map.get(food).toString());
                }else{
                    table.add("0");
                }
            }
            main.add(table);
        }

        System.out.println();
        System.out.println(tablesMap);
        System.out.println(hashedOrders);
        System.out.println(sortedOrders);

        return main;
    }
}
//1418. Display Table of Food Orders in a Restaurant