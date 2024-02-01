import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Node {
    public int value;
    public Node next;

    public Node(int value) {
        this.value = value;
        this.next = null;
    }
}

class Result {

    public static Node turnIntoLinkedList(List<Integer> plants){
        Node head = new Node(plants.get(0));

        Node temp = head;
        for (int i = 1; i < plants.size(); i++) {
            int value = plants.get(i);
            Node newNode = new Node(value);
            temp.next = newNode;

            temp = temp.next;
        }

        return head;
    }

    public static int poisonousPlants(List<Integer> plants) {
        Node head = turnIntoLinkedList(plants);

        Node tempPlantNode = head;
        int lastPlant = tempPlantNode.value;
        Node lastPlantNode = tempPlantNode;

        tempPlantNode = tempPlantNode.next;
        while (tempPlantNode != null) {
            int currentPlant = tempPlantNode.value;
            Node currentPlantNode = tempPlantNode;

            if (lastPlant < currentPlant){
                lastPlantNode.next = currentPlantNode.next;
                tempPlantNode = tempPlantNode.next;
                continue;
            }

            if (lastPlant > currentPlant) {
                lastPlant = currentPlant;
            }

            lastPlantNode = currentPlantNode;
            tempPlantNode = tempPlantNode.next;
        }

        return 0;
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        Vector<Integer> list = new Vector<>();

        for (int i = 0; i < n; i++) {
            list.add(scanner.nextInt());
        }

        System.out.println(Result.poisonousPlants(list));
    }
}


//        while (true){
//            boolean flag = true;
//
//            Node tempPlantNode = head;
//            int lastPlant = tempPlantNode.value;
//            Node lastPlantNode = tempPlantNode;
//
//
//            tempPlantNode = tempPlantNode.next;
//            while (tempPlantNode != null) {
//                int currentPlant = tempPlantNode.value;
//                Node currentPlantNode = tempPlantNode;
//
//                if (lastPlant < currentPlant){
//                    lastPlant = currentPlant;
////                   plants.remove(i);
//                    lastPlantNode.next = currentPlantNode.next;
//                    tempPlantNode = tempPlantNode.next;
//                    flag = false;
//                    continue;
//                }
//
//                lastPlant = currentPlant;
//                lastPlantNode = currentPlantNode;
//                tempPlantNode = tempPlantNode.next;
//            }
//
//            if (flag){
//                return counter;
//            }
//            counter++;
//
//        }