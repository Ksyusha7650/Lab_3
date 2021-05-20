#include "Interface.h"


double get_double() {
	double input = 0;
	cin >> input;
	while (cin.fail()) {
		while ((getchar() != '\n'));
		cin.clear();
		cout << "Введите число." << endl;
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
		cout << "Введите число." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
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
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			output_file_matrix >> arr(i, j);
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
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << i + 1 << " строка, " << j + 1 << " столбец: ";
			arr(i,j) = get_double();
		}
	}
	cout << "Ввoд завершен" << endl;
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
		<< "[2] - для ввода матрицы из файла" << endl;
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
		else cout << "Введите либо 1, либо 2." << endl;
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
path:cout << "Введите путь файла, в который запишутся данные." << endl << "Образец: C:\\\\Папка1(если необходимо)\\\\"
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
				 goto path;
				 break;
			 }
			 else
				 cout << "Введите 1, либо 2";
		 }
	 }
	 ofstream result_file(name, ofstream::app);
	 error_code ec;
	 if (!is_regular_file(name, ec)) {
		 cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
		 ec.clear();
		 goto path;
	 }
	 result_file.close();
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
			cout << "Введите либо 0, либо 1." << endl;
		}
	}
}

