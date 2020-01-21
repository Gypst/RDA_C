#include "Array.h"


void CreateArray(Array* myArray)
{
	myArray->Array = new int[myArray->Capacity];
};

void RandArray(Array* myArray)
{
	myArray->Length = myArray->Capacity;
	srand(time(NULL));
	for (int i = 0; i < myArray->Length; i++)
	{
		myArray->Array[i] = rand() % 10;
	}
};

void ShowArray(Array* myArray)
{
	for (int i = 0; i < myArray->Length; i++)
	{
		cout << i + 1 << ": \t" << myArray->Array[i] << endl;
	}
};

void ShowArrayLinear(Array* myArray)
{
	cout << "Array: " << endl;
	for (int i = 0; i < myArray->Length; i++)
	{
		cout << i + 1<< ": " << myArray->Array[i] << "\t";
	}
	cout << endl;
};

void ShowFullArray(Array* myArray)
{
	for (int i = 0; i < myArray->Capacity; i++)
	{
		cout << i + 1 << ": \t" << myArray->Array[i] << endl;
	}
};

void DelArray(Array* myArray)
{
		delete[] myArray->Array;
};

void ManualAddArray(Array* myArray, short unsigned int k)
{
	for (int i = 0; i < k; i++)
	{
		cout << i + 1 << ":" << "-> ";
		cin >> myArray->Array[i];
		if (myArray->Length < i + 1)
		{
			myArray->Length++;
		}
	}
};


void ExpandArray(Array* myArray)
{
	int* oldArray = myArray->Array;
	myArray->Capacity += 4;
	CreateArray(myArray);

	for (int i = 0; i < myArray->Length; i++)
	{
		myArray->Array[i] = oldArray[i];
	}
	delete[] oldArray;
};

int DeleteIndex(Array* myArray, int unsigned index)
{
	if (index == -1 || index == myArray->Length)
	{
		//If need errase value
		//myArray->array[myArray->length] = NULL;
		myArray->Length -= 1;
		return 0;
	}

	if (index > myArray->Length)
	{
		cout << "Index is over array!";
		return -1;
	}

	for (int i = index - 1; i < myArray->Length - 1; i++)
	{
		myArray->Array[i] = myArray->Array[i + 1];
	}
	myArray->Length -= 1;

	return 0;
};

void AddElement(Array* myArray, int element)
{
	myArray->Length += 1;

	if (myArray->Length == myArray->Capacity)
	{
		ExpandArray(myArray);
	}

	myArray->Array[myArray->Length - 1] = element;
};

void InsertElement(Array* myArray, int element, int unsigned index)
{
	if (index == myArray->Length)
	{
		AddElement(myArray, element);
		return;
	}

	myArray->Length += 1;
	//Check avability to insert
	if (myArray->Length >= myArray->Capacity)
	{
		ExpandArray(myArray);
	}
	for (int i = myArray->Length - 1; i > index - 1; i--)
	{
		myArray->Array[i] = myArray->Array[i - 1];
	}
	myArray->Array[index - 1] = element;
	return;
};


int LinearFind(Array* array, int element)
{
	for (int i = 0; i < array->Length; i++)
	{
		if (array->Array[i] == element)
		{
			return i + 1;
		}
	}
	return -1;
};

void Swap(Array* array, int left, int right)
{
	if (left != right)
	{
		int temp = array->Array[left];
		array->Array[left] = array->Array[right];
		array->Array[right] = temp;
	}
}

void Sort(Array* array)
{
	bool swapped;

	do
	{
		swapped = false;
		for (int i = 1; i < array->Length; i++) {
			if (array->Array[i - 1] - (array->Array[i]) > 0)
			{
				Swap(array, i - 1, i);
				swapped = true;
			}
		}
	} while (swapped != false);
};

