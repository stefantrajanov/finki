import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        DLL<Integer> firstList = new DLL<Integer>();
        DLL<Integer> secondList = new DLL<Integer>();
        for (int i = 0; i < n; i++) {
            firstList.insertLast(in.nextInt());
        }
        for (int i = 0; i < m; i++) {
            secondList.insertLast(in.nextInt());
        }
        in.close();

        connectLists(firstList,secondList);
    }

    public static void connectLists(DLL<Integer> firstList, DLL<Integer> secondList){
        DLL<Integer> connectedList = new DLL<Integer>();

        // prvata sortirana rastecki -> 1 2 3 4 5
        // vtorata sortirana opadzacki -> 5 4 3 2 1

        DLLNode<Integer> firstListNode = firstList.getLast();
        DLLNode<Integer> secondListNode = secondList.getFirst();

        while(firstListNode != null || secondListNode != null){
            if (firstListNode.element == secondListNode.element){
                connectedList.insertLast(firstListNode.element);
                connectedList.insertLast(secondListNode.element);
                firstListNode = firstListNode.pred;
                secondListNode = secondListNode.succ;
                continue;
            }



            if (firstListNode.element > secondListNode.element){
                connectedList.insertLast(firstListNode.element);
                firstListNode = firstListNode.pred;
            }else{
                connectedList.insertLast(secondListNode.element);
                secondListNode = secondListNode.succ;
            }
        }


        DLLNode<Integer> first = connectedList.getLast();
        StringBuilder result = new StringBuilder();
        if (first != null){
            while (first != null){
                result.append(first.element + "<->");
                first = first.pred;
            }
        }else{
            result.append("Prazna Lista");
        }

        System.out.println(connectedList.toString());
        System.out.println(result.toString());
    }
}