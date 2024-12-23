import java.util.*;

class DeliveryPerson {
    public String id;
    public String name;
    public Location currentLocation;
    public int ordersCompleted;
    public float moneyEarned;

    public DeliveryPerson(String id, String name, Location currentLocation) {
        this.id = id;
        this.name = name;
        this.currentLocation = currentLocation;
        this.ordersCompleted = 0;
        this.moneyEarned = 0;
    }

    public float addMoney(Location destination) {
        int units = this.currentLocation.distance(destination) / 10;

        float fee = 90 + (units * 10);

        this.moneyEarned += fee;

        return fee;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Location getCurrentLocation() {
        return currentLocation;
    }

    public int getOrdersCompleted() {
        return ordersCompleted;
    }

    public float getMoneyEarned() {
        return moneyEarned;
    }

    @Override
    public String toString() {
        return String.format(
                "ID: %s Name: %s Total deliveries: %d Total delivery fee: %.2f Average delivery fee: %.2f",
                this.id, this.name, this.ordersCompleted, this.moneyEarned, this.moneyEarned/((float)this.ordersCompleted > 0 ? this.ordersCompleted : 1));
    }

}

class Restaurant {
    public String id;
    public String name;
    public Location location;
    public List<Float> orderPrices;


    public Restaurant(String id, String name, Location location) {
        this.id = id;
        this.name = name;
        this.location = location;
        this.orderPrices = new ArrayList<>();
    }

    public void addOrderPrice(float price) {
        this.orderPrices.add(price);
    }

    public float averageOrder() {
        float average = 0;
        for (float order : orderPrices) {
            average += order;
        }
        if (this.orderPrices.size() != 0) {
            average /= this.orderPrices.size();
        }
        return average;
    }

    public float moneyMade(){
        float sum = 0;
        for (float order : orderPrices) {
            sum += order;
        }
        return sum;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Location getLocation() {
        return location;
    }

    @Override
    public String toString() {
        return String.format(
                "ID: %s Name: %s Total orders: %d Total amount earned: %.2f Average amount earned: %.2f",
                this.id, this.name, this.orderPrices.size(), this.moneyMade(), this.averageOrder());
    }
}

class UserD {
    public String id;
    public String name;
    public Map<String, Location> addresses;
    public float moneySpent;
    public float moneySpentOnFees;
    public int orderCount;

    public UserD(String id, String name) {
        this.id = id;
        this.name = name;
        this.addresses = new HashMap<>();
        this.moneySpent = 0;
        this.moneySpentOnFees = 0;
        this.orderCount = 0;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Map<String, Location> getAddresses() {
        return addresses;
    }

    public float getMoneySpent() {
        return moneySpent;
    }

    @Override
    public String toString() {
        return String.format(
                "ID: %s Name: %s Total orders: %d Total amount spent: %.2f Average amount spent: %.2f",
                this.id, this.name, this.orderCount, this.moneySpent, this.moneySpent / (orderCount > 0 ? orderCount : 1)
                );
    }
}

class DeliveryApp {
    public String name;
    public List<DeliveryPerson> deliveryPeople;
    public List<Restaurant> restaurants;
    public List<UserD> users;

    public DeliveryApp(String name) {
        this.name = name;
        this.deliveryPeople = new ArrayList<>();
        this.restaurants = new ArrayList<>();
        this.users = new ArrayList<>();
    }

    public void registerDeliveryPerson(String id, String name, Location currentLocation) {
        this.deliveryPeople.add(new DeliveryPerson(id, name, currentLocation));
    }

    public void addRestaurant(String id, String name, Location location) {
        this.restaurants.add(new Restaurant(id, name, location));
    }

    public void addUser(String id, String name) {
        this.users.add(new UserD(id, name));
    }

    public void addAddress(String id, String addressName, Location location) {
        UserD user = this.users.stream().filter(u -> u.id.contentEquals(id)).findFirst().get();
        user.addresses.putIfAbsent(addressName, location);
    }

