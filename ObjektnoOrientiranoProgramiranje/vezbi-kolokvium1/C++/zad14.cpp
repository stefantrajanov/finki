//
// Created by Stefan on 3/5/2023.
//
#include<iostream>
#include<cstring>

using namespace std;

enum Extension {
    pdf, txt, exe
};

class File {
private:
    char *fileName;
    Extension extension;
    char *fileOwner;
    int fileSize;

    void copy(File &object) {
        if (this == &object) {
            return;
        }
        this->fileName = new char[strlen(object.fileName)];
        strcpy(this->fileName, object.fileName);
        this->fileOwner = new char[strlen(object.fileOwner)];
        strcpy(this->fileOwner, object.fileOwner);

        this->fileSize = object.fileSize;
        this->extension = object.extension;
    }

public:
//    File() = default;
    File(File &object) {
        if (this == &object) {
            return;
        }
        this->fileName = new char[strlen(object.fileName)];
        strcpy(this->fileName, object.fileName);
        this->fileOwner = new char[strlen(object.fileOwner)];
        strcpy(this->fileOwner, object.fileOwner);

        this->fileSize = object.fileSize;
        this->extension = object.extension;
    }

    File(char *fileName = "", char *fileOwner = "", int fileSize = 0, Extension extension = pdf) :
            extension(extension),
            fileSize(fileSize) {
        this->fileName = new char[strlen(fileName)];
        strcpy(this->fileName, fileName);
        this->fileOwner = new char[strlen(fileOwner)];
        strcpy(this->fileOwner, fileOwner);
    }

    File &operator=(const File &object) {
        if (this == &object) {
            return *this;
        }
        this->fileName = new char[strlen(object.fileName)];
        strcpy(this->fileName, object.fileName);
        this->fileOwner = new char[strlen(object.fileOwner)];
        strcpy(this->fileOwner, object.fileOwner);

        this->fileSize = object.fileSize;
        this->extension = object.extension;

        return *this;
    }

    bool equals(const File &object) {
        return (
                (strcmp(this->fileName, object.fileName) == 0)
                &&
                this->extension == object.extension
                &&
                (strcmp(this->fileOwner, object.fileOwner) == 0)
        );
    }

    bool equalsType(const File &object) {
        return ((strcmp(this->fileName, object.fileName) == 0) && this->extension == object.extension);
    }

    void print() {
        printf("File name: %s.", this->fileName);

        if (this->extension == pdf) {
            cout << "pdf" << endl;
        } else if (this->extension == exe) {
            cout << "exe" << endl;
        } else {
            cout << "txt" << endl;
        }

        printf("File owner: %s\n", this->fileOwner);
        printf("File size: %d\n", this->fileSize);
    }
};

class Folder {
private:
    char *folderName;
    File *files;
    int numberOfFiles;
public:
    Folder(const char *folderName) {
        this->folderName = new char[strlen(folderName)];
        strcpy(this->folderName, folderName);
    }

    Folder(char *folderName = "", File *files = {}, int numberOfFiles = 0) : numberOfFiles(numberOfFiles) {

        this->folderName = new char[strlen(folderName)];
        strcpy(this->folderName, folderName);

        this->files = new File[numberOfFiles];

        for (int i = 0; i < numberOfFiles; ++i) {
            this->files[i] = files[i];
        }
    }

    void remove(const File &object) {
        int fileIndex = (-1);

        for (int i = 0; i < this->numberOfFiles; ++i) {
            if (this->files[i].equals(object)) {
                fileIndex = i;
                break;
            }
        }
        if (fileIndex == (-1)) {
            return;
        }

        // switch with last element;
        File temp = this->files[this->numberOfFiles - 1];
        this->files[this->numberOfFiles - 1] = this->files[fileIndex];
        this->files[fileIndex] = temp;

        File *tempArray = new File[this->numberOfFiles - 1];
        for (int i = 0; i < this->numberOfFiles - 1; ++i) {
            tempArray[i] = this->files[i];
        }

        this->files = new File[this->numberOfFiles - 1];

        for (int i = 0; i < this->numberOfFiles - 1; ++i) {
            this->files[i] = tempArray[i];
        }
        this->numberOfFiles--;

        for (int i = fileIndex; i < this->numberOfFiles - 1; ++i) {
            temp = this->files[i + 1];
            this->files[i + 1] = this->files[i];
            this->files[i] = temp;
        }

        delete[] tempArray;
    }

    void add(const File &file) {
        File *tempArray = new File[this->numberOfFiles];
        for (int i = 0; i < this->numberOfFiles; ++i) {
            tempArray[i] = this->files[i];
        }

        this->files = new File[this->numberOfFiles + 1];
        for (int i = 0; i < this->numberOfFiles; ++i) {
            this->files[i] = tempArray[i];
        }
        this->files[this->numberOfFiles] = file;
        this->numberOfFiles++;

        delete[] tempArray;
    }

    void print() {
        printf("Folder name: %s\n", this->folderName);
        if (this->numberOfFiles > 0) {
            for (int i = 0; i < this->numberOfFiles; ++i) {
                this->files[i].print();
            }
        }
    }
};


int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created;
        created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied;
        copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    } else if (testCase == 2) {
        cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    } else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    } else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    }
    else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}