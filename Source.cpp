#include <iostream>
using namespace std;
#include "Arr.h"
#include <ctime>
#include <stdexcept>


int main()
{
	srand(time(0));
	Arr<int> arr;
	arr.show();
	cout << "isFull: " << arr.isFull() << endl;
	cout << "isEmpty: " << arr.isEmpty() << endl;

	for (int i = 0; !arr.isFull(); i++)
	{
		arr.add(rand() % (100 - 1) + 1);
	}
	cout << "getSize: " << arr.getSize() << endl;
	cout << "getCap: " << arr.getCap() << endl;
	arr.show();
	arr.add(5);
	arr.show();
	cout << "getSize: " << arr.getSize() << endl;
	cout << "getCap: " << arr.getCap() << endl;

	cout <<endl<< "TEST SET SIZE" << endl << endl;
	arr.setSize(15,5);
	arr.show();
	cout << "getSize: " << arr.getSize() << endl;
	cout << "getCap: " << arr.getCap() << endl;
	cout << "getGrow: " << arr.getGrow() << endl;
	cout << "GetUpperBound: " << arr.getUpperBound() << endl;

	arr.freeExtra();
	cout<<endl<<"freeExtra(): " << endl << "getSize: " << arr.getSize() << endl;
	cout << "getCap: " << arr.getCap() << endl;

	//cout << "removeAll(): "<<endl;
	//arr.removeAll();
	//arr.show();
	//arr.add(5);
	//arr.show();

	cout <<"getAt(): " << arr.getAt(16) << endl;


	//cout << "TEST CHAR" << endl;
	//Arr<char> arrC;
	//cout << "getAt(): " << arrC.getAt(22) << endl;

	cout<<endl << "operator []: " << endl;
	arr[0] = 999;
	arr[10] = 999;
	cout << arr;
	cout << arr[0] << endl;

	//cout << arr;

	cout << "Append arr + arr2: " << endl;
	//Arr<int> arr2(arr);
	Arr<int> arr2;
	for (int i = 0; i<5; i++)
	{
		arr2.add(rand() % (100 - 1) + 1);
	}
	cout << arr2;
	arr.append(arr2);
	cout << arr;
	cout << endl << "operator =: " << endl;

	Arr<int> arr5 = arr2;
	cout << arr5;
	cout<<"GetData: " << arr5.getData() << endl;

	cout << "arr test for" << endl;


	return 0;
}