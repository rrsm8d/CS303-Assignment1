#include "Functions.h"

int findIndex(int arr[], int num, int& arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (num == arr[i])
		{
			return i;
		}
	}
	return -1;
}

void changeValue(int arr[], int index, int& arrSize)
{
	try
	{
		int input;
		cout << "What value would you like to change " << arr[index] << " to? " << endl;
		cin >> input;
		cout << arr[index] << " was changed to " << input << endl;
		arr[index] = input;
	}
	catch (exception& e)
	{
		cerr << "Invalid input" << endl;
	}
}

void appendArray(int arr[], int num, int& arrSize)
{
	extendArray(arr, 1, arrSize);
	arr[arrSize-1] = num;
}

void extendArray(int arr[], int size, int& arrSize)
{
	// Take note and store the old size of the array
	int oldSize = arrSize;
	// Calculate the new size of the array, using the given param
	arrSize += size;
	// Make a new array that our pointer will point to
	int *newArray = new int[arrSize];
	// Copy all values from the old array to the new one
	std::copy(arr, arr + std::min(oldSize, arrSize), newArray);
	/*
	for (int i = 0; i < oldSize; i++)
	{
		newArray[i] = arr[i];
	}
	*/
	// Set the array
	arr = newArray;
	delete[] newArray;
}

void shrinkArray(int arr[], int size, int& arrSize)
{
	// Take note and store the old size of the array
	int oldSize = arrSize;
	// Calculate the new size of the array, using the given param
	arrSize += size;
	// Make a new array that our pointer will point to
	int* newArray = new int[arrSize];
	// Copy all values from the old array to the new one
	std::copy(arr, arr + std::min(oldSize, arrSize), newArray);
	/*
	for (int i = 0; i < arrSize; i++)
	{
		newArray[i] = arr[i];
	}
	*/
	// Set the array
	arr = newArray;
	delete[] newArray;
}

void readFile(ifstream& in, int arr[], int& arrSize)
{

	stringstream stream;
	string readString;
	int num;
	cout << "[ ";
	// While there are still new lines in the file...
	while (getline(in, readString)) {
		stream.clear();
		stream.str(readString);
		// Because each line has 10 entries, increase the array size by 10
		// While there are still new numbers in the line...
		while (stream >> num)
		{
			// printArray(arr, arrSize);
			cout << num << " ";
			appendArray(arr, num, arrSize);
			// printArray(arr, arrSize);
		}

	}
	cout << "] read from file" << endl;
}

void clearValue(int arr[], int index, int& arrSize)
{
	cout << arr[index] << " was deleted from the array" << endl << endl;
	for (int i = index; i < arrSize; ++i)
		arr[i] = arr[i + 1]; // Shift all elements to the left, where the deleted value is to be
	shrinkArray(arr, -1, arrSize);
}

void printArray(int arr[], int& arrSize)
{
	cout << "[ ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl << endl;

}

char printMenu()
{
	cout << "What would you like to do?" << endl;
	cout << "1 - Print the array" << endl;
	cout << "2 - Find index of number" << endl;
	cout << "3 - Change the value of a certain index" << endl;
	cout << "4 - Append an number to the array" << endl;
	cout << "5 - Remove a number at a certain index" << endl;
	cout << "0 - Quit" << endl;
	cout << "Make your choice: ";
	char sel;
	cin >> sel;
	cout << endl;
	return sel;
}

/*
void calcNewSize(int arr[], int& arrSize)
{
	arrSize = sizeof(arr) / sizeof(int);
	cout << "CALCULATED A NEW SIZE AS " << arrSize << endl;
}
*/