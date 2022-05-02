#include "Class.h"
Multidity operator*(Multidity objA, Multidity objB)
{
	vector<int> mnozhA = objA.getVector();
	vector<int> mnozhB = objB.getVector();
	vector<int> mnozhC;
	for (int i = 0; i < objB.mnozh.size(); i++) {
		if (find(mnozhA.begin(), mnozhA.end(), mnozhB[i]) != mnozhA.end())
			mnozhC.push_back(mnozhB[i]);
	}

	Multidity objC(mnozhC);
	return objC;
}

Multidity operator+(Multidity objA, Multidity objB)
{
	vector<int> mnozhA = objA.getVector();
	vector<int> mnozhB = objB.getVector();
	vector<int> mnozhC;
	for (int i = 0; i < mnozhA.size(); i++)
		mnozhC.push_back(mnozhA[i]);
	for (int i = 0; i < mnozhB.size(); i++) {
		if (find(mnozhC.begin(), mnozhC.end(), mnozhB[i]) != mnozhC.end())
			continue;
		mnozhC.push_back(mnozhB[i]);
	}
	Multidity objC(mnozhC);
	return objC;
}

Multidity operator-(Multidity objA, Multidity objB)
{
	vector<int> mnozhA = objA.getVector();
	vector<int> mnozhB = objB.getVector();
	vector<int> mnozhC;
	for (int i = 0; i < mnozhA.size(); i++) {
		if (find(mnozhB.begin(), mnozhB.end(), mnozhA[i]) != mnozhB.end())
			continue;
		mnozhC.push_back(mnozhA[i]);
	}
	Multidity objC(mnozhC);
	return objC;
}
