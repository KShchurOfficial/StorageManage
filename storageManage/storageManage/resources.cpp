#include "prototypes.h"

bool oneFromTwoCh(string checkingVal, string rightVal1, string rightVal2) // ������ ������� "oneFromTwoCh"
{
	while (checkingVal != rightVal1 && checkingVal != rightVal2) // ���� ������� �������� �� ����� ������ �� ���� ��������� �������
	{
		cout << " Wrong answer. Try again: _____\b\b\b\b\b"; // �������� �������������� � ����������� ����� ������� ��������
		getline(cin, checkingVal);
	}
	if (checkingVal == rightVal1) // ���� ������� �������� ����� ������� ��������
		return 1; // ������� 1 (true)
	else
		return 0; // ����� ������� 0 (false)
}

string adminAuthorization(string pass) // ������ ������� "adminAuthorization"
{
	string returningVal, reader; // "returningVal" - ������������ ��������; "reader" - ������ ��� ������ ���������� �� ����� � �������� � ������ �������
	bool passIsFound = false; // ��� ��������� ����� ������
	ifstream adminKeys; // ��� ������ � ������
	adminKeys.open("adminKeys.txt");
	getline(adminKeys, reader, ' '); // ������ ����� �������� (�� �������)
	while (!adminKeys.eof() && !passIsFound)
	{
		returningVal = reader; // ������ ���������� ����� - ��������� ��� ��������������
		getline(adminKeys, reader, ' '); // ������ ������ - ������ ������ ������
		if (reader == pass) // ���� ���������� ������ ��������� � ��������
		{
			passIsFound = true; // ��������� ������� ��� ���������� �����
			cout << endl << " Entry was completed successfully." << endl << endl;
			continue; // ������� � �������� ������� �����
		}
		getline(adminKeys, reader, ' '); // ���� ���������� ������ �� ��������� � ��������, �� �������� ��������� ����� (��� �� ����� ������),
	}								     // ������� �������� ������ ��������� ����� ������
	if (passIsFound) // ���� ���� ���������� ��-�� ����, ��� ������ ������, �� ����������� ���� � ������������ �������� ���������� �����.
	{
		adminKeys.close();
		return returningVal;
	}
	else // ���� ���� ���������� ��� ���������� ����� �����, �� ������ �� ��� ������
	{
		cout << " Wrong password. Try again: ______\b\b\b\b\b\b";
		getline(cin, pass); // ����� ������������� ���� ������
		adminKeys.close(); // ����������� ���� � ��������
		string retry = adminAuthorization(pass); // � ����� ������ "retry" ������������ ������������ �������� ���������� ������ ������� "adminAuthorization"
		return retry; // � ����� ������������ �������� "retry"
	}
}

void instructions(int mode, bool admRights) // ������ ������� "instructions"
{
	if (admRights) // ���� ������������ ����� ����� ��������������
	{
		switch (mode) // � ����������� �� ������ ��������� ��������������� ���������
		{
		case 10:  // �� ������ ������ �����
			cout << " Unknown command. Try again: _____\b\b\b\b\b";
			break;
		case 0:  // ��������� ���������� � ������� ���� ��������� ������ � �� ������� ���������.
			cout << "\n Here are the instructions you can write:\n \"help\" - to show instructions" << endl
				<< " \"showAll\" - to show all the information from warehouses\n \"searchI\" - to search by index" << endl
				<< " \"searchN\" - to search by name\n \"add\" - to add new string of data" << endl
				<< " \"delete\" - to delete string of data\n \"redact\" - to redact the string of data" << endl
				<< " \"move\" - to move the data between the warehouses\n \"shut\" - to shut down the program" << endl
				<< "\n Your enter: _____\b\b\b\b\b";
			break;
		case 1:  // � ������ ���������� ������� "showAll"
			cout << "\n Here's the all information from warehouses:\n";
			break;
		case 2:  // � ������ ���������� ������� "searchI"
			cout << "\n Enter the index of searching merchandice: _____\b\b\b\b\b";
			break;
		case 3:  // � ������ ���������� ������� "searchN"
			cout << "\n Enter the name of searching merchandice: _____\b\b\b\b\b";
			break;
		case 4:  // � ������ ���������� ������� "add"
			cout << "\n Before adding, enter the data about new  merchandice through the space" << endl
				<< " like in this example: name-price-quantity.\n Your enter: _____\b\b\b\b\b";
			break;
		case 5:  // � ������ ���������� ������� "delete"
			cout << "\n Before deleting, complete the search of merchandice you need by index or name\n"
				<< " Your enter: _____\b\b\b\b\b";
			break;
		case 6:  // � ������ ���������� ������� "redact"
			cout << "\n Before redacting, complete the search of merchandice you need by index or name\n"
				<< " Your enter: _____\b\b\b\b\b";
			break;
		case 7:  // � ������ ���������� ������� "move"
			cout << "\n Before moving, complete the search of merchandice you need by index or name\n"
				<< " Your enter: _____\b\b\b\b\b";
			break;
		case 8:  // � ������ ���������� ������
			cout << " \n The end of working." << endl;
			break;
		}
	}
	else // ���� ������������ �� ����� ����� ��������������
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

int commRecognition(string someComm, library *pocket, int pocketSize) // ������ ������� "commRecognition"
{
	for (int i = 0; i < pocketSize; ++i) // �������� ������� ����� �� ���������� ������ ���������
	{
		if (pocket[i].theWord == someComm) // ���� �������� ����� ��������� � ������ �� ���������� ������
		{
			return i; // ������� �����, ��������������� ������� �����
		}
	}
	return pocketSize+1; // ���� ���������� �� �������, ������� ����� ��� ������ ��������� �� ������ �����
}