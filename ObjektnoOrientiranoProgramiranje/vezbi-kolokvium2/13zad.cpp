//
// Created by Stefan on 5/5/2023.
//
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Image {
protected:
    char *name;
    char owner[60];
    int dimensions[2];
public:
    Image() {
        this->name = new char[9];
        strcpy(this->name, "untitled");
        strcpy(this->owner, "unknown");
        for (int i = 0; i < 2; ++i) {
            this->dimensions[i] = 800;
        }
    }

    Image(char *name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        strcpy(this->owner, "unknown");
        for (int i = 0; i < 2; ++i) {
            this->dimensions[i] = 800;
        }
    }

    Image(char *name, char *owner) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        strcpy(this->owner, owner);
        for (int i = 0; i < 2; ++i) {
            this->dimensions[i] = 800;
        }
    }

    Image(char *name, char *owner, int width, int height) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        strcpy(this->owner, owner);

        this->dimensions[0] = width;
        this->dimensions[1] = height;

    }

    Image(const Image &object) {
        this->name = new char[strlen(object.name) + 1];
        strcpy(this->name, object.name);
        strcpy(this->owner, object.owner);
        for (int i = 0; i < 2; ++i) {
            this->dimensions[i] = object.dimensions[i];
        }
    }

    Image &operator=(const Image &object) {
        if (this == &object) {
            return *this;
        }
        delete[] name;

        this->name = new char[strlen(object.name) + 1];
        strcpy(this->name, object.name);
        strcpy(this->owner, object.owner);
        for (int i = 0; i < 2; ++i) {
            this->dimensions[i] = object.dimensions[i];
        }
        return *this;
    }

    ~Image() {
        delete[] name;
    }

    // methods

    virtual int fileSize() {
        int size = this->dimensions[0] * this->dimensions[1] * 3;

        return size;
    }

    friend ostream &operator<<(ostream &os, Image &image) {
        os << image.name << " " << image.owner << " " << image.fileSize() << endl;
        return os;
    }

    bool operator>(Image &object) {
        if (this->fileSize() > object.fileSize()) {
            return true;
        }

        return false;
    }

};

class TransparentImage : public Image {
private:
    bool canHaveMoreTransparency;
public:
    TransparentImage() {
        this->name = new char[9];
        strcpy(this->name, "untitled");
        strcpy(this->owner, "unknown");
        for (int i = 0; i < 2; ++i) {
            this->dimensions[i] = 800;
        }
        this->canHaveMoreTransparency = true;
    }

    TransparentImage(char *name, char *owner, int width, int height, bool canHaveMoreTransparency) :
            Image(name, owner, width, height),
            canHaveMoreTransparency(canHaveMoreTransparency) {}

    TransparentImage &operator=(const TransparentImage &object) {
        if (this == &object) {
            return *this;
        }
        delete[] name;

        this->name = new char[strlen(object.name) + 1];
        strcpy(this->name, object.name);
        strcpy(this->owner, object.owner);
        for (int i = 0; i < 2; ++i) {
            this->dimensions[i] = object.dimensions[i];
        }
        this->canHaveMoreTransparency = object.canHaveMoreTransparency;
        return *this;
    }
    // methods

    int fileSize() override {
        int size;
        if (this->canHaveMoreTransparency) {
            size = this->dimensions[0] * this->dimensions[1] * 4;
            return size;
        }

        int temp = (this->dimensions[0] * this->dimensions[1]) / 8;

        size = (this->dimensions[0] * this->dimensions[1]) + temp;

        return size;
    }


};

class Folder {
private:
    char name[300];
    char folderOwner[60];
    Image *images[100];
    int numberOfImages;
public:
    Folder() {
        strcpy(this->name, "");
        strcpy(this->folderOwner, "unknown");
        this->numberOfImages = 0;
    }

    Folder(char *name, char *folderOwner) {
        strcpy(this->name, name);
        strcpy(this->folderOwner, folderOwner);
        this->numberOfImages = 0;
    }

    // methods
    int folderSize() const {
        int sum = 0;
        for (int i = 0; i < this->numberOfImages; ++i) {
            sum += this->images[i]->fileSize();
        }

        return sum;
    }

    Image *getMaxFile() {
        int max = 0;
        int index;
        for (int i = 0; i < this->numberOfImages; ++i) {
            if (max < this->images[i]->fileSize()) {
                max = this->images[i]->fileSize();
                index = i;
            }
        }

        return this->images[index];
    }

    void operator+=(Image &newImage) {
        if (this->numberOfImages == 100) {
            return;
        }
        this->images[this->numberOfImages++] = &newImage;
    }

