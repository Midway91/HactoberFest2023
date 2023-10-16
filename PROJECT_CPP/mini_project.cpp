/************************************************************************
 * Author        : Rohit Maroti Ramteke - 2041054
 * Date          : 2021-10-21
 * Aim           : Password Filling Program, Encryption, Decryption Status,Battery Status
 * OS Used       : Windows 10-64bit
 * Compiler      : MinGW-32 64bit C/C++ Compiler
 * IDE           : VS Code Editor
 * ***********************************************************************/

// As we can see there is no notepad is open in the bottom section of the window
#ifdef _WIN32
#include <windows.h> // sleep() cls() system()
#else
#include <unistd.h> // Sleep() clear()
#endif

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h> // cls()
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;      // nanoseconds, system_clock, seconds

#define BKSP 8    // BACKSPACE
#define TAB 9     // TAB
#define ENTER 10  // ENTER
#define RETURN 13 // Carriage Return

class Password
{
    protected:
        char str[256]; // for storing the password
        int i = 0; // password pointer
        char ch = ' '; 
        int size;
        int pos = 0; // rand() position
        short loop_iter = 100 ; // no of iteration for the loop
        string line;

        // all digits
        string digit = "0123456789";
        // all lower case, uppercase and special characters
        string low_case = "abcdefghijklmnopqrstuvwxyz_";
        string up_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string spl_char = "!#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
        string all_char = "0123456789abcdefghijklmnopqrstuvwxyz_ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
        // C++ flag's for characters
        bool l = false; // lower
        bool u = false; // upper
        bool d = false; // digit
        bool s = false; // special char
        short need = 0; // no of needed_charcacters to add in our password

        // Suggest password string
        string suggest_password;
};
class class_Password_functions : protected Password // Single level Inheritance
{
    public:
        string password();                                        // Encryption
        void password_instructions(void);                         // Password Instructions
        void erase_line(string line);                              // for erasing the line
        void battery_status();                                     // battery_status
        void loading_data();                                       // loadingStatus
        void hacker_text_animation();                             // hacker_text_animation effect
        void text_appearing_effect(string s);                     // password_text_effect
        void encrypt_data();                                       // encrypt data Status
        void decrypt_data();                                       // decrypt data Status
        void generate_password(string check_password, int n);     // GeneratePassword
        string suggester(int l, int u, int d, int s, string str); // password Suggestor
        string add_more_char(string str, int need);               // add extra characters in our password if it's small
};

void class_Password_functions::loading_data()
{
    system("cls");
    system("color a");
    int loop_iter = 10; // 10 Iteration Count
    while (loop_iter--)
    {
        cout << "\b\b\b\b\b\b\b\b\b\b\bLoading.   " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\bLOading..  " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\bLoAding... " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\bLoaDing...." << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\bLoadIng.   " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\bLoadiNg..  " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\bLoadinG... " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\bLoading.   " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\bLoading.." << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\bLoading..." << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\bLoading...." << flush;
        Sleep(100);
    }
}

void class_Password_functions::decrypt_data()
{
    system("color a");
    loop_iter = 10; // 10 Iteration Count
    cout << flush << endl ;
    while (loop_iter--)
    {
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bDecrypting.   " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bdEcrypting..  " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bdeCrypting... " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bdecRypting...." << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bdecrYpting.   " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bdecryPting..  " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bdecrypTing... " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bdecryptIng.   " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bdecryptiNg.." << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bdecryptinG..." << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bDecrypting...." << flush;
        Sleep(100);
    }
    cout << "Successfully decrypted." << endl;
}

void class_Password_functions::encrypt_data()
{
    system("color e");
    int loop_iter = 10; // 10 Iteration Count
    while (loop_iter--)
    {
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bEncrypting.   " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\beNcrypting..  " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\benCrypting... " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bencRypting...." << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bencrYpting.   " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bencryPting..  " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bencrypTing... " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bencryptIng.   " << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bencryptiNg.." << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bencryptinG..." << flush;
        Sleep(100);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bEncrypting...." << flush;
        Sleep(100);
    }
    cout << "Encryption start.\n\n"<< endl;
}

