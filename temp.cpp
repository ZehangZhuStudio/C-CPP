/*
* (C) 2023 ZeHangZhu
* -*-coding:GBK-*-
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*���붨����*/
#include "Temp_main.cpp"
/*����ʵ�ֳ�Ա����*/
#include "Temp_CheckType.cpp"
#include "Temp_Save.cpp"
#include "Temp_GetChars.cpp"
#include "Temp_format.cpp"
#include "Temp_AddNewObject.cpp"

string Temp::Unformat(string data) {
	string temp;
	return temp;
}

char Temp::GetObject(string type_name) {

	char temp[40960];

	/*��ȡĿ��λ��*/
	int i = data.find(type_name)-2;
	/*������ʼλ��*/
	int start = i;
	/*�������Ƿ����*/
	if(i<0) {
		cout<<"����["<<type_name<<"]������!"<<endl;
		return '\0';
	}

	/*ָ��ģʽ,1Ϊ����,2Ϊ������,3Ϊֵ,4�����ж�����*/
	unsigned int flag=1;
	while(1) {

		if(data[i] == '\0')
			break;

		if(data[i] == ':')
			flag = 2;

		if(data[i] == '\"' && flag == 2)
			flag = 3;

		if(data[i] == '\"' && flag == 3)
			flag = 4;

		if(data[i] == ';' && flag == 4)
			break;

		i++;
	}

	/*�����ݶ�д�뻺��*/
	
}

//��������
int test() {
	Temp a;
	a.AddNewObject("char","test1","test\"^");
	a.AddNewObject("int","test2","143",true);
	a.Save("1.txt",'y');
	return 0;
}

int main(int argc,char *argv[]) {
	char* a[][64] = {"aaaa","bbbb","cccc"};;
	cin>>char[1];
	cout<<a<<endl;
	return test();	//test 
}
