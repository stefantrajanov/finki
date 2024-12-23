import java.util.*;
import java.util.stream.Collectors;

class CosineSimilarityCalculator {

    public static double cosineSimilarity(Map<String, Integer> c1, Map<String, Integer> c2) {
        return cosineSimilarity(c1.values(), c2.values());
    }

    public static double cosineSimilarity(Collection<Integer> c1, Collection<Integer> c2) {
        int[] array1;
        int[] array2;
        array1 = c1.stream().mapToInt(i -> i).toArray();
        array2 = c2.stream().mapToInt(i -> i).toArray();
        double up = 0.0;
        double down1 = 0, down2 = 0;

        for (int i = 0; i < c1.size(); i++) {
            up += (array1[i] * array2[i]);
        }

        for (int i = 0; i < c1.size(); i++) {
            down1 += (array1[i] * array1[i]);
        }

        for (int i = 0; i < c1.size(); i++) {
            down2 += (array2[i] * array2[i]);
        }

        return up / (Math.sqrt(down1) * Math.sqrt(down2));
    }
}

class Movie {
    public String id;
    public String name;
    public Map<User, Integer> ratings;

    public Movie(String id, String name) {
        this.id = id;
        this.name = name;
        this.ratings = new HashMap<>();
    }

    public double getAverageRating(){
        double sum = 0;
        for (int value : ratings.values()){
            sum += value;
        }

        return sum / ratings.values().size();
    }

    @Override
    public String toString() {
        return String.format("Movie ID: %s Title: %s Rating: %.2f", this.id, this.name, this.getAverageRating());
    }
}

class User {
    public String id;
    public String username;
    public List<String> ratedMovies;
    public Map<String, Integer> ratings;

    public User(String id, String username) {
        this.id = id;
        this.username = username;
        this.ratedMovies = new ArrayList<>();
        this.ratings = new HashMap<>();
    }

    public double cosine(User otherUser){
        return CosineSimilarityCalculator.cosineSimilarity(this.ratings, otherUser.ratings);
    }

    @Override
    public String toString() {
        return String.format("User ID: %s Name: %s", this.id, this.username);
    }
}

class StreamingPlatform {
    public Map<String, Movie> movies;
    public Map<String, User> users;

    public StreamingPlatform() {
        this.movies = new HashMap<>();
        this.users = new HashMap<>();
    }

    public void addMovie(String id, String name) {
        this.movies.put(id, new Movie(id, name));
    }

    public void addUser(String id, String username) {
        this.users.put(id, new User(id, username));
    }

    public void addRating(String userId, String movieId, int rating) {
        User user = this.users.get(userId);
        Movie movie = this.movies.get(movieId);

        movie.ratings.put(user, rating);
        user.ratedMovies.add(movieId);
        user.ratings.put(movieId, rating);
    }

    public void favouriteMoviesForUsers(List<String> userIds) {
        for (String id : userIds){
            User currentUser = this.users.get(id);
            int maxRating = getUserMaxRating(id);

            System.out.println(currentUser);
            List<Movie> tempMovies = new ArrayList<>();
            for (String movieId : currentUser.ratedMovies){
                Movie currentMovie = this.movies.get(movieId);
                int currentRating = currentMovie.ratings.get(currentUser);

                if (currentRating == maxRating){
                    tempMovies.add(currentMovie);
                }
            }
            tempMovies.sort(Comparator.comparing(Movie::getAverageRating).reversed());

            for (Movie movie : tempMovies){
                System.out.println(movie);
            }
            System.out.println();
        }
    }

    public int getUserMaxRating(String id){
        User user = this.users.get(id);
        int maxRating = 0;
        for (String movieId : user.ratedMovies){
            int currentRating = this.movies.get(movieId).ratings.get(user);
            if (maxRating < currentRating){
                maxRating = currentRating;
            }
        }

        return maxRating;
    }

    public void topNMovies(int n) {
        List<Movie> topMovies = new ArrayList<>(this.movies.values());
        topMovies.sort(Comparator.comparing(Movie::getAverageRating).reversed());

        for (int i = 0; i < n; i++) {
            System.out.println(topMovies.get(i));
        }
    }

    void defaultValues(){
        for (String id : this.users.keySet()) {
            User user = this.users.get(id);
            for (String movieId : movies.keySet()) {
                if (!user.ratings.containsKey(movieId)) {
                    user.ratings.put(movieId, 0);
                }
            }
        }
    }

    public void similarUsers(String userId) {
        defaultValues();
        User compUser = this.users.get(userId);
        List<User> userList = new ArrayList<>(this.users.values());

        userList.sort(Comparator.comparing(user -> user.cosine(compUser)));

        for (int i = userList.size() - 1; i >= 0; i--) {
            User user = userList.get(i);

            if (user.id.compareTo(userId) == 0){
                continue;
            }
            System.out.println(user + " " + compUser.cosine(user));
        }
    }

}


public class StreamingPlatform2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        StreamingPlatform sp = new StreamingPlatform();

        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            String[] parts = line.split("\\s+");

            if (parts[0].equals("addMovie")) {
                String id = parts[1];
                String name = Arrays.stream(parts).skip(2).collect(Collectors.joining(" "));
                sp.addMovie(id, name);
            } else if (parts[0].equals("addUser")) {
                String id = parts[1];
                String name = parts[2];
                sp.addUser(id, name);
            } else if (parts[0].equals("addRating")) {
                //String userId, String movieId, int rating
                String userId = parts[1];
                String movieId = parts[2];
                int rating = Integer.parseInt(parts[3]);
                sp.addRating(userId, movieId, rating);
            } else if (parts[0].equals("topNMovies")) {
                int n = Integer.parseInt(parts[1]);
                System.out.println("TOP " + n + " MOVIES:");
                sp.topNMovies(n);
            } else if (parts[0].equals("favouriteMoviesForUsers")) {
                List<String> users = Arrays.stream(parts).skip(1).collect(Collectors.toList());
                System.out.println("FAVOURITE MOVIES FOR USERS WITH IDS: " + users.stream().collect(Collectors.joining(", ")));
                sp.favouriteMoviesForUsers(users);
            } else if (parts[0].equals("similarUsers")) {
                String userId = parts[1];
                System.out.println("SIMILAR USERS TO USER WITH ID: " + userId);
                sp.similarUsers(userId);
            }
        }
    }
}
