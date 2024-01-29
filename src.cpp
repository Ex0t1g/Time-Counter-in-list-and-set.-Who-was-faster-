#include <iostream>
#include <ctime>
#include <chrono>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    const long int SIZE = 1000000; 
    list<int> numbers;
    set<int> numberSet;
    srand(time(0));
    for (long int i = 0; i < SIZE; i++) {
        numbers.push_back(rand());
        numberSet.insert(rand());
    }

    int target = rand();
    auto startTime = chrono::high_resolution_clock::now();

    auto listIter = find(numbers.begin(), numbers.end(), target);
    if (listIter != numbers.end()) {
        cout << "Number found in list!" << endl;
    }
    else {
        cout << "Number not found in list." << endl;
    }

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    cout << "Time taken to search in list: " << duration << " microseconds" << endl;

    // Поиск случайного числа с использованием дерева и измерение времени
    startTime = chrono::high_resolution_clock::now();

    auto setIter = numberSet.find(target);
    if (setIter != numberSet.end()) {
        cout << "Number found in set!" << endl;
    }
    else {
        cout << "Number not found in set." << endl;
    }

    endTime = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    cout << "Time taken to search in set: " << duration << " microseconds" << endl;

    return 0;
}
