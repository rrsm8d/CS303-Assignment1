// Name: Richard Soriano
// Class: CS-303 T/Th

// Compiled with gcc+, using visual studio as an IDE
#include "Functions.h"

int main()
{
	// Arrays cannot have a dynamic size, so it should be a pointer that changes to arrays of different sizes
	int *testArr = new int[1];
	int arrSize = 0;

	// The filename of the file with a list of numbers goes here.
	string filename = "filename.txt";

	// Open the file with numbers
	try
	{
		ifstream fin(filename);
		// Is it open? If not, throw an exception
		if (!fin)
		{
			fin.close();
			throw exception("Failure opening file: ");
		}
		readFile(fin, testArr, arrSize);
		fin.close();
	}
	catch (exception& e)
	{
		cerr << e.what() << filename << endl;
	}


	char sel = 'x';
	while (sel != '0')
	{
		sel = printMenu();
		switch (sel) {
		case '1':
			// Printing the array
			printArray(testArr, arrSize);
			break;

		case '2':
			// Finding the index of a value
			try {
				int num;
				cout << "Enter value: ";
				cin >> num;
				cout << endl;
				int index = findIndex(testArr, num, arrSize);
				if (index == -1)
				{
					cout << "Value not found" << endl << endl;
				}
				else cout << "Value found at index: " << index << endl << endl;
			}
			catch (exception& e)
			{
				cerr << e.what() << endl;
			}
			break;

		case '3':
			// Change the value at an index
			try {
				int index;
				cout << "Enter value: ";
				cin >> index;
				cout << endl;
				if (index < 0 || index > arrSize)
				{
					throw exception("Please enter a valid number");
				}
				changeValue(testArr, index, arrSize);
			}
			catch (exception& e)
			{
				cerr << e.what() << endl;
			}
			break;

		case '4':
			// Append to end of array
			try {
				int num;
				cout << "Enter value: ";
				cin >> num;
				cout << endl;
				appendArray(testArr, num, arrSize);
			}
			catch (exception& e)
			{
				cerr << "Not a valid input!" << endl;
			}
			break;

		case '5':
			// Delete value at index
			try {
				int index;
				cout << "Enter index: ";
				cin >> index;
				cout << endl;
				if (index < 0 || index > arrSize)
				{
					throw exception("Please enter a valid number");
				}
				clearValue(testArr, index, arrSize);
			}
			catch (exception& e)
			{
				cerr << e.what() << endl;
			}
			break;

		default:
			break;
		}
			
	}
	cout << "Program closing..." << endl;

	// I do not know why, but deleting the array causes massive errors. It's trying to delete locations that the array no longer should point to
	// Days of debugging and I've had no results on fixing this. I've instead opted for assigning the testArr pointer to nullptr
	// So the program can run without randomly encountering errors. 
	// delete[] testArr;
	testArr = nullptr;
}