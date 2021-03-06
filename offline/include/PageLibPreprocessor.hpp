 ///
 /// @file    PageLibPreprocessor.hpp
 /// @author  Damon(1225228598@qq.com)
 /// @date    2017-01-19 10:41:45
 ///


#ifndef _WD_PAGE_LIB_PREPROCESSOR_H_
#define _WD_PAGE_LIB_PREPROCESSOR_H_


#include "WebPage.hpp"
#include "WordSegmentation.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::map;
using std::unordered_map;
using std::set;

using namespace wd;

namespace wd
{

class PageLibPreprocessor
{
public:
	PageLibPreprocessor(Configuration & conf);

	void doProcess();

private:

	void readInfoFromFile();

	void cutRedundantPages();

	void buildInvertIndexTable();

	void storeOnDisk();

private:
	Configuration &                                  _conf;
	WordSegmentation                                 _jieba; 

	vector<WebPage>                                  _pageLib;
	unordered_map<int, pair<int, int> >              _offsetLib;
	unordered_map<string, vector<pair<int, double>>> _invertIndexTable;//倒排索引表，map《单词，vector《文档ID，该单词在该文档中的权重》》
};


}// end of namespace wd


#endif
