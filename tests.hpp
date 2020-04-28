#include "FactorySimple.hpp"
#include "Operations.hpp"
#include <string>
#include <iostream>

TEST(TestSet, CreateTree)
{
	char* test[1] = {(char*) "3+5-1"};
	int length = 5;
	FactorySimple* aaa = new FactorySimple();
	Base* result = aaa->parse(test,length);
	EXPECT_EQ(result->evaluate(),7);
}


TEST(TestSet, TreeWithNegativeResult)
{
	char* test[1] = {(char*) "0-20"};
	int length = 4;
	FactorySimple* aaa = new FactorySimple();
	Base* result = aaa->parse(test,length);
	EXPECT_EQ(result->evaluate(),-20);
}

TEST(TestSet, AddSubDivMult)
{
	char* test[1] = {(char*) "2+2-1*3/9"};
	int length=9;
	FactorySimple* aaa = new FactorySimple();
	Base* result = aaa->parse(test,length);
	EXPECT_EQ(result->evaluate(),1);
}

TEST(TestSet2, WithUserInput)
{
	std::cout<<"Please input equation, no '()' or ' '."<<std::endl;
	string test;
	std::cin >> test;
	int length = strlen(test.c_str());
	char* test2 [1] = {(char*) test.c_str()};
	std::cout<<"length of equation is: " + length<<std::endl;
	double result;
	std::cout << "Please input expected result" << std::endl;
	std::cin >> result;
	FactorySimple* aaa = new FactorySimple();
	std::cout << "created factory"<<std::endl;
	Base* tree = aaa->parse(test2,length);
	std::cout<<"parsed"<<std::endl;
	EXPECT_EQ(tree->evaluate(),result);
}
