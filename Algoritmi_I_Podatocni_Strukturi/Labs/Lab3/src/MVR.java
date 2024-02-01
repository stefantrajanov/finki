import java.util.NoSuchElementException;
import java.util.Scanner;

class Citizen {
    private String name;
    private boolean wantsID;
    private boolean wantsPassport;
    private boolean wantsDrivingLicense;

    public Citizen(String name, int wantsID, int wantsPassport, int wantsDrivingLicense) {
        this.name = name;
        this.wantsID = wantsID == 1;
        this.wantsPassport = wantsPassport == 1;
        this.wantsDrivingLicense = wantsDrivingLicense == 1;
    }

    public boolean isWantsID() {
        return wantsID;
    }

    public void setWantsID(boolean wantsID) {
        this.wantsID = wantsID;
    }

    public boolean isWantsPassport() {
        return wantsPassport;
    }

    public void setWantsPassport(boolean wantsPassport) {
        this.wantsPassport = wantsPassport;
    }

    public boolean isWantsDrivingLicense() {
        return wantsDrivingLicense;
    }

    public void setWantsDrivingLicense(boolean wantsDrivingLicense) {
        this.wantsDrivingLicense = wantsDrivingLicense;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}

class Node {
    public Citizen data;
    public Node nextNode;

    public Node(Citizen data) {
        this.data = data;
        this.nextNode = null;
    }
}

class Queue {
    public Node head;
    public Node end;

    private int length;

    public Queue() {
        this.head = null;
        this.end = null;
        this.length = 0;
    }

    public boolean isEmpty() {
        return length == 0;
    }
    public int size() {
        return length;
    }

    public Citizen peek() {
        if(length > 0)
            return head.data;
        else
            throw new NoSuchElementException();
    }

    public void enque(Citizen newCitizen){
        Node newNode = new Node(newCitizen);

        if (length > 0){
            end.nextNode = newNode;
            end = newNode;
        }else{
            head = newNode;
            end = newNode;
        }

        length++;
    }

    public Citizen deque(){
        if (length > 0){
            Citizen temp = head.data;
            head = head.nextNode;
            length--;
            return temp;
        }else{
            throw new NoSuchElementException();
        }
    }

    public void displayQueue(){
        Node temp = head;

        while (temp != null){
            System.out.println(temp.data.getName());
            temp = temp.nextNode;
        }
    }
}


public class MVR {

    public static void printQueue(Citizen[] citizens, int n){
        Queue id = new Queue();
        Queue passport = new Queue();
        Queue driversLicense = new Queue();
        Queue finalQueue = new Queue();

        for (Citizen citizen : citizens) {
            if (citizen.isWantsID()){
                id.enque(citizen);
            } else if (citizen.isWantsPassport()) {
                passport.enque(citizen);
            } else {
                driversLicense.enque(citizen);
            }
        }

        // id
        Node temp = id.head;
        while (temp != null){
            temp.data.setWantsID(false);
            id.deque();

            if (temp.data.isWantsPassport()){
                passport.enque(temp.data);
            } else if (temp.data.isWantsDrivingLicense()){
                driversLicense.enque(temp.data);
            } else{
                finalQueue.enque(temp.data);
            }

            temp = temp.nextNode;
        }

        // passport
        Node passTemp = passport.head;
        while (passTemp != null){
            passTemp.data.setWantsPassport(false);
            passport.deque();

            if (passTemp.data.isWantsDrivingLicense()){
                driversLicense.enque(passTemp.data);
            }else{
                finalQueue.enque(passTemp.data);
            }

            passTemp = passTemp.nextNode;
        }

        //license
        Node licensetemp = driversLicense.head;
        while (licensetemp != null){
            licensetemp.data.setWantsDrivingLicense(false);
            driversLicense.deque();

            finalQueue.enque(licensetemp.data);

            licensetemp = licensetemp.nextNode;
        }


        finalQueue.displayQueue();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);



        int numberOfCitizens = Integer.parseInt(scanner.nextLine());;

        Citizen[] citizens = new Citizen[numberOfCitizens];

        for (int i = 0; i < numberOfCitizens; i++) {
            String name = scanner.nextLine();
            int wantsID = Integer.parseInt(scanner.nextLine());
            int wantsPassport = Integer.parseInt(scanner.nextLine());
            int wantsLicense = Integer.parseInt(scanner.nextLine());

            Citizen citizen = new Citizen(name, wantsID, wantsPassport, wantsLicense);

            citizens[i] = citizen;
        }

        printQueue(citizens, numberOfCitizens);
    }
}