    friend ostream &operator<<(ostream &os, const Folder &folder) {
        os << folder.name << " " << folder.folderOwner << endl;

        cout << "--" << endl;

        for (int i = 0; i < folder.numberOfImages; ++i) {
            cout << *folder.images[i];
        }
        cout << "--" << endl;

        cout << "Folder size: " << folder.folderSize();
        return os;
    }

    Image *operator[](int index) {
        return this->images[index];
    }
};

Folder max_folder_size(Folder folders[], int n) {
    int max = 0;
    int index;
    for (int i = 0; i < n; ++i) {
        if (max < folders->folderSize()) {
            max = folders->folderSize();
            index = i;
        }
    }

    return folders[index];
}

int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int w, h;
    bool tl;

    cin >> tc;

    if (tc == 1) {
        // Testing constructor(s) & operator << for class File

        cin >> name;
        cin >> user_name;
        cin >> w;
        cin >> h;


        Image f1;

        cout << f1;

        Image f2(name);
        cout << f2;

        Image f3(name, user_name);
        cout << f3;

        Image f4(name, user_name, w, h);
        cout << f4;
    } else if (tc == 2) {
        // Testing constructor(s) & operator << for class TextFile
        cin >> name;
        cin >> user_name;
        cin >> w >> h;
        cin >> tl;

        TransparentImage tf1;
        cout << tf1;

        TransparentImage tf4(name, user_name, w, h, tl);
        cout << tf4;
    } else if (tc == 3) {
        // Testing constructor(s) & operator << for class Folder
        cin >> name;
        cin >> user_name;

        Folder f3(name, user_name);
        cout << f3;
    } else if (tc == 4) {
        // Adding files to folder
        cin >> name;
        cin >> user_name;

        Folder dir(name, user_name);

        Image *f;
        TransparentImage *tf;

        int sub, fileType;

        while (1) {
            cin >> sub; // Should we add subfiles to this folder
            if (!sub) break;

            cin >> fileType;
            if (fileType == 1) { // Reading File
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                f = new Image(name, user_name, w, h);
                dir += *f;
            } else if (fileType == 2) {
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                cin >> tl;
                tf = new TransparentImage(name, user_name, w, h, tl);
                dir += *tf;
            }
        }
        cout << dir;
    } else if (tc == 5) {
        // Testing getMaxFile for folder

        cin >> name;
        cin >> user_name;

        Folder dir(name, user_name);

        Image *f;
        TransparentImage *tf;

        int sub, fileType;

        while (1) {
            cin >> sub; // Should we add subfiles to this folder
            if (!sub) break;

            cin >> fileType;
            if (fileType == 1) { // Reading File
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                f = new Image(name, user_name, w, h);
                dir += *f;
            } else if (fileType == 2) {
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                cin >> tl;
                tf = new TransparentImage(name, user_name, w, h, tl);
                dir += *tf;
            }
        }
        cout << *(dir.getMaxFile());
    } else if (tc == 6) {
        // Testing operator [] for folder

        cin >> name;
        cin >> user_name;

        Folder dir(name, user_name);

        Image *f;
        TransparentImage *tf;

        int sub, fileType;

        while (1) {
            cin >> sub; // Should we add subfiles to this folder
            if (!sub) break;

            cin >> fileType;
            if (fileType == 1) { // Reading File
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                f = new Image(name, user_name, w, h);
                dir += *f;
            } else if (fileType == 2) {
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                cin >> tl;
                tf = new TransparentImage(name, user_name, w, h, tl);
                dir += *tf;
            }
        }

        cin >> sub; // Reading index of specific file
        cout << *dir[sub];
    } else if (tc == 7) {
        // Testing function max_folder_size
        int folders_num;

        Folder dir_list[10];

        Folder dir;
        cin >> folders_num;

        for (int i = 0; i < folders_num; ++i) {
            cin >> name;
            cin >> user_name;
            dir = Folder(name, user_name);


            Image *f;
            TransparentImage *tf;

            int sub, fileType;

            while (1) {
                cin >> sub; // Should we add subfiles to this folder
                if (!sub) break;

                cin >> fileType;
                if (fileType == 1) { // Reading File
                    cin >> name;
                    cin >> user_name;
                    cin >> w >> h;
                    f = new Image(name, user_name, w, h);
                    dir += *f;
                } else if (fileType == 2) {
                    cin >> name;
                    cin >> user_name;
                    cin >> w >> h;
                    cin >> tl;
                    tf = new TransparentImage(name, user_name, w, h, tl);
                    dir += *tf;
                }
            }
            dir_list[i] = dir;
        }

        cout << max_folder_size(dir_list, folders_num);
    }
    return 0;
};
