/*
* (C) 2023 ZeHangZhu
* -*-coding:GBK-*-
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*导入定义类*/
#include "Temp_main.cpp"
/*导入实现成员函数*/
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

	/*获取目标位置*/
	int i = data.find(type_name)-2;
	/*设置起始位置*/
	int start = i;
	/*检查变量是否存在*/
	if(i<0) {
		cout<<"变量["<<type_name<<"]不存在!"<<endl;
		return '\0';
	}

	/*指针模式,1为类型,2为变量名,3为值,4用于判定结束*/
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

	/*将数据段写入缓存*/
	
}

//正常测试
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
