#pragma once
#include"singletonBase.h"
class textData : public singletonBase<textData>
{
public:
	textData();
	~textData();

	HRESULT init();

	//���̺��
	void textSave(char* saveFileName, vector<string>vStr);
	char* vectorArrayCombine(vector<string> vArray);

	//�ε�

	vector<string>textLoad(char* loadFileName);
	vector<string>charArraySeperation(char charArray[]);


};

