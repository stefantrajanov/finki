import java.util.Iterator;
import java.util.Scanner;
import java.util.Stack;

class DLLNode<E> {
    protected E element;
    protected DLLNode<E> pred, succ;
    public DLLNode(E elem, DLLNode<E> pred, DLLNode<E> succ) {
        this.element = elem;
        this.pred = pred;
        this.succ = succ;
    }

    @Override
    public String toString() {
        return element.toString();
    }
}

class DLL<E> {
    private DLLNode<E> first, last;

    public DLL() {
        // Construct an empty SLL
        this.first = null;
        this.last = null;
    }

    public void insertFirst(E o) {
        DLLNode<E> ins = new DLLNode<E>(o, null, first);
        if (first == null)
            last = ins;
        else
            first.pred = ins;
        first = ins;
    }

    public void insertLast(E o) {
        if (first == null)
            insertFirst(o);
        else {
            DLLNode<E> ins = new DLLNode<E>(o, last, null);
            last.succ = ins;
            last = ins;
        }
    }

    public void insertAfter(E o, DLLNode<E> after) {
        if (after == last) {
            insertLast(o);
            return;
        }
        DLLNode<E> ins = new DLLNode<E>(o, after, after.succ);
        after.succ.pred = ins;
        after.succ = ins;
    }

    public void insertBefore(E o, DLLNode<E> before) {
        if (before == first) {
            insertFirst(o);
            return;
        }
        DLLNode<E> ins = new DLLNode<E>(o, before.pred, before);
        before.pred.succ = ins;
        before.pred = ins;
    }

    public E deleteFirst() {
        if (first != null) {
            DLLNode<E> tmp = first;
            first = first.succ;
            if (first != null) first.pred = null;
            if (first == null)
                last = null;
            return tmp.element;
        } else
            return null;
    }

    public E deleteLast() {
        if (first != null) {
            if (first.succ == null)
                return deleteFirst();
            else {
                DLLNode<E> tmp = last;
                last = last.pred;
                last.succ = null;
                return tmp.element;
            }
        } else
            return null;
    }

    public E delete(DLLNode<E> node) {
        if (node == first) {
            return deleteFirst();
        }
        if (node == last) {
            return deleteLast();
        }
        node.pred.succ = node.succ;
        node.succ.pred = node.pred;
        return node.element;

    }

    public DLLNode<E> find(E o) {
        if (first != null) {
            DLLNode<E> tmp = first;
            while (!tmp.element.equals(o) && tmp.succ != null)
                tmp = tmp.succ;
            if (tmp.element.equals(o)) {
                return tmp;
            } else {
                System.out.println("Elementot ne postoi vo listata");
            }
        } else {
            System.out.println("Listata e prazna");
        }
        return null;
    }

    public void deleteList() {
        first = null;
        last = null;
    }

    public int getSize() {
        int listSize = 0;
        DLLNode<E> tmp = first;
        while(tmp != null) {
            listSize++;
            tmp = tmp.succ;
        }
        return listSize;
    }

    @Override
    public String toString() {
        String ret = new String();
        if (first != null) {
            DLLNode<E> tmp = first;
            ret += tmp.toString();
            while (tmp.succ != null) {
                tmp = tmp.succ;
                ret += "<->" + tmp.toString();
            }
        } else
            ret = "Prazna lista!!!";
        return ret;
    }

    public String toStringR() {
        StringBuilder stringBuilder = new StringBuilder();
        DLLNode<E> temp = last;

        while (temp.pred != null){
            stringBuilder.append(temp.element);
            stringBuilder.append("<->");

            temp = temp.pred;
        }

        stringBuilder.append(temp.element);

        return stringBuilder.toString();
    }

    public DLLNode<E> getFirst() {
        return first;
    }

    public DLLNode<E> getLast() {

        return last;
    }

    public void setFirst(DLLNode<E> node) {
        this.first = node;
    }

    public void setLast(DLLNode<E> node) {
        this.last = node;
    }



    public void mirror() {

        DLLNode<E> tmp = null;
        DLLNode<E> current = first;
        last = first;
        while(current!=null) {
            tmp = current.pred;
            current.pred = current.succ;
            current.succ = tmp;
            current = current.pred;
        }

        if(tmp!=null && tmp.pred!=null) {
            first=tmp.pred;
        }
    }
}

public class DLLBattalion {

    //TODO: implement function
    public static void battalion(DLL<Integer> list, int a, int b) {
        Stack<DLLNode<Integer>> stack = new Stack<>();

        DLLNode<Integer> temp = list.getFirst();

        while (temp.element != a){
            temp = temp.succ;
        }

        while (temp.element != b){
            stack.push(temp);

            temp = temp.succ;
        }
        stack.push(temp);
        // stack = 1 2 3 4 5

        DLLNode<Integer> next = temp.succ; // 6



        temp = list.getFirst();

        DLLNode<Integer> safeHead = null;
        if (temp.element == a){
            temp = stack.pop();
            safeHead = temp;
            safeHead.pred = null;
        }
        else {
            while (temp.succ.element != a) {
                temp = temp.succ;
            }
        }

        while (!stack.isEmpty()){
            DLLNode<Integer> safe = temp;
            temp.succ = stack.pop();
            temp.succ.pred = safe;

            temp = temp.succ;
        }

        temp.succ = next;

        if (next != null) {
            next.pred = temp;
        }else{
            list.setLast(temp);
        }

        if (safeHead != null){
            list.setFirst(safeHead);
        }
    }

    public static void reverse(DLL<Integer> list){
        Stack<DLLNode<Integer>> stack = new Stack<>();
        DLLNode<Integer> head = list.getFirst();

        while (head !=null){
            stack.push(head);
            head = head.succ;
        }


        head = stack.pop();
        DLLNode<Integer> safe = head;
        while (!stack.isEmpty()){
            DLLNode<Integer> temp = stack.pop();
            head.succ = temp;
            head.succ.pred = head;

            head = head.succ;
        }
        head.succ = null;
        safe.pred = null;

        list.setFirst(safe);
        list.setLast(head);

        System.out.println(list.toString());
        System.out.println(list.toStringR());
    }

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        DLL<Integer> list = new DLL<>();
        for(int i=0;i<n;i++) {
            list.insertLast(input.nextInt());
        }

        int a = input.nextInt();
        int b = input.nextInt();

        battalion(list, a, b);
//        reverse(list);
//
        System.out.println(list);
        System.out.println(list.toStringR());


    }
}