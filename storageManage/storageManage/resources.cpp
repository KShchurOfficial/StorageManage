#include "prototypes.h"

bool oneFromTwoCh(string checkingVal, string rightVal1, string rightVal2)
{
	while (checkingVal != rightVal1 && checkingVal != rightVal2)
	{
		cout << " Wrong answer. Try again: _____\b\b\b\b\b";
		getline(cin, checkingVal);
	}
	if (checkingVal == rightVal1)
		return 1;
	else
		return 0;
}

string adminAuthorization(string pass)
{
	string returningVal, reader;
	bool passIsFound = false;
	ifstream adminKeys;
	adminKeys.open("adminKeys.txt");
	getline(adminKeys, reader, ' ');
	while (!adminKeys.eof() && !passIsFound)
	{
		returningVal = reader;
		getline(adminKeys, reader, ' ');
		if (reader == pass)
		{
			passIsFound = true;
			cout << endl << " Entry was completed successfully." << endl << endl;
			continue;
		}
		getline(adminKeys, reader, ' ');
	}
	if (passIsFound)
	{
		adminKeys.close();
		return returningVal;
	}
	else
	{
		cout << " Wrong password. Try again: ______\b\b\b\b\b\b";
		getline(cin, pass);
		adminKeys.close();
		string retry = adminAuthorization(pass);
		return retry;
	}
}