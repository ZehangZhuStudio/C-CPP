//? 2022-2023 ZehangZhu Studio. All rights reserved
// -*-coding:GBK-*-

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Temp {
	private:
		/*缓存数据列表*/
		string data;
		/*数据名称列表*/
		char* names[][128];
		/*获得指定区域的字符串*/
		string GetChars(int start,int end,string data);
		/*格式化字符串*/
		string format(string data);
		/*反格式化字符串*/
		string Unformat(string data);
		/*检查类型*/
		bool CheckType(string value);
		/*获得值的名称集和值*/
		char GetData(void);
	public:
		/*
		* 在单元中增加新对象
		* 支持的类型有 'char','int','float','bool',类型
		*/
		int AddNewObject(string type_obj,string obj_name,string value,bool output);
		/*单独读取单元中的数据*/
		char GetObject(string type_name);
		/*储存到文件*/
		int Save(string file,char cover);

};

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
int Temp::AddNewObject(string type_obj,string obj_name,string value,bool output=false) {
	//检查值与类型是否相符
	if(type_obj == "int") {
		if(CheckType(value) == false) {
			if(output == true)
				cout<<"LINE["<<__LINE__<<"]:类型:"<<type_obj<<"的值不能为:"<<value<<endl;
			return -1;
		}
	}

	/*添加类型提示*/
	if(type_obj == "char") {
		data = data + "c:";
	}

	else if(type_obj == "bool") {
		data = data + "b:";
	}

	else if(type_obj == "int") {
		data = data+"i:";
	}

	else if(type_obj == "float") {
		data = data+"f:";
	} else {
		cout<<"LINE["<<__LINE__<<"]:类型不能为:"<<value <<endl;
		return -2;
	}
	//写入名称
	data += '[';
	data += obj_name;
	data += ']';
	/*写入开头的引号*/
	data += '\"';
	/*写入值*/
	data += format(value);
	/*写入结尾的引号*/
	data += "\"\n";
	//输出
	if(output == true)
		cout<<data<<endl;
	return 0;
}
bool Temp::CheckType(string value) {

	//检查数字
	istringstream sin(value);
	double test;
	return sin >> test && sin.eof();

}
string Temp::format(string datas) {
	string temp;

	const char* data;
	data = datas.c_str();

	int i = 0;
	char ch;

	//格式化
	while(i<datas.length()) {
		ch = data[i];
		if(ch == '\"') {
			temp += '^';
			temp += '0';
		} else if(ch == '^') {
			temp += '^';
			temp += '1';
		} else if(ch == '\n') {
			temp+="^n";
		} else if(ch == '\t') {
			temp+="^t";
		} else {
			temp += ch;
		}
		i++;
	}

	return temp;
}
string Temp::GetChars(int start,int end,string data) {
	//判断是否超出范围
	if(data.length() <end)
		return "-1";

	string temp;
	int i,j=0;

	for(i=start; i<=end; i++) {
		temp+= data[i];
		j++;
	}

	return temp;
}
int Temp::Save(string file,char cover = 'y') {
	fstream fileobj;
	if(cover == 'y')
		fileobj.open(file.c_str(),ios::out);
	if(cover == 'n')
		fileobj.open(file.c_str(),ios::app);
	if(fileobj.is_open())
		fileobj<<data;
	else
		cout<<"文件"<<file<<"写入失败 "<<endl;
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
	test();
	return test();	//test
}

