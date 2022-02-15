#include <iostream>
#include "Header.h"
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int Input(const char* fileName )
{
	string input[100];     //��������� ����� � �����
	int n = 0;				//�-��� �����
	string enter; 
	cout << "Enter text and press Ctrl+P to end\n";
	char ending = 16;		//������ Ctrl+P ��� ��������� ��������
	do {
		getline(cin, enter);
		if (enter.find(ending) == string::npos) {
			input[n] = enter;        
			n++;
		}
	} while (enter.find(ending) == string::npos); //������� ����� ���� �� ����������� Ctrl+P
	
	ofstream fout(fileName, ios::app);     //��������� ���� ��� ������
	if (!fout) {
		cout << "Cannot open the file" << endl;		//������� �������
		return 0;
	}
		for (int i = 0; i < n; i++) {     //�������� ������ �������
			if (input[i] != "")
				fout << input[i] << "\n";
		}
	fout.close();
}

int text_mod(const char* FileNameIn, const char* FileNameOut )
{
	string s_mas[100], s;
	int n = 0;
	ifstream file(FileNameIn);
	if (!file) {
	cout << "Cannot open the file" << endl;   //������� �������
	return 0;
	}
	while (!file.eof()) {   //������� ����� � ����� ������� � �����
		getline(file, s);
		s_mas[n] = s;
		n++;
	}
	file.close();

	ofstream fout(FileNameOut);  //��������� ����� ����
	if (!fout) {                                
		cout << "Cannot open the file" << endl;  //������� �������
		return 0;
	}
	for (int i = 0; i < n; i++) {          
		if (s_mas[i] != "")
			fout << s_mas[i].length() << " " << s_mas[i] << "\n";    //�������� �� ���������� ����� � ����� ����
	}
}

void add(const char* fileName) {
	int flag;
	do {
		cout << "\nIf you want to add enter 1, if no - 2: "; cin >> flag;
		if (flag == 1) {
			Input(fileName);    //���������� ����, ���� ���������� ������ 1
		}
	} while (flag == 1);
}

int output(const char* fileName) {
	string s;
	ifstream file(fileName);
	if (!file) {
		cout << "Cannot open the file" << endl;   //������� �������
		return 0;
	}
	while (!file.eof()) {      //������� ���� ����� ������� � �������� ���� � �������
		getline(file, s);
		cout << s << "\n";
	}
	file.close();
}

int clean(const char* fileName)
{
	fstream file;
	file.open(fileName, ios::out);   //������� ����
	if (!file) {
		cout << "Cannot open the file" << endl;   //������� �������
		return 0;
	}

	file.close();
}
