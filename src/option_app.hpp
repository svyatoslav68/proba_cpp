/******************************************************
 ******* Заголовок класса, разбирающего ***************
 ******* опции и клюи приложения        ***************
 ********        option_app.hpp         ***************
 *****************************************************/
#ifndef OPTION_APP_HPP
#define OPTION_APP_HPP

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class optionApp{
public:
	optionApp();
	void exec(int argc, char *argv[]);
	bool isHelp();
	int getCount();
	std::string getNameFile();
private:
	po::options_description op_desc; // Описание опций и ключей 
	po::positional_options_description pd_desc;
	po::variables_map op_store;	// Контейенер для хранения полученных опций
};
#endif // OPTION_APP_HPP
