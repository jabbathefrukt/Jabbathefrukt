#ifndef TRUCK_H
#define TRUCK_H
#include "goodshandler.h"

class Truck
{
private:
    string destination;
    string id;
    int maxWeight;
    float volume;
    bool avaliable;
    string currentLocation;
    GoodsHandler goodsHandler;


public:
    Truck();

    /*
    void loadGood(Goods* goods);
    Goods* getGoods(string id);
    void changeDestination(string destination);
    string getDestination()const;
    */
};

#endif // TRUCK_H