import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class GroupingPeople {

    public static void main(String[] args) {
        int[] groupSizes = {2,1,3,3,3,2};
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();

        for (int i = 0; i < groupSizes.length; i++) {
            if (!map.containsKey(groupSizes[i])) {
                map.put(groupSizes[i], new ArrayList<>());
            }
        }

        for (int i = 0; i < groupSizes.length; i++) {
            ArrayList<Integer> list = map.get(groupSizes[i]);

            list.add(i);

            map.replace(groupSizes[i], list);
        }

        System.out.println(map);

        List<List<Integer>> mainArray = new ArrayList<>();

        int i = 0;
        for (int key  : map.keySet()) {
            ArrayList<Integer> list = map.get(key);
            if (list.size() != key){
                int index = 0;
                for (int j = 0; j < list.size() / key; j++) {
                    int tempval = index;
                    ArrayList<Integer> temp = new ArrayList<>();
                    for (; index < key + tempval; index++) {

                        temp.add(list.get(index));
                    }
                    mainArray.add(temp);
                }
                continue;
            }
            mainArray.add(list);
        }

        System.out.println(mainArray);

    }
}


class SolutionGroupingPeople {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();

        for (int i = 0; i < groupSizes.length; i++) {
            if (!map.containsKey(groupSizes[i])) {
                map.put(groupSizes[i], new ArrayList<>());
            }
        }

        for (int i = 0; i < groupSizes.length; i++) {
            ArrayList<Integer> list = map.get(groupSizes[i]);

            list.add(i);

            map.replace(groupSizes[i], list);
        }

        System.out.println(map);

        List<List<Integer>> mainArray = new ArrayList<>();

        int i = 0;
        for (int key  : map.keySet()) {
            ArrayList<Integer> list = map.get(key);
            if (list.size() != key){
                int index = 0;
                for (int j = 0; j < list.size() / key; j++) {
                    int tempval = index;
                    ArrayList<Integer> temp = new ArrayList<>();
                    for (; index < key + tempval; index++) {

                        temp.add(list.get(index));
                    }
                    mainArray.add(temp);
                }
                continue;
            }
            mainArray.add(list);
        }

        return mainArray;
    }
}

//1282. Group the People Given the Group Size They Belong To