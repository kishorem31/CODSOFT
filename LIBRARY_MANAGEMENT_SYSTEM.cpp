#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> books;
    int choice;
    do
    {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            string book;
            cout << "Enter book name: ";
            getline(cin, book);
            books.push_back(book);
            cout << "Book Added Successfully!\n";
        }
        else if (choice == 2)
        {
            if (books.empty())
            {
                cout << "No Books Available.\n";
            }
            else
            {
                cout << "\nAvailable Books:\n";
                for (int i = 0; i < books.size(); i++)
                {
                    cout << i + 1 << ". " << books[i] << endl;
                }
            }
        }
        else if (choice == 3)
        {
            int num;
            if (books.empty())
            {
                cout << "No Books Available To Borrow.\n";
            }
            else
            {
                cout << "\nAvailable Books:\n";
                for (int i = 0; i < books.size(); i++)
                {
                    cout << i + 1 << ". " << books[i] << endl;
                }
                cout << "Enter book number to borrow: ";
                cin >> num;
                if (num >= 1 && num <= books.size())
                {
                    cout << "You borrowed: " << books[num - 1] << endl;
                    books.erase(books.begin() + num - 1);
                }
                else
                {
                    cout << "Invalid Book Number.\n";
                }
            }
        }
        else if (choice == 4)
        {
            string book;
            cin.ignore();
            cout << "Enter book name to return: ";
            getline(cin, book);
            books.push_back(book);
            cout << "Book Returned Successfully!\n";
        }
        else if (choice == 5)
        {
            cout << "Thank You!\n";
        }
        else
        {
            cout << "Invalid Choice.\n";
        }
    } while (choice != 5);
    return 0;
}