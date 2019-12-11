/******************************************************
 *********** Реализация класса, разбирающего **********
 *********** опции и ключи приложения        **********
 ***********        option_app.hpp           **********
 *****************************************************/

#include <iostream>
#include "option_app.hpp"

optionApp::optionApp(){
	op_desc.add_options()
		("help,h", "Show help")
		("count,c", po::value<int>(), "Counter")
		;
}

void optionApp::exec(int argc, char *argv[]){
	po::store(po::parse_command_line(argc, argv, op_desc), op_store);
	if(op_store.count("help")){
		std::cout << "Помощь по программе:" << std::endl;
		std::cout << op_desc << std::endl;
	}
}

bool optionApp::isHelp(){
	return op_store.count("help");
}

int optionApp::getCount(){
	return op_store["count"].as<int>();
}

