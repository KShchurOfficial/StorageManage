#include "prototypes.h"

bool oneFromTwoCh(string checkingVal, string rightVal1, string rightVal2) // работа функции "oneFromTwoCh"
{
	while (checkingVal != rightVal1 && checkingVal != rightVal2) // пока входное значение не равно одному из двух возможных ответов
	{
		cout << " Wrong answer. Try again: _____\b\b\b\b\b"; // выводить предупреждение и запрашивать новое входное значение
		getline(cin, checkingVal);
	}
	if (checkingVal == rightVal1) // если входное значение равно первому варианту
		return 1; // вернуть 1 (true)
	else
		return 0; // иначе вернуть 0 (false)
}

string adminAuthorization(string pass) // работа функции "adminAuthorization"
{
	string returningVal, reader; // "returningVal" - возвращаемое значение; "reader" - строка для чтения информации из файла с паролями и никами админов
	bool passIsFound = false; // для остановки цикла чтения
	ifstream adminKeys; // сам объект с файлом
	adminKeys.open("adminKeys.txt");
	getline(adminKeys, reader, ' '); // чтение файла посложно (до пробела)
	while (!adminKeys.eof() && !passIsFound)
	{
		returningVal = reader; // первое прочтенное слово - возможный ник администратора
		getline(adminKeys, reader, ' '); // второе чтение - чтение пароля админа
		if (reader == pass) // если прочтенный пароль совпадает с введеным
		{
			passIsFound = true; // изменение условия для завершения цикла
			cout << endl << " Entry was completed successfully." << endl << endl;
			continue; // переход к проверке условия цикла
		}
		getline(adminKeys, reader, ' '); // если прочтенный пароль не совпадает с введеным, то читается следующее слово (уже на новой строке),
	}								     // которое является другим возможным ником админа
	if (passIsFound) // если цикл завершился из-за того, что пароль найден, то закрывается файл и возвращается значение возможного имени.
	{
		adminKeys.close();
		return returningVal;
	}
	else // если цикл завершился при достижении конца файла, но пароль не был найден
	{
		cout << " Wrong password. Try again: ______\b\b\b\b\b\b";
		getline(cin, pass); // снова запрашивается ввод пароля
		adminKeys.close(); // закрывается файл с паролями
		string retry = adminAuthorization(pass); // в новую строку "retry" записывается возвращаемое значение повторного вызова функции "adminAuthorization"
		return retry; // и потом возвращается значение "retry"
	}
}

void instructions(int mode, bool admRights) // работа функции "instructions"
{
	if (admRights) // если пользователь имеет права администратора
	{
		switch (mode) // в зависимости от режима выводится соответствующее сообщение
		{
		case 10:  // на случай ошибки ввода
			cout << " Unknown command. Try again: _____\b\b\b\b\b";
			break;
		case 0:  // начальная инструкция с выводом всех возможных команд и их кратким описанием.
			cout << "\n Here are the instructions you can write:\n \"help\" - to show instructions" << endl
				<< " \"showAll\" - to show all the information from warehouses\n \"searchI\" - to search by index" << endl
				<< " \"searchN\" - to search by name\n \"add\" - to add new string of data" << endl
				<< " \"delete\" - to delete string of data\n \"redact\" - to redact the string of data" << endl
				<< " \"move\" - to move the data between the warehouses\n \"shut\" - to shut down the program" << endl
				<< "\n Your enter: _____\b\b\b\b\b";
			break;
		case 1:  // в случае выполнения команды "showAll"
			cout << "\n Here's the all information from warehouses:\n";
			break;
		case 2:  // в случае выполнения команды "searchI"
			cout << "\n Enter the index of searching merchandice: _____\b\b\b\b\b";
			break;
		case 3:  // в случае выполнения команды "searchN"
			cout << "\n Enter the name of searching merchandice: _____\b\b\b\b\b";
			break;
		case 4:  // в случае выполнения команды "add"
			cout << "\n Before adding, enter the data about new  merchandice through the space" << endl
				<< " like in this example: name-price-quantity.\n Your enter: _____\b\b\b\b\b";
			break;
		case 5:  // в случае выполнения команды "delete"
			cout << "\n Before deleting, complete the search of merchandice you need by index or name\n"
				<< " Your enter: _____\b\b\b\b\b";
			break;
		case 6:  // в случае выполнения команды "redact"
			cout << "\n Before redacting, complete the search of merchandice you need by index or name\n"
				<< " Your enter: _____\b\b\b\b\b";
			break;
		case 7:  // в случае выполнения команды "move"
			cout << "\n Before moving, complete the search of merchandice you need by index or name\n"
				<< " Your enter: _____\b\b\b\b\b";
			break;
		case 8:  // в случае завершения работы
			cout << " \n The end of working." << endl;
			break;
		}
	}
	else // ксли пользователь не имеет права администратора
	{
		switch (mode)
		{
		case 10:
			cout << " Unknown command. Try again: _____\b\b\b\b\b";
			break;
		case 0:
			cout << "\n Here are the instructions you can write:\n \"help\" - to show instructions" << endl
				<< " \"showAll\" - to show all the information from warehouses\n \"searchI\" - to search by index" << endl
				<< " \"searchN\" - to search by name\n \"shut\" - to shut down the program" << endl
				<< "\n Your enter: _____\b\b\b\b\b";
			break;
		case 1:
			cout << "\n Here's the all information from warehouses:\n";
			break;
		case 2:
			cout << "\n Enter the index of searching merchandice: _____\b\b\b\b\b";
			break;
		case 3:
			cout << "\n Enter the name of searching merchandice: _____\b\b\b\b\b";
			break;
		case 4:
			cout << " You need to have the admin rights to complete this action.\n Your enter: _____\b\b\b\b\b";
			break;
		case 5:
			cout << " You need to have the admin rights to complete this action.\n Your enter: _____\b\b\b\b\b";
			break;
		case 6:
			cout << " You need to have the admin rights to complete this action.\n Your enter: _____\b\b\b\b\b";
			break;
		case 7:
			cout << " You need to have the admin rights to complete this action.\n Your enter: _____\b\b\b\b\b";
			break;
		case 8:
			cout << " \n The end of working." << endl;
			break;
		}
	}
}

int commRecognition(string someComm, library *pocket, int pocketSize) // работа функции "commRecognition"
{
	for (int i = 0; i < pocketSize; ++i) // проверка каждого слова из словарного запаса программы
	{
		if (pocket[i].theWord == someComm) // если введеное слово совпадает с словом из словарного запаса
		{
			return i; // вернуть режим, соответствующий данному слову
		}
	}
	return pocketSize+1; // если совпадений не найдено, вернуть режим для вывода сообщения об ошибке ввода
}