void class_Password_functions::hacker_text_animation()
{
    system("color 8f") ;
    loop_iter = 100 ; // 100 Iteration Count
    cout << flush << endl ;
    while (loop_iter--)
    {
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b" << low_case[rand() % 27] << up_case[rand() % 26] << " " << up_case[rand() % 26] << digit[rand() % 11] << " " << digit[rand() % 11] << spl_char[rand() % 11] << " " << low_case[rand() % 27] << spl_char[rand() % 32] << flush;
        sleep_for(microseconds(75000));
    }
    short i = 0;
    while (i < 13)
    {
        cout << "\b \b" ;
        i++ ;
    }
}

void class_Password_functions::text_appearing_effect(string s)
{
    cout << "Password: ";
    for (int j = s.length(); j > 0; j--)
        cout << "*";

    for (int j = s.length(); j > 0; j--)
        cout << "\b";

    for (int j = 0; j < s.length(); j++)
    {
        int size = all_char.length();
        sleep_for(microseconds(2500));
        for (int i = 0; i < 50 ; i++)
        {
            sleep_for(microseconds(2500));
            cout << all_char[rand()%size] << "\b" ;
        }
        cout << s[j] ;
    }
}

void class_Password_functions::battery_status()
{
    system("color e");

    SYSTEM_POWER_STATUS status; // note not LPSYSTEM_POWER_STATUS
    GetSystemPowerStatus(&status);
    int life = status.BatteryLifePercent;
    int BTime = status.BatteryLifeTime;
    cout << "\nBattery Status ";
    if (status.ACLineStatus == 1)
        cout << "Charging\n";

    else if (status.ACLineStatus == 5)
        cout << "Critical Battery with " << life << "% and " << BTime << " Battery Life!\n";

    else if (status.ACLineStatus == 10)
        cout << "Battery Low with " << life << "% and " << BTime << " Battery Life!\n";

    else
        cout << "Battery High with " << life << "% and " << BTime << " Battery Life!\n";

    system("pause");
}

void class_Password_functions::password_instructions(void)
{
    system("cls");
    system("color a"); // Green Text
    cout << endl << "::::::CPP Program to demonstrate password Encrypting.:::::: ";
    cout << endl << "---------------------------------------------------------------";
    cout << endl << ".:: Criteria for strong password is as follows : ";
    cout << endl << ".:: At least 8 characters-the more characters, the better.  ";
    cout << endl << ".:: A mixture of both uppercase and lowercase letters.";
    cout << endl << ".:: A mixture of letters and numbers.";
    cout << endl << ".:: Inclusion of at least one special character, e.g., ! @ # ? ]";
    cout << endl << ".:: Press any key to continue . . . ";
    _getch();
}
void class_Password_functions::erase_line(string line)
{
    size = line.size() - 1;
    cout << line;
    _getch(); // Press any key . . .
    while (size > -1)
    {
        sleep_for(microseconds(10000));
        cout << "\b \b";
        size--;
    }
}

string class_Password_functions::password()
{
    while (ch != ENTER || ch != TAB || ch == RETURN)
    {
        ch = getch();
        if (ch == BKSP && i > 0)
        {
            cout << "\b \b";
            i--;
        }
        else if (ch == BKSP)
        {
            cout << "";
        }
        else if (ch == RETURN || ch == ENTER || ch == TAB)
        {
            if (i < 8)
            {
                string line = "Password must be atleast longer than 8 characters. Press any key to continue . . .";
                erase_line(line);
            }
            else
                break;
        }
        else
        {
            cout << "*";
            str[i] = ch;
            i++;
        }
    }
    str[i] = '\0';
    return str;
}
// adding more characters to suggest strong password
string class_Password_functions::add_more_char(string str, int need)
{
    pos = 0;

    // all 26 letters
    low_case = "abcdefghijklmnopqrstuvwxyz_"; // Underscore is added
    up_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < need; i++)
    {
        pos = rand() % str.length();
        str.insert(pos, 1, low_case[rand() % 27]);
        str.insert(pos, 1, up_case[rand() % 26]);
    }
    return str;
}
// make powerful string
string class_Password_functions::suggester(int l, int u, int d, int s, string str)
{

    // all digits
    digit = "0123456789";

    // all lower case, uppercase and special characters
    low_case = "abcdefghijklmnopqrstuvwxyz_"; 
    up_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    spl_char = "!#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    // position at which place a character
    pos = 0;

    // if there is no lowercase char in password string, add it
    if (l == 0)
    {
        // generate random integer under password string length
        pos = rand() % str.length();

        // generate random integer under 27 for indexing of a to z plus '_' UnderScore
        str.insert(pos, 1, low_case[rand() % 27]);
    }

    // if there is no upper case char in password string, add it
    if (u == 0)
    {
        pos = rand() % str.length();
        str.insert(pos, 1, up_case[rand() % 26]);
    }

    // if there is no digit in password string, add it
    if (d == 0)
    {
        pos = rand() % str.length();
        str.insert(pos, 1, digit[rand() % 10]);
    }

    // if there is no special character in password string, add it
    if (s == 0)
    {
        pos = rand() % str.length();
        str.insert(pos, 1, spl_char[rand() % 32]);
    }

    return str;
}

