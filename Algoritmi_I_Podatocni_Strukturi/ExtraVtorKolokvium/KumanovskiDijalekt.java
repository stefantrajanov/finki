import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//class MapEntry<K extends Comparable<K>,E> implements Comparable<K> {
//
//    // Each MapEntry object is a pair consisting of a key (a Comparable
//    // object) and a value (an arbitrary object).
//    K key;
//    E value;
//
//    public MapEntry (K key, E val) {
//        this.key = key;
//        this.value = val;
//    }
//
//    public int compareTo (K that) {
//        // Compare this map entry to that map entry.
//        @SuppressWarnings("unchecked")
//        MapEntry<K,E> other = (MapEntry<K,E>) that;
//        return this.key.compareTo(other.key);
//    }
//
//    public String toString () {
//        return "<" + key + "," + value + ">";
//    }
//}

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

class CBHT<K extends Comparable<K>, E> {

    // An object of class CBHT is a closed-bucket hash table, containing
    // entries of class MapEntry.
    private SLLNode<MapEntry<K,E>>[] buckets;

    @SuppressWarnings("unchecked")
    public CBHT(int m) {
        // Construct an empty CBHT with m buckets.
        buckets = (SLLNode<MapEntry<K,E>>[]) new SLLNode[m];
    }

    private int hash(K key) {
        return Math.abs(key.hashCode()) % buckets.length;
    }

    public List<MapEntry<K,E>> getBuckets(){
        List<MapEntry<K,E>> list = new ArrayList<>();

        for (SLLNode<MapEntry<K,E>> head : buckets) {
            while (head != null){
                if (head.element != null){
                    list.add(head.element);
                }
                head = head.succ;
            }
        }


        return list;
    }

    public SLLNode<MapEntry<K,E>> search(K targetKey) {
        // Find which if any node of this CBHT contains an entry whose key is
        // equal
        // to targetKey. Return a link to that node (or null if there is none).
        int b = hash(targetKey);
        for (SLLNode<MapEntry<K,E>> curr = buckets[b]; curr != null; curr = curr.succ) {
            if (targetKey.equals(((MapEntry<K, E>) curr.element).key))
                return curr;
        }
        return null;
    }

    public MapEntry<K,E> getEntry(K key){
        if (containsKey(key)){
            return search(key).element;
        }

        return null;
    }

    public E get(K key){
        SLLNode<MapEntry<K,E>> current = search(key);
        if (current != null){
            return current.element.value;
        }

        return null;
    }
    public boolean containsKey(K key){
            SLLNode<MapEntry<K,E>> current = search(key);
            if (current != null){
                return true;
            }
            return false;
    }

    public void insert(K key, E val) {		// Insert the entry <key, val> into this CBHT.
        MapEntry<K, E> newEntry = new MapEntry<K, E>(key, val);
        int b = hash(key);
        for (SLLNode<MapEntry<K,E>> curr = buckets[b]; curr != null; curr = curr.succ) {
            if (key.equals(((MapEntry<K, E>) curr.element).key)) {
                // Make newEntry replace the existing entry ...
                curr.element = newEntry;
                return;
            }
        }
        // Insert newEntry at the front of the 1WLL in bucket b ...
        buckets[b] = new SLLNode<MapEntry<K,E>>(newEntry, buckets[b]);
    }

    public void delete(K key) {
        // Delete the entry (if any) whose key is equal to key from this CBHT.
        int b = hash(key);
        for (SLLNode<MapEntry<K,E>> pred = null, curr = buckets[b]; curr != null; pred = curr, curr = curr.succ) {
            if (key.equals(((MapEntry<K,E>) curr.element).key)) {
                if (pred == null)
                    buckets[b] = curr.succ;
                else
                    pred.succ = curr.succ;
                return;
            }
        }
    }

    public String toString() {
        String temp = "";
        for (int i = 0; i < buckets.length; i++) {
//            temp += i + ":";
            for (SLLNode<MapEntry<K,E>> curr = buckets[i]; curr != null; curr = curr.succ) {
                if (curr.element != null) {
                    temp += curr.element.toString() + " ";
                }
            }
//            temp += "\n";
        }
        return temp;
    }

}

public class KumanovskiDijalekt {
    public static void main (String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(
                System.in));
        int N = Integer.parseInt(br.readLine());

        String rechnik[]=new String[N];
        for(int i=0;i<N;i++){
            rechnik[i]=br.readLine();
        }

        String tekst=br.readLine();

        //Vasiot kod tuka
        CBHT<String, String> map = new CBHT<>(rechnik.length * 2 + 1);

        for (String word : rechnik) {
            String[] split = word.split(" ");
            map.insert(split[0], split[1]);
        }

        String[] text = tekst.split(" ");
        for (String word : text) {
            if (map.containsKey(word)){
                System.out.print(map.get(word) + " ");
                continue;
            }
            //////
            String changedWord = word;
            changedWord = changedWord.toLowerCase();


            // ako ima golema bukva
            if (map.containsKey(changedWord)){
                changedWord = map.get(changedWord);
                StringBuilder printWord = new StringBuilder(changedWord);
                char letter = printWord.charAt(0);
                letter = Character.toUpperCase(letter);

                printWord.deleteCharAt(0);
                printWord.insert(0, letter);
                System.out.print(printWord.toString() + " ");
                continue;
            }

            //ako ima znaci

            changedWord = word;
            changedWord = changedWord.replaceAll(",", "");
            changedWord = changedWord.replaceAll("!", "");
            changedWord = changedWord.replaceAll("\\.", "");
            changedWord = changedWord.replaceAll("\\?", "");

            if (map.containsKey(changedWord)){
                String printWord = map.get(changedWord);
                if (word.charAt(word.length() - 1) == '.'){
                    printWord += '.';
                }
                if (word.charAt(word.length() - 1) == ','){
                    printWord += ',';
                }
                if (word.charAt(word.length() - 1) == '?'){
                    printWord += '?';
                }
                if (word.charAt(word.length() - 1) == '!'){
                    printWord += '!';
                }

                System.out.print(printWord + " ");
                continue;
            }

            changedWord = changedWord.toLowerCase();

            if (map.containsKey(changedWord)){
                changedWord = map.get(changedWord);
                StringBuilder printWord = new StringBuilder(changedWord);
                char letter = printWord.charAt(0);
                letter = Character.toUpperCase(letter);

                printWord.deleteCharAt(0);
                printWord.insert(0, letter);

                if (word.charAt(word.length() - 1) == '.'){
                    printWord.append('.');
                }
                if (word.charAt(word.length() - 1) == ','){
                    printWord.append(',');
                }
                if (word.charAt(word.length() - 1) == '?'){
                    printWord.append('?');
                }
                if (word.charAt(word.length() - 1) == '!'){
                    printWord.append('!');
                }

                System.out.print(printWord.toString() + " ");
                continue;
            }



            System.out.print(word + " ");
        }
    }
}
