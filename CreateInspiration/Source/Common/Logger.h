#pragma once
#include <string> 

class CREATEINSPIRATION_API Logger
{
	//日志工具类，设计为静态类，单例模式
private:
	static Logger* inst;
public:
	static Logger* Instance() { return inst; }

	//构造和解构函数
public:
	~Logger();
	Logger();


	//向日志文件打印日志信息
	static VOID PrintLog(const WCHAR* fmt, ...);

	static WSTRING LogDirectory();

	static WSTRING LogFile();

	//输出分隔符
	static VOID PrintDebugSeperator();

	//检查MTail是否运行
	static BOOL IsMTailRunning();

	//启动MTail程序
	static VOID StartMTail();
};