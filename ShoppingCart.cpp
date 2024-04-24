#include <iostream>
using namespace std;

#include "ShoppingCart.h"

//constructors
ShoppingCart::ShoppingCart();
ShoppingCart::ShoppingCart(string name, string date){
   customerName = name;
   currentDate = date;
}


//getters
string ShoppingCart::GetCustomerName(){
   return name;
   }
string ShoppingCart::GetDate(){
   return date;
   }
int ShoppingCart::GetNumItemsInCart(){
   return cartItems.size();
   }
double ShoppingCart::GetCostOfCart(){
   double costOfCart = 0.0;
    for(int i = 0; i<cartItems.size(); ++i){
       costOfCart += cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity();
    }
   return costOfCart
   }

//Mutators
void ShoppingCart::AddItem(ItemToPurchase item){
   cartItems.push_back(item);
   }

void ShoppingCart::RemoveItem(string itemName){
   bool Found = false;
   for(int i = 0; i<cartItems.size(); ++i){
      if(cartItems.at(i).GetName() == itemName){
         
         //still need to remove item
         
         Found = true;
         break;
      }
   }
   if(!Found){
      cout << "Item not found in cart. Nothing removed." <<endl;
   }
}

void ShoppingCart::ModifyItem(ItemToPurchase item){
   bool found = false;
   for(int i = 0; i<cartItems.size(); ++i){
      if(cartItems.at(i).GetName() == item.GetName()){

         //have to check if parameter has default values
         //modify if it does not         
      }
      found = true;
      break;
   }
   if(!Found){
      cout << "Item not found in cart. Nothing removed." <<endl;
   }
}

//Print Functions
void ShoppingCart::PrintTotal(){
   cout << ItemToPurchase.costOfCart << endl;
   }
void ShoppingCart::PrintDescriptions(){
   cout << ItemToPurchase.description << endl;
   }
