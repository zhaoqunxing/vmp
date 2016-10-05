#ifndef H_GLOBAL
#include <string>
using namespace std;

enum RET
{
	OK,
	ERR
};
typedef int INT;
typedef unsigned int UINT;

const int SizeofChar = 1;

string getFirstDecNums(const string & str);
string getNameFromPath(const string & docPath);

//#define DEBUG

#define H_GLOBAL
#endif