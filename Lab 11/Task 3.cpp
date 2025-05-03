#include <iostream>
using namespace std;

class FileException
{
    public:
        virtual const char* what() const noexcept
        {
            return "FileException - Error!";
        }


};

class FileNotFoundException : public FileException
{
    public:
        const char* what() const noexcept override
        {
            return "FileNotFoundException - File not found!";
        }
};

class PermissionDeniedException : public FileException
{
    public:
        const char* what() const noexcept override
        {
            return "PermissionDeniedException - Access Denied!";
        }
};

void readFile(const string& filename)
{
    if (filename == "books.txt")
    {
        throw FileNotFoundException();
    }
    else if(filename == "secret.txt")
    {
        throw PermissionDeniedException();
    }
    else
    {
        cout << "Reading file " << filename << endl;
    }
}

int main()
{
    try 
    {
        readFile("inventory.txt");
        readFile("secret.txt");
        readFile("books.txt");
    }
    catch(const FileNotFoundException& e)
    {
        cout << e.what() << endl;
    }
    catch(const PermissionDeniedException& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
