#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// ����������� ���������� �����
int randomNuber(int min, int max) {
	if (max <= min)
		throw invalid_argument("����� ���������  ������ ���� ������, ��� ������");
	srand(time(NULL));
	int z = rand() % (max - min) + min;
	return z;
}

// �������� ����� � �����
bool word_and_size() {
	string str, str1;
	int number, space = 0, sumLetters = 0;
	cout << "������� ����� � ��� ����� (����� ������): ";
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ')
			space++;
	}
	if (space != 1)
		throw runtime_error("�������� ������");
	int index = str.find(" ");
	for (int i = 0; i < index; i++) {
		if (str[i] < char(65))
			throw runtime_error("c���� �������� ������ �����");
	}
	for (int i = index + 1; i < str.size(); i++) {
		if (str[i] != char(48) && str[i] != char(49) && str[i] != char(50) && str[i] != char(51) && str[i] != char(52) && str[i] != char(53) && str[i] != char(54) && str[i] != char(55) && str[i] != char(56) && str[i] != char(57))
			throw runtime_error("� ����� ������ ���� ����� �����");
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


	// ������ 1.
	cout << "\t������ 1.\n";
	do {
		cout << "������� ������ � ����� ���������: ";
		cin >> n >> m;
		cin.ignore();
		try {
			cout << "��������� ����� �������� ��������� = " << randomNuber(n, m) << "\n\n";
			func = true;
		}
		catch (const invalid_argument& ex) {
			cout << "������ ���������: " << ex.what() << ".\n\n";
		}
		system("pause");
		system("cls");
	} while (func == false);
	func = false;
	// ������ 2.
	cout << "\t������ 2.\n";
	do {
		try {
			if (word_and_size() == true) {
				cout << "������! �������� ����� ����� �������� �����.\n\n";
				func = true;
			}
			else {
				cout << "�� ������! �������� ����� �� ����� �������� �����.\n\n";
				func = true;
			}
		}
		catch (const runtime_error& ex) {
			cout << "������: " << ex.what() << ".\n\n";
		}
		system("pause");
		system("cls");
	} while (func == false);

	return 0;
}