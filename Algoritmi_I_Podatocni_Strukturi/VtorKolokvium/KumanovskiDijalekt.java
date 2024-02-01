import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

class MapEntry<K extends Comparable<K>, E> implements Comparable<K> {

    // Each MapEntry object is a pair consisting of a key (a Comparable 
    // object) and a value (an arbitrary object).
    K key;
    E value;

    public MapEntry(K key, E val) {
        this.key = key;
        this.value = val;
    }

    public int compareTo(K that) {
        // Compare this map entry to that map entry.
        @SuppressWarnings("unchecked")
        MapEntry<K, E> other = (MapEntry<K, E>) that;
        return this.key.compareTo(other.key);
    }

    public String toString() {
        return "<" + key + "," + value + ">";
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

class CBHT<K extends Comparable<K>, E> {

    // An object of class CBHT is a closed-bucket hash table, containing
    // entries of class MapEntry.
    private SLLNode<MapEntry<K, E>>[] buckets;

    @SuppressWarnings("unchecked")
    public CBHT(int m) {
        // Construct an empty CBHT with m buckets.
        buckets = (SLLNode<MapEntry<K, E>>[]) new SLLNode[m];
    }

    private int hash(K key) {
        // Napishete ja vie HASH FUNKCIJATA
        return Math.abs(key.hashCode()) % buckets.length;
    }

    public SLLNode<MapEntry<K, E>> search(K targetKey) {
        // Find which if any node of this CBHT contains an entry whose key is
        // equal
        // to targetKey. Return a link to that node (or null if there is none).
        int b = hash(targetKey);
        for (SLLNode<MapEntry<K, E>> curr = buckets[b]; curr != null; curr = curr.succ) {
            if (targetKey.equals(((MapEntry<K, E>) curr.element).key))
                return curr;
        }
        return null;
    }

    public void insert(K key, E val) {      // Insert the entry <key, val> into this CBHT.
        MapEntry<K, E> newEntry = new MapEntry<K, E>(key, val);
        int b = hash(key);
        for (SLLNode<MapEntry<K, E>> curr = buckets[b]; curr != null; curr = curr.succ) {
            if (key.equals(((MapEntry<K, E>) curr.element).key)) {
                // Make newEntry replace the existing entry ...
                curr.element = newEntry;
                return;
            }
        }
        // Insert newEntry at the front of the 1WLL in bucket b ...
        buckets[b] = new SLLNode<MapEntry<K, E>>(newEntry, buckets[b]);
    }

    public void delete(K key) {
        // Delete the entry (if any) whose key is equal to key from this CBHT.
        int b = hash(key);
        for (SLLNode<MapEntry<K, E>> pred = null, curr = buckets[b]; curr != null; pred = curr, curr = curr.succ) {
            if (key.equals(((MapEntry<K, E>) curr.element).key)) {
                if (pred == null)
                    buckets[b] = curr.succ;
                else
                    pred.succ = curr.succ;
                return;
            }
        }
    }

    public boolean containsKey(K key){
        return (search(key) != null);
    }

    public void replace(K key, E value){
        SLLNode<MapEntry<K, E>> node = search(key);
        node.element.value = value;
    }

    public E get(K key){
        SLLNode<MapEntry<K, E>> node = search(key);
        return node.element.value;
    }

    public String toString() {
        String temp = "";
        for (int i = 0; i < buckets.length; i++) {
            temp += i + ":";
            for (SLLNode<MapEntry<K, E>> curr = buckets[i]; curr != null; curr = curr.succ) {
                temp += curr.element.toString() + " ";
            }
            temp += "\n";
        }
        return temp;
    }

}

public class KumanovskiDijalekt {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        CBHT<String, String> map = new CBHT<>(100);
        HashMap<String,String> test = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String current = br.readLine();
            String[] split = current.split(" ");

            map.insert(split[0], split[1]);
            test.put(split[0], split[1]);
        }

        String text_ = br.readLine();
        String[] text = text_.split(" ");

        for (String word : text) {
            String transformToLower = word.toLowerCase();
            SLLNode<MapEntry<String, String>> result = map.search(word);
            String write = result != null ? result.element.value : null;

            if (result == null){
                result = map.search(transformToLower);
                write = result != null ? result.element.value : null;
                if (result != null) {
                    StringBuilder builder = new StringBuilder(write);

                    char value = builder.charAt(0);

                    builder.deleteCharAt(0);
                    builder.insert(0, Character.toUpperCase(value));

                    write = builder.toString();
                }

                StringBuilder builder = new StringBuilder();

                char temp = ' ';
                for (char letter : word.toCharArray()) {
                    if (letter == '.' || letter == '!' || letter == ',' || letter == '?'){
                        temp = letter;
                        continue;
                    }

                    builder.append(letter);
                }

                result = map.search(builder.toString());
                write = result != null ? result.element.value : null;

                if (result == null){
                    result = map.search(builder.toString().toLowerCase());
                    write = result != null ? result.element.value : null;

                    if (result != null) {
                        StringBuilder newBuilder = new StringBuilder(write);

                        char value = newBuilder.charAt(0);

                        newBuilder.deleteCharAt(0);
                        newBuilder.insert(0, Character.toUpperCase(value));

                        write = newBuilder.toString();
                    }

                }

                if (result != null) {
                    if (temp != ' ') {
                        StringBuilder builder1 = new StringBuilder(write);

                        builder1.append(temp);

                        write = builder1.toString();
                    }
                }
            }

            if (result != null) {
                System.out.print(write + " ");
            }else{
                System.out.print(word + " ");
            }
        }


    }
}