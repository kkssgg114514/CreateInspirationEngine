#pragma once
#include <string> 

class CREATEINSPIRATION_API Logger
{
	//��־�����࣬���Ϊ��̬�࣬����ģʽ
private:
	static Logger* inst;
public:
	static Logger* Instance() { return inst; }

	//����ͽ⹹����
public:
	~Logger();
	Logger();


	//����־�ļ���ӡ��־��Ϣ
	static VOID PrintLog(const WCHAR* fmt, ...);

	static WSTRING LogDirectory();

	static WSTRING LogFile();

	//����ָ���
	static VOID PrintDebugSeperator();

	//���MTail�Ƿ�����
	static BOOL IsMTailRunning();

	//����MTail����
	static VOID StartMTail();
};