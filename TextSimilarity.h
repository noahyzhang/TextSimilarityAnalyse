#pragma once
#include<unordered_map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include <string>
#include<windows.h>
#include<cassert>
#include<set>
#include<unordered_set>
#include<vector>
#include "cppjieba/Jieba.hpp"



using namespace std;

const std::string DICT_PATH = "E://cppjieba-master/dict/jieba.dict.utf8";
const std::string HMM_PATH = "E://cppjieba-master/dict/hmm_model.utf8";
const std::string USER_DICT_PATH = "E://cppjieba-master/dict/user.dict.utf8";
const std::string IDF_PATH = "E://cppjieba-master/dict/idf.utf8";
const std::string STOP_WORD_PATH = "E://cppjieba-master/dict/stop_words.utf8";


//算法的缺点：不能处理同义词和多义词

class TextSimilarity
{
public:
	
	TextSimilarity();

	void getStopWordTable(const char* stopWordFile);
	unordered_map<string, int> getWordFreq(const char* file);  //统计出词频

	vector<pair<string, int>> sortByValueReverse(unordered_map<string, int>& wf); //排序

	void selectAimWords(vector<pair<string, int>>&wfvec, unordered_set<string>& wset);
	vector<double> getOneHot(unordered_set<string>& wset, unordered_map<string, int>& wf);

	double cosine(vector<double> oneHot1, vector<double> oneHot2);

	string gbk_utf8(string str);
	string utf8_gbk(string str);

	double GetCosine(const char* txt1, const char* txt2);
private:

	//定义一个jieba对象
	cppjieba::Jieba _jieba;
	unordered_set<string> stopWordSet;
	int _maxWordNumber;
};