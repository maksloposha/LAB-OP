#pragma once
#include<vector>
#include<iostream>
#include<time.h>
using namespace std;
class Multidity
{private:
	vector<int> mnozh;
public:
	Multidity(vector<int> mnozh) {     // Конструктор з параметром
		this->mnozh = mnozh;
	}
	Multidity() {                     // Конструктор за замовчуванням
		srand(time(NULL));
		for (int i = 0; i < rand() % 10 + 6; i++) {
			int el = rand() % 15 + 1;
			if (find(mnozh.begin(), mnozh.end(), el) != mnozh.end())
				continue;
			mnozh.push_back(el);
		}
	}
	vector<int> getVector() {    // геттер
		return mnozh;
	}
	void display() {        // метод виведення в консоль множини 
		for (int i = 0; i < mnozh.size(); i++) {   
			cout << mnozh[i] << " ";
		}
		cout << "\n";
	}
	bool existance(int digit) {    // метод , який показує чи належить число заданій множині
		if (find(mnozh.begin(), mnozh.end(), digit) != mnozh.end())
			return true;
		else
			return false;
	}
	friend Multidity operator* (Multidity objA, Multidity objB);    // перетин
	friend Multidity operator+ (Multidity objA, Multidity objB);    // об'єднання
	friend Multidity operator- (Multidity objA, Multidity objB);    // різниця
};

