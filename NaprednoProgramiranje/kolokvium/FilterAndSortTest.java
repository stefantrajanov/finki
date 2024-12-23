import java.util.*;
import java.util.function.Predicate;
import java.util.logging.Filter;
import java.util.stream.Collectors;

class Student implements Comparable<Student> {
    String id;
    List<Integer> grades;

    public Student(String id, List<Integer> grades) {
        this.id = id;
        this.grades = grades;
    }

    public double average() {
        return grades.stream().mapToDouble(i -> i).average().getAsDouble();
    }

    public int getYear() {
        return (24 - Integer.parseInt(id.substring(0, 2)));
    }

    public int totalCourses() {
        return Math.min(getYear() * 10, 40);
    }

    public double labAssistantPoints() {
        return average() * ((double) grades.size() / totalCourses()) * (0.8 + ((getYear() - 1) * 0.2) / 3.0);
    }

    @Override
    public int compareTo(Student o) {
        return Comparator.comparing(Student::labAssistantPoints)
                .thenComparing(Student::average)
                .compare(this, o);
    }

    @Override
    public String toString() {
        return String.format("Student %s (%d year) - %d/%d passed exam, average grade %.2f.\nLab assistant points: %.2f", id, getYear(), grades.size(), totalCourses(), average(), labAssistantPoints());
    }
}

class EmptyResultException extends Exception {
    public EmptyResultException() {
        super("No element met the criteria");
    }
}

class FilterAndSort {
    public static <T extends Comparable<T>> List<T> execute(List<T> list, Predicate<T> predicate) throws EmptyResultException {

        List<T> temp = new ArrayList<>();

        for (T element : list) {
            if (predicate.test(element)) {
                temp.add(element);
            }
        }

        temp.sort(Comparator.reverseOrder());

        if (temp.isEmpty()) {
            throw new EmptyResultException();
        }

        return temp;
    }
}


public class FilterAndSortTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = Integer.parseInt(sc.nextLine());
        int n = Integer.parseInt(sc.nextLine());

        if (testCase == 1) { // students
            int studentScenario = Integer.parseInt(sc.nextLine());
            List<Student> students = new ArrayList<>();
            while (n > 0) {

                String line = sc.nextLine();
                String[] parts = line.split("\\s+");
                String id = parts[0];
                List<Integer> grades = Arrays.stream(parts).skip(1).map(Integer::parseInt).collect(Collectors.toList());
                students.add(new Student(id, grades));
                --n;
            }

            if (studentScenario == 1) {
                //TODO filter and sort all students who have at least 8.0 points and are at least 3rd year student
                Predicate<Student> predicate = student -> student.getYear() >= 3 && student.labAssistantPoints() >= 8.0;

                try {
                    students = FilterAndSort.execute(students, predicate);
                }catch (EmptyResultException e){
                    System.out.println(e.getMessage());
                    return;
                }

                students.forEach(System.out::println);

            } else {
                //TODO filter and sort all students who have passed at least 90% of their total courses with an average grade of at least 9.0

                Predicate<Student> predicate = student -> student.totalCourses() * 0.9 < student.grades.size() && student.average() >= 9.0;

                try {
                    students = FilterAndSort.execute(students, predicate);
                }catch (EmptyResultException e){
                    System.out.println(e.getMessage());
                    return;

                }
                students.forEach(System.out::println);

            }
        } else { //integers
            List<Integer> integers = new ArrayList<>();
            while (n > 0) {
                integers.add(Integer.parseInt(sc.nextLine()));
                --n;
            }

            //TODO filter and sort all even numbers divisible with 15
            Predicate<Integer> predicate = number -> number % 15 == 0;

            try {
                integers = FilterAndSort.execute(integers, predicate);
            }catch (EmptyResultException e){
                System.out.println(e.getMessage());
                return;

            }
            integers.forEach(System.out::println);
        }

    }
}
