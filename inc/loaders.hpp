#ifndef LOADERS_L
#define LOADERS_L

#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<boost/regex.hpp>

namespace loaders
{
	const int min_size = 4,train_size = 4415,test_size = 4414;
	void load_train(const std::string&,std::vector<std::vector<std::string> >&,std::vector<bool>&);
    void load_data(const std::string&, 
                            const std::string&, 
                            std::vector<std::vector<std::string> >&, 
                            std::vector<bool>&,
                            std::vector<std::vector<std::string> >&,
									 const int& = -1,
									 const unsigned int& = 2,
									 const bool& = 0);
    void load_smileys(const std::string&, std::vector<std::pair<std::string, bool>>&);
    void load_corrections(const std::string&, std::vector<std::pair<std::string, std::string>>&);
    void getRegexps(std::vector<std::pair<std::string, std::string>>&,const bool&);
	void load_test(const std::string&,std::vector<std::vector<std::string> >&);
};

#endif