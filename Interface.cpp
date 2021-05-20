#include "Interface.h"


double get_double() {
	double input = 0;
	cin >> input;
	while (cin.fail()) {
		while ((getchar() != '\n'));
		cin.clear();
		cout << "������� �����." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
	return input;
}

int get_int() {
	int input = 0;
	cin >> input;
	while (cin.fail()) {
		while (getchar() != '\n');
		cin.clear();
		cout << "������� �����." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
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
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			output_file_matrix >> arr(i, j);
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
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << i + 1 << " ������, " << j + 1 << " �������: ";
			arr(i,j) = get_double();
		}
	}
	cout << "��o� ��������" << endl;
}

void output_arr(Matrix& arr) {
	for (int i = 0; i < arr.get_row(); i++) {
		for (int j = 0; j < arr.get_col(); j++) {
			cout << setw(3)
			 <<  arr(i, j) << " ";
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
		<< "[2] - ��� ����� ������� �� �����" << endl;
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
		else cout << "������� ���� 1, ���� 2." << endl;
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
path:cout << "������� ���� �����, � ������� ��������� ������." << endl << "�������: C:\\\\�����1(���� ����������)\\\\"
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
				 goto path;
				 break;
			 }
			 else
				 cout << "������� 1, ���� 2";
		 }
	 }
	 ofstream result_file(name, ofstream::app);
	 error_code ec;
	 if (!is_regular_file(name, ec)) {
		 cout << "����� �������� ������������ ��������. ��������� ����." << endl;
		 ec.clear();
		 goto path;
	 }
	 result_file.close();
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
			cout << "������� ���� 0, ���� 1." << endl;
		}
	}
}

