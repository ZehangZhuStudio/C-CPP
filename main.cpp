#include <iostream>
#include <string>
#include <fstream>
#include "ZZH/1.txt"
using namespace std;

#define __PROJECT_NAME__ "C++ with Chinese src,C-CPP(2C2P)"
#define __PROJECT_VERSION__ "V1.0.0"
#define __PROJECT_COPYRIGHT__ "Copyright (C) 2022-2023 ZZH Studio"

#define PRINT_COPYRIGHT cout<<__PROJECT_NAME__<<endl<<__PROJECT_VERSION__<<endl<<__PROJECT_COPYRIGHT__<<endl;

string SRC_FILE_ROOT;
string CPP_FILE_ROOT;
fstream src_file;

class Zlist{
	private:
		char List[99][128];
	public:
		string GetList(int place);
		
};
//帮助文档
void help();
//异常退出报告
void EXIT_WITH_ERROR(int flag,string reason);
//检查文件是否存在
bool CheckFile(string file);
//int complie(string argv);

int main(int argc,char* argv[]){
	//检查参数
	if(argc == 1){
		//异常退出
		help();
		EXIT_WITH_ERROR(1,"未指定要编译的文件");
		return 0;
	}
	cout<<argv[1]<<endl;
	//打印版权所有
	PRINT_COPYRIGHT
	
	if(CheckFile(argv[2]) == false){
		//异常退出
		EXIT_WITH_ERROR(1,"指定的文件无法打开");
		return 1;
	}
	return 0;
}
void EXIT_WITH_ERROR(int flag,string reason){
	cout<<"程序异常退出，异常代码-"<<flag<<endl
		<<"原因:"<<reason<<endl;;
}
void help(){
	cout<<"####################HELPS####################"<<endl
		<<"使用方法  2c2p.exe [要编译的文件] -选项"<<endl
		<<"选项："<<endl
		<<"-p  \t\t-----在编译时显示细节"<<endl
		<<"-pl \t\t-----在编译时显示细节,并打印与中文代码对应的语句之间的对应关系"<<endl
		<<"-o  \t\t-----编译过程中输出解释好的C++和自动模块文件"<<endl
		<<"-n  \t\t-----解释前不检查中文代码是否有误，遇到问题直接报错退出"<<endl;
}

bool CheckFile(string fileroot){
	fstream file;
	file.open(fileroot.c_str(),ios::in);
	
	if(!file.is_open()){
		cout<<"源代码文件无法代开或不存在!"<<endl;
		return false;
	}
	else
		return true;
}