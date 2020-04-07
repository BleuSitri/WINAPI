#pragma once
#include"singletonBase.h"
class textData : public singletonBase<textData>
{
public:
	textData();
	~textData();

	HRESULT init();

	//세이브용
	void textSave(char* saveFileName, vector<string>vStr);
	char* vectorArrayCombine(vector<string> vArray);

	//로드

	vector<string>textLoad(char* loadFileName);
	vector<string>charArraySeperation(char charArray[]);


};

