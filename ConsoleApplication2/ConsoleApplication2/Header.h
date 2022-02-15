#pragma once
int Input(const char*);            //введення й запис в файл
int text_mod(const char*, const char*);   // зчитування з файлу , модифікація тексту і введення в новий файл обробленого тексту
void add(const char*);             //додавання в початкочий файл тексту
int output(const char*);			//виведення в консоль того, що є в файлі
int clean(const char*);				// очистка файлу