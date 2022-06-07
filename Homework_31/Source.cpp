#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// Возвращение рандомного числа
int randomNuber(int min, int max) {
	if (max <= min)
		throw invalid_argument("конец диапазона  должен быть больше, чеь начало");
	srand(time(NULL));
	int z = rand() % (max - min) + min;
	return z;
}

// Проверка слова и длины
bool word_and_size() {
	string str, str1;
	int number, space = 0, sumLetters = 0;
	cout << "Введите слово и его длину (через пробел): ";
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ')
			space++;
	}
	if (space != 1)
		throw runtime_error("неверный формат");
	int index = str.find(" ");
	for (int i = 0; i < index; i++) {
		if (str[i] < char(65))
			throw runtime_error("cлова содержат только буквы");
	}
	for (int i = index + 1; i < str.size(); i++) {
		if (str[i] != char(48) && str[i] != char(49) && str[i] != char(50) && str[i] != char(51) && str[i] != char(52) && str[i] != char(53) && str[i] != char(54) && str[i] != char(55) && str[i] != char(56) && str[i] != char(57))
			throw runtime_error("в конце должна быть длина слова");
	}
	for (int i = index + 1; i < str.size(); i++)
		str1 += str[i];
	number = stoi(str1);
	for (int i = 0; i < index; i++) {
		str1 += str[i];
		sumLetters++;
	}
	if (sumLetters != number)
		return false;
	return true;
}

int main() {
	setlocale(LC_ALL, "ru");
	int n, m;
	bool func = false;


	// Задача 1.
	cout << "\tЗадача 1.\n";
	do {
		cout << "Введите начало и конец диапазона: ";
		cin >> n >> m;
		cin.ignore();
		try {
			cout << "Случайное число введёного диапазона = " << randomNuber(n, m) << "\n\n";
			func = true;
		}
		catch (const invalid_argument& ex) {
			cout << "Ошибка диапазона: " << ex.what() << ".\n\n";
		}
		system("pause");
		system("cls");
	} while (func == false);
	func = false;
	// Задача 2.
	cout << "\tЗадача 2.\n";
	do {
		try {
			if (word_and_size() == true) {
				cout << "Правда! Введённое слово равно введённой длине.\n\n";
				func = true;
			}
			else {
				cout << "Не правда! Введённое слово НЕ равно введённой длине.\n\n";
				func = true;
			}
		}
		catch (const runtime_error& ex) {
			cout << "ОШИБКА: " << ex.what() << ".\n\n";
		}
		system("pause");
		system("cls");
	} while (func == false);

	return 0;
}