//
// Created by q2015 on 25-6-16.
//
#include<iostream>
#include<cmath>

using namespace std;

int main() {
    double floorWidth, floorHeight;

    const double tileWidth = 0.6;
    const double tileHeight = 0.6;
    double tileCost;

    cout<<"Enter the floor width: ";
    cin >> floorWidth;

    cout<<"Enter the floor height: ";
    cin >> floorHeight;

    cout<<"Enter the floor cost你是: ";
    cin >> tileCost;

    int tileInWidth = ceil(floorWidth / tileWidth);
    int tileInHeight = ceil(floorHeight / tileHeight);

    int totalTiles = tileInWidth * tileInHeight;
    double totalCost = tileCost * totalTiles;

    cout << "Cost total is:" << totalCost << endl;
    cout << "total number of tile is :"<< totalTiles << endl;

    return 0;
}