#include "prototypes.h"

using namespace std;

const int dictSize = 8; // размер словарного запаса программы
const int parSize = 4;
library dictionary[dictSize]{ "help", "showAll", "searchI", // сам словарный запас программы
"searchN", "add", "delete", "redact", "shut" };
library parameterNames[parSize]{ "name", "price", "quantity", "index" };

int main()
{
    // Часть 1. Начало работы в программе. Авторизация для администраторов
    string dialog; // строка, использующаяся во всей программе, нужная, чтобы получать текстовый ввод пользователя
    cout << " Greetings in the storageManage application! " << endl
         << " Enter \"start\" to run the program: _____\b\b\b\b\b";
    getline(cin, dialog);
    while (dialog != "start") // проверка на правильность ввода
    {
        cout << " Wrong command. Try again: _____\b\b\b\b\b";
        getline(cin, dialog); // ввод строчно-ориентированный нужен здесь для того,
    } //  чтобы при вводе нескольких слов через пробел сообщение не выводилось несколько раз.
    cout << " Before start working, please, enter, who are you\n \"admin\" - administrator" << endl
        << " \"visit\" - visitor\n Your choice: _____\b\b\b\b\b";
    getline(cin, dialog);
    string username; // строка, хранящая имя админа. Если пользователь не админ, то значение строки всегда будет "guest".
    bool isAdmin = false; // права администратора
    if (oneFromTwoCh(dialog, "admin", "visit")) // "oneFromTwoCh" - функция для определения выбранного варианта из двух возможных
    {
        cout << " Enter your special admin-key: ______\b\b\b\b\b\b";
        getline(cin, dialog);
        username = adminAuthorization(dialog); // "adminAuthorization" - функция для выполнения авторизации администратора в программе
    } 
    else
        username = "guest";
    if (username != "guest")
        isAdmin = true;
    cout << " User " << username << " has started the work." << endl;
    int result = 0, parRes = 0; // переменная, значения которой являются режимами работы программы.
    instructions(result, isAdmin); // "instructions" - функция для вывода инструкций в зависимости от режима работы программы и наличия прав админа
    string workingStr, clone;
    getline(cin, dialog);
    while (result != 7) // режим 8 - завершение работы программы
    {
        result = commRecognition(dialog, dictionary, dictSize); // "commRecognition" - функция для распознания введеной пользователем команды
        switch (result)
        {
        case 10:
            instructions(result, isAdmin);
            getline(cin, dialog);
            break;
        case 0:
            instructions(result, isAdmin);
            getline(cin, dialog);
            break;
        case 1:
        {
            ifstream house;
            string queueOnOut = "AAAA", fWay = "warehouses/" + queueOnOut + ".txt";
            house.open(fWay);
            while (house.is_open())
            {
                while (!house.eof()) {
                    getline(house, dialog);
                    cout << dialog << endl;
                }
                house.close();
                queueOnOut = bruteForce(queueOnOut, 1);
                fWay = "warehouses/" + queueOnOut + ".txt";
                house.open(fWay);
            }
            cout << endl << " Your next command: ";
            getline(cin, dialog);
            break;
        }  
        case 2:
        {
            instructions(result, isAdmin);
            getline(cin, dialog);
            workingStr = " " + searchIn("searchI", dialog);
            clone = workingStr;
            for (int i = 0; i < clone.length(); i++)
            {
                if (clone[i] == '_')
                {
                    clone[i] = ' ';
                }
            }
            cout << endl << " Result: \n - " << clone << endl;
            cout << endl << " Your next command: ";
            getline(cin, dialog);
            break;
        }
        case 3:
        {
            instructions(result, isAdmin);
            getline(cin, dialog);
            workingStr = " " + searchIn("searchN", dialog) + " ";
            clone = workingStr;
            for (int i = 0; i < clone.length(); i++)
            {
                if (clone[i] == '_')
                {
                    clone[i] = ' ';
                }
            }
            cout << endl << " Result: \n - " << clone << endl;
            cout << endl << " Your next command: ";
            getline(cin, dialog);
            break;
        }
        case 4:
            if (isAdmin)
            {
                instructions(result, isAdmin);
                string strToAddIn, whAddress;
                int numbOfWH = 0;
                for (int i = 0; i < 3; i++)
                {
                    cout << endl << " Enter the " << parameterNames[i].theWord << " of merchandice: _____\b\b\b\b\b";
                    getline(cin, dialog);
                    if (!i)
                    {
                        for (int i = 0; i < dialog.length(); i++)
                        {
                            if (dialog[i] == ' ')
                                dialog[i] = '_';
                        }
                    }
                    strToAddIn += dialog + ' ';
                }
                cout << " Enter the number of warehouse: ";
                cin >> numbOfWH;
                numbOfWH -= 1;
                whAddress = "warehouses/";
                whAddress += bruteForce("AAAA", numbOfWH);
                whAddress += ".txt";
                addition(whAddress, strToAddIn);
                cout << endl << " Addition was completed successfully.\n Your next command: ";
                cin.get();
                getline(cin, dialog);
            }
            else
            {
                instructions(result, isAdmin);
                getline(cin, dialog);
            }
            break;
            // Функция для добавления новой информации.
            /* Принцип работы:
            * Программа запрашивает информацию о товаре через пробел
            * по образцу имя->стоимость->количество, затем программа
            * запрашивает номер склада, а потом переводит номер склада в имя файла
            * и добавляет новую строчку в конец файла и присваивает новому товару
            * его персональный индекс.
            * 
            * ifstream house("AAAB.txt");
            string kostil;
            cout << "Please enter name of staf:";//имя
                cin >> kostil;
                house << kostil;
                house << " ";
            cout << "Please enter price:";//стоимость
                cin >> kostil;
                house << kostil;
                house << " ";
                cout << "Please enter name of staf:";//каличество
                cin >> kostil;
                house << kostil;
                house << " ";

                house.close();
            */
            break;
        case 5:
            if (isAdmin)
            {
                if (workingStr.length() == 0)
                {
                    instructions(result, isAdmin);
                    getline(cin, dialog);
                }
                else
                {
                    string address = findingAdrs(workingStr);
                    string connectWord, strNum;
                    for (int i = 0; i < address.length(); i++)
                    {
                        if (address[i] == ' ')
                        {
                            for (int j = i + 1; j < address.length(); j++)
                            {
                                strNum += address[j];
                            }
                            break;
                        }
                        connectWord += address[i];
                    }
                    int strNumTrans = stoi(strNum);
                    deletingValue(connectWord, strNumTrans);
                    workingStr = "";
                    cout << endl << " Deleting was completed successfully " << endl
                         << endl << " Your next command: ";
                    getline(cin, dialog);
                }
            }
            else
            {
                instructions(result, isAdmin);
                getline(cin, dialog);
            }
            break;
        case 6:
            if (isAdmin)
            {
                if (workingStr.length() == 0)
                {
                    instructions(result, isAdmin);
                    getline(cin, dialog);
                }
                else
                {
                    string address = findingAdrs(workingStr);
                    string connectWord, strNum;
                    for (int i = 0; i < address.length(); i++)
                    {
                        if (address[i] == ' ')
                        {
                            for (int j = i+1; j < address.length(); j++)
                            {
                                strNum += address[j];
                            }
                            break;
                        }
                        connectWord += address[i];
                    }
                    int strNumTrans = stoi(strNum);
                    cout << "\n Enter the parameter you want to redact.\n --> ( note: data about merchandice"
                        << " writed in next order: name->price->quantity->index )\n Your choice: ";
                    getline(cin, dialog);
                    parRes = commRecognition(dialog, parameterNames, parSize);
                    cout << " Enter new value: ";
                    getline(cin, dialog);
                    if(parRes == 0)
                    {
                        for (int i = 0; i < dialog.length(); i++)
                        {
                            if (dialog[i] == ' ')
                                dialog[i] = '_';
                        }
                    }
                    workingStr = strRedacting(connectWord, workingStr, dialog, strNumTrans, parRes);
                    cout << endl << " Your next command: ";
                    getline(cin, dialog);
                }
            }
            else
            {
                instructions(result, isAdmin);
                getline(cin, dialog);
            }
            break;
        case 7:
            instructions(result, isAdmin);
        }  
    }
}