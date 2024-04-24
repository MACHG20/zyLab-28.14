#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu(){
   cout << "a - Add item to cart " <<endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o = Output shopping cart" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
   cout << "Choose an option:" <<endl;
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   if (option == 'a'){
      ShoppingCart::AddItem(theCart);
   }
   if (option == 'd'){
      ShoppingCart::RemoveItem(theCart);
   }
   if (option == 'c'){
      ShoppingCart::ModifyItem(theCart);
   }
   if (option == 'i'){
      ShoppingCart::PrintDescription(theCart);
   }
   if (option == 'o'){
      ShoppingCart::PrintTotal(theCart);
   }
}

int main() {
   for (bool i=false; i == false){
   PrintMenu();
   char option;
   cin << option;
   if (option == 'a' || 'd' || 'c' || 'i' || 'o'){
      ExecuteMenu(option, theCart);
   }
   if (option == 'q'){
      i = true;
      }
   else {
      cout << "invalid input" << endl;
   }
   }
   return 0;
}
