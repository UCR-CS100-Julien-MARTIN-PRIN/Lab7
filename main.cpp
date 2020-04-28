#include "FactorySimple.hpp"
#include "Operations.hpp"
#include <string>




int main(int argv, char** argc)
{
	std::cout<< "Input an equation. Make sure not to use any parenthesis or spaces in the line."<<std::endl;
	string input;
	std::cin >> input;
	int length = strlen(input.c_str());
	char* truc[1] = {(char*) input.c_str()};
	FactorySimple* aaa= new FactorySimple();
	Base* tree = aaa->parse(truc,(int)length);
	std::cout << tree->stringify() << std::endl;
	std::cout << tree->evaluate() << std::endl;


	return 0;
}
