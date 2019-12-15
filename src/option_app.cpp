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
		("input_file", po::value<std::string>(), "input_file")
		;
	pd_desc.add("input_file", -1);
}

void optionApp::exec(int argc, char *argv[]){
	//po::store(po::parse_command_line(argc, argv, op_desc), op_store);
	po::store(po::command_line_parser(argc, argv).options(op_desc).positional(pd_desc).run(), op_store);
	po::notify(op_store);
	if(op_store.count("help")){
		std::cout << "Помощь по программе:" << std::endl;
		std::cout << op_desc << std::endl;
	}
}

bool optionApp::isHelp(){
	return op_store.count("help");
}

int optionApp::getCount(){
	if (op_store.count("count"))
		return op_store["count"].as<int>();
	else
		return -1;
}

std::string optionApp::getNameFile(){
	if (op_store.count("input_file"))
		return op_store["input_file"].as<std::string>();
	else
		return "";
}

