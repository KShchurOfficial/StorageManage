#include "prototypes.h"

using namespace std;

int main()
{
    // Тест авторизации.
    string dialog;
    cout << " Greetings in the storageManage application! " << endl
         << " Enter \"start\" to run the program: _____\b\b\b\b\b";
    getline(cin, dialog);
    while (dialog != "start")
    {
        cout << " Wrong command. Try again: _____\b\b\b\b\b";
        cin >> dialog;
    }
    cout << " Before start working, please, enter, who are you\n \"admin\" - administrator" << endl
        << " \"visit\" - visitor\n Your choice: _____\b\b\b\b\b";
    getline(cin, dialog);
    string username;
    if (oneFromTwoCh(dialog, "admin", "visit"))
    {
        cout << " Enter your special admin-key: ______\b\b\b\b\b\b";
        getline(cin, dialog);
        username = adminAuthorization(dialog);
    } 
    else
        username = "guest";
    cout << " User " << username << " has started the work.";

}