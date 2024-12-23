import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class NonExistingItemException extends Exception{
    NonExistingItemException(int id){
        super("Item with id "+ id +" doesn't exist");
    }
}

class Archive {
    protected int id;
    protected LocalDate dateArchived;

}

class LockedArchive extends Archive {
    public LocalDate toOpen;

    LockedArchive(int id, LocalDate toOpen) {
        this.id = id;
        this.toOpen = toOpen;
        this.dateArchived = LocalDate.now();
    }

}

class SpecialArchive extends Archive {
    public int maxOpen;
    int counter;

    SpecialArchive(int id, int maxOpen) {
        this.id = id;
        this.maxOpen = maxOpen;
        counter = 0;
        this.dateArchived = LocalDate.now();
    }
}

class ArchiveStore {
    List<Archive> archiveList;
    StringBuilder logs;

    ArchiveStore() {
        archiveList = new ArrayList<Archive>();
        logs = new StringBuilder();
    }

    void archiveItem(Archive item, LocalDate date) {
        item.dateArchived = date;
        this.archiveList.add(item);

        logs.append("Item ").append(item.id).append(" archived at ").append(date).append("\n");

    }

    void openItem(int id, LocalDate date) throws NonExistingItemException {
        Archive archive = this.archiveList.stream().filter(arhive -> arhive.id == id).findAny().orElse(null);
       if (archive == null){
           throw new NonExistingItemException(id);
       }

       if (archive instanceof LockedArchive) {
           LockedArchive temp = (LockedArchive) archive;

           if (temp.toOpen.isAfter(date)) {
               logs.append("Item ").append(id).append(" cannot be opened before ").append(temp.toOpen).append("\n");
               return;
           }
       }else {
           SpecialArchive temp = (SpecialArchive) archive;

           temp.counter++;

           if (temp.counter > temp.maxOpen) {
               logs.append("Item ").append(id).append(" cannot be opened more than ").append(temp.maxOpen).append(" times").append("\n");
               return;
           }
       }



       logs.append("Item ").append(id).append(" opened at ").append(date).append("\n");
    }

    String getLog() {
        return logs.toString();
    }
}

public class ArchiveStoreTest {
    public static void main(String[] args) {
        ArchiveStore store = new ArchiveStore();
        LocalDate date = LocalDate.of(2013, 10, 7);
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        int n = scanner.nextInt();
        scanner.nextLine();
        scanner.nextLine();
        int i;
        for (i = 0; i < n; ++i) {
            int id = scanner.nextInt();
            long days = scanner.nextLong();

            LocalDate dateToOpen = date.atStartOfDay().plusSeconds(days * 24 * 60 * 60).toLocalDate();
            LockedArchive lockedArchive = new LockedArchive(id, dateToOpen);
            store.archiveItem(lockedArchive, date);
        }
        scanner.nextLine();
        scanner.nextLine();
        n = scanner.nextInt();
        scanner.nextLine();
        scanner.nextLine();
        for (i = 0; i < n; ++i) {
            int id = scanner.nextInt();
            int maxOpen = scanner.nextInt();
            SpecialArchive specialArchive = new SpecialArchive(id, maxOpen);
            store.archiveItem(specialArchive, date);
        }
        scanner.nextLine();
        scanner.nextLine();
        while (scanner.hasNext()) {
            int open = scanner.nextInt();
            try {
                store.openItem(open, date);
            } catch (NonExistingItemException e) {
                System.out.println(e.getMessage());
            }
        }
        System.out.println(store.getLog());
    }
}