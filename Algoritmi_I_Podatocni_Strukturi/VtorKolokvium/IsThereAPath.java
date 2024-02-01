import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class IsThereAPath {
    public static void main(String[] args) {
        int[][] temp = {{0,1},{0,2},{3,5},{5,4},{4,3}};
        System.out.println(validPath(6,temp, 0, 5 ));
    }

    public static boolean helper(Map<Integer, HashSet<Integer>> map, int source, int destination, HashSet<Integer> used){
        if (map.get(source).contains(destination)){
            return true;
        }

        for (int key : map.get(source)) {
            if (used.contains(key)){
                continue;
            }
            used.add(key);
            boolean test = helper(map, key, destination, used);

            if (test){
                return true;
            }
        }

        return false;
    }
    public static boolean validPath(int n, int[][] edges, int source, int destination) {
        Map<Integer, HashSet<Integer>> map = new HashMap<>();

        for (int[] edge : edges) {
            for (int vertex : edge){
                if (!map.containsKey(vertex)){
                    HashSet<Integer> tempHash = new HashSet<>();
                    for (int temp : edge) {
                        tempHash.add(temp);
                    }
                    tempHash.remove(vertex);
                    map.put(vertex, tempHash);
                }else{
                    HashSet<Integer> tempHash = new HashSet<>(map.get(vertex));
                    for (int temp : edge) {
                        tempHash.add(temp);
                    }
                    tempHash.remove(vertex);
                    map.replace(vertex, tempHash);
                }
            }
        }
        System.out.println(map);

        return helper(map, source, destination, new HashSet<>());
    }
}

class SolutionIsThereAPath {

    public static boolean helper(Map<Integer, HashSet<Integer>> map, int source, int destination, HashSet<Integer> used){
        if (map.get(source).contains(destination)){
            return true;
        }

        for (int key : map.get(source)) {
            if (used.contains(key)){
                continue;
            }
            used.add(key);
            boolean test = helper(map, key, destination, used);

            if (test){
                return true;
            }
        }

        return false;
    }
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        Map<Integer, HashSet<Integer>> map = new HashMap<>();

        for (int[] edge : edges) {
            for (int vertex : edge){
                if (!map.containsKey(vertex)){
                    HashSet<Integer> tempHash = new HashSet<>();
                    for (int temp : edge) {
                        tempHash.add(temp);
                    }
                    tempHash.remove(vertex);
                    map.put(vertex, tempHash);
                }else{
                    HashSet<Integer> tempHash = new HashSet<>(map.get(vertex));
                    for (int temp : edge) {
                        tempHash.add(temp);
                    }
                    tempHash.remove(vertex);
                    map.replace(vertex, tempHash);
                }
            }
        }
        System.out.println(map);
        if (map.isEmpty()){
            return true;
        }

        return helper(map, source, destination, new HashSet<>());
    }
}