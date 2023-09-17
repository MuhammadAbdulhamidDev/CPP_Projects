#include <iostream>
#include <string>
#include "projectFunctions.h"
#include "projectFunctions.cpp"

using namespace std;

namespace LibraryData
{
    vector<Book> booksList;
    vector<User> usersList;
    vector<Admin> adminsList;
}

int main()
{
    // ------------------------------------ Start Main Admins ------------------------------------- //
    Admin firstAdmin = {"Muhammad AbdulHamid", "muhammad_ad", "Qena1997", 'M', "1997"};
    LibraryData::adminsList.push_back(firstAdmin);
    Admin secondAdmin = {"Khloud Muhammad", "khloud_ad", "Qena2004", 'F', "2004"};
    LibraryData::adminsList.push_back(secondAdmin);
    // ------------------------------------ End Main Admins --------------------------------------- //
    // ------------------------------------ Start Users For Test ---------------------------------- //
    User firstUser = {"Muhammad AbdulHamid", "muhammad_us", "Qena1997", 'M', "1997"};
    LibraryData::usersList.push_back(firstUser);
    User secondUser = {"Khloud Muhammad", "khloud_us", "Qena2005", 'F', "2005"};
    LibraryData::usersList.push_back(secondUser);
    // ------------------------------------ End Users For Test ------------------------------------ //
    // ------------------------------------ Start Books List -------------------------------------- //
    Book firstBook = {"C++ Basics", "Mark Reed", "Fundamental programming", true, 1001, 1};
    LibraryData::booksList.push_back(firstBook);
    Book secondBook = {"OOP", "Steven F.Lott", "Fundamental programming", true, 1003, 3};
    LibraryData::booksList.push_back(secondBook);
    Book thirdBook = {"Data Structure", "Rudolph Russell", "Fundamental programming", true, 1005, 5};
    LibraryData::booksList.push_back(thirdBook);
    Book fourthBook = {"Algorithms", "Rudolph Russell", "Fundamental programming", true, 1007, 7};
    LibraryData::booksList.push_back(fourthBook);
    Book fifthBook = {"Java", "Brett Spell", "Fundamental programming", true, 1009, 5};
    LibraryData::booksList.push_back(fifthBook);
    Book sixthBook = {"Solid principles", "Bipin Joshi", "Fundamental programming", true, 1011, 3};
    LibraryData::booksList.push_back(sixthBook);
    Book seventhBook = {"Design pattern", "Erich Gamma", "Fundamental programming", true, 1013, 1};
    LibraryData::booksList.push_back(seventhBook);
    Book eighthBook = {"DataBase", "Michael Hernandez", "Fundamental programming", true, 1015, 3};
    LibraryData::booksList.push_back(eighthBook);
    Book ninthBook = {"Clean Code", "Robert C. Martin", "Fundamental programming", true, 1017, 5};
    LibraryData::booksList.push_back(ninthBook);
    // ------------------------------------ End Books List ---------------------------------------- //

    // ------ # Part 01 ---> Start Functions to display the main menu (Admin & User) ------ //
    int mustBreak = 0;
main_loop:
    while (mustBreak < 100)
    {
        mustBreak++;

        int mainChoice{};

        mainChoice = getMainChoice();

        // ------- # Part 01 ---> End Functions to display the main menu (Admin & User) ------- //
        // Break main_loop & the program.
        if (mainChoice == 3)
        {
            printExitMessage();
            break;
        }
        // ------- # Part 02 ---> Start the Admin section ------------------------------------- //
        else if (mainChoice == 1)
        {
            if (loginAdmin())
            {
                goto main_loop;
            }

            int adminChoice{};

        admin_choice:
            adminChoice = getAdminChoice();

            if (adminChoice == 9)
            {
                autoClearScreen();
                goto main_loop;
            }
            else if (adminChoice == 1)
            {
                displayAdminsList();
                goto admin_choice;
            }
            else if (adminChoice == 2)
            {
                addNewAdmin();
                goto admin_choice;
            }
            else if (adminChoice == 3)
            {
                deleteAdmin();
                goto admin_choice;
            }
            else if (adminChoice == 4)
            {
                displayUsersList();
                goto admin_choice;
            }
            else if (adminChoice == 5)
            {
                displayBooksForAdmin();
                goto admin_choice;
            }
            else if (adminChoice == 6)
            {
                addBook();
                goto admin_choice;
            }
            else if (adminChoice == 7)
            {
                deleteBook();
                goto admin_choice;
            }
            else if (adminChoice == 8)
            {
                updateBook();
                goto admin_choice;
            }
        }
        // ------- # Part 03 ---> Start the User section -------------------------------------- //
        else if (mainChoice == 2)
        {
            if (logInUser())
            {
                goto main_loop;
            }
        user_section:
            int userMainChoice{};
            userMainChoice = getUserMainChoice();

            if (userMainChoice == 3)
            {
                autoClearScreen();
                goto main_loop;
            }
            else if (userMainChoice == 1)
            {
                signUpNewUser();
                autoClearScreen();
                goto user_section;
            }
            else if (userMainChoice == 2)
            {
                string loggedInUserId;
                int userMenuChoice{};
                if (signInUser(loggedInUserId))
                {
                    autoClearScreen();
                    goto user_section;
                }
            user_menu_choice:
                userMenuChoice = getUserMenuChoice();
                if (userMenuChoice == 5)
                {
                    autoClearScreen();
                    goto main_loop;
                }
                else if (userMenuChoice == 1)
                {
                    displayBooksForUser();
                    goto user_menu_choice;
                }
                else if (userMenuChoice == 2)
                {
                    displayBorrowedBookList(loggedInUserId);
                    goto user_menu_choice;
                }
                else if (userMenuChoice == 3)
                {
                    borrowBook(loggedInUserId);
                    goto user_menu_choice;
                }
                else if (userMenuChoice == 4)
                {
                    returnBook(loggedInUserId);
                    goto user_menu_choice;
                }
            }
        }
        // ------- # Part 03 ---> End the User section ---------------------------------------- //
    }
    return 0;
}