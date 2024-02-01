import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.Objects;

class Lek{
    String ime;
    int pozLista;
    int cena;
    int kolicina;

    public String getIme() {                return ime;                 }
    public void setIme(String ime) {        this.ime = ime;	            }
    public int getCena() {      		    return cena;	            }
    public void setCena(int cena) {		    this.cena = cena;           }
    public int getKolicina() {  		    return kolicina;	        }
    public void setKolicina(int kolicina) { this.kolicina = kolicina;	}
    public int getPozLista() {      		return pozLista;        	}

    public Lek(String ime, int pozLista, int cena, int kolicina) {
        this.ime = ime.toUpperCase();
        this.pozLista = pozLista;
        this.cena = cena;
        this.kolicina = kolicina;
    }

    @Override
    public String toString() {
        if(pozLista==1) return ime+"\n"+"POZ\n"+cena+"\n"+kolicina;
        else return ime+"\n"+"NEG\n"+cena+"\n"+kolicina;
    }
//    @Override
//    public String toString() {
//        if(pozLista==1) return ime+" "+"POZ "+cena+" "+kolicina;
//        else return ime+" "+"NEG "+cena+" "+kolicina;
//    }
}

class LekKluch implements Comparable<LekKluch> {
    String ime;
    public LekKluch(String ime) {
        this.ime = ime.toUpperCase();
    }

    @Override
    public int hashCode() {
        int c1,c2,c3;
        c1 = ime.charAt(0);
        c2 = ime.charAt(1);
        c3 = ime.charAt(2);
        return (29*(29*(29*0 + c1)+c2)+c3)%102780;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        LekKluch lekKluch = (LekKluch) o;
        return Objects.equals(ime, lekKluch.ime);
    }

    @Override
    public String toString(){
        return ime;
    }

    @Override
    public int compareTo(LekKluch o) {
        return this.ime.compareTo(o.ime);
    }
}

class CBHT<K extends Comparable<K>, E> {
    private SLLNode<MapEntry<K,E>>[] buckets;

    @SuppressWarnings("unchecked")
    public CBHT(int m) {
        buckets = (SLLNode<MapEntry<K,E>>[]) new SLLNode[m];
    }

    private int hash(K key) {
        return Math.abs(key.hashCode()) % buckets.length;
    }

    // probajte da ja reshite ovaa zadacha bez koristenje na ovoj metod
    // try to solve this task without using this method

//     public SLLNode<MapEntry<K,E>> search(K targetKey) {
//         int b = hash(targetKey);
//         for (SLLNode<MapEntry<K,E>> curr = buckets[b]; curr != null; curr = curr.succ) {
//             if (targetKey.equals(curr.element.key))     return curr;
//         }
//         return null;
//     }
     public SLLNode<MapEntry<K,E>> findMedicine(K targetKey) {
         int b = hash(targetKey);
         for (SLLNode<MapEntry<K,E>> curr = buckets[b]; curr != null; curr = curr.succ) {
             if (curr.element.key.toString().compareTo(targetKey.toString()) == 0){
                 return curr;
             }
         }
         return null;
     }
    public void insert(K key, E val) {
        MapEntry<K, E> newEntry = new MapEntry<K, E>(key, val);
        int b = hash(key);
        for (SLLNode<MapEntry<K,E>> curr = buckets[b]; curr != null; curr = curr.succ) {
            if (key.equals(curr.element.key)) {
                curr.element = newEntry;
                return;
            }
        }
        buckets[b] = new SLLNode<MapEntry<K,E>>(newEntry, buckets[b]);
    }

    public void delete(K key) {
        int b = hash(key);
        for (SLLNode<MapEntry<K,E>> pred = null, curr = buckets[b]; curr != null; pred = curr, curr = curr.succ) {
            if (key.equals(curr.element.key)) {
                if (pred == null)   buckets[b] = curr.succ;
                else                pred.succ = curr.succ;
                return;
            }
        }
    }

    public String toString() {
        String temp = "";
        for (int i = 0; i < buckets.length; i++) {
            temp += i + ":";
            for (SLLNode<MapEntry<K,E>> curr = buckets[i]; curr != null; curr = curr.succ) {
                temp += curr.element.toString() + " ";
            }
            temp += "\n";
        }
        return temp;
    }

}

class SLLNode<E> {
    protected E element;
    protected SLLNode<E> succ;
    public SLLNode(E elem, SLLNode<E> succ) {
        this.element = elem;
        this.succ = succ;
    }
    @Override
    public String toString() {
        return element.toString();
    }
}

public class Apteka {
    public static void main(String[] args) throws  IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        CBHT<LekKluch, Lek> hashTable = new CBHT<>(N*2);
        for(int i=1;i<=N;i++){
            String pair = br.readLine();
            String[] pom = pair.split(" ");

            LekKluch key = new LekKluch(pom[0]);
            Lek medicine = new Lek(pom[0], Integer.parseInt(pom[1]), Integer.parseInt(pom[2]), Integer.parseInt(pom[3]));

            hashTable.insert(key, medicine);
        }

        while (true){
            String key = br.readLine();
            if (key.compareTo("KRAJ") == 0){
                return;
            }

            int giveMe = Integer.parseInt(br.readLine());

            SLLNode<MapEntry<LekKluch, Lek>> medicine = hashTable.findMedicine(new LekKluch(key));
            if (medicine == null){
                System.out.println("Nema takov lek");
                continue;
            }

            System.out.println(medicine.element.value);

            if (medicine.element.value.kolicina < giveMe){
                System.out.println("Nema dovolno lekovi");
                continue;
            }

            medicine.element.value.kolicina -= giveMe;
            System.out.println("Napravena naracka");
        }


//        System.out.println(hashTable.findMedicine(new LekKluch("hydroCyklin")));
    }
}
