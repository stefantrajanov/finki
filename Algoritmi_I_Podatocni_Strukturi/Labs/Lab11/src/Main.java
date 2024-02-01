import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Stack;

public class Main {
    public static void calculateDistance(HashMap<String, HashMap<String, Float>> map, String startingCity, String destinationCity){
        HashMap<String, Float> start = map.get(startingCity);
        HashMap<String, Float> dest = map.get(destinationCity);

        if (start.containsKey(destinationCity)){
            System.out.println(startingCity + " " + destinationCity);
            System.out.println(destinationCity + " " + startingCity);
            System.out.println(start.get(destinationCity) + dest.get(startingCity));
            return;
        }



        Stack<String> stack = new Stack<>();
        stack.push(startingCity);
        float min = Float.MAX_VALUE;
        HashSet<String> checked = new HashSet<>();
        while (!stack.isEmpty()){
            System.out.println(stack.peek());
            HashMap<String, Float> current = map.get(stack.pop());

            if (current.containsKey(destinationCity)){
                System.out.println(destinationCity);
                stack.push(destinationCity);
                break;
            }else{
                for (String key : current.keySet()) {
                    if (key.compareTo(startingCity) == 0 || stack.contains(key) || checked.contains(key)){
                        continue;
                    }
                    stack.push(key);
                    checked.add(key);
                }
            }
        }

        while (!stack.isEmpty()){
            System.out.print(stack.pop() + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int skip = Integer.parseInt(reader.readLine());

        int n = Integer.parseInt(reader.readLine());

        HashMap<String, HashMap<String, Float>> map = new HashMap<>();
//        HashMap<String, HashMap<String, Integer>> backwords = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String[] road = reader.readLine().split(" ");
            String startingCity = road[1];
            String destinationCity = road[3];
            float distance = Float.parseFloat(road[4]);

            if (!map.containsKey(startingCity)){
                HashMap<String, Float> entry = new HashMap<>();
                entry.put(destinationCity, distance);
                map.put(startingCity, entry);
            }else{
                HashMap<String, Float> entry = map.get(startingCity);
                entry.put(destinationCity, distance);
                map.replace(startingCity, entry);
            }
        }


        String startingCity = reader.readLine();
        String destinationCity = reader.readLine();

        calculateDistance(map, startingCity, destinationCity);

        System.out.println(map);
    }
}