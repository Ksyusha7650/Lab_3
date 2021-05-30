#include "Interface.h"
#include "Array.h" 
#include "sorting.h"

using namespace std;
using namespace filesystem;

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
	bool repeat = true;
	do {
		repeat = false;
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
		Output_file_elements file_elements;
		if (!(repeat)) {
			output_file_matrix >> col >> row;
			int AMOUNT_DATA = abs(col * row);
			file_elements.set_size(AMOUNT_DATA);
			for (int index = 0; index < AMOUNT_DATA; index++) {
				if (!(output_file_matrix >> file_elements[index])) {
					repeat = true;
				}
			}
			if (repeat) cout << "������������ ������." << endl;
			else {
				if (row <= 0) {
					cout << "���������� ����� ������ ���� ������ ����." << endl;
					repeat = true;
				}
				if (col <= 0) {
					cout << "���������� �������� ������ ���� ������ ����." << endl;
					repeat = true;
				}
				if (!(repeat)) {
					arr.set_size(col, row);
					t_arr.set_size(col, row);
					int index = 0;
					for (int rows = 0; rows < row; rows++) {
						for (int columns = 0; columns < col; columns++) {
							arr(rows, columns) = file_elements[index];
							index++;
						}
					}
				}
			}
		}
	} while (repeat);
    
}

void user_input(Matrix& arr, Matrix& t_arr, int& col, int& row) {
	cout << "������� ������ �������." << endl
		<< "���������� �����: ";
	while (true) {
		row = get_int();
		if (row <= 0) cout << "���������� ����� ������ ���� ������ ����." << endl;
		else break;
	}
	cout << "���������� ��������: ";
	while (true) {
		col = get_int();
		if (col <= 0) cout << "���������� �������� ������ ���� ������ ����." << endl;
		else break;
	}
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

void results(Matrix& arr, Bubble_sort& bubble, Selection_sort& selection, Insert_sort& insert, Shell_sort& shell, Quick_sort& quick) {
	cout << "��������������� �������: " << endl;
	output_arr(arr);
	cout << "--------------------" << endl;
	cout << "������������� �������: " << endl;
	cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
	cout << "|                          |               |                 |" << endl;
	cout << "|     ������ ����������    |   ���������   |  ������������   |" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "|       �����������        |" << setw(9) << bubble.get_comparisons() << "      |" << setw(9) << bubble.get_permutations() << "        |" << endl;
	cout << "|       ����������         |               |                 |" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "|      ����������          |" << setw(9) << insert.get_comparisons() << "      |" << setw(9) << insert.get_permutations() << "        |" << endl;
	cout << "|       �������            |               |                 |" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "|      ����������          |" << setw(9) << selection.get_comparisons() << "      |" << setw(9) << selection.get_permutations() << "        |" << endl;
	cout << "|       �������            |               |                 |" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "|      ����������          |" << setw(9) << shell.get_comparisons() << "      |" << setw(9) << shell.get_permutations() << "        |" << endl;
	cout << "|         �����            |               |                 |" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "|       �������            |" << setw(9) << quick.get_comparisons() << "      |" << setw(9) << quick.get_permutations() << "        |" << endl;
	cout << "|      ����������          |               |                 |" << endl;
	cout << "|                          |               |                 |" << endl;
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

void save_file(Matrix& arr, Matrix& arr_t, Bubble_sort& bubble, Selection_sort& selection, Insert_sort& insert, Shell_sort& shell, Quick_sort& quick) {
	cout << "��������� ����������?" << endl
		<< "�������� ����� ����:" << endl;
	cout << "[1] - ���������" << endl << "[2] - ����������" << endl;
	bool save_text = false;
	while (true) {
		int save = get_int();
		if (save == YES) {
			save_text = true;
			break;
		}
		else if (save == NO) {
			cout << "�� ������� ���������� ����������." << endl;
			cout << "- - - - - - - - - -" << endl;
			break;
		}
		else cout << "������� ���� 1, ���� 2." << endl;
	}
	string name = "";
	if (save_text) {
		cout << "���� ��������� ����������?" << endl;
		result_file_name(name);
		ofstream result_file(name);
		result_file.clear();
		result_file << "�������� �������: " << endl;
		for (int rows = 0; rows < arr.get_row(); rows++) {
			for (int columns = 0; columns < arr.get_col(); columns++) {
				result_file <<  arr(rows, columns) << "   ";
			}
			result_file << endl;
		}
		result_file << "��������������� �������: " << endl;
		for (int rows = 0; rows < arr_t.get_row(); rows++) {
			for (int columns = 0; columns < arr_t.get_col(); columns++) {
				result_file << arr_t(rows, columns) << "   ";
			}
			result_file << endl;
		}
		result_file << "--------------------" << endl;
		result_file << "��������� � ������������: " << endl;
		result_file << "����������� ����������: " << bubble.get_comparisons() << " " << bubble.get_permutations() << " " << endl;
		result_file << "���������� �������: " << insert.get_comparisons() << " " << insert.get_permutations() << " " << endl;
		result_file << "���������� �������: " << selection.get_comparisons() << " " << selection.get_permutations() << " " << endl;
		result_file << "���������� �����: " << shell.get_comparisons() << " " << shell.get_permutations() << " " << endl;
		result_file << "������� ����������: " << quick.get_comparisons() << " " << quick.get_permutations() << " " << endl;
		cout << "������ ���������." << endl;
		cout << "- - - - - - - - - -" << endl;
	}
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
	cout << "��������� ���������? " << endl;
	cout << "�������� ����� ����:" << endl
		<< "[1] - ��������� ���������" << endl << "[2] - ��������� ���������" << endl;
	while (true) {
		int end = get_int();
		switch (end) {
		case END:
			cout << "��������� �����������..." << endl;
			return true;
			break;
		case CONTINUE:
			cout << "�� ������� ��������� ���������: " << endl;
			return false;
			break;
		default:
			cout << "������� ���� 1, ���� 2." << endl;
		}
	}
}
