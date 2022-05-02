// lab4_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<vector>
#include"Class.h"
using namespace std;

int main()
{
    
    int n;
    cout << "Enter the number of elements in multidity "; cin >> n;
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
        int el; cout << "Enter: "; cin >> el;
        if (find(tmp.begin(), tmp.end(), el) != tmp.end()) { //заповнюємо вектор множиною чисел, які не повторюються
            i--;
            continue;
        }
        tmp.push_back(el);
    }
    Multidity A(tmp);
    tmp.clear();
    cout << "A = "; A.display();
    Multidity B;
    cout << "B = "; B.display();
    Multidity C = (A + B) - (A * B);
    cout << "C = ";  C.display();


    int flag;
    cout << "If you want to explore multidity A press 1\n";
    cout << "If you want to explore multidity B press 2\n";
    cout << "If you want to explore multidity C press 3\n";
    cout << "If you want to exit press 0\n";
    do {
        cout << "Your choice ";
        cin >> flag;
        int digit;
        switch (flag) {
            case 1:
                cout << "Enter the digit ";  cin >> digit;
                if (A.existance(digit))
                    cout << "Digit is in multidity\n";
                else
                    cout << "Digit is not in the multidity\n";
                break;
            case 2:
                cout << "Enter the digit ";  cin >> digit;
                if (B.existance(digit))
                    cout << "Digit is in multidity\n";
                else
                    cout << "Digit is not in the multidity\n";
                break;
            case 3:
                cout << "Enter the digit ";  cin >> digit;
                if (C.existance(digit))
                    cout << "Digit is in multidity\n";
                else
                    cout << "Digit is not in the multidity\n";
                break;
            default:
                flag = 0;
                break;
        }

       
    } while (flag != 0);
    


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
