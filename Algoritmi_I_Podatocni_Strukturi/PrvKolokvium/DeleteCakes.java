import java.util.Scanner;

class Cake{
    int price;
    String name;

    public Cake(int price, String name) {
        this.price = price;
        this.name = name;
    }

    @Override
    public String toString(){
        StringBuilder builder = new StringBuilder();

        builder.append(name);
        builder.append(", cena:").append(price).append(" ");

        return builder.toString();
    }
}

public class DeleteCakes {
    public static void removeCakes(SLL<Cake> cakes){
        SLLNode<Cake> head = cakes.getFirst();

        int sum = 0;
        int counter = 1;
        while (head != null){
            sum += head.element.price;
            head = head.succ;
            counter++;
        }
        double average = (float)sum / counter;

        head = cakes.getFirst();

        SLLNode<Cake> last = null;
        while (head != null){
            if (head.element.price > average){
                if (last == null){
                    SLLNode<Cake> temp = head.succ.succ;
                    cakes.insertFirst(head.succ.element);
                    cakes.getFirst().succ = temp;
                    head = cakes.getFirst();
                }else{
                    last.succ = head.succ;
                    head = head.succ;
                }
            }else{
                last = head;
                head = head.succ;
            }
        }
    }
    public static void main(String[] args) {
        SLL<Cake> list = new SLL<>();
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            Cake newCake = new Cake(scanner.nextInt(), "torta" + i);
            list.insertLast(newCake);
        }

        removeCakes(list);
        System.out.println(list.toString());
    }
}
