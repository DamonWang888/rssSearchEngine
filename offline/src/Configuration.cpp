 ///
 /// @file    Configuration.cpp
 /// @author  Damon(1225228598@qq.com)
 /// @data    2017-11-10 17:30:39
 ///

#include "Configuration.hpp"
#include "GlobalDefine.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;

namespace wd
{

Configuration::Configuration(const std::string & filepath)//创建对象时就初始化好该文件
	: filepath_(filepath)
{
	readConfiguration();
}

void Configuration::readConfiguration()
{
	std::ifstream ifs(filepath_.c_str());//ifstream input 打开即为文件形成输入流的源头----实际为读文件
	if(ifs.good())
	{
		std::string line;
		while(getline(ifs, line))
		{
			std::istringstream iss(line);
			std::string key;
			std::string value;
			iss >> key >> value;
			configMap_[key] = value;
		}
		std::cout << "read configuration is over!" << std::endl;
	}
	else
	{
		std::cout << "ifstream open error" << std::endl;
	}
}

std::map<std::string, std::string> & Configuration::getConfigMap()
{
	return configMap_;
}

std::set<std::string> & Configuration::getStopWordList()
{
	if(stopWordList_.size() > 0)
		return stopWordList_;

	std::string stopWordFilePath = configMap_[STOP_WORD_KEY];
	std::ifstream ifs(stopWordFilePath.c_str());
	if(!ifs)
	{
		std::cout << "StopWord ifstream open error!" << std::endl;
	}
	
	std::string word;
	while(getline(ifs, word))
	{
		stopWordList_.insert(word);
	}

// for debug	
#if 0
	for(auto &str : stopWordList_)
	{
		std::cout << str << "\t" << str.size() << std::endl;
	}
	std::cout << std::endl;
#endif

	return stopWordList_;
}

void Configuration::debug()
{
	for(auto & elem : configMap_)
	{
		cout << elem.first << " --> " << elem.second << endl;
	}
}

}// end of namespace wd
