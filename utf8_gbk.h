//#pragma once
//#include<string>
//#include<windows.h>
//using namespace std;
//
//
//string gbk_utf8(string str)
//{
//	//获取buffer大小
//	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
//	wchar_t* wstr = new wchar_t[len];
//	//GBK-->UTF16
//	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wstr, len);
//	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
//	char* utf8char = new char[len];
//	//utf16-->utf8
//	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8char, len, NULL, NULL);
//	string out(utf8char);
//
//	if (wstr != NULL)
//	{
//		delete[] wstr;
//		wstr = NULL;
//	}
//	if (utf8char != NULL)
//	{
//		delete[] utf8char;
//		utf8char = NULL;
//	}
//	return out;
//}
//
//string utf8_gbk(string str)
//{
//	//获取buffer大小
//	int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
//	wchar_t* wstr = new wchar_t[len];
//	//utf8-->utf16
//	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wstr, len);
//
//	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
//	char* gbkchar = new char[len];
//	//utf16--->gbk
//	WideCharToMultiByte(CP_ACP, 0, wstr, -1, gbkchar, len, NULL, NULL);
//
//	string out(gbkchar);
//
//	if (wstr != NULL)
//	{
//		delete[] wstr;
//		wstr = NULL;
//	}
//
//	if (gbkchar != NULL)
//	{
//		delete[] gbkchar;
//		gbkchar = NULL;
//	}
//
//	return out;
//}