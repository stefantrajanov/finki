import javax.swing.plaf.IconUIResource;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class TownJudge {
    public static void main(String[] args) {
        int[][] test = {{1,3}, {2,3}, {3,1}};
        findJudge(3, test);
    }

    public static int findJudge(int n, int[][] trust) {
        Map<Integer, HashSet<Integer>> map = new HashMap<>();

        for (int i = 1; i <= n; i++) {
            map.put(i, new HashSet<>());
        }

        for (int[] relationship : trust) {
            if (!map.containsKey(relationship[0])){
                HashSet<Integer> temp = new HashSet<>();
                temp.add(relationship[1]);
                map.put(relationship[0], temp);
            }else{
                HashSet<Integer> temp = new HashSet<>(map.get(relationship[0]));
                temp.add(relationship[1]);

                map.replace(relationship[0], temp);
            }
        }

        boolean flag = false;
        int theJudge = -1;
        for (int key : map.keySet()) {
            if (map.get(key).isEmpty()){
                if (flag){
                    return -1;
                }
                theJudge = key;
                flag = true;
            }
        }

        if (theJudge == -1){
            return theJudge;
        }


        for (int key : map.keySet()) {
            if (key == theJudge){
                continue;
            }
            if (!map.get(key).contains(theJudge)){
                return -1;
            }
        }


        System.out.println(map);
        System.out.println(theJudge);
        return theJudge;
    }
}
class SolutionTownJudge {
    public static int findJudge(int n, int[][] trust) {
        Map<Integer, HashSet<Integer>> map = new HashMap<>();

        for (int i = 1; i <= n; i++) {
            map.put(i, new HashSet<>());
        }

        for (int[] relationship : trust) {
            if (!map.containsKey(relationship[0])){
                HashSet<Integer> temp = new HashSet<>();
                temp.add(relationship[1]);
                map.put(relationship[0], temp);
            }else{
                HashSet<Integer> temp = new HashSet<>(map.get(relationship[0]));
                temp.add(relationship[1]);

                map.replace(relationship[0], temp);
            }
        }

        boolean flag = false;
        int theJudge = -1;
        for (int key : map.keySet()) {
            if (map.get(key).isEmpty()){
                if (flag){
                    return -1;
                }
                theJudge = key;
                flag = true;
            }
        }

        if (theJudge == -1){
            return theJudge;
        }


        for (int key : map.keySet()) {
            if (key == theJudge){
                continue;
            }
            if (!map.get(key).contains(theJudge)){
                return -1;
            }
        }


        System.out.println(map);
        return theJudge;
    }
}