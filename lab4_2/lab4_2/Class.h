#pragma once
#include<vector>
#include<iostream>
#include<time.h>
using namespace std;
class Multidity
{private:
	vector<int> mnozh;
public:
	Multidity(vector<int> mnozh) {     // ����������� � ����������
		this->mnozh = mnozh;
	}
	Multidity() {                     // ����������� �� �������������
		srand(time(NULL));
		for (int i = 0; i < rand() % 10 + 6; i++) {
			int el = rand() % 15 + 1;
			if (find(mnozh.begin(), mnozh.end(), el) != mnozh.end())
				continue;
			mnozh.push_back(el);
		}
	}
	vector<int> getVector() {    // ������
		return mnozh;
	}
	void display() {        // ����� ��������� � ������� ������� 
		for (int i = 0; i < mnozh.size(); i++) {   
			cout << mnozh[i] << " ";
		}
		cout << "\n";
	}
	bool existance(int digit) {    // ����� , ���� ������ �� �������� ����� ������ ������
		if (find(mnozh.begin(), mnozh.end(), digit) != mnozh.end())
			return true;
		else
			return false;
	}
	friend Multidity operator* (Multidity objA, Multidity objB);    // �������
	friend Multidity operator+ (Multidity objA, Multidity objB);    // ��'�������
	friend Multidity operator- (Multidity objA, Multidity objB);    // ������
};