int BinaryFind(Array* array, int element)
{
	int first = 0;
	int last = array->Length - 1;
	while (first < last)
	{
		int mid = (first + last) / 2;
		if (element <= array->Array[mid])
		{
			last = mid;
		}
		else
		{
			first = mid + 1;
		}
	}
	if (array->Array[first] == element)
	{
		return first;
	}
	else
	{
		return -1;
	}
	
		
};

int CheckCapacity(Array* array, int answer)
{
	while (answer <= 0 or answer > array->Capacity)
	{
		cout << "Please insert the correct count" << endl;
		cout << "Capacity of array is " << array->Capacity << endl;
		cin >> answer;
	}
	return answer;
}
int  CheckIndex(Array* array, int answer)
{

	while (answer <= 0 or answer > array->Length)
	{
		cout << "Please insert the correct index" << endl;
		cout << "Length of array is " << array->Length << endl;
		cin >> answer;
	}
	return answer;
};

int Menu()
{
	int answer;
	Array array;
	//Deafult array capasity is 4 or 8 by task
	array.Capacity = 8;
	array.Length = 0;
	CreateArray(&array);

	while (true)
	{
		system("CLS");

		ShowArrayLinear(&array);
		cout << "Menu:" 										<< endl
			<< "1. Insert an element at the beginning"			<< endl
			<< "2. Insert an element at the end"				<< endl
			<< "3. Insert an element by index"					<< endl
			<< "4. Manually filling array"						<< endl
			<< "5. Fill the array with random numbers"			<< endl
			<< "6. Show the array"								<< endl
			<< "7. Delete element by index"						<< endl
			<< "8. Linear find"									<< endl
			<< "9. Sort array"									<< endl
			<< "10. Binary find"								<< endl
			<< "0. Delete array and exit"						<< endl;

		//Check int	
		while (!(cin >> answer))
		{
			cout << "This is not number" << endl;

			cin.clear();
			//Discard previous input 
			cin.ignore(132, '\n');
		}

		switch (answer)
		{
		case 1:
			cout << "What number you want to insert?" << endl;
			cin >> answer;

			InsertElement(&array, answer, 1);
			break;
		case 2:
			cout << "What number you want to insert?" << endl;
			cin >> answer;

			InsertElement(&array, answer, array.Length + 1);
			break;
		case 3:
			if (array.Length == 0)
			{
				cout << "The arry is empty!" << endl;
				system("pause");
				break;
			}
			cout << "What number you want to insert?" << endl;
			int number;
			cin >> number;

			cout << "What index you need?" << endl;
			cin >> answer;

			answer = CheckIndex(&array, answer);

			InsertElement(&array, number, answer);
			break;
		case 4:
			cout << "How many value you need to fill?" << endl;
			cin >> answer;
			
			answer = CheckCapacity(&array, answer);

			ManualAddArray(&array, answer);
			break;
		case 5:
			RandArray(&array);
			break;
		case 6:
			cout << "Showing array:" << endl;
			ShowArray(&array);
			system("pause");
			break;
		case 7:
			cout << "What index you want to delete?" << endl;
			cin >> answer;
			
			answer = CheckCapacity(&array, answer);

			DeleteIndex(&array, answer);
			break;
		case 8:
			cout << "What element you need?" << endl;
			cin >> answer;

			answer = LinearFind(&array, answer);
			
				if (answer > 0)
				{
					cout << "Index of this element is " << answer << endl;
				}
				else
				{
					cout << "Element not founded" << endl;
				}
			system("pause");
			break;
		case 9:
			Sort(&array);
			break;
		case 10:
			Sort(&array);
			cout << "(Array was sorted)" << endl;
			cout << "What element you need?" << endl;
			cin >> answer;
			answer = BinaryFind(&array, answer);
			if (answer < 0 )
			{
				cout << "Your element not founded" << endl;
			}
			else
			{
				cout << "Your element under " << answer + 1 << " position"<<  endl;
			}

			system("pause");
			break;
		case 0:
			CreateArray(&array);
			DelArray(&array);
			return 0;

		default:
			cout << "Please select menu number" << endl;
			system("pause");
			break;
		}
		
	}

};
