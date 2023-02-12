#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

// Pre: The array storing numbers, the number to find, and the size of the array
// Post: Return the found index of num. If not found, returns -1
int findIndex(int arr[], int num, int& arrSize);

// Pre: The array storing numbers, the index to replace, and the size of the array
// Post: Modifies the array at index
void changeValue(int arr[], int index, int& arrSize);

// Pre: The array storing numbers, the number to append, and the size of the array
// Post: Expands the array and adds num to the end of the array
void appendArray(int arr[], int num, int& arrSize);

// Pre: The array storing numbers, the number to find, and the size of the array. A helper function
// Post: Extends the array by size amount. 
void extendArray(int arr[], int size, int& arrSize);

// Pre: The array storing numbers, the number to find, and the size of the array. A helper function
// Post: Shrinks the array by size amount.
void shrinkArray(int arr[], int size, int& arrSize);

// Pre: ifstream of the open file, the array to modify, and the size of the array
// Post: fills the array with the entries found in the file
void readFile(ifstream& in, int arr[], int& arrSize);

// Pre: The array storing numbers, the index to delete, and the size of the array
// Post: delete the value at index
void clearValue(int arr[], int index, int& arrSize);

// Pre: The array storing numbers, and the size of the array
// Post: Print the whole array, values seperated by spaces
void printArray(int arr[], int& arrSize);

// Pre: none
// Post: Prints the menu and returns the user selection
char printMenu();

/*
void calcNewSize(int arr[], int& arrSize);
*/