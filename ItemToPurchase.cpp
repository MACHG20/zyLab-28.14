#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

//define constructor
ItemToPurchase::ItemToPurchase(){
  itemName = "";
  itemDescription = "";
  itemPrice = 0;
  itemQuantity = 0;
}

//define mutators
void ItemToPurchase::SetName(string name){
  itemName = name;
}
void ItemToPurchase::SetDescription(string description){
  itemDescription = description;
}
void ItemToPurchase::SetPrice(int price){
  itemPrice = price;
}
void ItemToPurchase::SetQuantity(int quantity){
  itemQuantity = quantity;
}

//define getters
string ItemToPurchase::GetName() const{
  return itemName;
}
string ItemToPurchase::GetDescription() const{
  return itemDescription;
}
int ItemToPurchase::GetPrice() const{
  return itemPrice;
}
int ItemToPurchase::GetQuantity() const{
  return itemQuantity;
}

//define print functions
void ItemToPurchase::PrintItemCost(){
  cout << GetName() << " " << GetQuantity() << " @ $" << GetPrice() << " = $" << itemQuantity * itemPrice << endl;
}
void ItemToPurchase::PrintItemDescription(){
  cout << GetName() << ": " << GetDescription() << endl;
}
   
