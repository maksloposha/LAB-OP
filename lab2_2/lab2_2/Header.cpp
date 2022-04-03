#include <iostream>
#include "Header.h"
#include <string>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

void Input(string fileName)
{	vector<string> input;         //������ �����,�� �� ������� � �������
	string enter;
	cout << "Enter text in format:\n\"City\" time \"departure time\" \"durations in hours\" h  \"durations in hours\" min  \n";
	cout << "Example: Lutsk time 22:00 10 h 30 min\n";
	cout << "press Ctrl + P to end\n";
	char ending = 16;		//������ Ctrl+P ��� ��������� ��������
	do {
		getline(cin, enter);
		if (enter.find(ending) == string::npos) {     
			input.push_back(enter);
		}
	} while (enter.find(ending) == string::npos); //������� ����� ���� �� ����������� Ctrl+P

	ofstream fout(fileName, ios::binary | ios::app);     //��������� ���� ��� ������
	if (!fout) {
		cout << "Cannot open the file" << endl;		//������� �������
	}
	for (int i = 0; i < input.size(); i++) {     //�������� ������ �������
		if (input[i] != "")
			fout << input[i] << "\n";
	}
	fout.close();

}

int text_mod(string FileName)
{
	string s;
	vector<string> s_mas;								//������ ����� ��� ���������� � ����� 
	ifstream file(FileName, ios::binary);				//��������� ���� �������� ���� �������
	if (!file) {
		cout << "Cannot open the file" << endl;   //������� �������
		return 0;
	}
	while (!file.eof()) {   //������� ����� � ����� ������� � �����
		getline(file, s);
		s_mas.push_back(s);
	}
	file.close();

	fstream f;
	f.open(FileName,ios::binary | ios::out);   //������� ����
	f.close();

	ofstream fout(FileName, ios::binary);  //��������� ����� ����
	if (!fout) {
		cout << "Cannot open the file" << endl;  //������� �������
		return 0;
	}
	for (int i = 0; i < s_mas.size(); i++) {      
		if (s_mas[i] != "") {
			int arr_hour, arr_min;
			int hours = (s_mas[i][s_mas[i].rfind("h") - 2]) - '0' +( (s_mas[i][s_mas[i].rfind("h") - 3]) - '0' )* 10;      // ������� ��� ������
			int min = ((s_mas[i][s_mas[i].rfind("min") - 2])-'0') +( (s_mas[i][s_mas[i].rfind("min") - 3]) - '0') * 10;
			
			int dep_hour = ((s_mas[i][s_mas[i].rfind("time") + 5]) - '0') * 10 + (s_mas[i][s_mas[i].rfind("time") + 6]) - '0';  // ������� ��� �����������
			int dep_min = ((s_mas[i][s_mas[i].rfind("time") + 8]) - '0') * 10 + (s_mas[i][s_mas[i].find("time") + 9]) - '0';
			if (hours < 17) {
				if (dep_hour + hours > 24)             // ���������� ��� ��������
					 arr_hour = dep_hour + hours - 24;
				else
					 arr_hour = dep_hour + hours;
				if (dep_min + min >= 60) {
					arr_min = dep_min + min - 60;
					arr_hour += 1;
				}
				else
					arr_min = dep_min + min;

				if (23 > arr_hour && arr_hour>= 6) {    
					bool flag = ((23 - hours < dep_hour&& dep_hour < 23) || (6 + hours > arr_hour && arr_hour > 6));     //�����, �� ���� �� ��������� �����
					if (!flag) {
						fout << s_mas[i]<<"\n";
					}
				}

			}
			else 
				fout << s_mas[i]<<"\n";
			
		}
	}
}

int output(string fileName) {
	string s;	
	ifstream file(fileName, ios::binary);
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

void last_bus(string fileName)
{
	string city;
	cout << "Enter the city: "; cin >> city;   //̳��� ��� ��� ������
	vector<string> buses;						//������ ��� �����
	ifstream file(fileName, ios::binary);
	if (!file) {
		cout << "Cannot open the file" << endl;   //������� �������
	}
	while (!file.eof()) {   //������� ����� � ����� ������� � �����
		string s;
		getline(file, s);
		buses.push_back(s);
	}
	vector<string> last_buses;						//������ �����, �� ���������� � ������ ���� 
	for (int i = 0; i < buses.size(); i++) {
		if (buses[i].find(city) != string::npos) {
			last_buses.push_back(buses[i]);
		}
	}
	int last_hour = ((last_buses[0][last_buses[0].rfind("time") + 5]) - '0') * 10 + (last_buses[0][last_buses[0].rfind("time") + 6]) - '0';         
	int last_min = ((last_buses[0][last_buses[0].rfind("time") + 8]) - '0') * 10 + (last_buses[0][last_buses[0].find("time") + 9]) - '0';
	for (int i = 0; i < last_buses.size(); i++) {																							//��������� ������� ��� ��������
		int h = ((last_buses[i][last_buses[i].rfind("time") + 5]) - '0') * 10 + (last_buses[i][last_buses[i].rfind("time") + 6]) - '0';
		int min = ((last_buses[i][last_buses[i].rfind("time") + 8]) - '0') * 10 + (last_buses[i][last_buses[i].find("time") + 9]) - '0';
		if (h > last_hour) {
			last_hour = h;
			last_min = min;
		}
		else if (h == last_hour && min > last_min)
			last_min = min;
	}
	cout << last_hour << ":" <<last_min;
}


void add(string fileName) {
	int flag;
	do {
		cout << "\nIf you want to add enter 1, if no - 2: "; cin >> flag;
		if (flag == 1) {
			Input(fileName);    //���������� ����, ���� ���������� ������ 1
		}
	} while (flag == 1);
}