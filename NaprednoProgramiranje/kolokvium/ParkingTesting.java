import java.time.Duration;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Collectors;

class Car {
    public String registration;
    public String spot;
    public LocalDateTime startTimestamp;
    public LocalDateTime endTimestamp;

    public Car(String registration, String spot, LocalDateTime timestamp) {
        this.registration = registration;
        this.spot = spot;
        this.startTimestamp = timestamp;
        endTimestamp = null;
    }

    public LocalDateTime getTimestamp() {
        return startTimestamp;
    }

    public long getDuration() {
        if (endTimestamp == null) {
            return 0;
        }
        return DateUtil.durationBetween(startTimestamp, endTimestamp);
    }

    @Override
    public String toString() {
        if (endTimestamp != null) {
            return String.format("Registration number: %s Spot: %s Start timestamp: %s End timestamp: %s Duration in minutes: %d", this.registration, this.spot, this.startTimestamp, this.endTimestamp, this.getDuration());
        }

        return String.format("Registration number: %s Spot: %s Start timestamp: %s", this.registration, this.spot, this.startTimestamp);
    }
}

class Parking {
    public int capacity;
    public List<Car> cars;
    public List<Car> carHistory;

    private Map<String, Integer> carStats;
    private Map<String, List<Car>> spots;

    public Parking(int capacity) {
        this.capacity = capacity;
        this.cars = new ArrayList<>();
        this.carHistory = new ArrayList<>();
        carStats = new TreeMap<>();
        spots = new HashMap<>();
    }

    void update(String registration, String spot, LocalDateTime timestamp, boolean entry) {
        if (capacity == cars.size() && entry) {
            return;
        }

        if (entry) {
            this.cars.add(new Car(registration, spot, timestamp));

            if (!carStats.containsKey(registration)) {
                carStats.put(registration, 1);
            } else {
                carStats.compute(registration, (k, value) -> value + 1);
            }

            if (!spots.containsKey(spot)) {
                spots.put(spot, new ArrayList<>());
            }
            return;
        }

        Car current = this.cars.stream().filter(car -> car.registration.compareToIgnoreCase(registration) == 0).findFirst().get();
        current.endTimestamp = timestamp;

        if (spots.containsKey(spot)) {
            spots.get(spot).add(current);
        }

        this.carHistory.add(current);
        this.cars.remove(current);
    }

    void currentState() {
        float percent = 0;
        if (!this.cars.isEmpty()) {
            percent = this.cars.size() / (float) this.capacity * 100;
        }

        System.out.printf("Capacity filled: %.2f%%%n", percent);

        this.cars.sort(Comparator.comparing(Car::getTimestamp).reversed());

        for (Car car : cars) {
            System.out.println(car);
        }
    }

    void history() {
        this.carHistory.sort(Comparator.comparing(Car::getDuration).reversed());

        for (Car car : carHistory) {
            System.out.println(car);
        }
    }

    Map<String, Integer> carStatistics() {
        return carStats;
    }

    Map<String, Double> spotOccupancy(LocalDateTime start, LocalDateTime end) {
        long duration = DateUtil.durationBetween(start, end);
        Map<String, Double> spotMap = new HashMap<>();
        for (String spot : this.spots.keySet()) {
            List<Car> carsInTheSpot = this.spots.get(spot);

            long sum = 0;
            for (Car car : carsInTheSpot) {
                if (car.startTimestamp.isBefore(start)) {
                    sum += 0;
                    continue;
                }
                sum += DateUtil.durationBetween(car.startTimestamp, car.endTimestamp.isAfter(end) ? end : car.endTimestamp);
            }

            double value = ((double) sum / (double) duration) * 100.0;
            spotMap.put(spot, value > 0 && value < 100 ? value : 0.0);
        }
        return spotMap;
    }
}

class DateUtil {
    public static long durationBetween(LocalDateTime start, LocalDateTime end) {
        return Duration.between(start, end).toMinutes();
    }
}

public class ParkingTesting {

    public static <K, V extends Comparable<V>> void printMapSortedByValue(Map<K, V> map) {
        map.entrySet().stream()
                .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
                .forEach(entry -> System.out.println(String.format("%s -> %s", entry.getKey().toString(), entry.getValue().toString())));

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int capacity = Integer.parseInt(sc.nextLine());

        Parking parking = new Parking(capacity);

        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            String[] parts = line.split("\\s+");
            if (parts[0].equals("update")) {
                String registration = parts[1];
                String spot = parts[2];
                LocalDateTime timestamp = LocalDateTime.parse(parts[3]);
                boolean entrance = Boolean.parseBoolean(parts[4]);
                parking.update(registration, spot, timestamp, entrance);
            } else if (parts[0].equals("currentState")) {
                System.out.println("PARKING CURRENT STATE");
                parking.currentState();
            } else if (parts[0].equals("history")) {
                System.out.println("PARKING HISTORY");
                parking.history();
            } else if (parts[0].equals("carStatistics")) {
                System.out.println("CAR STATISTICS");
                printMapSortedByValue(parking.carStatistics());
            } else if (parts[0].equals("spotOccupancy")) {
                LocalDateTime start = LocalDateTime.parse(parts[1]);
                LocalDateTime end = LocalDateTime.parse(parts[2]);
                printMapSortedByValue(parking.spotOccupancy(start, end));
            }
        }
    }
}
