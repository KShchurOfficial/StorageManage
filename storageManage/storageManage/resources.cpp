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
		case 9:  // на случай ошибки ввода
			cout << " Unknown command. Try again: _____\b\b\b\b\b";
			break;
		case 0:  // начальная инструкция с выводом всех возможных команд и их кратким описанием.
			cout << "\n Here are the instructions you can write:\n \"help\" - to show instructions" << endl
				<< " \"showAll\" - to show all the information from warehouses\n \"searchI\" - to search by index" << endl
				<< " \"searchN\" - to search by name\n \"add\" - to add new string of data" << endl
				<< " \"delete\" - to delete string of data\n \"redact\" - to redact the string of data" << endl
				<< " \"shut\" - to shut down the program" << endl
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
				<< " like in this example: name *enter* price *enter* quantity.\n Your enter:";
			break;
		case 5:  // в случае выполнения команды "delete"
			cout << "\n Before deleting, complete the search of merchandice you need by index or name\n"
				<< " Your enter: _____\b\b\b\b\b";
			break;
		case 6:  // в случае выполнения команды "redact"
			cout << "\n Before redacting, complete the search of merchandice you need by index or name\n"
				<< " Your enter: _____\b\b\b\b\b";
			break;
		case 7:  // в случае завершения работы
			cout << " \n The end of working." << endl;
			break;
		}
	}
	else // ксли пользователь не имеет права администратора
	{
		switch (mode)
		{
		case 9:
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

string searchIn(string typeSearch, string searchingObj)
{
	ifstream searchArea;
	string reader, returningVal[4], startSO = searchingObj, finalAns;
	bool founded = false;
	string nameFile = "AAAA", endNF = "warehouses/" + nameFile + ".txt";
	searchArea.open(endNF);
	while (searchArea.is_open())
	{
		while (!searchArea.eof())
		{
			if (typeSearch == "searchN")
			{
				getline(searchArea, reader, ' ');
				int length1 = reader.length(), length2 = searchingObj.length(), concidence = 0;
				for (int i = 0; i < length1; i++)
				{
					if (reader[i] == '_')
					{
						reader[i] = ' ';
					}
				}
				for (int i = 0; i < length1; i++)
				{
					for (int j = 0; j < length2; j++)
					{
						if (searchingObj[j] == reader[i])
						{
							searchingObj[j] = '#';
							concidence += 1;
							break;
						}
					}
				}
				if (concidence == length2)
				{
					founded = true;
					returningVal[0] = reader;
					for (int i = 0; i < returningVal[0].length(); i++)
					{
						if (returningVal[0][i] == ' ')
							returningVal[0][i] = '_';
					}
					returningVal[0] += " ";
					for (int i = 1; i < 4; i++)
					{
						getline(searchArea, reader, ' ');
						returningVal[i] = reader;
						returningVal[i] += " ";
					}
					return returningVal[0] + returningVal[1] + returningVal[2] + returningVal[3];
				}
				else
				{
					searchingObj = startSO;
				}
			}
			if (typeSearch == "searchI")
			{
				for (int i = 0; i < 4; i++)
				{
					getline(searchArea, reader, ' ');
					returningVal[i] = reader;
					returningVal[i] += " ";
				}
				if (reader == searchingObj)
				{
					founded = true;
					for (int i = 0; i < returningVal[0].length(); i++)
					{
						if (returningVal[0][i] == ' ')
							returningVal[0][i] = '_';
					}
					return returningVal[0] + returningVal[1] + returningVal[2] + returningVal[3];
				}
			}
		}
		searchArea.close();
		nameFile = bruteForce(nameFile, 1);
		endNF = "warehouses/" + nameFile + ".txt";
		searchArea.open(endNF);
	}
	if (!founded)
	{
		return "\n nothing";
	}
}

string findingAdrs(string inputStr)
{
	 
	 ifstream assumedAdrs;
	 string nameTemplate = "AAAA", endFileName = "warehouses/" + nameTemplate + ".txt", reader, answer;
	 int strAccum = 0, length1, length2, concidence = 0;
	 bool stopSearching = false;
	 assumedAdrs.open(endFileName);
	 while (assumedAdrs.is_open())
	 {
		 while (!assumedAdrs.eof())
		 {
			 getline(assumedAdrs, reader);
			// cout << " reader: " << reader << endl << " inputStr: " << inputStr << endl;
			 length1 = inputStr.length(), length2 = reader.length();
			 if (length1 < length2)
			 {
				 for (int i = 0; i < length1; i++)
				 {
					 if (inputStr[i] == reader[i])
						 concidence += 1;
				 }
			 }
			 else
			 {
				 for (int i = 0; i < length2; i++)
				 {
					 if (inputStr[i] == reader[i])
						 concidence += 1;
				 }
			 }
			 if (length1 == concidence || length2 == concidence)
			 {
				 stopSearching = true;
				 break;
			 }
			 // cout << " length1: " << length1 << endl << " length2: " << length2 << endl << "concidence" << concidence << endl;
			 concidence = 0;
			 strAccum += 1;
		 }
		 if (stopSearching)
		 {
			 answer = endFileName + " " + to_string(strAccum);;
			 return answer;
		 }
		 strAccum = 0;
		 assumedAdrs.close();
		 nameTemplate = bruteForce(nameTemplate, 1);
		 endFileName = "warehouses/" + nameTemplate + ".txt";
		 assumedAdrs.open(endFileName);
	 }
	 return " nothing";
}

string strRedacting(string address, string changingStr, string newWord, int strNum, int parNum)
{
	ifstream changingFile;
	string reserveCopy, reader;
	int length, lengthNew, lengthOld, counter = 0, cdinStart = 0;
	changingFile.open(address);
	int strCountdown = strNum, parCountdown = parNum + 1;
	while (!changingFile.eof())
	{
		getline(changingFile, reader);
		if (strCountdown != 0)
			strCountdown--;
		else
		{
			reserveCopy += reader;
		}
	}
	length = reserveCopy.length();
	reader = "";
	for (int i = 0; i < length; i++)
	{
		if (parCountdown == 0)
		{
			if (reserveCopy[i] == ' ')
			{
				break;
			}
			reader += reserveCopy[i];
		}
		else
		{
			if (reserveCopy[i] == ' ')
			{
				parCountdown -= 1;
				cdinStart = i + 1;
			}
		}
	}
	lengthNew = newWord.length();
	lengthOld = reader.length();
	parCountdown = parNum + 1;
	string buffer;
	for (int i = 0; i < lengthNew; i++)
	{
		reserveCopy += ' ';
	}
	length = reserveCopy.length();
	for (int i = 0; i < length; i++)
	{	
		if (parCountdown == 0)
		{
			if (reserveCopy[i] == ' ' || buffer.length() != 0)
				buffer += reserveCopy[i];
			if (counter < lengthNew)
			{
				reserveCopy[i] = newWord[counter];
				counter++;
			}				
		}
		else
		{
			if (reserveCopy[i] == ' ')
				parCountdown -= 1;
		}
	}
	counter = 0;
	reserveCopy[cdinStart + lengthNew] = ' ';
	for (int i = cdinStart + lengthNew; i < length; i++)
	{
		reserveCopy[i] = buffer[counter];
		counter++;
	}
	string allFileContent;
	counter = strNum;
	changingFile.close();
	changingFile.open(address);
	while (!changingFile.eof() && counter)
	{
		getline(changingFile, reader);
		allFileContent += reader;
		counter--;
	}
	changingFile.close();
	allFileContent += reserveCopy;
	ofstream changedFile;
	changedFile.open(address);
	for (int i = 0; i < allFileContent.length(); i++)
	{
		if (allFileContent[i] == ' ' && allFileContent[i + 1] == ' ')
		{
			changedFile << allFileContent[i] << '\n';
			i += 1;
		}
			changedFile << allFileContent[i];
	}
	changedFile.close();
	changingFile.open(address);
	strCountdown = strNum;
	while (!changingFile.eof())
	{
		getline(changingFile, reader);
		if (strCountdown != 0)
			strCountdown--;
		else
		{
			return reader;
		}
	}
}

void deletingValue(string address, int strNum)
{
	ifstream delBefore;
	delBefore.open(address);
	string content, reader;
	int counter = 0;
	while (!delBefore.eof())
	{
		getline(delBefore, reader);
		if (counter != strNum)
		{
			content += reader;
			content += '\n';
		}
		counter++;
	}
	delBefore.close();
	ofstream delAfter;
	delAfter.open(address);
	delAfter << content;
	delAfter.close();
}

void addition(string address, string addObj)
{
	string reader, finalAns, lastIndex;
	ifstream targetFile;
	int length, counter = 0;
	targetFile.open(address);
	while (!targetFile.eof())
	{
		getline(targetFile, reader);
	}
	for (int i = 0; i < reader.length(); i++)
	{
		if (reader[i] == ' ')
			counter++;
		if (counter == 4 && reader[i] != ' ')
			lastIndex += reader[i];
		if (counter == 5)
			counter = 0;
	}
	length = lastIndex.length();
	lastIndex[length - 1] += 1;
	if (lastIndex[length - 1] == '9')
	{
		lastIndex[length - 2] += 1;
		lastIndex[length - 1] = '0';
		if (lastIndex[length - 2] == '9')
		{
			lastIndex[length - 3] += 1;
			lastIndex[length - 2] = '0';
			if (lastIndex[length - 3] == '9')
			{
				lastIndex[length - 4] += 1;
				lastIndex[length - 3] = '0';
				if (lastIndex[length - 4] == '9')
				{
					lastIndex[length - 5] += 1;
					lastIndex[length - 4] = '0';
					if (lastIndex[length - 5] == '9')
					{
						lastIndex[length - 6] += 1;
						lastIndex[length - 5] = '0';
					}
				}
			}
		}
	}
	finalAns = ' ';
	finalAns += "\n " + addObj + lastIndex + ' ';
	targetFile.close();
	fstream tFWriting;
	tFWriting.open(address, ios_base::app);
	tFWriting << finalAns;
	tFWriting.close();
}

string bruteForce(string name, int number)
{
	int length = name.length();
	for (int i = 0; i < number; i++)
	{
		name[length - 1] += 1;
		if (name[length - 1] == '[')
		{
			name[length - 1] = 'A';
			name[length - 2] += 1;
			if (name[length - 2] == '[')
			{
				name[length - 2] = 'A';
				name[length - 3] += 1;
				if (name[length - 3] == '[')
				{
					name[length - 3] = 'A';
					name[length - 4] += 1;
					if (name[length - 4] == '[')
					{
						return "limit";
					}
				}
			}
		}
	}
	return name;
}