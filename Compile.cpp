//© 2022-2023 ZehangZhu Studio. All rights reserved
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define __PROJECT_NAME__ "C++ with Chinese src,C-CPP(2C2P)"
#define __PROJECT_VERSION__ "V1.0.0"
#define __PROJECT_COPYRIGHT__ " (C) 2022-2023 ZehangZhu Studio. All rights reserved"
#define PRINT_COPYRIGHT cout<<__PROJECT_NAME__<<endl<<__PROJECT_VERSION__<<endl<<__PROJECT_COPYRIGHT__<<endl;

//Z-module类
class Zmodule{
	private:
		//模块文件
		string Module;
		//Init标记
		bool InitFlag = false;
		//获得模块信息
		char GetModuleInfoemation(void);
	public:
		//构造函数
		Zmodule(char* ModuleFile){Module = ModuleFile;}
		void open(char* ModuleFile){Module = ModuleFile;}
		//运行模块
		int run(void);
};

class File{
	public:
		string SRC_FILE_ROOT;
		
		string CPP_FILE_ROOT;
		
		fstream src_file;
		//检查文件是否存在
		bool CheckFile(string file);
		//解释代码
		int explain();
		//编译
		int compile(string argv);
};

bool File::CheckFile(string fileroot){
	fstream file;
	file.open(fileroot.c_str(),ios::in);
	
	if(!file.is_open()){
		cout<<"源代码文件无法代开或不存在!"<<endl;
		return false;
	}
	else
		return true;
}

//帮助文档
void help(){
	cout<<"####################HELPS####################"<<endl
		<<"使用方法  compile.exe [要编译的文件] -选项"<<endl
		<<"选项："<<endl
		<<"-p  \t\t-----在编译时显示细节"<<endl
		<<"-pl \t\t-----在编译时显示细节,并打印与中文代码对应的语句之间的对应关系"<<endl
		<<"-o  \t\t-----编译过程中输出解释好的C++和自动模块文件"<<endl
		<<"-n  \t\t-----解释前不检查中文代码是否有误，遇到问题直接报错退出"<<endl;
}

//异常退出报告
void EXIT_WITH_ERROR(int flag,string reason){
	cout<<"程序异常退出，异常代码-"<<flag<<endl
		<<"原因:"<<reason<<endl;
}

//main
int main(int argc,char* argv[]){
	char* src_file_temp;
	File file;
	//检查参数
	if(argc == 1){
		//异常退出
		help();
		EXIT_WITH_ERROR(1,"未指定要编译的文件");
		return 0;
	}
	
	//打印版权所有
	PRINT_COPYRIGHT
	
	//复制参数到数组
	src_file_temp = argv[1];
	if(file.CheckFile(src_file_temp) == false){
		//异常退出
		EXIT_WITH_ERROR(1,"指定的文件无法打开");
		return 1;
	}
	//打开要解释的文件
	file.src_file.open(src_file_temp,ios::in);
	return 0;
}



