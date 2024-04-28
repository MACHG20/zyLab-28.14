#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
}

void ExecuteMenu(char choice, ShoppingCart &cart) {
    switch(choice) {
      case 'a':{
         
         string itemName;
         string itemDescription;
         int itemPrice;
         int itemQuantity;
         
         cout<<"ADD ITEM TO CART" << endl;
         cout << "Enter the item name:"<<endl;
         getline(cin, itemName);
         cout << "Enter the item description:"<<endl;
         getline(cin, itemDescription);
         cout << "Enter the item price:"<<endl;
         cin >> itemPrice;
         cout << "Enter the item quantity:"<<endl;
         cin >> itemQuantity;

         ItemToPurchase newItem(itemName, itemDescription, itemPrice, itemQuantity);
         cart.AddItem(newItem);

         break;
      }
      case 'd':{
         
         string itemName;

         cout << "REMOVE ITEM FROM CART" << endl;
         cout << "Enter name of item to remove:" <<endl;
         getline(cin, itemName);

         cart.RemoveItem(itemName);

         break;
      }
      case 'c':{
         
         string itemName;
         int newQuantity;
         
         cout << "CHANGE ITEM QUANTITY" << endl;
         cout << "Enter the item name:"<<endl;
         getline(cin, itemName);
         cout << "Enter the new quantity:"<<endl;
         cin >> newQuantity;

         ItemToPurchase modifiedItem(itemName, "", 0, newQuantity);
         cart.ModifyItem(modifiedItem);

         break;
      }
      case 'i':{
         
         cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
         cart.PrintDescriptions();

         break;
      }
      case 'o':{
         
         cout << "OUTPUT SHOPPING CART" << endl;
         cout << cart.GetCustomerName() << "'s Shopping Cart - "<< cart.GetDate() << endl;
         cout << "Number of Items: " << cart.GetNumItemsInCart() << endl << endl;
         cart.PrintTotal();

         break;
      }
      case 'q':{
         break;
      }   
      default:
         cout << "Choose an option:" << endl;
         break;
    }
}

int main() {
   
   //STEP 3
   string name;
   string date;
   cout<<"Enter customer's name:" << endl;
   getline(cin, name);
   cout<<"Enter today's date:" << endl;
   getline(cin, date);
   cout<< endl << "Customer name: " << name << endl;
   cout<< "Today's date: " << date << endl;
   ShoppingCart Cart(name, date);
   
   //STEP 5a
   cout<<endl;
   PrintMenu();
   cout<<endl;
   cout<<"Choose an option:"<<endl;
   char choice;
   cin>>choice;
   while(choice != 'q'){
      if(choice == 'a' || choice == 'd' || choice == 'c' || choice == 'i' || choice == 'o'){
         ExecuteMenu(choice, Cart);
         PrintMenu();
         cout<<endl;
         cout<<"Choose an option:"<<endl;
         cin>>choice;
         continue;
      }
      else{
         cout<<"Choose an option:"<<endl;
         cin>>choice;
      }
   }
   
   return 0;   
}
