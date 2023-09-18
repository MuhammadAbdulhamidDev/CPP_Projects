#include <iostream>
#include "projectFunctions.h"
using namespace std;

// ---------------------------------> General Functions <--------------------------------- //
void printIntroMessage()
{
    cout << "*********************************************************\n";
    cout << "**************** Welcome to Qena Library ****************\n";
    cout << "*********************************************************\n";
}
void handleInvalidInput(int &choice)
{
    clearInput();
    cout << "Your choice: ";
    cin >> choice;
}
void handleInvalidChoice(int &choice)
{
    clearChoice();
    cout << "Your choice: ";
    cin >> choice;
}
void printInvalidInputsMessage()
{
    cout << "=========================================================\n";
    cout << "========== Invalid Input/s .. Please Try Again! =========\n";
    cout << "=========================================================\n";
}
void printInvalidChoiceMessage()
{
    cout << "=========================================================\n";
    cout << "========== Invalid Choice .. Please Try Again! ==========\n";
    cout << "=========================================================\n";
}
bool stopFunction(string message)
{
    while (true)
    {
        char stopChoice{};
        cout << "=========================================================\n";
        cout << message;
        cin >> stopChoice;
        clear();
        if (stopChoice == 'n' || stopChoice == 'N')
        {
            cout << "=========================================================\n";
            return true;
        }
        else if (stopChoice == 'y' || stopChoice == 'Y')
        {
            cout << "=========================================================\n";
            return false;
        }
    }
}
void readHiddenInput(string &field)
{
    field.clear();
    char ch{};

    while (true)
    {
        ch = _getch();

        if (ch == ' ')
        {
            break;
        }

        field.push_back(ch);
        cout << '*';
    }

    cout << endl;
}
void clearInput()
{
    clear();
    printInvalidInputsMessage();
}
void clearChoice()
{
    clear();
    printInvalidChoiceMessage();
}
void clear()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void autoClearScreen()
{
    system("cls");
}
// --------------------------------------------------------------------------------------- //
// ------ # Part 01 ---> Start Functions to display the main menu (Admin & User) --------- //
int getMainChoice()
{
    printIntroMessage();
    int mainChoice{};
    displayMainMenu();
    cin >> mainChoice;

    while (true)
    {
        if (cin.fail())
        {
            handleInvalidInput(mainChoice);
        }
        else if (mainChoice >= 1 && mainChoice <= 3)
        {
            return mainChoice;
        }
        else
        {
            handleInvalidChoice(mainChoice);
        }
    }
}
void displayMainMenu()
{
    cout << "=========================================================\n";
    cout << "Please choose an option below: \n";
    cout << "1- Admin\n";
    cout << "2- User\n";
    cout << "3- Exit\n";
    cout << "Your choice: ";
}
void printExitMessage()
{
    cout << "*********************************************************\n";
    cout << "***** Thanks For using our library .. See you soon! *****\n";
    cout << "*********************************************************\n";
}
// ------- # Part 01 ---> End Functions to display the main menu (Admin & User) ---------- //
// ------- # Part 02 ---> Start Functions For Admin Section ------------------------------ //
// ---------------------------- Start loginAdmin() Function ------------------------------ //
bool loginAdmin(string &mainAdminId)
{
    while (true)
    {
        string username, password, id;

        if (stopFunction("==== Do you try to log in as an administrator? (y / n): "))
        {
            return true;
        }

        username, password, id;
        getAdminData(username, password, id);

        bool oldAdminExists = checkOldAdminExists(username, password, id);

        if (oldAdminExists && !isValidAdmin(username, password, id))
        {
            printFailMessage();
        }
        else if (isValidAdmin(username, password, id))
        {
            mainAdminId = id;
            printWelcomeAdminMessage(id);
            break;
        }
        else
        {
            cout << "======= Error: You are not an admin in our system =======\n";
        }
    }
    return false;
}
void getAdminData(string &username, string &password, string &id)
{
    displayLoginAdminPromptMessage();

    cout << "Username: ";
    readHiddenInput(username);
    cout << "Password: ";
    readHiddenInput(password);
    cout << "ID: ";
    readHiddenInput(id);
    cout << "=========================================================\n";
}
void displayLoginAdminPromptMessage()
{
    cout << "=========================================================\n";
    cout << "====== Please enter your Username & Password & ID =======\n";
    cout << "= Note: Press spacebar in hidden input to finish typing =\n";
    cout << "=========================================================\n";
}
bool checkOldAdminExists(const string &username, const string &password, const string &id)
{
    for (const Admin &existingAdmin : LibraryData::adminsList)
    {
        if ((existingAdmin.username == username) || (existingAdmin.password == password) || (existingAdmin.id == id))
        {
            return true;
        }
    }
    return false;
}
bool isValidAdmin(const string &username, const string &password, const string &id)
{
    for (const Admin &admin : LibraryData::adminsList)
    {
        if (username == admin.username && password == admin.password && id == admin.id)
        {
            return true;
        }
    }
    return false;
}
void printWelcomeAdminMessage(const string &id)
{
    for (const Admin &admin : LibraryData::adminsList)
    {
        if (id == admin.id)
        {
            printSuccessMessage();
            if (admin.gender == 'M')
            {
                cout << "<--> Welcome Mr - " << admin.name << "\n";
            }
            else
            {
                cout << "<--> Welcome Miss - " << admin.name << "\n";
            }
            break;
        }
    }
}
void printSuccessMessage()
{
    cout << "============ The login process is successful ============\n";
    cout << "=========================================================\n";
}
void printFailMessage()
{
    cout << "========== The login process is not successful ==========\n";
    cout << "=========================================================\n";
    cout << "======== Error: Invalid username, password, or ID =======\n";
}
void printInvalidMainAdminMessage()
{
    cout << "=========================================================\n";
    cout << "===== Sorry: This feature for the main admin only! ======\n";
    cout << "=========================================================\n";
}
// // ---------------------------- End loginAdmin() Function ----------------------------- //
// // ---------------------------- Start GetAdminChoice() Function ----------------------- //
int getAdminChoice()
{
    int adminChoice{};

    displayAdminMenu();
    cin >> adminChoice;

    while (true)
    {
        if (cin.fail())
        {
            handleInvalidInput(adminChoice);
        }
        else if (adminChoice >= 1 && adminChoice <= 9)
        {
            return adminChoice;
        }
        else
        {
            handleInvalidChoice(adminChoice);
        }
    }
}
void displayAdminMenu()
{
    cout << "=========================================================\n";
    cout << "Please choose an option below: " << endl;
    cout << "1- Display Admins List" << endl;
    cout << "2- Add a new admin" << endl;
    cout << "3- Delete an admin" << endl;
    cout << "4- Display Users List" << endl;
    cout << "5- Display books list" << endl;
    cout << "6- Add a book" << endl;
    cout << "7- Delete a book" << endl;
    cout << "8- Update a book" << endl;
    cout << "9- Exit" << endl;
    cout << "Your choice: ";
}
// // ---------------------------- End GetAdminChoice() Function ------------------------- //
// // ---------------------------- Start displayAdminInfo() Function --------------------- //
void displayAdminsList(string &mainAdminId)
{
    if (mainAdminId != "1997" && mainAdminId != "2004")
    {
        printInvalidMainAdminMessage();
        return;
    }
    printAdminsListMessage();

    bool found = false;

    printSubAdminsMessage();
    for (const Admin &admin : LibraryData::adminsList)
    {
        if (admin.id != "1997" && admin.id != "2004")
        {
            printAdminsInfo(admin);
            found = true;
        }
    }

    if (!found)
    {
        printNoSubAdminsMessage();
    }
}
void printAdminsListMessage()
{
    cout << "=========================================================\n";
    cout << "================ The Admins in our system ===============\n";
}
void printSubAdminsMessage()
{
    cout << "===================== The Sub-Admins ====================\n";
}
void printNoSubAdminsMessage()
{
    cout << "=========================================================\n";
    cout << "=========== There are not Sub Admins for now ============\n";
}
void printAdminsInfo(const Admin &admin)
{
    cout << "=========================================================\n";
    cout << "Admin's Name: " << admin.name << endl;
    cout << "Admin's UserName: " << admin.username << endl;
    cout << "Admin's Password: " << admin.password << endl;
    cout << "Admin's Gender: " << admin.gender << endl;
    cout << "Admin's ID: " << admin.id << endl;
    cout << "=========================================================\n";
}
// // ---------------------------- End displayAdminInfo() Function ----------------------- //
// // ---------------------------- Start addAdmin() Function ----------------------------- //
void addNewAdmin(string &mainAdminId)
{
    if (mainAdminId != "1997" && mainAdminId != "2004")
    {
        printInvalidMainAdminMessage();
        return;
    }
    Admin newAdmin;

    while (true)
    {
        if (stopFunction("Do you want to (continue||repeat) this process? (y/n): "))
        {
            break;
        }

        newAdmin = getNewAdminData();

        bool adminExists = checkNewAdminExists(newAdmin.id);
        if (adminExists)
        {
            printAddNewAdminFailMessage();
        }
        else
        {
            printAddNewAdminSucceesMessage();
            LibraryData::adminsList.push_back(newAdmin);
        }
    }
}
Admin getNewAdminData()
{
    Admin newAdmin;
    displayNewAdminDataEntryPrompt();

    getAndCheckNewAdminNameValidation(newAdmin.name);

    getAndCheckNewAdminUsernameValidation(newAdmin.username, newAdmin.name);

    getAndcheckNewAdminIdValidtion(newAdmin.id);

    getAndCheckNewAdminPasswordValidation(newAdmin.password, newAdmin.id);

    getAndCheckNewAdminGenderValidation(newAdmin.gender);

    clear();

    return newAdmin;
}
void displayNewAdminDataEntryPrompt()
{
    cout << "=================================================================\n";
    cout << "Please enter admin' data(Name, Username, ID, Password and Gender)\n";
    cout << "======= Name (FirstName SecondName), Username (fisrtN_ad) =======\n";
    cout << "=== ID (1990 - 2000), Password (Qena + ID), Gender 'M' or 'F' ===\n";
    cout << "===== Note: Press spacebar in hidden input to finish typing =====\n";
    cout << "=================================================================\n";
}
void getAndCheckNewAdminNameValidation(string &name)
{
    while (true)
    {
        cout << "Name (FirstName SecondName): ";
        getline(cin, name);
        bool validName = (name.find(' ') != string::npos);
        string firstName = name.substr(0, name.find(' '));
        string secondName = name.substr(name.find(' ') + 1);
        // Check if the first character of the first name and second name are uppercase
        bool validFirstName = !firstName.empty() && isupper(firstName[0]);
        bool validSecondName = !secondName.empty() && isupper(secondName[0]);

        if (validName && validFirstName && validSecondName)
        {
            break;
        }
        else
        {
            cout << "Error --->  ";
        }
    }
}
void getAndCheckNewAdminUsernameValidation(string &username, string &name)
{
    while (true)
    {
        cout << "Username (firstName_ad): ";
        readHiddenInput(username);
        string firstName = name.substr(0, name.find(' '));
        transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
        bool validUsername = (username == (firstName + "_ad"));

        if (validUsername)
        {
            break;
        }
        else
        {
            cout << "Error ---> ";
        }
    }
}
void getAndcheckNewAdminIdValidtion(string &newAdminId)
{
    while (true)
    {
        cout << "ID (1990 - 2000): ";
        readHiddenInput(newAdminId);

        bool isDigits = true;
        for (char c : newAdminId)
        {
            if (!isdigit(c))
            {
                isDigits = false;
                cout << "Error ---> ";
                break;
            }
        }
        if (isDigits)
        {
            if (bool validID = (stoi(newAdminId) >= 1990 && stoi(newAdminId) <= 2000 && stoi(newAdminId) != 1997))
            {
                break;
            }
            else
            {
                cout << "Error ---> ";
            }
        }
    }
}
void getAndCheckNewAdminPasswordValidation(string &password, string &id)
{
    while (true)
    {
        cout << "Password (Qena + ID): ";
        readHiddenInput(password);

        bool validPassword = (password == ("Qena" + id));

        if (validPassword)
        {
            break;
        }
        else
        {
            cout << "Error ---> ";
        }
    }
}
void getAndCheckNewAdminGenderValidation(char &gender)
{
    while (true)
    {
        cout << "Gender (M || F): ";
        cin >> gender;

        bool validGender = (gender == 'M' || gender == 'F');
        if (validGender)
        {
            break;
        }
        else
        {
            cout << "Error ---> ";
        }
    }
}
bool checkNewAdminExists(string &adminId)
{
    for (const Admin &existingAdmin : LibraryData::adminsList)
    {
        if (existingAdmin.id == adminId)
        {
            return true;
        }
    }
    return false;
}
void printAddNewAdminSucceesMessage()
{
    cout << "=========================================================\n";
    cout << "============= New Admin added successfully! =============\n";
    cout << "=========================================================\n";
}
void printAddNewAdminFailMessage()
{
    cout << "=================================================================\n";
    cout << "====== The addition process is failed .. Please try again! ======\n";
    cout << "=================================================================\n";
    cout << "================= The Admin is already existed ==================\n";
    cout << "=================================================================\n";
}
// // ---------------------------- end() addAdmin Function ------------------------------- //
// // ---------------------------- Start deleteAmine() Function -------------------------- //
void deleteAdmin(string &mainAdminId)
{
    if (mainAdminId != "1997" && mainAdminId != "2004")
    {
        printInvalidMainAdminMessage();
        return;
    }

    Admin deletedAdmin;

    while (true)
    {
        string adminId;
        if (stopFunction("Do you want to (continue||repeat) this process? (y/n): "))
        {
            break;
        }

        readAdminId(adminId);
        if (isDeletedAdmin(adminId))
        {
            printDeletedAdminSucceesMessage();
        }
        else
        {
            printDeletedAdminFailMessage();
        }
    }
}
void readAdminId(string &adminId)
{
    cout << "=========================================================\n";
    while (true)
    {
        cout << "Admin's ID (1990 - 2000): ";
        readHiddenInput(adminId);

        if (checkAdminIdValidation(adminId))
        {
            break;
        }
    }
}
bool checkAdminIdValidation(string &adminId)
{
    for (char c : adminId)
    {
        if (!isdigit(c))
        {
            cout << "Error ---> ";
            return false;
        }
    }
    if (stoi(adminId) < 1990 || stoi(adminId) > 2000 || (stoi(adminId) == 1997))
    {
        cout << "Error ---> ";
        return false;
    }
    return true;
}
bool isDeletedAdmin(string &adminId)
{
    for (auto it = LibraryData::adminsList.begin(); it != LibraryData::adminsList.end(); ++it)
    {
        if (adminId == it->id)
        {
            LibraryData::adminsList.erase(it);
            return true;
        }
    }
    return false;
}
void printDeletedAdminFailMessage()
{
    cout << "=========================================================\n";
    cout << "== The deletion process is failed .. Please try again! ==\n";
    cout << "========= This Admin is not found in our system =========\n";
    cout << "=========================================================\n";
}
void printDeletedAdminSucceesMessage()
{
    cout << "=========================================================\n";
    cout << "============== Admin Deleted successfully! ==============\n";
    cout << "=========================================================\n";
}
// // ---------------------------- End deleteAdmine() Function --------------------------- //
// // ---------------------------- Start displayAminsList() Function --------------------- //
void displayUsersList()
{
    printUsersListMessage();

    bool found = false;
    for (const User &user : LibraryData::usersList)
    {
        printUsersInfo(user);
        found = true;
    }
    if (!found)
    {
        printNoUsersMessage();
    }
    // manualClearScreen("Enter c || C to clear the console screen: ");
}
void printUsersListMessage()
{
    cout << "=========================================================\n";
    cout << "================= The Users in our system ===============\n";
}
void printNoUsersMessage()
{
    cout << "=========================================================\n";
    cout << "============== There are not Users for now ==============\n";
}
void printUsersInfo(const User &user)
{
    cout << "=========================================================\n";
    cout << "User's Name: " << user.name << endl;
    cout << "User's UserName: " << user.username << endl;
    cout << "User's Password: " << user.password << endl;
    cout << "User's Gender: " << user.gender << endl;
    cout << "User's ID: " << user.id << endl;
    cout << "=========================================================\n";
}
// // ---------------------------- End displayAminsList() Function ----------------------- //
// // ---------------------------- Start displayBookInfo() Function ---------------------- //
void displayBooksForAdmin()
{
    printBooksMessage();
    for (const Book &book : LibraryData::booksList)
    {
        printBookInfo(book);
    }
    // manualClearScreen("Enter c || C to clear the console screen: ");
}
void printBooksMessage()
{
    cout << "=========================================================\n";
    cout << "============== The books in our library are: ============\n";
}
void printBookInfo(const Book &book)
{
    cout << "=========================================================\n";
    cout << "Book Name: " << book.name << endl;
    cout << "Book ID: " << book.id << endl;
    cout << "Book Count: " << book.count << endl;
    cout << "Book Status: " << (book.status ? "Available" : "Not Available") << endl;
    cout << "=========================================================\n";
}
// // ---------------------------- End displayBookInfo() Function ------------------------ //
// // ---------------------------- Start addBook() Function ------------------------------ //
void addBook()
{
    Book newBook;
    while (true)
    {
        if (stopFunction("Do you want to (continue||repeat) this process? (y/n): "))
        {
            break;
        }

        newBook = getNewBookInfo();

        if (isValidBook(newBook, LibraryData::booksList))
        {
            printAddBookSucceesMessage();
            LibraryData::booksList.push_back(newBook);
            break;
        }
    }
}
Book getNewBookInfo()
{
    Book newBook;
    displayBookInfoPromptMessage();

    cout << "Book's Name: ";
    getline(cin, newBook.name);

    cout << "Book's Author: ";
    getline(cin, newBook.author);

    cout << "Book's Category: ";
    getline(cin, newBook.category);

    getAndCheckBookStatusValidation(newBook.status);

    getAndCheckBookIdValidation(newBook.id);

    getAndCheckBookCountValidation(newBook.count);

    return newBook;
}
void getAndCheckBookIdValidation(int &newBookId)
{
    while (true)
    {
        cout << "Book's ID (1001 - 1099, Odd): ";
        cin >> newBookId;
        if (cin.fail() || newBookId < 1001 || newBookId > 1099 || newBookId % 2 == 0)
        {
            clear();
            cout << "Error ---> ";
        }
        else
        {
            break;
        }
    }
}
void getAndCheckBookStatusValidation(bool &newBookStatus)
{
    while (true)
    {
        cout << "Book's Status (1 for true, 0 for false): ";
        cin >> newBookStatus;
        if (cin.fail())
        {
            clear();
            cout << "Error ---> ";
        }
        else
        {
            break;
        }
    }
}
void getAndCheckBookCountValidation(int &newBookCount)
{
    while (true)
    {
        cout << "Book's Count (greater than 0): ";
        cin >> newBookCount;
        if (cin.fail() || (newBookCount <= 0))
        {
            clear();
            cout << "Error ---> ";
        }
        else
        {
            break;
        }
    }
}
void displayBookInfoPromptMessage()
{
    cout << "==================================================================\n";
    cout << "Please enter Book' (Name, Author, Category, Status, ID and Count):\n";
    cout << "== Status must be 1 or 0, 1001 =< ID (Odd) >= 1099 & Count > 0 ===\n";
    cout << "==================================================================\n";
}
bool isValidBook(const Book &newBook, const vector<Book> &booksList)
{
    for (const Book &book : booksList)
    {
        if (newBook.id == book.id)
        {
            printExistBookMessage();
            return false;
        }
    }
    return true;
}
void printExistBookMessage()
{
    cout << "=============================================================\n";
    cout << "==== The addition process is failed .. Please try again! ====\n";
    cout << "================ The Book is already existed ================\n";
    cout << "=============================================================\n";
}
void printAddBookSucceesMessage()
{
    cout << "=========================================================\n";
    cout << "=============== Book added successfully! ================\n";
}
// // ---------------------------- End addBook() Function --------------------------------- //
// // ---------------------------- Start deleteBook() Function ---------------------------- //
void deleteBook()
{
    while (true)
    {
        if (stopFunction("Do you want to (continue||repeat) this process? (y/n): "))
        {
            break;
        }

        int bookId{};
        getAndCheckBookIdValidation(bookId);

        bool deleted = isDeletedBook(bookId);

        if (deleted)
        {
            printDeletionSuccessMessage();
        }
        else
        {
            printDeletionFailMessage();
        }
    }
}
bool isDeletedBook(int &bookId)
{
    for (auto it = LibraryData::booksList.begin(); it != LibraryData::booksList.end(); ++it)
    {
        if (bookId == it->id)
        {
            it = LibraryData::booksList.erase(it);
            return true;
        }
    }
    return false;
}
void printDeletionFailMessage()
{
    cout << "=========================================================\n";
    cout << "============ The deletion process is failed =============\n";
    cout << "========= This Book was not found in our system =========\n";
    cout << "=========================================================\n";
}
void printDeletionSuccessMessage()
{
    cout << "=========================================================\n";
    cout << "============== Book deleted successfully! ===============\n";
    cout << "=========================================================\n";
}
// // ------------------------------ End deleteBook() Function ------------------------------- //
// // ------------------------------ Start updateBook() Function ----------------------------- //
void updateBook()
{
    int bookId{}, choice{}, newCount{};

    while (true)
    {
        if (stopFunction("Do you want to (continue||repeat) this process? (y/n): "))
        {
            break;
        }

        getAndCheckBookIdValidation(bookId);

        choice = getUpdateMenuChoice();

        if (choice == 1)
        {
            bool success = isUpdateStatus(bookId);
            printUpdateStatusMessage(success);
        }
        else if (choice == 2)
        {
            newCount = getNewCount();
            bool success = isUpdateCount(bookId, newCount);
            printUpdateCountMessage(success);
        }
    }
}
int getUpdateMenuChoice()
{
    int choice{};
    displayUpdateMenu();
    cin >> choice;

    do
    {
        if (cin.fail())
        {
            handleInvalidInput(choice);
        }
        else if (choice != 1 && choice != 2)
        {
            handleInvalidChoice(choice);
        }
    } while (choice != 1 && choice != 2);
    return choice;
}
void displayUpdateMenu()
{
    cout << "=========================================================\n";
    cout << "Please choose an option below: \n";
    cout << "1- update the status\n";
    cout << "2- update the count\n";
    cout << "Your choice: ";
}
bool isUpdateStatus(int &bookId)
{
    for (Book &book : LibraryData::booksList)
    {
        if (bookId == book.id)
        {
            book.status = !book.status;
            return true;
        }
    }
    return false;
}
void printUpdateStatusMessage(bool &success)
{
    if (success)
    {
        cout << "=========================================================\n";
        cout << "============== updated Status successfully! =============\n";
    }
    else
    {
        cout << "=========================================================\n";
        cout << "======== This Book ID was not found in our system =======\n";
        cout << "The update status process is failed ... Please try again!\n";
    }
}
int getNewCount()
{
    int newCount{};
    do
    {
        cout << "=========================================================\n";
        cout << "Please enter the updated count: ";
        cin >> newCount;
    } while (!checkNewCountValidation(newCount));
    return newCount;
}
bool checkNewCountValidation(int &newCount)
{
    if (cin.fail() || newCount < 1)
    {
        clearInput();
        return false;
    }
    return true;
}
bool isUpdateCount(int &bookId, int &newCount)
{
    for (Book &book : LibraryData::booksList)
    {
        if (bookId == book.id)
        {
            book.count = newCount;
            return true;
        }
    }
    return false;
}
void printUpdateCountMessage(bool &success)
{
    if (success)
    {
        cout << "=========================================================\n";
        cout << "============== Updated Count successfully! ==============\n";
        cout << "=========================================================\n";
    }
    else
    {
        cout << "=========================================================\n";
        cout << "======== This Book ID was not found in our system =======\n";
        cout << "The update count process is failed .... Please try again!\n";
        cout << "=========================================================\n";
    }
}
// // ---------------------------- End updateBook() Function ----------------------------- //
// // ---------------------------- End Functions For Admin Section ----------------------- //
// // ------- # Part 02 ---> End the Admin section --------------------------------------- //
// // ------- # Part 03 ---> Start the User section -------------------------------------- //
// // ---------------------------- Start Functions For User ------------------------------ //
// // ---------------------------- Start GetUserChoice() Function ------------------------ //
bool logInUser()
{
    if (stopFunction("== Do you try to sign-in or sign-up as a user? (y / n): "))
    {
        autoClearScreen();
        return true;
    }
    return false;
}
int getUserMainChoice()
{
    int userMainChoice{};
    displayUserMainMenu();
    cin >> userMainChoice;

    while (true)
    {
        if (cin.fail())
        {
            handleInvalidInput(userMainChoice);
        }
        else if (userMainChoice >= 1 && userMainChoice <= 3)
        {
            return userMainChoice;
        }
        else
        {
            handleInvalidChoice(userMainChoice);
        }
    }
}
void displayUserMainMenu()
{
    cout << "=========================================================\n";
    cout << "Please choose an option below: \n";
    cout << "1- SignUp\n";
    cout << "2- SignIn\n";
    cout << "3- Exit\n";
    cout << "Your choice: ";
}
// // ---------------------------- End GetUserChoice() Function -------------------------- //
// // ---------------------------- Start Function signUpNewUser() ------------------------ //
void signUpNewUser()
{
    User newUser;
    if (stopFunction("Do you want to (continue (y) || stop (n)) this process? "))
    {
        return;
    }

    getNewUserData(newUser);

    if (isValidNewUser(newUser.id))
    {
        printAddNewUserSucceesMessage();
        LibraryData::usersList.push_back(newUser);
    }
    else
    {
        printExistUserMessage();
    }

    char c{};
    cout << "------------> PLease enter (c) to sign in: ";
    cin >> c;
}
void getNewUserData(User &newUser)
{
    displayNewUserDataEntryPrompt();

    getAndCheckNewUserNameValidation(newUser.name);

    getAndCheckNewUserUsernameValidation(newUser.username, newUser.name);

    getAndcheckNewUserIdValidtion(newUser.id);

    getAndCheckNewUserPasswordValidation(newUser.password, newUser.id);

    getAndCheckNewUserGenderValidation(newUser.gender);

    clear();
}
void displayNewUserDataEntryPrompt()
{
    cout << "=================================================================\n";
    cout << "=============== Please enter your data to sign up ===============\n";
    cout << "====== Name (FirstName SecondName), Username (firstName_us) =====\n";
    cout << "==== ID > 1000 (Odd), Password (Qena + ID), Gender (M || F) =====\n";
    cout << "===== Note: Press spacebar in hidden input to finish typing =====\n";
    cout << "=================================================================\n";
}
void getAndCheckNewUserNameValidation(string &name)
{
    while (true)
    {
        cout << "Name (FirstName SecondName): ";
        getline(cin, name);
        bool validName = (name.find(' ') != string::npos);
        string firstName = name.substr(0, name.find(' '));
        string secondName = name.substr(name.find(' ') + 1);
        // Check if the first character of the first name and second name are uppercase
        bool validFirstName = !firstName.empty() && isupper(firstName[0]);
        bool validSecondName = !secondName.empty() && isupper(secondName[0]);

        if (validName && validFirstName && validSecondName)
        {
            break;
        }
        else
        {
            cout << "Error ---> ";
        }
    }
}
void getAndCheckNewUserUsernameValidation(string &username, string &name)
{
    while (true)
    {
        cout << "Username (firstName_us): ";
        readHiddenInput(username);
        string firstName = name.substr(0, name.find(' '));
        transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
        bool validUsername = (username == (firstName + "_us"));

        if (validUsername)
        {
            break;
        }
        else
        {
            cout << "Error ---> ";
        }
    }
}
void getAndcheckNewUserIdValidtion(string &newUserId)
{
    while (true)
    {
        cout << "ID > 1000 (Odd): ";
        readHiddenInput(newUserId);

        bool isDigits = true;
        for (char c : newUserId)
        {
            if (!isdigit(c))
            {
                isDigits = false;
                cout << "Error ---> ";
                break;
            }
        }
        if (isDigits)
        {
            if (bool validID = ((stoi(newUserId) > 1000) && (stoi(newUserId) % 2 != 0)))
            {
                break;
            }
            else
            {
                cout << "Error ---> ";
            }
        }
    }
}
void getAndCheckNewUserPasswordValidation(string &password, string &id)
{
    while (true)
    {
        cout << "Password (Qena + ID): ";
        readHiddenInput(password);

        bool validPassword = (password == ("Qena" + id));

        if (validPassword)
        {
            break;
        }
        else
        {
            cout << "Error ---> ";
        }
    }
}
void getAndCheckNewUserGenderValidation(char &gender)
{
    while (true)
    {
        cout << "Gender (M || F): ";
        cin >> gender;

        bool validGender = (gender == 'M' || gender == 'F');
        if (validGender)
        {
            break;
        }
        else
        {
            cout << "Error ---> ";
        }
    }
}
bool isValidNewUser(const string &id)
{
    if (LibraryData::usersList.empty())
    {
        return true; // The list is empty, so the new user is valid.
    }

    for (const User &existingUser : LibraryData::usersList)
    {
        if (id == existingUser.id)
        {
            return false; // The new user's data matches an existing user, so it's not valid.
        }
    }
    return true; // The new user is unique and valid.
}
void printAddNewUserSucceesMessage()
{
    cout << "=========================================================\n";
    cout << "============= New User added successfully! ==============\n";
    cout << "============= PLease sign in to continue!! ==============\n";
    cout << "=========================================================\n";
}
void printExistUserMessage()
{
    cout << "=================================================================\n";
    cout << "================= This User is already existed ==================\n";
    cout << "====== The addition process is failed .. Please try again! ======\n";
    cout << "=================================================================\n";
}
// ---------------------------- End Function signUpNewUser() ------------------------- //
// ---------------------------- Start signInUser() Function -------------------------- //
bool signInUser(string &loggedInUserId) // Pass a reference to store the user ID
{
    while (true)
    {
        string username, password, id;

        if (stopFunction("============ Do you try to sign in as an User? (y / n): "))
        {
            return true;
        }

        getUserInputs(username, password, id);

        bool oldUserExists = checkOldUserExists(username, password, id);

        if (oldUserExists && !isValidUser(username, password, id))
        {
            printFailMessage();
        }
        else if (isValidUser(username, password, id))
        {
            loggedInUserId = id; // Store the user ID in the provided variable
            printUserWelcomeMessage(id);
            break;
        }
        else
        {
            printSignUpRequiredMessage();
        }
    }
    return false;
}
void getUserInputs(string &username, string &password, string &id)
{
    displaySignInPromptMessage();

    cout << "Username: ";
    readHiddenInput(username);
    cout << "Password: ";
    readHiddenInput(password);
    cout << "ID: ";
    readHiddenInput(id);
    cout << "=========================================================\n";
}
void displaySignInPromptMessage()
{
    cout << "=========================================================\n";
    cout << "====== Please enter your Username & Password & ID =======\n";
    cout << "= Note: Press spacebar in hidden input to finish typing =\n";
    cout << "=========================================================\n";
}
bool checkOldUserExists(const string &username, const string &password, const string &id)
{
    for (const User &existingUser : LibraryData::usersList)
    {
        if ((existingUser.username == username) || (existingUser.password == password) || (existingUser.id == id))
        {
            return true;
        }
    }
    return false;
}
bool isValidUser(const string &username, const string &password, const string &id)
{
    for (const User &user : LibraryData::usersList)
    {
        if (username == user.username && password == user.password && id == user.id)
        {
            return true;
        }
    }
    return false;
}
void printUserWelcomeMessage(const string &id)
{
    for (const User &user : LibraryData::usersList)
    {
        if (id == user.id)
        {
            printSuccessMessage();
            if (user.gender == 'M')
            {
                cout << "<--> Welcome Mr - " << user.name << "\n";
            }
            else
            {
                cout << "<--> Welcome Miss - " << user.name << "\n";
            }
            break;
        }
    }
}
void printSignUpRequiredMessage()
{
    cout << "=========================================================\n";
    cout << "===== Sorry! .. You don't sign up yet in our system =====\n";
    cout << "=========================================================\n";
}
// // ---------------------------- End signInUser() Function ---------------------------- //
// // ---------------------------- Start GetUserChoice() Function ----------------------- //
int getUserMenuChoice()
{
    int userMenuChoice{};
    displayUserMenuChoice();
    cin >> userMenuChoice;
    cout << "=========================================================\n";
    while (true)
    {
        if (cin.fail())
        {
            handleInvalidInput(userMenuChoice);
        }
        else if (userMenuChoice >= 1 && userMenuChoice <= 5)
        {
            return userMenuChoice;
        }
        else
        {
            handleInvalidChoice(userMenuChoice);
        }
    }
}
void displayUserMenuChoice()
{
    cout << "=========================================================\n";
    cout << "Please choose an option below: " << endl;
    cout << "1- Display books list" << endl;
    cout << "2- Display the borrowed booklist" << endl;
    cout << "3- Borrow a book" << endl;
    cout << "4- Return a book" << endl;
    cout << "5- Exit" << endl;
    cout << "Your choice: ";
}
// // ---------------------------- End displayAdminMenu() Function ----------------------- //
// // ---------------------------- Start displayBooksForuser() Function ------------------ //
void displayBooksForUser()
{
    printBooksMessage();
    for (const Book &book : LibraryData::booksList)
    {
        displayBookInfoForUser(book);
    }
}
void displayBookInfoForUser(const Book &book)
{
    cout << "=========================================================\n";
    cout << "Book's Name: " << book.name << endl;
    cout << "Book's Author: " << book.author << endl;
    cout << "Book's Category: " << book.category << endl;
    cout << "Book's Status: " << (book.status ? "Available" : "Not Available") << endl;
    cout << "Book's ID: " << book.id << endl;
    cout << "Book's Count: " << book.count << endl;
    cout << "=========================================================\n";
}
// // ---------------------------- End displayBookInfo Function -------------------------- //
// // ---------------------------- Start borrowBook() Function --------------------------- //
void borrowBook(const string &loggedInUserId) // Pass the user's ID
{
    while (true)
    {
        if (stopFunction("Do you want to (continue||repeat) this process? (y/n): "))
        {
            break;
        }
        int bookId{};
        getAndCheckBookIdValidation(bookId);

        bool borrowed = isBorrowedBook(bookId);
        if (borrowed)
        {
            printBorrowSucceesMessage();

            for (User &user : LibraryData::usersList)
            {
                if (user.id == loggedInUserId) // Use the user's ID from the argument
                {
                    for (Book &book : LibraryData::booksList)
                    {
                        if (bookId == book.id)
                        {
                            // Add the borrowed book to the user's container
                            user.borrowedBooks.push_back(book);
                            displayBorrowedBookInfo(book);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        else
        {
            for (const Book &book : LibraryData::booksList)
            {
                if (bookId == book.id)
                {
                    if (!book.status || book.count == 0)
                    {
                        printNotAvailableBookMessage();
                        break;
                    }
                }
                else
                {
                    printNotFoundBookMessage();
                    break;
                }
            }
        }
    }
}
bool isBorrowedBook(int &bookId)
{
    for (auto it = LibraryData::booksList.begin(); it != LibraryData::booksList.end(); ++it)
    {
        if (bookId == it->id)
        {
            if (it->count > 0 && it->status)
            {
                it->count = it->count - 1;
                if (it->count == 0)
                {
                    it->status = false;
                }
                return true;
            }
        }
    }
    return false;
}
void displayBorrowedBookInfo(Book book)
{
    cout << "=========================================================\n";
    cout << "Book's Name: " << book.name << endl;
    cout << "Book's Author: " << book.author << endl;
    cout << "Book's Category: " << book.category << endl;
    cout << "Book's ID: " << book.id << endl;
    cout << "=========================================================\n";
}
void printNotAvailableBookMessage()
{
    cout << "=========================================================\n";
    cout << "======= Soory! ... This book is not available now =======\n";
    cout << "=========================================================\n";
}
void printNotFoundBookMessage()
{
    cout << "=========================================================\n";
    cout << "==== Sorry! ... This Book is not found in our system ====\n";
    cout << "=========================================================\n";
}
void printBorrowSucceesMessage()
{
    cout << "=========================================================\n";
    cout << "============== Book borrowed successfully! ==============\n";
    cout << "=========================================================\n";
    cout << "=================== The Borrowed book ===================\n";
}
// // ---------------------------- End borrowBook() Function ----------------------------- //
// // ---------------------------- Start returnBook() Function --------------------------- //
void returnBook(const string &loggedInUserId) // Pass the user's ID
{
    while (true)
    {
        if (stopFunction("Do you want to (continue||repeat) this process? (y/n): "))
        {
            break;
        }

        int bookId{};
        getAndCheckBookIdValidation(bookId);

        bool returned = isReturnedBook(bookId);

        if (returned)
        {
            printReturnSucceesMessage();

            for (User &user : LibraryData::usersList)
            {
                if (user.id == loggedInUserId)
                {
                    // Find and remove the returned book from the user's container
                    for (auto it = user.borrowedBooks.begin(); it != user.borrowedBooks.end(); ++it)
                    {
                        if (it->id == bookId)
                        {
                            user.borrowedBooks.erase(it);
                            break;
                        }
                    }
                }
            }
            for (const Book &book : LibraryData::booksList)
            {
                if (bookId == book.id)
                {
                    displayBorrowedBookInfo(book);
                    break;
                }
            }
        }
        else
        {
            for (const Book &book : LibraryData::booksList)
            {
                if (bookId != book.id)
                {
                    printNotFoundBookMessage();
                    break;
                }
            }
        }
    }
}
bool isReturnedBook(int &bookId)
{
    for (auto it = LibraryData::booksList.begin(); it != LibraryData::booksList.end(); ++it)
    {
        if (bookId == it->id)
        {
            if (!it->status)
            {
                it->status = true;
            }
            it->count += 1;
            return true;
        }
    }
    return false;
}
void printReturnSucceesMessage()
{
    cout << "=========================================================\n";
    cout << "============== Book returned successfully! ==============\n";
    cout << "=========================================================\n";
    cout << "=================== The Returned book ===================\n";
}
void printReturnFailMessage()
{
    cout << "=========================================================\n";
    cout << "==== Sorry! ... This Book is not found in our system ====\n";
    cout << "=========================================================\n";
}
// // ---------------------------- End returnBook() Function ----------------------------- //
// // ---------------------------- Start DisplayBorrowedBookList() Function -------------- //
void displayBorrowedBookList(const string &loggedInUserId) // Pass the user's ID
{
    bool userHasBorrowedBooks = false;

    for (const User &user : LibraryData::usersList)
    {
        if (user.id == loggedInUserId)
        {
            const vector<Book> &borrowedBooks = user.borrowedBooks;

            if (!borrowedBooks.empty())
            {
                printBooksListMessage();
                userHasBorrowedBooks = true;

                for (const Book &borrowedBook : borrowedBooks)
                {
                    cout << "=========================================================\n";
                    cout << "Book Name: " << borrowedBook.name << endl;
                    cout << "Book Author: " << borrowedBook.author << endl;
                    cout << "Book Category: " << borrowedBook.category << endl;
                    cout << "Book ID: " << borrowedBook.id << endl;
                    cout << "=========================================================\n";
                }
            }
        }
    }

    if (!userHasBorrowedBooks)
    {
        printNoBooksMessage();
    }
}
void printNoBooksMessage()
{
    cout << "=========================================================\n";
    cout << "============== There are not Books for now ==============\n";
}
void printBooksListMessage()
{
    cout << "=========================================================\n";
    cout << "================= The Books in your shelf ===============\n";
}
// // ---------------------------- End DisplayBorrowedBookList() Function ---------------- //
// // ---------------------------- End Functions For Admin ------------------------------- //