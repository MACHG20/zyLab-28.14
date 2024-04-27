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
    cout<<endl;
}

void ExecuteMenu(char choice, ShoppingCart &cart) {
    switch(choice) {
      case 'a':{
         // Add item to cart
         cout << "\nADD ITEM TO CART" << endl;
         string itemName, itemDescription;
         int itemPrice, itemQuantity;

         cout << "Enter the item name:"<<endl;
         cin.ignore();
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
         // Remove item from cart
         cout << "\nREMOVE ITEM FROM CART" << endl;
         string itemName;

         cout << "Enter name of item to remove:" <<endl;
         cin.ignore();
         getline(cin, itemName);

         cart.RemoveItem(itemName);
         break;
      }
      case 'c':{
         // Change item quantity
         cout << "\nCHANGE ITEM QUANTITY" << endl;
         string itemName;
         int newQuantity;

         cout << "Enter the item name:"<<endl;
         cin.ignore();
         getline(cin, itemName);

         cout << "Enter the new quantity:"<<endl;
         cin >> newQuantity;

         ItemToPurchase modifiedItem(itemName, "", 0, newQuantity);
         cart.ModifyItem(modifiedItem);
         break;
      }
      case 'i':{
         // Output items' descriptions
         cout << "\nOUTPUT ITEMS' DESCRIPTIONS" << endl;
         cart.PrintDescriptions();
         break;
      }
      case 'o':{
         // Output shopping cart
         cout << "\nOUTPUT SHOPPING CART" << endl;
         cout << cart.GetCustomerName() << "'s Shopping Cart - "<< cart.GetDate() << endl;
         cout << "Number of Items: " << cart.GetNumItemsInCart() << endl << endl;
         cart.PrintTotal();
         break;
      }
      case 'q':{
         // Quit
         cout << "Choose an option:" << endl;
         break;
      }   
      default:
         cout << "Invalid choice. Please try again." << endl;
    }
}

int main() {
   string customerName, currentDate;
   char choice;

    // Prompt the user for customer's name
   cout << "Enter customer's name:"<<endl;
   getline(cin, customerName);

    // Prompt the user for today's date
   cout << "Enter today's date:"<<endl;
   getline(cin, currentDate);
   
    // Output the name and date
   cout << "\nCustomer name: " << customerName << endl;
   cout << "Today's date: " << currentDate << endl;
   
   cout<<endl;

    // Create an object of type ShoppingCart
   ShoppingCart cart(customerName, currentDate);

   do {
      PrintMenu();
      cin >> choice;

      // Execute the menu option
      ExecuteMenu(choice, cart);
   } while (choice != 'q');

   return 0;
}
