#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int* mergeSort(int arr[], int size);
int* bubbleSort(int arr[], int size);

int main()
{
	//int arr[] = { 114,738,34,56,671,982,78,45,37,43,55,90,51,56,78,43,93,65,84,54,23,862,786,78,79,455,356,534,972,318,345,394,127,57,47,5437,7,73,84,346,84,34 }; //size 42
	int arr[] = { 1,7,5,2,3,9,8,4,6 }; //size 9
	int* arrSorted = mergeSort(arr, 9);
	for (int i = 0; i < 9; i++)
	{
		cout << arrSorted[i] << " ";
	}
	cout << endl;
	delete[] arrSorted;

	int arr2[] = { 1,7,5,2,3,9,8,4,6 }; //size 9
	arrSorted = bubbleSort(arr2, 9);
	for (int i = 0; i < 9; i++)
	{
		cout << arrSorted[i] << " ";
	}


	return 0;
}

int* mergeSort(int arr[], int size)
{

	if (size > 1)
	{
		int* tempArr1 = new int[size / 2];
		int* tempArr2 = new int[size - size / 2];
		for (int i = 0; i < size / 2; i++)
		{
			tempArr1[i] = arr[i];
			//cout << arr[i] << " ";
		}
		
		for (int i = size / 2; i < size; i++)
		{
			tempArr2[i - size / 2] = arr[i];
			//cout << arr[i] << " ";
		}
		//cout << endl;

		int* tempArr3 = mergeSort(tempArr1, size / 2);
		int* tempArr4 = mergeSort(tempArr2, size - size / 2);

		int* returnArray = new int[size];
		int j = 0;
		int k = 0;
		for (int i = 0; i < size; i++)
		{
			if (j == size / 2)
			{
				returnArray[i] = tempArr4[k];
				k++;
			}
			else if (k == size - size / 2)
			{
				returnArray[i] = tempArr3[j];
				j++;
			}
			else if (tempArr3[j] < tempArr4[k])
			{
				returnArray[i] = tempArr3[j];
				j++;
			}
			else if (tempArr3[j] > tempArr4[k])
			{
				returnArray[i] = tempArr4[k];
				k++;
			}
			else
			{
				returnArray[i] = tempArr3[j];
				j++;
			}
			//cout << returnArray[i] << " ";
		}
		//cout << endl;
		delete[] tempArr1;
		delete[] tempArr2;
		return returnArray;
	}
	else
	{
		return arr;
	}
}
int* bubbleSort(int arr[], int size)
{
	int* tempArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = arr[i];
	}

	for (int i = size; i > 0; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (tempArr[j] > tempArr[j + 1])
			{
				int temp = tempArr[j + 1];
				tempArr[j + 1] = tempArr[j];
				tempArr[j] = temp;
			}
		}
	}
	return tempArr;
}