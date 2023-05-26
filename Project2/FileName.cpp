#include <iostream>

void DynamicArr(int*& arr, int& size);
void InicDynamicArr(int& size, int*& arr);
void PrintDynamicArr(int*& arr, int& size);
void DeleteDynamicArr(int*& arr);
void EndElement(int*& arr, int& size, int element);
void PrintIndex(int*& arr, int& size, int index);
void DeleteIndex(int*& arr, int& size, int index);


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int size;
	int* arr;
	int element = 10;
	int index;
	std::cin >> index;
	PrintIndex(arr, size, index);
	DeleteIndex(arr, size, index);

	return 0;
}

void DynamicArr(int*& arr, int& size)
{
	arr = new int[size];
}
void InicDynamicArr(int& size, int*& arr)
{

	for (int i = 0; i < size; i++)
	{
		arr[i] = 1 + rand() % 11;
	}
}
void PrintDynamicArr(int*& arr, int& size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "|";
	}
}
void DeleteDynamicArr(int*& arr)
{
	delete[]arr;
}
void EndElement(int*& arr, int& size, int element)
{
	int* temparr = new int[size];
	for (int i = 0; i < size; i++)
	{
		temparr[i] = arr[i];
	}
	DeleteDynamicArr(arr);
	size++;
	DynamicArr(arr, size);
	for (int i = 0; i < size - 1; i++)
	{
		arr[i] = temparr[i];
	}
	arr[size - 1] = element;
	DeleteDynamicArr(temparr);
}
void PrintIndex(int*& arr, int& size, int index)
{
	DynamicArr(arr, size);
	InicDynamicArr(size, arr);
	PrintDynamicArr(arr, size);
	int* temparr = new int[size];
	for (int i = 0; i < index; i++)
	{
		temparr[i] = arr[i];
		temparr[index] = 1 + rand() % 11;
	}
	for (int i = index + 1; i < size + 1; i++)
	{
		temparr[i] = arr[i - 1];
	}
	size++;
	DeleteDynamicArr(arr);
	arr = temparr;
	DeleteDynamicArr(temparr);
	PrintDynamicArr(arr, size);


}
void DeleteIndex(int*& arr, int& size, int index)
{
	DynamicArr(arr, size);
	InicDynamicArr(size, arr);
	PrintDynamicArr(arr, size);
	int* temparr = new int[size];
	for (int i = 0; i < index; i++)
	{
		temparr[i] = arr[i];
		temparr[index] = 1 + rand() % 11;
	}
	for (int i = index + 1; i < size + 1; i++)
	{
		temparr[i] = arr[i - 1];
	}
	size++;
	DeleteDynamicArr(arr);
	arr = temparr;
	DeleteDynamicArr(temparr);
	PrintDynamicArr(arr, size);
}