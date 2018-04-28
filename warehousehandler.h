#ifndef WAREHOUSEHANDLER_H
#define WAREHOUSEHANDLER_H
#include "warehouse.h"

class WareHouseHandler
{
private:
    int nrOfWareHouses;
    int capacity;
    WareHouse* wareHouses;

    
public:
    WareHouseHandler();

    WareHouse* selectWareHouse(string id);

    /*
    void addWareHouse();
    bool removeWareHouse();
    int getNrOfWareHouses()const;
    void loadWareHousesFromFile();
    void saveWareHousesToFile();
    */
    
};

#endif // WAREHOUSEHANDLER_H