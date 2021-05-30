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
	bool repeat = true;
	do {
		repeat = false;
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
			if (repeat) cout << "Некорректные данные." << endl;
			else {
				if (row <= 0) {
					cout << "Количество строк должно быть больше нуля." << endl;
					repeat = true;
				}
				if (col <= 0) {
					cout << "Количество столбцов должно быть больше нуля." << endl;
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
	cout << "Введите размер матрицы." << endl
		<< "Количество строк: ";
	while (true) {
		row = get_int();
		if (row <= 0) cout << "Количество строк должно быть больше нуля." << endl;
		else break;
	}
	cout << "Количество столбцов: ";
	while (true) {
		col = get_int();
		if (col <= 0) cout << "Количество столбцов должно быть больше нуля." << endl;
		else break;
	}
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

void results(Matrix& arr, Bubble_sort& bubble, Selection_sort& selection, Insert_sort& insert, Shell_sort& shell, Quick_sort& quick) {
	cout << "Отсортированная матрица: " << endl;
	output_arr(arr);
	cout << "--------------------" << endl;
	cout << "Сравнительная таблица: " << endl;
	cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
	cout << "|                          |               |                 |" << endl;
	cout << "|     МЕТОДЫ СОРТИРОВКИ    |   СРАВНЕНИЯ   |  ПЕРЕСТАНОВКИ   |" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "|       Пузырьковая        |" << setw(9) << bubble.get_comparisons() << "      |" << setw(9) << bubble.get_permutations() << "        |" << endl;
	cout << "|       сортировка         |               |                 |" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "|      Сортировка          |" << setw(9) << insert.get_comparisons() << "      |" << setw(9) << insert.get_permutations() << "        |" << endl;
	cout << "|       вставки            |               |                 |" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "|      Сортировка          |" << setw(9) << selection.get_comparisons() << "      |" << setw(9) << selection.get_permutations() << "        |" << endl;
	cout << "|       выборки            |               |                 |" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "|      Сортировка          |" << setw(9) << shell.get_comparisons() << "      |" << setw(9) << shell.get_permutations() << "        |" << endl;
	cout << "|         Шелла            |               |                 |" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|" << endl;
	cout << "|                          |               |                 |" << endl;
	cout << "|       Быстрая            |" << setw(9) << quick.get_comparisons() << "      |" << setw(9) << quick.get_permutations() << "        |" << endl;
	cout << "|      сортировка          |               |                 |" << endl;
	cout << "|                          |               |                 |" << endl;
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

void save_file(Matrix& arr, Matrix& arr_t, Bubble_sort& bubble, Selection_sort& selection, Insert_sort& insert, Shell_sort& shell, Quick_sort& quick) {
	cout << "Сохранить результаты?" << endl
		<< "Выберите пункт меню:" << endl;
	cout << "[1] - сохранить" << endl << "[2] - пропустить" << endl;
	bool save_text = false;
	while (true) {
		int save = get_int();
		if (save == YES) {
			save_text = true;
			break;
		}
		else if (save == NO) {
			cout << "Вы выбрали пропустить сохранение." << endl;
			cout << "- - - - - - - - - -" << endl;
			break;
		}
		else cout << "Введите либо 1, либо 2." << endl;
	}
	string name = "";
	if (save_text) {
		cout << "Куда сохранить результаты?" << endl;
		result_file_name(name);
		ofstream result_file(name);
		result_file.clear();
		result_file << "Исходная матрица: " << endl;
		for (int rows = 0; rows < arr.get_row(); rows++) {
			for (int columns = 0; columns < arr.get_col(); columns++) {
				result_file <<  arr(rows, columns) << "   ";
			}
			result_file << endl;
		}
		result_file << "Отсортированная матрица: " << endl;
		for (int rows = 0; rows < arr_t.get_row(); rows++) {
			for (int columns = 0; columns < arr_t.get_col(); columns++) {
				result_file << arr_t(rows, columns) << "   ";
			}
			result_file << endl;
		}
		result_file << "--------------------" << endl;
		result_file << "Сравнения и перестановки: " << endl;
		result_file << "Пузырьковая сортировка: " << bubble.get_comparisons() << " " << bubble.get_permutations() << " " << endl;
		result_file << "Сортировка вставки: " << insert.get_comparisons() << " " << insert.get_permutations() << " " << endl;
		result_file << "Сортировка выборки: " << selection.get_comparisons() << " " << selection.get_permutations() << " " << endl;
		result_file << "Сортировка Шелла: " << shell.get_comparisons() << " " << shell.get_permutations() << " " << endl;
		result_file << "Быстрая сортировка: " << quick.get_comparisons() << " " << quick.get_permutations() << " " << endl;
		cout << "Данные сохранены." << endl;
		cout << "- - - - - - - - - -" << endl;
	}
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
	cout << "Повторить программу? " << endl;
	cout << "Выберите пункт меню:" << endl
		<< "[1] - завершить программу" << endl << "[2] - повторить программу" << endl;
	while (true) {
		int end = get_int();
		switch (end) {
		case END:
			cout << "Программа завершается..." << endl;
			return true;
			break;
		case CONTINUE:
			cout << "Вы выбрали повторить программу: " << endl;
			return false;
			break;
		default:
			cout << "Введите либо 1, либо 2." << endl;
		}
	}
}
