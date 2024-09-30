#include <iostream>
using namespace std;


int main() {
int numbers[] = {1,2,3,4,5,6,7,8,9,10};//Set Or Initialize The Array
int newNum; //Allows The Initialization Of New Variable
const int OrigSize = sizeof (numbers) / sizeof (numbers[0]); //Set Or Initialize The Constant Of A Variable By Calculating The Size Of The Array
int newArray[OrigSize + 1]; //Set Or Initialize The New Array
  
//Prints Out The Original Array For The New Variable
for (int n = 0; n < OrigSize; n++) {
newArray[n] = numbers[n];
}
  
//Prints The Old Array
for (int n = 0; n < OrigSize; n++) {
    std::cout << numbers[n] << " ";  
}
  
std::cout << std::endl;
  
//Allows The User To Enter A New Number
std::cout << "Enter a new number: "; 
std::cin >> newNum;
  
//Adds The New Number To The Array
newArray[OrigSize] = newNum;  

//Prints The New Array All Together
for (int n = 0; n < OrigSize + 1; n++) {
std::cout << newArray[n] << " ";
} 
  
return 0;
}
