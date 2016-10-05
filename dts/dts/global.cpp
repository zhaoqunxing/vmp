#include <string>
#include <iostream>
#include "global.h"
#include "tools.h"
using namespace std;

string getFirstDecNums(const string & str)
{
	string tmpStr = getNameFromPath(str);
#ifdef DEBUG
					cout << "tmpStr " << tmpStr << endl;
#endif
	string nums;
	UINT index = 0;
	while(index < tmpStr.size())
	{
		if(OK == checkFormatOfDecNum(tmpStr[index]))
		{
			const UINT numsBegin = index;
			++index;
			while(index < tmpStr.size())
			{
				if(OK != checkFormatOfDecNum(tmpStr[index]))
				{
					const UINT numsEnd = index;
					nums = tmpStr.substr(numsBegin, numsEnd - numsBegin);
#ifdef DEBUG
					cout << "numsBegin " << numsBegin << endl;
					cout << "numsEnd " << numsEnd << endl;
					cout << "nums " << nums << endl;
#endif

					return nums;
				}
				++index;
			}

		}
		++index;
	}

	return string("");
}

//获取文件名不含路径
string getNameFromPath(const string & docPath)
{
	string::size_type index = docPath.rfind("\\");
	if(string::npos == index)
	{
		cout << "string::npos == index" << endl;
		return string("");
	}

	return docPath.substr(index + SizeofChar);
}