#include "AlchemicalPlant.hpp"

int main()
{
	AlchemicalPlant ap;
	std::string buff;
	ap.Help();
	ap.Stock();
	
	while(buff != "exit")
	{
		std::cout << "Command: ";
		std::cin >> buff;

		if(!ap.InputValidation(buff))
		{
			ap.SetFirstElement(buff);
			std::cin >> buff >> buff;
			ap.SetSecondElement(buff);

			ap.RecipesCheck();
		} 
	}

	return 0;
}