/* make_password function :This function is used to check
strongness and if password string is not strong, it will suggest */
void class_Password_functions::generate_password(string check_password, int n)
{
    system("color a");
    // flag for lower case, upper case, special
    // characters and need of more characters
    l = false, u = false, d = false, s = false;
    need = 0;

    //string password suggestions.
    suggest_password;

    for (int i = 0; i < n; i++)
    {
        if (check_password[i] >= 97 && check_password[i] <= 122)
            l = true;
        else if (check_password[i] >= 65 && check_password[i] <= 90)
            u = true;
        else if (check_password[i] >= 48 && check_password[i] <= 57)
            d = true;
        else
            s = true;
    }

    // Check if password string is strong that
    // means all flag are active.
    if ((l + u + d + s) == 4)
    {
        cout << "Your Password is Strong" << endl;
        return;
    }
    else
    {
        line = "Your password is weak . . .Hit Enter.";
        erase_line(line);

        line = "Your password is weak.";
        cout << '\n' << line << endl;

        line = "Suggested password. . . .Hit Enter";
        erase_line(line);

        line = "Suggested password.";
        cout << line << endl;
    }

    /*suggest 15 strong strings */
    for (int i = 0; i < 15; i++)
    {
        // sleep_for(microseconds(100000));
        suggest_password = suggester(l, u, d, s, check_password);
        need = 8 - suggest_password.length();
        if (need > 0)
            suggest_password = add_more_char(suggest_password, need);
        cout << "::..  " << suggest_password << endl;
    }
}
int main()
{
    class_Password_functions password_class_object; // class_Password_functions Object
    password_class_object.loading_data();   // Loading name text-animation effect
    password_class_object.password_instructions();
    system("cls");    // clear Screen()
    string user_name; // user-name
    char ch;          // taking "yes" or "no" in 'y' or 'n' format

    fstream fout;
    fout.open("password.txt", ios::out | ios::app);
    
    password_class_object.encrypt_data(); // Encrypt named text_animation_effect
    
    // Taking user-name and password from the user and Encrypting the password
    cout << "User-name: ";
    cin >> user_name;
    cout << "Password:  ";
    string user_password = password_class_object.password(); // Password() call here, replacing '*' with characters 

    // Writing the user-name and password in password.txt
    fout << "\nUser-name: " << user_name;
    fout << "\nPassword: " << user_password;

    fout.close();

    cout << "\n\nWant to see password: (y/n) \n";
    cin >> ch;

    if (ch == 'Y' || ch == 'y')
    {
        password_class_object.battery_status(); // battery_status()
        password_class_object.decrypt_data(); // decryption animation_text_effect
        password_class_object.hacker_text_animation(); // hacker_text animation_effect
        password_class_object.text_appearing_effect(user_password); // cool_text_type_writter_effect

        system("color 8f");
        cout << "\nPassword: " << user_password << endl;
        password_class_object.generate_password(user_password, user_password.length()); // generate_password() calls here

        cout << "\nOPEN the Existing NOTE-PAD Window from bottom pannel";
        cout << "\nSee Your saved Password";

        // Opening the password.txt using system()
        string open_notepad;
        open_notepad = "notepad.exe password.txt";
        system(open_notepad.c_str());
    }
    return 0;
}
