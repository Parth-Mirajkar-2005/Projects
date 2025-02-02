#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// XOR-based simple encryption and decryption functions
string encryptData(const string &data, const string &password)
{
    string encrypted = data;
    for (size_t i = 0; i < data.size(); ++i)
    {
        encrypted[i] ^= password[i % password.size()]; // XOR encryption
    }
    return encrypted;
}

string decryptData(const string &data, const string &password)
{
    return encryptData(data, password); // XOR works both ways
}

struct FileNode
{
    string fileName;
    string password;
    FileNode *next;
};

class FilePasswordList
{
private:
    FileNode *head;

public:
    FilePasswordList() : head(nullptr) {}

    void addFilePassword(const string &fileName, const string &password)
    {
        if (fileExists(fileName))
            return;

        FileNode *newNode = new FileNode{fileName, password, nullptr};
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            FileNode *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    FileNode *getHead() const { return head; }

    void displayFiles() const
    {
        if (!head)
        {
            cout << "No files available." << endl;
            return;
        }

        FileNode *temp = head;
        int index = 1;
        while (temp)
        {
            cout << index++ << ": " << temp->fileName << endl;
            temp = temp->next;
        }
    }

    string getPasswordForFile(const string &fileName) const
    {
        for (FileNode *temp = head; temp; temp = temp->next)
            if (temp->fileName == fileName)
                return temp->password;
        return "";
    }

    bool fileExists(const string &fileName) const
    {
        for (FileNode *temp = head; temp; temp = temp->next)
            if (temp->fileName == fileName)
                return true;
        return false;
    }

    ~FilePasswordList()
    {
        while (head)
        {
            FileNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Save both file names and encrypted passwords in one file
void saveFileData(const FilePasswordList &fileList, const string &masterPassword)
{
    ofstream file("passwords.txt");
    if (file.is_open())
    {
        for (FileNode *temp = fileList.getHead(); temp; temp = temp->next)
            file << temp->fileName << " " << encryptData(temp->password, masterPassword) << endl;
    }
    else
    {
        cerr << "Error saving file data." << endl;
    }
}

// Load file data (names and passwords) from the single file
void loadFileData(FilePasswordList &fileList, const string &masterPassword)
{
    ifstream file("passwords.txt");
    string fileName, encryptedPassword;

    while (file >> fileName >> encryptedPassword)
        fileList.addFilePassword(fileName, decryptData(encryptedPassword, masterPassword));
}

int main()
{
    FilePasswordList fileList; // Linked list for storing files and their passwords
    char choice;
    string fileName, password, fileData, line;
    string masterPassword;

    cout << "Enter master password: ";
    getline(cin, masterPassword);

    loadFileData(fileList, masterPassword);

    do
    {
        cout << "\nMenu:\n1. Create a new File\n2. Display list of Files\n3. Encrypt File\n4. Decrypt File\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case '1':
        {
            cout << "Enter the name of the file to create: ";
            getline(cin, fileName);

            if (fileList.fileExists(fileName))
            {
                cout << "File already exists!" << endl;
                break;
            }

            ofstream file(fileName);
            if (!file)
            {
                cout << "Error creating file." << endl;
            }
            else
            {
                cout << "File " << fileName << " created successfully." << endl;
                file.close();

                cout << "Set a password for the file: ";
                getline(cin, password);
                fileList.addFilePassword(fileName, password);

                saveFileData(fileList, masterPassword);
            }
            break;
        }
        case '2':
        {
            cout << "List of files:" << endl;
            fileList.displayFiles();
            break;
        }
        case '3':
        {
            fileList.displayFiles();

            cout << "Enter the name of the file to encrypt: ";
            getline(cin, fileName);

            if (!fileList.fileExists(fileName))
            {
                cout << "File does not exist!" << endl;
                break;
            }

            ifstream inFile(fileName);
            if (!inFile.is_open())
            {
                cout << "Error: File not found." << endl;
                break;
            }

            fileData = "";
            while (getline(inFile, line))
            {
                fileData += line + '\n';
            }
            inFile.close();

            password = fileList.getPasswordForFile(fileName);
            if (password.empty())
            {
                cout << "Password not found for file." << endl;
                break;
            }

            ofstream outFile(fileName);
            outFile << encryptData(fileData, password);
            outFile.close();
            cout << "File encrypted successfully!" << endl;
            break;
        }

        case '4':
        {
            fileList.displayFiles();

            cout << "Enter the name of the file to decrypt: ";
            getline(cin, fileName);

            if (!fileList.fileExists(fileName))
            {
                cout << "File does not exist!" << endl;
                break;
            }

            ifstream inFile(fileName);
            if (!inFile.is_open())
            {
                cout << "Error: File not found." << endl;
                break;
            }

            fileData = "";
            while (getline(inFile, line))
            {
                fileData += line + '\n';
            }
            inFile.close();

            string enteredPassword;
            cout << "Enter password for decryption: ";
            getline(cin, enteredPassword);

            if (fileList.getPasswordForFile(fileName) != enteredPassword)
            {
                cout << "Incorrect password. Decryption failed!" << endl;
                break;
            }

            ofstream outFile(fileName);
            outFile << decryptData(fileData, enteredPassword);
            outFile.close();
            cout << "File decrypted successfully!" << endl;
            break;
        }

        case '5':
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}
