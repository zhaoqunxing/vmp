#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "global.h"
#include "tools.h"
#include "cfg.h"
using namespace std;
//将输入文件夹中文件中数字串，用文件夹名称重新命名

INT getFolderName(string & folderPath, string & folderName);
INT getNumsDocName(const string & path, string & nums, vector<string> & docName);
INT	renameDoc(const string & folderPath, const string & num, const vector<string> & docName);

int main()
{
	while(true)
	{
		string folderName;
		string folderPath;
		if (OK != getFolderName(folderPath,folderName))
		{
			cout << "OK != getFolderName(folderName)" << endl;
			return ERR;
		}

#ifdef DEBUG
		cout << "getFolderName end" << endl;
#endif
		string num;
		vector<string> docName;
		getNumsDocName(folderPath, num, docName);
		renameDoc(folderPath, folderName, docName);
	}
	return OK;
}

INT getFolderName(string & folderPath, string & folderName)
{
	cout << "请输入文件夹路径：" << endl;
	cin >> folderPath;
#ifdef DEBUG
	cout << folderPath << endl;
#endif

	folderName = folderPath;
	//获取文件名，不含路径
	string::size_type index = folderName.rfind("\\");
	if(string::npos == index)
	{
		cout << "string::npos == index" << endl;
		return ERR;
	}
	folderName = folderName.substr(index + SizeofChar);
#ifdef DEBUG
	cout << folderName << "    " << folderName.size() << endl;
#endif

	return OK;
}

INT getNumsDocName(const string & path, string & nums, vector<string> &docName)
{
	getFiles(path, docName);
	if(docName.empty())
	{
		//empty yu size ==0 ?
		cout << "docName.empty()" << endl;
		return ERR;
	}
	UINT index = 0;
	while(nums.empty() && index < docName.size())
	{
		nums = getFirstDecNums(docName[index]);
		++index;
	}
#ifdef DEBUG
	cout << nums << "    docName.size():" << docName.size() << endl;
#endif
	return OK;
}

INT	renameDoc(const string & folderPath, const string & num, const vector<string> & docName)
{
	UINT index = 0;
	UINT docFlag = OK;
	UINT xlsFlag = OK;
	string newName;
	while(index < docName.size())
	{
		string::size_type docIndex = docName[index].rfind(".doc");
		if(std::string::npos != docIndex)
		{
			if(docIndex + string(".docx").size() == docName[index].size())
			{
				newName = folderPath + string("\\") + num + docFileName + string(".docx");
			}
			else if(docIndex + string(".doc").size() == docName[index].size())
			{
				newName = folderPath + string("\\") + num + docFileName + string(".doc");
			}
		}
		string::size_type xlsIndex = docName[index].rfind(".xls");
		if(std::string::npos != xlsIndex)
		{
			if(xlsIndex + string(".xls").size() == docName[index].size())
			{
				newName = folderPath + string("\\") + num + xlsFileName + string(".xls");
			}
			else if(xlsIndex + string(".xlsx").size() == docName[index].size())
			{
				newName = folderPath + string("\\") + num + xlsFileName + string(".xlsx");
			}
		}
#ifdef DEBUG
		cout << newName << endl;
#endif
		if (rename(docName[index].c_str(), newName.c_str()) == 0)
			printf("Renamed %s to %s.\n", docName[index].c_str(), newName.c_str());
		else
			perror("rename");
		++index; 
	}
	return OK;
}
