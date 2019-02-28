#include"TF_IDF.h"

void TestWordFreq()
{
	TF_IDF tsy;  //构建对象
	unordered_map<string, double> wfg1;  //文档1的词频
	unordered_map<string, double> wfg2;  //文档2的词频
	const char* test1 = "E://test1.txt";
	const char* test2 = "E://test2.txt";

	wfg1 = tsy.getWordFreq(test1);
	wfg2 = tsy.getWordFreq(test2);

	//auto自动识别为迭代器类型unordered_map<string,int>::iterator
	auto iter1 = wfg1.begin();
	cout << "文档1的词频--------------------------------------" << endl;
	while (iter1 != wfg1.end())  //打印文档1的词频
	{
		cout << tsy.utf8_gbk(iter1->first) << ":" << iter1->second << endl;;
		++iter1;
	}
	cout << wfg1.size() << endl;

	auto iter2 = wfg2.begin();
	cout << "文档2的词频--------------------------------------" << endl;
	while (iter2 != wfg2.end())  //打印文档2的词频
	{
		cout << tsy.utf8_gbk(iter2->first) << ":" << iter2->second << endl;
		++iter2;
	}
	cout << wfg2.size() << endl;
}


void TestSort()  //将两个文档的词频进行降序排序
{
	TF_IDF tsy;  //构建对象
	unordered_map<string, double> wfg1;  //文档1的词频
	unordered_map<string, double> wfg2;  //文档2的词频
	const char* test1 = "E://test1.txt";
	const char* test2 = "E://test2.txt";

	wfg1 = tsy.getWordFreq(test1);
	wfg2 = tsy.getWordFreq(test2);

	vector<pair<string, double>> v1 = tsy.sortByValueReverse(wfg1);  //将文档1得到的词频进行排序
	vector<pair<string, double>> v2 = tsy.sortByValueReverse(wfg2);  //将文档2得到的词频进行排序

	auto iter1 = v1.begin();
	cout << "文档1的词频降序排序--------------------------------------" << endl;
	while (iter1 != v1.end())  //打印拿到的文档1的词频按降序排列
	{
		cout << tsy.utf8_gbk(iter1->first) << ":" << iter1->second << endl;
		++iter1;
	}

	auto iter2 = v2.begin();
	cout << "文档2的词频降序排序--------------------------------------" << endl;
	while (iter2 != v2.end())  //打印拿到的文档2的词频按降序排列
	{
		cout << tsy.utf8_gbk(iter2->first) << ":" << iter2->second << endl;
		++iter2;
	}
}

void TestOneHot()  //得到词频向量
{
	TF_IDF tsy;  //构建对象
	unordered_map<string, double> wfg1;  //文档1的词频
	unordered_map<string, double> wfg2;  //文档2的词频
	const char* test1 = "E://test1.txt";
	const char* test2 = "E://test2.txt";

	wfg1 = tsy.getWordFreq(test1);
	wfg2 = tsy.getWordFreq(test2);

	vector<pair<string, double>> v1 = tsy.sortByValueReverse(wfg1);  //将文档1得到的词频进行排序
	vector<pair<string, double>> v2 = tsy.sortByValueReverse(wfg2);  //将文档2得到的词频进行排序

	unordered_set<string> wset1;  //用来存文档1中排序好的元素
	unordered_set<string> wset2;  //用来存文档2中排序号的元素
	tsy.selectAimWords(v1, wset1);
	tsy.selectAimWords(v2, wset2); //这两个函数用来将vector中的元素存到set中，构建词频向量


	vector<double> vd1;
	vector<double> vd2;
	vd1 = tsy.getOneHot(wset1, wfg1);  //拿到文档1的构建好的词频向量
	vd2 = tsy.getOneHot(wset2, wfg2); //拿到文档2的构建好的词频向量 

	for (int i = 0; i < vd1.size(); i++)  //打印文档1的词频向量
	{
		cout << "文档1 的词频向量" << i + 1 << ":" << vd1[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < vd2.size(); i++)  //打印文档2的词频向量
	{
		cout << "文档2 的词频向量" << i + 1 << ":" << vd2[i] << "\t";
	}
	cout << endl;
}

void TestConine()  //测试两个文档的文本相似度
{
	TF_IDF tsy;  //构建对象
	unordered_map<string, double> wfg1;  //文档1的词频
	unordered_map<string, double> wfg2;  //文档2的词频
	const char* test1 = "E://test1.txt";
	const char* test2 = "E://test2.txt";

	wfg1 = tsy.getWordFreq(test1);
	wfg2 = tsy.getWordFreq(test2);

	vector<pair<string, double>> v1 = tsy.sortByValueReverse(wfg1);  //将文档1得到的词频进行排序
	vector<pair<string, double>> v2 = tsy.sortByValueReverse(wfg2);  //将文档2得到的词频进行排序

	unordered_set<string> wset1;  //用来存文档1中排序好的元素
	unordered_set<string> wset2;  //用来存文档2中排序号的元素
	tsy.selectAimWords(v1, wset1);
	tsy.selectAimWords(v2, wset2); //这两个函数用来将vector中的元素存到set中，构建词频向量


	vector<double> vd1;
	vector<double> vd2;
	vd1 = tsy.getOneHot(wset1, wfg1);  //拿到文档1的构建好的词频向量
	vd2 = tsy.getOneHot(wset2, wfg2); //拿到文档2的构建好的词频向量 

	double res = tsy.cosine(vd1, vd2);   //计算两个文本的文本相似度
	cout << "两个文档的文本相似度:" << res << endl;
}

int main()
{
	//TestShowWordFreq();    //测试打印出两个文档的词频
	//TestSort();  //将两个文档的词频进行降序排序
	//TestOneHot();  //得到词频向量
	TestConine();  //测试两个文档的文本相似度
	system("pause");
	return 0;
}


