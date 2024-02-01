import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

//class MapEntry<K extends Comparable<K>,E> implements Comparable<K> {
//    K key;
//    E value;
//
//    public MapEntry (K key, E val) {
//        this.key = key;
//        this.value = val;
//    }
//    public int compareTo (K that) {
//        @SuppressWarnings("unchecked")
//        MapEntry<K,E> other = (MapEntry<K,E>) that;
//        return this.key.compareTo(other.key);
//    }
//    public String toString () {
//        return "(" + key + "," + value + ")";
//    }
//}

class OBHT<K extends Comparable<K>,E> {

    private MapEntry<K,E>[] buckets;
    static final int NONE = -1; // ... distinct from any bucket index.
    @SuppressWarnings({ "rawtypes", "unchecked" })
    private static final MapEntry former = new MapEntry(null, null);
    private int occupancy = 0;

    @SuppressWarnings("unchecked")
    public OBHT (int m) {
        buckets = (MapEntry<K,E>[]) new MapEntry[m];
    }

    private int hash (K key) {
        return Math.abs(key.hashCode()) % buckets.length;
    }

    public MapEntry<K,E> getBucket(int i){
        return buckets[i];
    }

    public int search (K targetKey) {
        int b = hash(targetKey); int n_search=0;
        for (;;) {
            MapEntry<K,E> oldEntry = buckets[b];
            if (oldEntry == null)
                return NONE;
            else if (targetKey.equals(oldEntry.key))
                return b;
            else{
                b = (b + 1) % buckets.length;
                n_search++;
                if(n_search==buckets.length)
                    return NONE;
            }
        }
    }

    public void insert (K key, E val) {
        MapEntry<K,E> newEntry = new MapEntry<K,E>(key, val);
        int b = hash(key); int n_search=0;

        for (;;) {
            MapEntry<K,E> oldEntry = buckets[b];
            if (oldEntry == null) {
                if (++occupancy == buckets.length) {
                    System.out.println("Hash tabelata e polna!!!");
                }
                buckets[b] = newEntry;
                return;
            } else if (oldEntry == former
                    || key.equals(oldEntry.key)) {
                buckets[b] = newEntry;
                return;
            } else{
                b = (b + 1) % buckets.length;
                n_search++;
                if(n_search==buckets.length)
                    return;

            }
        }
    }

    @SuppressWarnings("unchecked")
    public void delete (K key) {
        int b = hash(key); int n_search=0;
        for (;;) {
            MapEntry<K,E> oldEntry = buckets[b];

            if (oldEntry == null)
                return;
            else if (key.equals(oldEntry.key)) {
                buckets[b] = former;
                return;
            } else{
                b = (b + 1) % buckets.length;
                n_search++;
                if(n_search==buckets.length)
                    return;

            }
        }
    }

    public String toString () {
        String temp = "";
        for (int i = 0; i < buckets.length; i++) {
            temp += i + ":";
            if (buckets[i] == null)
                temp += "\n";
            else if (buckets[i] == former)
                temp += "former\n";
            else
                temp += buckets[i] + "\n";
        }
        return temp;
    }
}

public class Speluvanje {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        OBHT<String, String> map = new OBHT<>(n * 2 + 1);

        for (int i = 0; i < n; i++) {
            String word = br.readLine();
            map.insert(word, word);
        }
        String sentence = br.readLine();

        String[] words = sentence.split(" ");
        List<String> errors = new ArrayList<>();

        for (String word : words) {
            int result = map.search(word);
            String current = word;
            if (result == -1){
                current = current.replaceAll("\\.", "");
                current = current.replaceAll("\\?", "");
                current = current.replaceAll(",", "");
                current = current.replaceAll("!", "");
                result = map.search(current);
                if (result == -1){
                    current = current.toLowerCase();
                    result = map.search(current);
                    if (result == -1){
                        word = word.replaceAll("\\.", "");
                        word = word.replaceAll("\\?", "");
                        word = word.replaceAll(",", "");
                        word = word.replaceAll("!", "");
                        errors.add(word);
                    }
                }
            }
        }

        if (errors.isEmpty()){
            System.out.println("Bravo");
            return;
        }

        if (errors.get(0).compareTo("") == 0){
            System.out.println("Bravo");
            return;
        }

        for (String word: errors) {
            System.out.println(word);
        }
    }
}
