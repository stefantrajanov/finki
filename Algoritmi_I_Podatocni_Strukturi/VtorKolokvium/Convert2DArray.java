import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Convert2DArray {
    public static void main(String[] args) {
        int[] nums = {1, 3, 4, 1, 2, 3, 1};

        HashMap<Integer, Integer> map = new HashMap<>();
        int max = 1;

        for (int num : nums) {
            if (!map.containsKey(num)) {
                map.put(num, 1);
            } else {
                map.replace(num, map.get(num) + 1);

                if (max < map.get(num)){
                    max = map.get(num);
                }
            }
        }

        List<List<Integer>> mainList = new ArrayList<>();

        for (int i = 0; i < max; i++) {
            List<Integer> list = new ArrayList<>();
            for (int num : map.keySet()) {
                if (map.get(num) == 0){
                    continue;
                }

                list.add(num);
                map.replace(num, map.get(num) - 1);
            }

            mainList.add(list);
        }

        System.out.println(max);
        System.out.println(map.toString());

        System.out.println(mainList);
    }
}


class SolutionConvert2DArray {
    public List<List<Integer>> findMatrix(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int max = 1;

        for (int num : nums) {
            if (!map.containsKey(num)) {
                map.put(num, 1);
            } else {
                map.replace(num, map.get(num) + 1);

                if (max < map.get(num)){
                    max = map.get(num);
                }
            }
        }

        List<List<Integer>> mainList = new ArrayList<>();

        for (int i = 0; i < max; i++) {
            List<Integer> list = new ArrayList<>();
            for (int num : map.keySet()) {
                if (map.get(num) == 0){
                    continue;
                }

                list.add(num);
                map.replace(num, map.get(num) - 1);
            }

            mainList.add(list);
        }



        return mainList;
    }
}

//2610. Convert an Array Into a 2D Array With Conditions