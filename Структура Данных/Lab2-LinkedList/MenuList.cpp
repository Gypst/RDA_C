#include "MenuList.h";
#include <ctime>

int GetInt()
{
	int number;
	while (!(cin >> number))
	{
		cout << "This is not a natural number" << endl;

		cin.clear();
		cin.ignore(132, '\n');
	}
	return number;
}

void ListPrint(List* list)
{
	Node* headNode = list->Head;

	while (headNode != nullptr)
	{
		printf("%d ", headNode->Data);
		headNode = headNode->Next;
	};
}

void NodePrint(Node* myNode)
{
	printf("%d ", myNode->Data);
}


void MenuList()
{
	List* menuList = new List;
	menuList->Head = nullptr;
	menuList->Capacity = 0;
	bool headListCreated = false;
	Node* linearSearchPointer = nullptr;
	
	while (true)
	{
		system("CLS");
		ListPrint(menuList);
		cout << endl;
		cout << "Menu of creation doubly linked list:"		<< endl
			<< "1. Add a new element to the linked list"	<< endl
			<< "2. Delete the element"						<< endl
			<< "3. Sorting the doubly linked list"			<< endl
			<< "4. Linear search in the linked list"		<< endl
			<< "0. Exit with deleting linked list"			<< endl;

		int userAnswer = GetInt();
		while (headListCreated == false && (userAnswer == 2 || userAnswer ==3 || userAnswer == 4))
		{
			cout << "You need create a doubly linked list first!"	<< endl;
			userAnswer = GetInt();
		}

		switch (userAnswer)
		{
		case 1:
			
			cout << "Please select where you want to add element:"	<< endl
				<< "1. Insert an item at the begining of list"		<< endl
				<< "2. Insert an item at the end of list"			<< endl
				<< "3. Insert an item befor the certain element"	<< endl
				<< "4. Insert an item after the certain element"	<< endl;
			userAnswer = GetInt();

			while (!(userAnswer == 1 || userAnswer == 2 || userAnswer == 3 || userAnswer == 4  ))
			{
				cout << "You should choice number from additional menu!" << endl;
				userAnswer = GetInt();
			}
			while (headListCreated == false && userAnswer != 1)
			{
				cout << "Create list fist" << endl;
				userAnswer = GetInt();
			}

					switch (userAnswer)
					{
					case 1:
						cout << "What a number you want to put in?" << endl;
						userAnswer = GetInt();

						if (menuList->Head == nullptr)
						{
							InitHead(menuList, userAnswer);
						}
						else
						{
							AddHead(menuList, userAnswer);
						}
						headListCreated = true;
						menuList->Capacity++;
						break;
					case 2:
					{
						cout << "What a number you want to put in?" << endl;
						userAnswer = GetInt();

						Node* findedNode = FindNodePointerByCount(menuList, menuList->Capacity);
						if (findedNode != nullptr)
						{
							AddElem(findedNode, userAnswer);
						}
						else
						{
							cout << "Error: Finded Node is over list" << endl;
							break;
						}

						menuList->Capacity++;
						break;
					}
					case 3:
					{
						cout << "What a number you want to put in?" << endl;
						userAnswer = GetInt();

						cout << "What count of the elements you choose?" << endl;
						int element = GetInt();
						while (element <= 1 || element > menuList->Capacity)
						{
							cout << "Please, enter a correct count " << endl;
							element = GetInt();
						}
						// Uncomment to see how many sec program delete item
						//clock_t begin = clock();
						Node* findedNode = FindNodePointerByCount(menuList, element - 1);
						if (findedNode != nullptr)
						{
							AddElem(findedNode, userAnswer);
							//clock_t end = clock();
							//double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
							//cout << "Clock: " << elapsed_secs;
						}
						else
						{
							cout << "Error: Finded Node is over list" << endl;
							break;
						}

						menuList->Capacity++;
						break;
					}
					case 4:
					{
						cout << "What a number you want to put in?" << endl;
						userAnswer = GetInt();

						cout << "What count of the elements you choose?" << endl;
						int element = GetInt();
						while (element < 1 || element > menuList->Capacity)
						{
							cout << "Please, enter a correct count " << endl;
							element = GetInt();
						}

						Node* findedNode = FindNodePointerByCount(menuList, element);
						if (findedNode != nullptr)
						{
							AddElem(findedNode, userAnswer);
						}
						else
						{
							cout << "Error: Finded Node is over list" << endl;
							break;
						}

						menuList->Capacity++;
						break;
					}
					default:
						cout << "Error!" << endl;
						break;
					}

			system("pause");
			break;
		case 2:
		{
			cout << "What count of the element you choose?" << endl;
			userAnswer = GetInt();
			while (userAnswer < 1 || userAnswer > menuList->Capacity)
			{
				cout << "Please, enter a correct count " << endl;
				userAnswer = GetInt();
			}
			Node* findedNode = FindNodePointerByCount(menuList, userAnswer);
			if (findedNode != nullptr)
			{
				menuList->Head = DelElem(findedNode);
			}
			else
			{
				cout << "Error: Finded Node is over list" << endl;
				break;
			}
			if (menuList->Head == nullptr)
			{
				headListCreated = false;
			}
			menuList->Capacity--;
			system("pause");
			break;
		}
		case 3:
			if (headListCreated)
			{
				cout << "Unsorted list:" << endl;
				ListPrint(menuList); cout << endl;
				menuList->Head = ListSort(menuList);  cout << endl;
				cout << "Result of sorting:" << endl;
				ListPrint(menuList); cout << endl;
			}
			else
			{
				cout << "List is empty" << endl;
			}
			
			system("pause");
			break;
		case 4:
			cout << "What the number you search?" << endl;
			userAnswer = GetInt();

			linearSearchPointer = LinearSearch(menuList, userAnswer);

			if (linearSearchPointer == nullptr)
			{
				cout << "The number not found" << endl;
			}
			else
			{
				cout << "Found you number: ";
				NodePrint(linearSearchPointer);
				cout << endl;
;			}
			system("pause");
			break;
			//Debug function
		//case 2733:
		//	srand(time(NULL));
		//	InitHead(menuList, rand() % 100);
		//	headListCreated = true;
		//	menuList->Capacity++;
		//	int debugLength;
		//	cout << "Welcome to debug function!" << endl
		//		<< "Enter Length of random array you need" << endl;
		//	cin >> debugLength;
		//	//head was already created later
		//	debugLength--;
		//	for (int i = 0; i < debugLength; i++)
		//	{
		//		AddElem(menuList->Head, rand() % 100);
		//		menuList->Capacity++;
		//	}
		//	break;
		case 0:
			return;
		default:
			cout << "You should choice number from menu!" << endl;
			system("pause");
			break;
		}
	}
}