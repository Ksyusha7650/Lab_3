#include "Interface.h"

double get_double() {
	double input = 0;
	cin >> input;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� �����." << endl;
		cin >> input;
	}
	return input;
}

int get_int() {
	int input = 0;
	cin >> input;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� �����." << endl;
		cin >> input;
	}
	return input;
}

void input_file(Matrix& arr, Matrix& t_arr, int& col, int& row) {
	cout << "������� ���� ����� � ��������." << endl
		<< "�������: C:\\\\�����1(���� ����������)\\\\�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl
		<< "���� ������� ������ �������� �����, ���� �� � ����� ����� �������."
		<< endl;
	string name;
	while (true) {
		cin >> name;
		ofstream output_file_text(name, ofstream::app);
		error_code ec;
		if (!is_regular_file(name, ec)) {
			cout << "����� �������� ������������ ��������. ��������� ����." << endl;
			ec.clear();
		}
		else break;
		output_file_text.close();
	}
	ifstream output_file_matrix(name);
	output_file_matrix >> row >> col;
	arr.set_size(col, row);
	t_arr.set_size(col, row);
	for (int rows = 0; rows < row; rows++) {
		for (int columns = 0; columns < col; columns++) {
			output_file_matrix >> arr(rows, columns);
		}
	}
    
}

void user_input(Matrix& arr, Matrix& t_arr, int& col, int& row) {
	cout << "������� ������ �������." << endl
		<< "���������� �����: ";
	cin >> row;
	cout << "���������� ��������: ";
	cin >> col;
	cout << "--------------------" << endl;
	arr.set_size(col, row);
	t_arr.set_size(col, row);
	for (int rows = 0; rows < row; rows++) {
		for (int columns = 0; columns < col; columns++) {
			cout << rows + 1 << " ������, " << columns + 1 << " �������: ";
			arr(rows,columns) = get_double();
		}
	}
	cout << "��o� ��������" << endl;
}

void generation_input(Matrix& arr, Matrix& t_arr, int& col, int& row) {
	const int MIN_COL = 1;
	const int MAX_COL = 10;
	const int MIN_ROW = 1;
	const int MAX_ROW = 10;
	const int MIN_ELEMENT = -5;
	const int MAX_ELEMENT = 15;
	col = rand() % MAX_COL + MIN_COL;
	row = rand() % MAX_ROW + MIN_ROW;
	cout << "���������� �����: " << row << endl;
	cout << "���������� ��������: " << col << endl;
	cout << "--------------------" << endl;
	arr.set_size(col, row);
	t_arr.set_size(col, row);
	for (int rows = 0; rows < row; rows++) {
		for (int columns = 0; columns < col; columns++) {
			arr(rows, columns) = rand() % MAX_ELEMENT + MIN_ELEMENT;
		}
	}
}

void output_arr(Matrix& arr) {
	for (int rows = 0; rows < arr.get_row(); rows++) {
		for (int columns = 0; columns < arr.get_col(); columns++) {
			cout << setw(3)
			 <<  arr(rows, columns) << " ";
		}
		cout << endl;
	}
}

void results(Bubble_sort& bubble, Selection_sort& selection, Insert_sort& insert, Shell_sort& shell, Quick_sort& quick) {
	cout << "������������� �������: " << endl;
	cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
	cout << "|                          |               |                 |\n";
	cout << "|     ������ ����������    |   ���������   |  ������������   |\n";
	cout << "|                          |               |                 |\n";
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|                          |               |                 |\n";
	cout << "|       �����������        |" << setw(9) << bubble.get_comparisons() << "      |" << setw(10) << bubble.get_permutations() << "       |\n";
	cout << "|       ����������         |               |                 |\n";
	cout << "|                          |               |                 |\n";
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|                          |               |                 |\n";
	cout << "|      ����������          |" << setw(9) << selection.get_comparisons() << "      |" << setw(10) << selection.get_permutations() << "       |\n";
	cout << "|       �������            |               |                 |\n";
	cout << "|                          |               |                 |\n";
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|                          |               |                 |\n";
	cout << "|      ����������          |" << setw(9) << insert.get_comparisons() << "      |" << setw(9) << insert.get_permutations() << "        |\n";
	cout << "|       �������            |               |                 |\n";
	cout << "|                          |               |                 |\n";
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|                          |               |                 |\n";
	cout << "|      ����������          |" << setw(9) << shell.get_comparisons() << "      |" << setw(9) << shell.get_permutations() << "        |\n";
	cout << "|         �����            |               |                 |\n";
	cout << "|                          |               |                 |\n";
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|                          |               |                 |\n";
	cout << "|       �������            |" << setw(9) << quick.get_comparisons() << "      |" << setw(9) << quick.get_permutations() << "        |\n";
	cout << "|      ����������          |               |                 |\n";
	cout << "|                          |               |                 |\n";
	cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
}

