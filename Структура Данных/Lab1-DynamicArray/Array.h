#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct Array
{
	int Length;
	int Capacity;
	int* Array;
};


void CreateArray(Array* myArray);
void RandArray(Array* myArray);
void ShowArray(Array* myArray);
void ShowFullArray(Array* myArray);
void ManualAddArray(Array* myArray, short unsigned int k);
void AddElement(Array* myArray, int element);
void ExpandArray(Array* myArray);
int DeleteIndex(Array* myArray, int unsigned index = NULL);
void DelArray(Array* myArray);
int Menu();
int LinearFind(Array* array, int element);
int BinaryFind(Array* array, int element);
int CheckCapacity(Array* array, int answer);
int  CheckIndex(Array* array, int answer);
void ShowArrayLinear(Array* myArray);