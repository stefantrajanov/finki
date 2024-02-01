import java.util.HashMap;
import java.util.Map;

public class CenterInAStarGraph {
}

class SolutionCenterInAStarGraph {
    public int findCenter(int[][] edges) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int[] edge : edges) {
            for (int vertex : edge) {
                if (!map.containsKey(vertex)){
                    map.put(vertex, 1);
                }else{
                    map.replace(vertex, map.get(vertex) + 1);
                }
            }
        }

        for (int key : map.keySet()) {
            if (map.get(key) == edges.length){
                return key;
            }
        }
        System.out.println(map);
        return 0;
    }
}