void input_types(Matrix& arr, Matrix& t_arr, int& col, int& row, int& mode) {
	cout << "�������� ������ ���������� �������." << endl
		<< "�������� ����� ����: " << endl << "[1] - ��� ����� �������" << endl
		<< "[2] - ��� ����� ������� �� �����" << endl << "[3] - ��� ��������� �������" << endl;
	while (true) {
		mode = get_int();
		if (mode == MANUAL) {
			user_input(arr, t_arr, col, row);
			cout << "- - - - - - - - - - - -" << endl;
			break;
		}
		if (mode == FILE_INPUT) {
			input_file(arr, t_arr, col, row);
			cout << "- - - - - - - - - - - -" << endl;
			break;
		}
		if (mode == GENERATION) {
			generation_input(arr, t_arr, col, row);
			break;
		}
		else cout << "������� ���� 1, ���� 2, ���� 3." << endl;
	}
	cout << "�������� �������:" << endl;
	output_arr(arr);
	cout << "- - - - - - - - - - - -" << endl;
}



bool test_or_try(void) {
	cout << "�������� ����� ����:" << endl;
	cout << "[1] - �������� �����" << endl;
	cout << "[2] - ��������� ���������" << endl;
	int mode = 0;
	while (!((mode == TEST) || (mode == TRY))) {
		mode = get_int();
		switch (mode) {
		case TEST: return true;
			break;
		case TRY: return false;
			break;
		default: cout << "������� ���� 1, ���� 2." << endl;
		}
	}
	return true;
}

void result_file_name(string& name) {
	bool repeat = true;
	do {
		repeat = false;
		cout << "������� ���� �����, � ������� ��������� ������." << endl << "�������: C:\\\\�����1(���� ����������)\\\\"
			"�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl << "���� ������� ������ �������� �����, ����� �� ����� � ����� ����� �������" << endl;
		cin >> name;
		if (ifstream(name)) {
			cout << "���� ��� ����������." << endl;
			cout << "�������� ����� ����:" << endl;
			cout << "[0] - ������������ ������������ ����" << endl << "[1] - ��������� ����" << endl;
			while (true) {
				int rewrite = get_int();
				if (rewrite == 0) {
					cout << "�� ������� ����� ������������ ����." << endl;
					break;
				}
				if (rewrite == 1) {
					cout << "�� ������� ����� ��������� ����." << endl;
					repeat = true;
					break;
				}
				else
					cout << "������� 1, ���� 2";
			}
		}
		if (!(repeat)) {
			ofstream result_file(name, ofstream::app);
			error_code ec;
			if (!is_regular_file(name, ec)) {
				cout << "����� �������� ������������ ��������. ��������� ����." << endl;
				ec.clear();
				repeat = true;
			}
			result_file.close();
		}
	} while (repeat);
}


void greetings() {
	cout << "��������� ��������� ������� ������ ����������." << endl << "������: 404." << endl << "�������: 22." << endl <<
		"������ ����� 22:" << endl <<
		"����������� ������ ������ ������� �� ��������, ������ ������ �� ��������." << endl;
}


bool end_program() {
	cout << "��������� ���������? " << endl << "������� 0 ��� ����������." << endl << "������� 1 ��� �������." << endl;
	bool repeat = true;
	do {
		repeat = false;
		int end = get_int();
		switch (end) {
		case END:
			cout << "��������� �����������..." << endl;
			break;
		case CONTINUE:
			cout << "�� ������� ��������� ���������: " << endl;
			break;
		default:
			cout << "������� ���� 0, ���� 1." << endl;
			repeat = true;
		}
		return !(end);
	} while (repeat);
}

