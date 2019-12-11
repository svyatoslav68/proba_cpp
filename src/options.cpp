/* Тестовое приложение. Пока пустое. По мере изучение будет наполняться
различной функциональностью. Все делается для изучение технологий
програмирования*/

#include <iostream>
#include "version.hpp"
#include "option_app.hpp"			

int main(int argc, char *argv[]){
	optionApp ops;
	ops.exec(argc, argv);
	if (ops.isHelp()){
		//std::cout << "Помощь по программе " << argv[0] << std::endl;
		exit(0);
	}
	std::cout << "Версия № " << get_version() << "; count = " << ops.getCount() << "; name_file = " << ops.getNameFile() << std::endl;
	return 0;
}
