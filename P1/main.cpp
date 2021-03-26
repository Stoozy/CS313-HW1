#include <iostream>
#include <list>
#include <vector>
#include <chrono>
#include <time.h>
#include <stdlib.h>
using namespace std;  
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

template <typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();
}
//Part A. Vector that has been filled with random numbers.
//Random numbers function for the vector.
void VectorOfRandomNumbers(int size, vector<int> v) {
	for (int i = 0; i < size; i++) {
		v.push_back(rand());
	}
	
}

//Random numbers fuction for the linkedlist.
void ListOfRandomNumbers(int size, list<int> l) {
	for (int i = 0; i < size; i++) {
		l.push_back(rand());
	}
}

//Part B. Random string vector and linkedlist

//Random strings function
string getRandomString(int length) {
	int flag;
	char* ch = new char[length] ;
	for (int i = 0; i < length - 1; i++) {
		flag = rand() % 3;
		switch (flag)
		{
			case 0:
				ch[i] = rand() % 26 + 'A';
				break;

			case 1:
				ch[i] = rand() % 26 + 'a';
				break;

		default:
			ch[i] = rand() % 10 + '0';
			break;
		}
	}
	ch[length - 1] = '\0';
	string str = ch;
	return str;
}

//Random strings function for the vector.
void VectorOfRandomStrings(int size, vector<string> v) {
	for (int i = 0; i < size; i++) {
		int length = rand() % 50 + 1;
		string str = getRandomString(length);
		v.push_back(str);

	}
}
//Random strings fuction for the linkedlists
void ListOfRandomString(int size, list<string> l) {
	for (int i = 0; i < size; i++) {
		int length = rand() % 50 + 1;
		string str = getRandomString(length);
		l.push_back(str);
	}
}


//Part C. Move semantics
//Random strings fuction for vector using move semantics.
void VectorOfRandomStrings_Move(int size, vector<string> v) {
	for (int i = 0; i < size; i++) {
		int length = rand() % 50 + 1;
		string str = getRandomString(length);
		v.push_back(move(str));

	}
}
//Random strings fuction for linkedlist using move semantics.
void ListOfRandomString_Move(int size, list<string> l) {
	for (int i = 0; i < size; i++) {
		int length = rand() % 50 + 1;
		string str = getRandomString(length);
		l.push_back(move(str));
	}
}


int main()
{
	srand(time(nullptr));

	int const size = 10000;
	
	cout << "A." << endl;
	vector <int> v1;
	list <int> l1;
	auto vectormilliseconds_int = TimeFunc([&]() {VectorOfRandomNumbers(size, v1); });
	auto listmilliseconds_int = TimeFunc([&]() {ListOfRandomNumbers(size, l1); });
	cout << "A vector with 10,000 random numbers takes " << vectormilliseconds_int << " milliseconds\n";
	cout << "A linkedlist with 10,000 random numbers takes " << listmilliseconds_int << " milliseconds\n";
	if (vectormilliseconds_int < listmilliseconds_int) {
		cout << "Filling a vector with random numbers is faster than a linkedlist.\n";
	}
	else {
		cout << "Filling a linkedlist with random numbers is faster than a vector.\n";
	}
	
	cout << endl << endl;


	cout << "B." << endl;
	vector <string> v2;
	list <string> l2;
	auto vectormilliseconds_string = TimeFunc([&]() {VectorOfRandomStrings(size, v2); });
	auto listmilliseconds_string = TimeFunc([&]() {ListOfRandomString(size, l2); });
	cout << "A vector with 10,000 random strings takes " << vectormilliseconds_string << " milliseconds\n";
	cout << "A linkedlist with 10,000 random strings takes " << listmilliseconds_string << " milliseconds\n";
	if (vectormilliseconds_string < listmilliseconds_string) {
		cout << "Filling a vector with random strings is faster than a linkedlist.\n";
	}
	else {
		cout << "Filling a linkedlist with random strings is faster than a vector.\n";
	}
	cout << endl << endl;


	cout << "C." << endl;
	vector <string> v3;
	list <string> l3;
	auto vectormilliseconds_string_move = TimeFunc([&]() {VectorOfRandomStrings_Move(size, v2); });
	auto listmilliseconds_string_move = TimeFunc([&]() {ListOfRandomString_Move(size, l2); });
	cout << "A vector with 10,000 random strings using move semantics takes " << vectormilliseconds_string_move << " milliseconds\n";
	cout << "A linkedlist with 10,000 random strings using move semantics takes " << listmilliseconds_string_move << " milliseconds\n";
	if (vectormilliseconds_string_move < listmilliseconds_string_move) {
		cout << "Filling a vector with random strings while using move semantics is faster than a linkedlist.\n";
	}
	else {
		cout << "Filling a linkedlist with random strings while using move semantics is faster than a vector.\n";
	}
}

