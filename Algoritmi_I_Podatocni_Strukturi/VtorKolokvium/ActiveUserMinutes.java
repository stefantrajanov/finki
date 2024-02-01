import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

public class ActiveUserMinutes {
    public static void main(String[] args) {
        int[][] logs = {{1,1}, {2,2}, {2,3}};
        int k = 4;

        HashMap<Integer, HashSet<Integer>> map = new HashMap<>();
        for (int[] log : logs) {
            if (!map.containsKey(log[0])){
                HashSet<Integer> temp = new HashSet<>();
                temp.add(log[1]);

                map.put(log[0], temp);
            }else{
                HashSet<Integer> temp = map.get(log[0]);
                temp.add(log[1]);

                map.replace(log[0], temp);
            }
        }

        int[] userActiveMinutes = new int[k];
        Arrays.fill(userActiveMinutes, 0);


        for (int key : map.keySet()) {
            int values = map.get(key).size();

            userActiveMinutes[values-1]++;
        }

        System.out.println(Arrays.toString(userActiveMinutes));
        System.out.println(map.toString());
    }
}

class SolutionActiveUserMinutes {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        HashMap<Integer, HashSet<Integer>> map = new HashMap<>();
        for (int[] log : logs) {
            if (!map.containsKey(log[0])){
                HashSet<Integer> temp = new HashSet<>();
                temp.add(log[1]);

                map.put(log[0], temp);
            }else{
                HashSet<Integer> temp = map.get(log[0]);
                temp.add(log[1]);

                map.replace(log[0], temp);
            }
        }

        int[] userActiveMinutes = new int[k];
        Arrays.fill(userActiveMinutes, 0);


        for (int key : map.keySet()) {
            int values = map.get(key).size();

            userActiveMinutes[values-1]++;
        }

        return userActiveMinutes;
    }
}
//1817. Finding the Users Active Minutes