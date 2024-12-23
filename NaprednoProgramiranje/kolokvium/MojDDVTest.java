import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class AmountNotAllowedException extends Exception {
    public AmountNotAllowedException(int sum) {
        super(String.format("Receipt with amount %d is not allowed to be scanned", sum));
    }
}

class Ticket {
    public int price;
    public String taxType;

    public Ticket(int price, String taxType) {
        this.price = price;
        this.taxType = taxType;
    }
}

class MojDDV {
    private List<List<Ticket>> scannedTickets;
    private List<Integer> userIds;

    public MojDDV() {
        this.scannedTickets = new ArrayList<>();
        this.userIds = new ArrayList<>();
    }

    void readRecords(InputStream inputStream) throws IOException, AmountNotAllowedException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));

        String line = "";
        while ((line = reader.readLine()) != null) {
            String[] split = line.split(" ");
            int id = Integer.parseInt(split[0]);
            userIds.add(id);
            List<Ticket> tickets = new ArrayList<>();
            for (int i = 1; i < split.length; i+=2) {
                int price = Integer.parseInt(split[i]);
                if (price > 30000){
                    throw new AmountNotAllowedException(price);
                }
                String taxType = split[i + 1];

                tickets.add(new Ticket(price, taxType));
            }
            scannedTickets.add(tickets);
        }
    }

    void printTaxReturns(OutputStream outputStream) {
        for (int i = 0; i < scannedTickets.size(); i++) {
            System.out.print(this.userIds.get(i).toString() + " ");
        }
    }

}

public class MojDDVTest {

    public static void main(String[] args) {

        MojDDV mojDDV = new MojDDV();

        System.out.println("===READING RECORDS FROM INPUT STREAM===");
        try {
            mojDDV.readRecords(System.in);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        System.out.println("===PRINTING TAX RETURNS RECORDS TO OUTPUT STREAM ===");
        mojDDV.printTaxReturns(System.out);

    }
}