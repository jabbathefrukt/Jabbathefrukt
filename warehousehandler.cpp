#include "warehousehandler.h"

WareHouseHandler::WareHouseHandler(int capacity)
{
	this->capacity = capacity;
	this->nrOfWareHouses = 0;

	loadWareHousesFromFile();
	//saveWareHousesToFile(); fungerar h�r men inte i destruktorn
}

WareHouseHandler::~WareHouseHandler()
{
	//saveWareHousesToFile();
	for (int i = 0; i < this->nrOfWareHouses; i++)
	{
		delete wareHouses[i];
	}
	delete[] wareHouses;

	//fungerar men endast om programmet avslutas vanligt och inte med att klicka ner programmet
}

WareHouse * WareHouseHandler::selectWareHouse(string id)
{
	int index = -1;
	for (int i = 0; i < this-> nrOfWareHouses && index == -1; i++)
	{
		if (wareHouses[i]->getId() == id)
		{
			index = i;
		}
	}
	WareHouse* wareHouseTemp = nullptr;
	if (index != -1)
	{
		return wareHouses[index];
	}
	else
	{
		return wareHouseTemp;
	}
}

void WareHouseHandler::addWareHouse(string id, string name)
{
	if (this->nrOfWareHouses != capacity)
	{
		bool idExist = false;
		for (int i = 0; i < this->nrOfWareHouses && idExist == false; i++)
		{
			if (wareHouses[i]->getId() == id)
			{
				idExist = true;
			}
		}
		if (idExist == false)
		{
			wareHouses[this->nrOfWareHouses] = new WareHouse(id, name);
		}
	}
}

bool WareHouseHandler::removeWareHouse(string id)
{
	bool removed = false;
	int index = -1;
	for (int i = 0; i < this->nrOfWareHouses && index == -1; i++)
	{
		if (wareHouses[i]->getId() == id)
		{
			index = i;
		}
	}
	if (index != -1)
	{
		delete wareHouses[index];
		wareHouses[index] = wareHouses[nrOfWareHouses - 1];
		wareHouses[nrOfWareHouses - 1] = nullptr; // kanske ta bort
		this->nrOfWareHouses--;
		removed = true;
	}
	return removed;
}

int WareHouseHandler::getNrOfWareHouses() const
{
	return this->nrOfWareHouses;
}

void WareHouseHandler::loadWareHousesFromFile()
{
	std::ifstream openFile("WareHouses.txt");
	openFile >> this->nrOfWareHouses;
	wareHouses = new WareHouse*[this->nrOfWareHouses];

	if (openFile.is_open())
	{
		for (int i = 0; i <this->nrOfWareHouses; i++)
		{
			string names;
			string id;
			openFile >> names;
			openFile >> id; //kanske l�s in direkt fr�n filen;
			wareHouses[i] = new WareHouse(id, names);
		}
	}
	openFile.close();
}

void WareHouseHandler::saveWareHousesToFile()
{
	std::ofstream myfile;
	myfile.open("WareHouses.txt");

	if (myfile.is_open())
	{
		myfile << nrOfWareHouses << '\n';

		for (int i = 0; i < this->nrOfWareHouses; i++)
		{
			myfile << wareHouses[i]->getId() << " " << wareHouses[i]->getName() << '\n';
		}
		myfile.close();
	}
}
