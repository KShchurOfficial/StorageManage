#ifndef prototypes
#define prototypes

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
struct library
{
	string theWord;
};
bool oneFromTwoCh(string, string, string);
string adminAuthorization(string);
void instructions(int, bool);
int commRecognition(string, library *, int);
string bruteForce(string, int);
string searchIn(string, string);
string findingAdrs(string);
string strRedacting(string, string, string, int, int);
void deletingValue(string, int);
void addition(string, string);
#endif