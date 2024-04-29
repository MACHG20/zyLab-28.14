#include <iostream>
using namespace std;

#include "ShoppingCart.h"

//constructors
ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date){
   customerName = name;
   currentDate = date;
}


//getters
string ShoppingCart::GetCustomerName() const{
   return customerName;
   }
string ShoppingCart::GetDate() const{
   return currentDate;
   }
int ShoppingCart::GetNumItemsInCart(){
   int totalQuantity = 0;
    for (int i = 0; i < cartItems.size(); ++i) {
        totalQuantity += cartItems[i].GetQuantity();
    }
    return totalQuantity;
}
double ShoppingCart::GetCostOfCart(){
   double costOfCart = 0.0;
    for(int i = 0; i<cartItems.size(); ++i){
       costOfCart += cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity();
    }
   return costOfCart;
   }

//Mutators
void ShoppingCart::AddItem(ItemToPurchase item){
   cartItems.push_back(item);
   }

void ShoppingCart::RemoveItem(string itemName){
   bool Found = false;
   for(int i = 0; i<cartItems.size(); ++i){
      if(cartItems.at(i).GetName() == itemName){
         cartItems.erase(cartItems.begin()+i);         
         Found = true;
         cout<<endl;
         break;
      }
   }
   if(!Found){
      cout << "Item not found in cart. Nothing removed." <<endl<<endl;
   }
}

void ShoppingCart::ModifyItem(ItemToPurchase item){
   bool found = false;
   for(int i = 0; i<cartItems.size(); ++i){
      if(cartItems.at(i).GetName() == item.GetName()){
         if(item.GetDescription() != "none"){
            cartItems.at(i).SetDescription(item.GetDescription());
         }
         if(item.GetPrice() != 0){
            cartItems.at(i).SetPrice(item.GetPrice());
         }
         if(item.GetQuantity() != 0) {
            cartItems.at(i).SetQuantity(item.GetQuantity());
         }
         found = true;
         break;
      }  
   }
   if(!found){
      cout << "Item not found in cart. Nothing modified." <<endl;
      cout<<endl;
   }
}

//Print Functions
void ShoppingCart::PrintTotal(){
   if(cartItems.empty()){
      cout<<"SHOPPING CART IS EMPTY" << endl;
      cout<<endl;
      cout<<"Total: $0"<<endl;
      cout<<endl;
   }
   else{
      // cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
      // cout << "Number of Items: " << GetNumItemsInCart() << endl;
      
      double totalCost = 0.0;

      for (int i = 0; i < cartItems.size(); ++i) {
         cout << cartItems.at(i).GetName() << " " << cartItems.at(i).GetQuantity() << " @ $" << cartItems.at(i).GetPrice() << " = $" << (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity()) << endl;
         totalCost += (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
      }

      cout << endl << "Total: $" << totalCost << endl<<endl;
    }
}
void ShoppingCart::PrintDescriptions(){
   if (cartItems.empty()) {
      cout << "SHOPPING CART IS EMPTY" << endl;
    } 
    else {
      cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl << endl;
      cout << "Item Descriptions" << endl;
      for (int i = 0; i < cartItems.size(); ++i) {
         cout << cartItems[i].GetName() << ": " << cartItems[i].GetDescription() << endl;
      }
      cout<<endl;
   }
}

