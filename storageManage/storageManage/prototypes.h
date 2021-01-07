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
#endif