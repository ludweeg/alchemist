#ifndef ALCHEMICALPLANT__
#define ALCHEMICALPLANT__

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>

class AlchemicalPlant
{

private:
	std::pair <std::string, std::string> elements;
	std::map <std::string, std::pair <std::string, int>> stock;
	int numb_open;

public:
	AlchemicalPlant();
	void RecipesCheck();
	void SetFirstElement(std::string);
	std::string GetFirstElement();
	void SetSecondElement(std::string);
	std::string GetSecondElement();
	void SetNumbOpen(int);
	int GetNumbOpen();
	void OpenElement(std::string);
	int GetStatus(std::string);
	std::string GetSymbol(std::string);
	std::pair <std::string, std::string> GetElements();
	std::pair <std::string, std::string> GetReversElements();
	bool InputValidation(std::string);

	void Stock();
	void Help();
	void Exit();

	void SuccessfulMessage(std::string);
	void UnsuccessfulMessage();

	void PrintiSpaces(int);
};

#endif