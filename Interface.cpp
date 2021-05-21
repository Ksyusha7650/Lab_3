#include "Interface.h"

double get_double() {
	double input = 0;
	cin >> input;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Введите число." << endl;
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
		cout << "Введите число." << endl;
		cin >> input;
	}
	return input;
}

void input_file(Matrix& arr, Matrix& t_arr, int& col, int& row) {
	cout << "Введите путь файла с матрицей." << endl
		<< "Образец: C:\\\\Папка1(если необходимо)\\\\Папка2(если необходимо)\\\\...\\\\Название файла.txt " << endl
		<< "Либо введите просто название файла, если он в папке этого проекта."
		<< endl;
	string name;
	while (true) {
		cin >> name;
		ofstream output_file_text(name, ofstream::app);
		error_code ec;
		if (!is_regular_file(name, ec)) {
			cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
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
	cout << "Введите размер матрицы." << endl
		<< "Количество строк: ";
	cin >> row;
	cout << "Количество столбцов: ";
	cin >> col;
	cout << "--------------------" << endl;
	arr.set_size(col, row);
	t_arr.set_size(col, row);
	for (int rows = 0; rows < row; rows++) {
		for (int columns = 0; columns < col; columns++) {
			cout << rows + 1 << " строка, " << columns + 1 << " столбец: ";
			arr(rows,columns) = get_double();
		}
	}
	cout << "Ввoд завершен" << endl;
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
	cout << "Количество строк: " << row << endl;
	cout << "Количество столбцов: " << col << endl;
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
	cout << "Сравнительная таблица: " << endl;
	cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
	cout << "|                          |               |                 |\n";
	cout << "|     МЕТОДЫ СОРТИРОВКИ    |   СРАВНЕНИЯ   |  ПЕРЕСТАНОВКИ   |\n";
	cout << "|                          |               |                 |\n";
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|                          |               |                 |\n";
	cout << "|       Пузырьковая        |" << setw(9) << bubble.get_comparisons() << "      |" << setw(10) << bubble.get_permutations() << "       |\n";
	cout << "|       сортировка         |               |                 |\n";
	cout << "|                          |               |                 |\n";
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|                          |               |                 |\n";
	cout << "|      Сортировка          |" << setw(9) << selection.get_comparisons() << "      |" << setw(10) << selection.get_permutations() << "       |\n";
	cout << "|       вставки            |               |                 |\n";
	cout << "|                          |               |                 |\n";
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|                          |               |                 |\n";
	cout << "|      Сортировка          |" << setw(9) << insert.get_comparisons() << "      |" << setw(9) << insert.get_permutations() << "        |\n";
	cout << "|       выборки            |               |                 |\n";
	cout << "|                          |               |                 |\n";
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|                          |               |                 |\n";
	cout << "|      Сортировка          |" << setw(9) << shell.get_comparisons() << "      |" << setw(9) << shell.get_permutations() << "        |\n";
	cout << "|         Шелла            |               |                 |\n";
	cout << "|                          |               |                 |\n";
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n";
	cout << "|                          |               |                 |\n";
	cout << "|       Быстрая            |" << setw(9) << quick.get_comparisons() << "      |" << setw(9) << quick.get_permutations() << "        |\n";
	cout << "|      сортировка          |               |                 |\n";
	cout << "|                          |               |                 |\n";
	cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
}

void input_types(Matrix& arr, Matrix& t_arr, int& col, int& row, int& mode) {
	cout << "Выберите способ заполнения матрицы." << endl
		<< "Выберите пункт меню: " << endl << "[1] - для ввода вручную" << endl
		<< "[2] - для ввода матрицы из файла" << endl << "[3] - для генерации матрицы" << endl;
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
		else cout << "Введите либо 1, либо 2, либо 3." << endl;
	}
	cout << "Исходная матрица:" << endl;
	output_arr(arr);
	cout << "- - - - - - - - - - - -" << endl;
}



bool test_or_try(void) {
	cout << "Выберите пункт меню:" << endl;
	cout << "[1] - показать тесты" << endl;
	cout << "[2] - запустить программу" << endl;
	int mode = 0;
	while (!((mode == TEST) || (mode == TRY))) {
		mode = get_int();
		switch (mode) {
		case TEST: return true;
			break;
		case TRY: return false;
			break;
		default: cout << "Введите либо 1, либо 2." << endl;
		}
	}
	return true;
}

void result_file_name(string& name) {
	bool repeat = true;
	do {
		repeat = false;
		cout << "Введите путь файла, в который запишутся данные." << endl << "Образец: C:\\\\Папка1(если необходимо)\\\\"
			"Папка2(если необходимо)\\\\...\\\\Название файла.txt " << endl << "Либо введите просто название файла, тогда он будет в папке этого проекта" << endl;
		cin >> name;
		if (ifstream(name)) {
			cout << "Файл уже существует." << endl;
			cout << "Выберите пункт меню:" << endl;
			cout << "[0] - перезаписать существующий файл" << endl << "[1] - повторить ввод" << endl;
			while (true) {
				int rewrite = get_int();
				if (rewrite == 0) {
					cout << "Вы выбрали опцию перезаписать файл." << endl;
					break;
				}
				if (rewrite == 1) {
					cout << "Вы выбрали опцию повторить ввод." << endl;
					repeat = true;
					break;
				}
				else
					cout << "Введите 1, либо 2";
			}
		}
		if (!(repeat)) {
			ofstream result_file(name, ofstream::app);
			error_code ec;
			if (!is_regular_file(name, ec)) {
				cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
				ec.clear();
				repeat = true;
			}
			result_file.close();
		}
	} while (repeat);
}


void greetings() {
	cout << "Программу выполнила Рухлова Ксения Алексеевна." << endl << "Группа: 404." << endl << "Вариант: 22." << endl <<
		"Задача номер 22:" << endl <<
		"Упорядочить каждый четный столбец по убыванию, каждую строку по убыванию." << endl;
}


bool end_program() {
	cout << "Повторить программу? " << endl << "Введите 0 для завершения." << endl << "Введите 1 для повтора." << endl;
	bool repeat = true;
	do {
		repeat = false;
		int end = get_int();
		switch (end) {
		case END:
			cout << "Программа завершается..." << endl;
			break;
		case CONTINUE:
			cout << "Вы выбрали повторить программу: " << endl;
			break;
		default:
			cout << "Введите либо 0, либо 1." << endl;
			repeat = true;
		}
		return !(end);
	} while (repeat);
}

