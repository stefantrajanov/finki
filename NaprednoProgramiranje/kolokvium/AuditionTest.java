import java.util.*;

class Participant{
    public String name;
    public String code;
    public String city;
    public int age;

    public Participant(String name, String code, String city, int age) {
        this.name = name;
        this.code = code;
        this.city = city;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getCode() {
        return code;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s",this.code, this.name, this.age);
    }
}

class Audition{
    public List<Participant> participants;
    public Map<String, List<String>> codes;

    public Audition() {
        this.participants = new ArrayList<>();
        this.codes = new HashMap<>();
    }

    void listByCity(String city){
        this.participants.sort(Comparator.comparing(Participant::getName).thenComparing(Participant::getAge).thenComparing(Participant::getCode));

        for (Participant participant : this.participants){
            if (participant.city.compareTo(city) == 0) {
                System.out.println(participant);
            }
        }
    }

    void addParticpant(String city, String code, String name, int age){
        if (this.codes.containsKey(city) && this.codes.get(city).contains(code)){
            return;
        }

        if (!this.codes.containsKey(city)){
            this.codes.put(city, new ArrayList<>());
            this.codes.get(city).add(code);
        }else{
            this.codes.get(city).add(code);
        }

        this.participants.add(new Participant(name, code, city, age));
    }
}

public class AuditionTest {
    public static void main(String[] args) {
        Audition audition = new Audition();
        List<String> cities = new ArrayList<String>();
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            String[] parts = line.split(";");
            if (parts.length > 1) {
                audition.addParticpant(parts[0], parts[1], parts[2],
                        Integer.parseInt(parts[3]));
            } else {
                cities.add(line);
            }
        }
        for (String city : cities) {
            System.out.printf("+++++ %s +++++\n", city);
            audition.listByCity(city);
        }
        scanner.close();
    }
}