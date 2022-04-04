#pragma once
#include<math.h>
class Geometric
{
private:
	int q,            // ���������
		a0,			  // ������ ����
		n;			  // ������� �����	
public:
	Geometric() {     // ����������� �� �������������
		q = 0;
		a0 = 0;
		n = 0;
	}
	Geometric(int q, int a0, int n) {    // �����������
		this -> q = q;
		this -> a0 = a0;
		this -> n = n;
	}
	int last() {
		return a0 * (pow(q, n - 1));  // ������� ������� �������
	}

};

