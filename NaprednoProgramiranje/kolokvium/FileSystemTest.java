import java.util.*;

class FileNameExistsException extends Exception {
    FileNameExistsException(String name) {
        super("There is already a file named "+ name +" in the folder test");
    }
}

class FileSystem {
    private Folder rootDirectory;

    FileSystem() {
        this.rootDirectory = new Folder("root");
    }

    void addFile(IFile file) throws FileNameExistsException {
        this.rootDirectory.addFile(file);
    }

    long findLargestFile() {
        return this.rootDirectory.getLargestFileSizeWithinTheFolder(0);
    }

    void sortBySize() {
        rootDirectory.sortBySize();
    }

    @Override
    public String toString(){
        return rootDirectory.getFileInfo();
    }
}

///////////////////////////////////////////////////////////
////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE

class Folder implements IFile {
    private String name;
    private long size;
    List<File> files;
    List<Folder> folders;
    List<IFile> theFiles;

    public Folder(String name) {
        this.name = name;
        this.size = 0;
        this.files = new ArrayList<>();
        this.folders = new ArrayList<>();
        this.theFiles = new ArrayList<>();
    }

    @Override
    public String getFileName() {
        return this.name;
    }

    @Override
    public long getFileSize() {
        long sum = 0;
        for (File file : this.files) {
            sum += file.getFileSize();
        }

        for (Folder folder : this.folders) {
            sum += folder.getFileSize();
        }

        return sum;
    }

    @Override
    public String getFileInfo() {
        StringBuilder builder = new StringBuilder("Folder name:        " + this.name + " Folder size:        " + this.getFileSize() + "\n");

        for (IFile file : this.theFiles){
            builder.append("    ").append(file.getFileInfo());
        }

        return builder.toString();
    }

    @Override
    public void sortBySize() {
        this.theFiles.sort((f1,f2) -> Long.compare(f1.getFileSize(), f2.getFileSize()));

        for (Folder folders : folders){
            folders.sortBySize();
        }
    }

    @Override
    public long findLargestFile() {
        return this.getLargestFileSizeWithinTheFolder(0);
    }

    public long getLargestFileSizeWithinTheFolder(long max) {
        max = Math.max(max, this.getLargestCurrentFileSize());

        for (Folder folder : this.folders) {
            max = Math.max(max, folder.getLargestFileSizeWithinTheFolder(max));
        }

        return max;
    }

    public long getLargestCurrentFileSize(){
        long max = 0;
        for (File file : files){
            if (max < file.getFileSize()){
                max = file.getFileSize();
            }
        }

        return max;
    }

    public void addFile(IFile file) throws FileNameExistsException {
        boolean fileFlag = this.files.stream().anyMatch(currentFile -> currentFile.getFileName().compareTo(file.getFileName()) == 0);
        boolean folderFlag = this.folders.stream().anyMatch(currentFile -> currentFile.getFileName().compareTo(file.getFileName()) == 0);

        if (fileFlag || folderFlag) {
            throw new FileNameExistsException(file.getFileName());
        }
        if (file instanceof Folder) {
            folders.add((Folder) file);
        } else {
            files.add((File) file);
        }

        theFiles.add(file);
    }
}

///////////////////////////////////////////////////////////
////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE///////////////////////////////////////////////////////////
//////FILE



class File implements IFile {
    private String name;
    private long size;

    public File(String name, long size) {
        this.name = name;
        this.size = size;
    }

    @Override
    public String getFileName() {
        return this.name;
    }

    @Override
    public long getFileSize() {
        return this.size;
    }

    @Override
    public String getFileInfo() {
        return "    File name:        " + this.name + " File size:        " + this.size + "\n";
    }

    @Override
    public void sortBySize() {

    }

    @Override
    public long findLargestFile() {

        return 0;
    }
}

interface IFile {
    String getFileName();

    long getFileSize();

    String getFileInfo();

    void sortBySize();

    long findLargestFile();
}

public class FileSystemTest {

    public static Folder readFolder(Scanner sc) {

        Folder folder = new Folder(sc.nextLine());
        int totalFiles = Integer.parseInt(sc.nextLine());

        for (int i = 0; i < totalFiles; i++) {
            String line = sc.nextLine();

            if (line.startsWith("0")) {
                String fileInfo = sc.nextLine();
                String[] parts = fileInfo.split("\\s+");
                try {
                    folder.addFile(new File(parts[0], Long.parseLong(parts[1])));
                } catch (FileNameExistsException e) {
                    System.out.println(e.getMessage());
                }
            } else {
                try {
                    folder.addFile(readFolder(sc));
                } catch (FileNameExistsException e) {
                    System.out.println(e.getMessage());
                }
            }
        }

        return folder;
    }

    public static void main(String[] args) {

        //file reading from input

        Scanner sc = new Scanner(System.in);

        System.out.println("===READING FILES FROM INPUT===");
        FileSystem fileSystem = new FileSystem();
        try {
            fileSystem.addFile(readFolder(sc));
        } catch (FileNameExistsException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("===PRINTING FILE SYSTEM INFO===");
        System.out.println(fileSystem.toString());

        System.out.println("===PRINTING FILE SYSTEM INFO AFTER SORTING===");
        fileSystem.sortBySize();
        System.out.println(fileSystem.toString());

        System.out.println("===PRINTING THE SIZE OF THE LARGEST FILE IN THE FILE SYSTEM===");
        System.out.println(fileSystem.findLargestFile());


    }
}