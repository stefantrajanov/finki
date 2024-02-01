import java.util.*;

interface Queue<E> {

    // Elementi na redicata se objekti od proizvolen tip.

    // Metodi za pristap:

    public boolean isEmpty();
    // Vrakja true ako i samo ako redicata e prazena.

    public int size();
    // Ja vrakja dolzinata na redicata.

    public E peek();
    // Go vrakja elementot na vrvot t.e. pocetokot od redicata.

    // Metodi za transformacija:

    public void clear();
    // Ja prazni redicata.

    public void enqueue(E x);
    // Go dodava x na kraj od redicata.

    public E dequeue();
    // Go otstranuva i vrakja pochetniot element na redicata.
}

class ArrayQueue<E> implements Queue<E> {

    // Redicata e pretstavena na sledniot nacin:
    // length go sodrzi brojot na elementi.
    // Ako length > 0, togash elementite na redicata se zachuvani vo elems[front...rear-1]
    // Ako rear > front, togash vo  elems[front...maxlength-1] i elems[0...rear-1]
    E[] elems;
    int length, front, rear;

    // Konstruktor ...

    @SuppressWarnings("unchecked")
    public ArrayQueue(int maxlength) {
        elems = (E[]) new Object[maxlength];
        clear();
    }

    public boolean isEmpty() {
        // Vrakja true ako i samo ako redicata e prazena.
        return (length == 0);
    }

    public int size() {
        // Ja vrakja dolzinata na redicata.
        return length;
    }

    public E peek() {
        // Go vrakja elementot na vrvot t.e. pocetokot od redicata.
        if (length > 0)
            return elems[front];
        else
            throw new NoSuchElementException();
    }

    public void clear() {
        // Ja prazni redicata.
        length = 0;
        front = rear = 0;  // arbitrary
    }

    public void enqueue(E x) {
        // Go dodava x na kraj od redicata.
        elems[rear++] = x;
        if (rear == elems.length) rear = 0;
        length++;
    }

    public E dequeue() {
        // Go otstranuva i vrakja pochetniot element na redicata.
        if (length > 0) {
            E frontmost = elems[front];
            elems[front++] = null;
            if (front == elems.length) front = 0;
            length--;
            return frontmost;
        } else
            throw new NoSuchElementException();
    }
}


class Gragjanin {
    String name;
    boolean id;
    boolean passport;
    boolean driversLicense;

    public Gragjanin(String name, int id, int passport, int driversLicense) {
        this.name = name;
        this.id = id == 1;
        this.passport = passport == 1;
        this.driversLicense = driversLicense == 1;
    }

    public boolean isFinished() {
        return (!id && !passport && !driversLicense);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean isId() {
        return id;
    }

    public void setId(boolean id) {
        this.id = id;
    }

    public boolean isPassport() {
        return passport;
    }

    public void setPassport(boolean passport) {
        this.passport = passport;
    }

    public boolean isDriversLicense() {
        return driversLicense;
    }

    public void setDriversLicense(boolean driversLicense) {
        this.driversLicense = driversLicense;
    }

    @Override
    public String toString(){

        return name;
    }
}

public class MVR {

    public static void findQueue(ArrayList<Gragjanin> citizens) {
        Queue<Gragjanin> idQueue = new ArrayQueue<>(citizens.size());
        Queue<Gragjanin> passportQueue = new ArrayQueue<>(citizens.size());
        Queue<Gragjanin> driversLicenseQueue = new ArrayQueue<>(citizens.size());

        for (Gragjanin cititzen : citizens) {
            if (cititzen.id) {
                idQueue.enqueue(cititzen);
            } else if (cititzen.passport) {
                passportQueue.enqueue(cititzen);
            } else if (cititzen.driversLicense) {
                driversLicenseQueue.enqueue(cititzen);
            }
        }

        for (int i = 0; !idQueue.isEmpty(); i++) {
            Gragjanin temp = idQueue.dequeue();
            temp.setId(false);
            if (temp.isFinished()){
                System.out.println(temp.name);
            }
            else{
                if (temp.passport){
                    passportQueue.enqueue(temp);
                }else {
                    driversLicenseQueue.enqueue(temp);
                }
            }
        }

        for (int i = 0; !passportQueue.isEmpty(); i++) {
            Gragjanin temp = passportQueue.dequeue();
            temp.setPassport(false);
            if (temp.isFinished()){
                System.out.println(temp.name);
            }
            else{
                driversLicenseQueue.enqueue(temp);
            }
        }

        for (int i = 0; !driversLicenseQueue.isEmpty(); i++) {
            Gragjanin temp = driversLicenseQueue.dequeue();
            temp.setDriversLicense(false);
            System.out.println(temp.name);
        }

    }

    public static void main(String[] args) {

        Scanner br = new Scanner(System.in);

        int N = Integer.parseInt(br.nextLine());
        ArrayList<Gragjanin> gragjani = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            String imePrezime = br.nextLine();
            int lKarta = Integer.parseInt(br.nextLine());
            int pasos = Integer.parseInt(br.nextLine());
            int vozacka = Integer.parseInt(br.nextLine());
            Gragjanin covek = new Gragjanin(imePrezime, lKarta, pasos, vozacka);
            gragjani.add(covek);
        }

        findQueue(gragjani);
    }
}
