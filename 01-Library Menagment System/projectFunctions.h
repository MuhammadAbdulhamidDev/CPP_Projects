#ifndef PROJECT_FUNCTIONS_H
#define PROJECT_FUNCTIONS_H
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include <algorithm>
#include <conio.h>
using namespace std;

struct Book
{
    string name;
    string author;
    string category;
    bool status;
    int id;
    int count;
};

struct Admin
{
    string name;
    string username;
    string password;
    char gender;
    string id;
};

struct User
{
    string name;
    string username;
    string password;
    char gender;
    string id;
    vector<Book> borrowedBooks; // Container for borrowed books
};


namespace LibraryData
{
    extern vector<Book> booksList;
    extern vector<Admin> adminsList;
    extern vector<User> usersList;
}

// -------------------------> Intro Function & General Functions <--------------------- //
void printIntroMessage();
void readHiddenInput(string &field);
void clearInput();
void clearChoice();
void handleInvalidInput(int &choice);
void handleInvalidChoice(int &choice);
void printInvalidInputsMessage();
void printInvalidChoiceMessage();
void clear();
bool stopFunction(string message);
void manualClearScreen(string message);
void autoClearScreen();
// ------------------------------------------------------------------------------------ //
// ------- # Part 01 --> Start Functions to display the main menu (Admin & User) ------ //
int getMainChoice();
void displayMainMenu();
void printExitMessage();
// ------- # Part 01 --> End Functions to display the main menu (Admin & User) -------- //
// ------- # Part 02 --> Start Functions For Admin Section ---------------------------- //
// ---------------------------- Start loginAdmin() Function --------------------------- //
bool loginAdmin();
void getAdminData(string &username, string &password, string &id);
void displayLoginAdminPromptMessage();
bool isValidAdmin(const string &username, const string &password, const string &id);
bool checkOldAdminExists(const string &username, const string &password, const string &id);
void printWelcomeAdminMessage(const string &id);
void printSuccessMessage();
void printFailMessage();
// ---------------------------- End loginAdmin() Function ----------------------------- //
// ---------------------------- Start displayAdminMenu() Function --------------------- //
int getAdminChoice();
void displayAdminMenu();
// ---------------------------- End displayAdminMenu() Function ----------------------- //
// ---------------------------- Start displayAdminInfo() Function --------------------- //
void displayAdminsList();
void printSubAdminsMessage();
void printNoSubAdminsMessage();
void printAdminsInfo(const Admin &admin);
void printAdminsListMessage();
// ---------------------------- End displayAdminInfo() Function ----------------------- //
// ---------------------------- start addAdmin() Function ----------------------------- //
void addNewAdmin();
Admin getNewAdminData();
void displayNewAdminDataEntryPrompt();
void getAndCheckNewAdminNameValidation(string &name);
void getAndCheckNewAdminUsernameValidation(string &username, string &name);
void getAndcheckNewAdminIdValidtion(string &newAdminId);
void getAndCheckNewAdminPasswordValidation(string &password, string &id);
void getAndCheckNewAdminGenderValidation(char &gender);
bool checkNewAdminExists(string &adminId);
void printAddNewAdminSucceesMessage();
void printAddNewAdminFailMessage();
// ---------------------------- end() addAdmin Function -------------------------------- //
// ---------------------------- Start deleteAdmin() Function --------------------------- //
void deleteAdmin();
void readAdminId(string &adminId);
bool checkAdminIdValidation(string &adminId);
bool isDeletedAdmin(string &adminId);
void printDeletedAdminFailMessage();
void printDeletedAdminSucceesMessage();
// ---------------------------- End deleteAmin() Function ----------------------------- //
// ---------------------------- Start DisplayUsersList() Function --------------------- //
void displayUsersList();
void printUsersListMessage();
void printNoUsersMessage();
void printUsersInfo(const User &user);
// ---------------------------- End DisplayUsersList() Function ----------------------- //
// ---------------------------- Start displayBooksForAdmin() Function ----------------- //
void displayBooksForAdmin();
void printBooksMessage();
void printBookInfo(const Book &book);
// ---------------------------- End displayBookInfo() Function ------------------------ //
// ---------------------------- Start addBook() Function ------------------------------ //
void addBook();
bool isValidBook(const Book &newBook, const vector<Book> &booksList);
void displayBookInfoPromptMessage();
Book getNewBookInfo();
void getAndCheckBookIdValidation(int &newBookId);
void getAndCheckBookStatusValidation(bool &newBookStatus);
void getAndCheckBookCountValidation(int &newBookCount);
void printExistBookMessage();
void printAddBookSucceesMessage();
// ---------------------------- End addBook() Function ------------------------------- //
// ---------------------------- Start deleteBook() Function -------------------------- //
void deleteBook();
bool isDeletedBook(int &bookId);
void printDeletionFailMessage();
void printDeletionSuccessMessage();
// ---------------------------- End deleteBook() Function ----------------------------- //
// ---------------------------- Start UpdateBook() Function --------------------------- //
void updateBook();
int getUpdateMenuChoice();
void displayUpdateMenu();
bool isUpdateStatus(int &bookId);
void printUpdateStatusMessage(bool &success);
int getNewCount();
bool checkNewCountValidation(int &value);
bool isUpdateCount(int &bookId, int &newCount);
void printUpdateCountMessage(bool &success);
// ---------------------------- End UpdateBook() Function ----------------------------- //
// ------- # Part 02 --> End Functions For Admin Section ------------------------------ //
// ------- # Part 03 -->Start Functions For User -------------------------------------- //
// ---------------------------- Start GetUserChoice() Function ------------------------ //
bool logInUser();
int getUserMainChoice();
void displayUserMainMenu();
// ---------------------------- End GetUserChoice() Function -------------------------- //
// ---------------------------- Start Function signUpNewUser() ------------------------ //
void signUpNewUser();
void getNewUserData(User &newUser);
void displayNewUserDataEntryPrompt();
void getAndCheckNewUserNameValidation(string &name);
void getAndCheckNewUserUsernameValidation(string &username, string &name);
void getAndcheckNewUserIdValidtion(string &newUserId);
void getAndCheckNewUserPasswordValidation(string &password, string &id);
void getAndCheckNewUserGenderValidation(char &gender);
bool isValidNewUser(const string &id);
void printAddNewUserSucceesMessage();
void printExistUserMessage();
// ---------------------------- End Function signUpNewUser() -------------------------- //
// ---------------------------- Start logInUser() Function ---------------------------- //
bool signInUser(string &loggedInUserId);
void getUserInputs(string &username, string &password, string &id);
void displaySignInPromptMessage();
bool checkOldUserExists(const string &username, const string &password, const string &id);
bool isValidUser(const string &username, const string &password, const string &id);
void printUserWelcomeMessage(const string &id);
void printSignUpRequiredMessage();
// ---------------------------- End logInUser() Function ------------------------------ //
// ---------------------------- Start getUserMenuChoice() Function -------------------- //
int getUserMenuChoice();
void displayUserMenuChoice();
// ---------------------------- End getUserMenuChoice() Function ---------------------- //
// ---------------------------- Start displayBooksForuser() Function ------------------ //
void displayBooksForUser();
void displayBookInfoForUser(const Book &book);
// ---------------------------- End displayBooksForuser() Function -------------------- //
// ---------------------------- Start borrowBook() Function --------------------------- //
void borrowBook(const string &loggedInUserId);
bool isBorrowedBook(int &bookId);
void printBorrowSucceesMessage();
void displayBorrowedBookInfo(Book book);
void printNotAvailableBookMessage();
void printNotFoundBookMessage();
// ---------------------------- End borrowBook() Function ----------------------------- //
// ---------------------------- Start returnBook() Function --------------------------- //
void returnBook(const string &loggedInUserId);
bool isReturnedBook(int &bookId);
void printReturnSucceesMessage();
void printReturnFailMessage();
// ---------------------------- End returnBook() Function ----------------------------- //
// // ------------------------- Start DisplayBorrowedBookList() Function -------------- //
void displayBorrowedBookList(const string &loggedInUserId);
void printNoBooksMessage();
void printBooksListMessage();
// // ------------------------- End DisplayBorrowedBookList() Function --------------- //
#endif