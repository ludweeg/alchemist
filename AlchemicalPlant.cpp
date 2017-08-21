#include "AlchemicalPlant.hpp"
#include "RecTemplate.hpp"

AlchemicalPlant::AlchemicalPlant()
	: numb_open(4)
{
	stock =
	{
		{"water",        {"🌢", 1}},
		{"fire",         {"🔥",1}},
		{"ground",       {"🌍",1}},
		{"air",          {"🌫",1}},
		{"wind",         {"🌬",0}},
		{"pressure",     {"🖡", 0}},
		{"alcohol",      {"🍾",0}},
		{"sea",          {"🏊",0}},
		{"steam",        {"💨",0}},
		{"lava",         {"🎇",0}},
		{"volcano",      {"🌋",0}},
		{"island",       {"🏝",0}},
		{"swamp",        {"🕳",0}},
		{"stone",        {"🌑",0}},
		{"metal",        {"☗",0}},
		{"turf",         {"🌰",0}},
		{"scotch",       {"🍷",0}},
		{"steam_boiler", {"⛭",0}},
		{"sand",         {"⏶",0}},
		{"beach",        {"🏖",0}},
		{"dust",         {"⌓",0}},
		{"ash",          {"🗑",0}},
		{"powder",       {"📣",0}},
		{"geyser",       {"♨",0}},
		{"desert",       {"🏜",0}},
		{"rust",         {"⌇",0}},
		{"mud",          {"☁",0}},
		{"energy",       {"🔁",0}},
		{"smoke",        {"🌁",0}},
		{"tempest",      {"🌪",0}},
		{"clay",         {"⛘",0}},
		{"sound",        {"🔊",0}},
		{"typhoon",      {"🌊",0}},
		{"brick",        {"🝚",0}},
		{"glass",        {"☐",0}}
	};
}

void AlchemicalPlant::RecipesCheck()
{
	unsigned int rec_size = recipes.size() - 1;

	for(unsigned int i = 0; i <= rec_size; i++)
	{
		bool condition = (recipes[i].first == this->GetElements() || recipes[i].first == this->GetReversElements())
			 && !this->GetStatus(recipes[i].second) 
			 &&  this->GetStatus(this->GetFirstElement())
			 &&  this->GetStatus(this->GetSecondElement());

		if(condition) 
		{
			this->OpenElement(recipes[i].second);
			this->SetNumbOpen(this->GetNumbOpen() + 1);
			this->SuccessfulMessage(recipes[i].second);
			this->Stock();
			return ;
		}
		else if(i == rec_size)
		{
			this->UnsuccessfulMessage();
		}
	}
}

void AlchemicalPlant::SetFirstElement(std::string firstElement)
{
	this->elements.first = firstElement;
	return ;
}

std::string AlchemicalPlant::GetFirstElement()
{
	return this->elements.first;
}

void AlchemicalPlant::SetSecondElement(std::string secondElement)
{
	this->elements.second = secondElement;
	return ;
}

std::string AlchemicalPlant::GetSecondElement()
{
	return this->elements.second;
}

void AlchemicalPlant::SetNumbOpen(int numb_open)
{
	this->numb_open = numb_open;
	return ;
}

int AlchemicalPlant::GetNumbOpen()
{
	return this->numb_open;
}

void AlchemicalPlant::OpenElement(std::string element)
{
	this->stock[element].second = 1;
	return ;
}

int AlchemicalPlant::GetStatus(std::string element)
{
	return this->stock[element].second;
}

std::string AlchemicalPlant::GetSymbol(std::string element)
{
	return this->stock[element].first;
}

std::pair <std::string, std::string> AlchemicalPlant::GetElements()
{
	return this->elements;
}

std::pair <std::string, std::string> AlchemicalPlant::GetReversElements()
{
	return std::pair <std::string, std::string>(elements.second, elements.first);
}

bool AlchemicalPlant::InputValidation(std::string command)
{
	if(command == "stock" || command == "1") 
	{
	 	this->Stock();
	   	return true;
	}
	else if(command == "help" || command == "2")
	{
		this->Help();
	   	return true;
	}
	else if(command == "exit" || command == "3")
	{
		this->Exit();
	   	return true;
	}
	else return false;
}

void AlchemicalPlant::Stock()
{
	std::map <std::string, std::pair <std::string, int>>::iterator it;

	std::cout << "┏─────────────────┓" << std::endl;
	for (it = stock.begin(); it != stock.end(); it++)
	{
		if((*it).second.second)
		{
			std::cout << "│ " << (*it).second.first << "  " << (*it).first;
			this->PrintiSpaces(13 - (*it).first.length());
			std::cout << "│" << std::endl;

		}
	}
	std::cout << "┗─────────────────┛" << std::endl;
	return ;
}

void AlchemicalPlant::Help()
{
	std::cout << "┏─────────────────────────────────────────────────────────────────────┓\n"
			  << "│Welcome to the alchemy laboratory! Mix the elements to get new ones. │\n"
			  << "│Example: first element + second element                              │\n"
			  << "│Other commands:                                                      │\n"
			  << "│[1] stock →  show stock                                              │\n"
			  << "│[2] help  →  help                                                    │\n"
			  << "│[3] exit  →  exit                                                    │\n"
			  << "┗─────────────────────────────────────────────────────────────────────┛\n";
	return ;
}

void AlchemicalPlant::Exit()
{
	std::cout << "Goodbye!" << std::endl;
	return ;
}

void AlchemicalPlant::SuccessfulMessage(std::string element)
{
	std::cout << "[+] You open new element: «" << this->GetSymbol(element) + "  " + element + "» [" << 
		this->GetNumbOpen() << "/" << recipes.size() + 4 << "]" << std::endl;
	return ;
}
void AlchemicalPlant::UnsuccessfulMessage()
{
	std::cout << "[!] Failure, try another combination :(" << std::endl;
	return ;
}

void AlchemicalPlant::PrintiSpaces(int n)
{
	for(int i = 1; i <= n; i++)
	{
		std::cout << " ";
	}
	return ;
}