    public void orderFood(String userId, String userAddressName, String restaurantId, float cost) {
        UserD user = this.users.stream().filter(u -> u.id.contentEquals(userId)).findFirst().get();
        Restaurant restaurant = this.restaurants.stream().filter(r -> r.id.contentEquals(restaurantId)).findFirst().get();
        Location userAddress = user.addresses.get(userAddressName);
        DeliveryPerson person = getClosestDeliveryPerson(userAddress);

        float fee = person.addMoney(userAddress);
        person.currentLocation = userAddress;
        person.ordersCompleted++;
        user.moneySpent += cost;
        user.moneySpentOnFees += fee;
        user.orderCount++;
        restaurant.orderPrices.add(cost);
    }

    DeliveryPerson getClosestDeliveryPerson(Location destination) {
        DeliveryPerson minPerson = this.deliveryPeople.get(0);
        int minDistance = minPerson.currentLocation.distance(destination);
        for (DeliveryPerson person : this.deliveryPeople) {
            if (minDistance > person.currentLocation.distance(destination)) {
                minDistance = person.currentLocation.distance(destination);
                minPerson = person;
            } else if (minDistance == person.currentLocation.distance(destination)) {
                if (minPerson.ordersCompleted > person.ordersCompleted) {
                    minPerson = person;
                }
            }
        }

        return minPerson;
    }

    public void printUsers() {
        this.users.sort(Comparator.comparing(UserD::getMoneySpent).thenComparing(UserD::getId).reversed());
        this.users.forEach(System.out::println);
    }

    public void printRestaurants() {
        this.restaurants.sort(Comparator.comparing(Restaurant::averageOrder).thenComparing(Restaurant::getName).reversed());
        this.restaurants.forEach(System.out::println);
    }

    public void printDeliveryPeople() {
        this.deliveryPeople.sort(Comparator.comparing(DeliveryPerson::getMoneyEarned).reversed());
        this.deliveryPeople.forEach(System.out::println);
    }
}


/*
YOUR CODE HERE
DO NOT MODIFY THE interfaces and classes below!!!
*/

interface Location {
    int getX();

    int getY();

    default int distance(Location other) {
        int xDiff = Math.abs(getX() - other.getX());
        int yDiff = Math.abs(getY() - other.getY());
        return xDiff + yDiff;
    }
}

class LocationCreator {
    public static Location create(int x, int y) {

        return new Location() {
            @Override
            public int getX() {
                return x;
            }

            @Override
            public int getY() {
                return y;
            }
        };
    }
}

public class DeliveryAppTester {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String appName = sc.nextLine();
        DeliveryApp app = new DeliveryApp(appName);
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            String[] parts = line.split(" ");

            if (parts[0].equals("addUser")) {
                String id = parts[1];
                String name = parts[2];
                app.addUser(id, name);
            } else if (parts[0].equals("registerDeliveryPerson")) {
                String id = parts[1];
                String name = parts[2];
                int x = Integer.parseInt(parts[3]);
                int y = Integer.parseInt(parts[4]);
                app.registerDeliveryPerson(id, name, LocationCreator.create(x, y));
            } else if (parts[0].equals("addRestaurant")) {
                String id = parts[1];
                String name = parts[2];
                int x = Integer.parseInt(parts[3]);
                int y = Integer.parseInt(parts[4]);
                app.addRestaurant(id, name, LocationCreator.create(x, y));
            } else if (parts[0].equals("addAddress")) {
                String id = parts[1];
                String name = parts[2];
                int x = Integer.parseInt(parts[3]);
                int y = Integer.parseInt(parts[4]);
                app.addAddress(id, name, LocationCreator.create(x, y));
            } else if (parts[0].equals("orderFood")) {
                String userId = parts[1];
                String userAddressName = parts[2];
                String restaurantId = parts[3];
                float cost = Float.parseFloat(parts[4]);
                app.orderFood(userId, userAddressName, restaurantId, cost);
            } else if (parts[0].equals("printUsers")) {
                app.printUsers();
            } else if (parts[0].equals("printRestaurants")) {
                app.printRestaurants();
            } else {
                app.printDeliveryPeople();
            }

        }
    }
}
