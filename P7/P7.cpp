//timing things
#include <iostream>
#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

#include <vector>
#include <list>
#include <random>
#include <math.h>
#include <time.h>

using namespace std;

using std::vector;
using std::list;

template <typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();
}


int main()
{
    srand(time(NULL));
    
	int const size = 10'000;

    int array[size] = {};

	vector<int> v;
	for (int i = 0; i < size; i++)
    {
        int n = rand() % 100 + 1;
        v.push_back(n);
    }
    
	list<int> l;
	l.push_back(0);

    for (int i = 0; i < size; i++)
    {
        int n = rand() % 100 + 1;
        array[i] = n;
    }

	auto vectormilliseconds = TimeFunc([&]() {vector<int> BuildVector(int size, vector<int> v); });
	auto listmilliseconds = TimeFunc([&]() {list<int> BuildList(int size, list<int> l); });
	auto arraymilliseconds = TimeFunc([&]() {int* BuildList(int size, int* array); });

    cout << "Vector Time: " << vectormilliseconds << endl;
    cout << "List Time: " << listmilliseconds << endl;
    cout << "Array Time: " << arraymilliseconds << endl;
}
