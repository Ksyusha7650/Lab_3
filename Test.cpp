#include "Test.h"


void update_dates(void) {
	
}
bool Test1(Matrix& arr, Matrix& exp_arr, Matrix& arr_t) {
	Bubble_sort bubble;
	int col = 2;
	int row = 2;
	arr.set_size(col, row);
	arr_t.copy(arr);
	exp_arr.set_size(col, row);
	arr(0, 0) = 1;
	arr(0, 1) = 2;
	arr(1, 0) = 3;
	arr(1, 1) = 4;
	exp_arr(0, 0) = 4;
	exp_arr(0, 1) = 1;
	exp_arr(1, 0) = 3;
	exp_arr(1, 1) = 2;
	bool correct = true;
	bubble.sort(arr, arr_t, row, col);
	for (int rows = 0; rows < arr_t.get_row(); rows++) {
		for (int columns = 0; columns < arr_t.get_col(); columns++) {
			if ((exp_arr(rows, columns) != arr_t(rows, columns)))
				correct = false;
		}
	}
	if (correct) {
		return true;
	}
	else {
		cout << "Тест пузырьковой сортировки не пройден!" << endl;
		cout << "Ожидалась такая матрица: " << endl;
		output_arr(exp_arr);
		cout << "Получилась такая матрица: " << endl;
		output_arr(arr_t);
		return false;
	}
}

bool Test2(Matrix& arr, Matrix& arr_t, Matrix& exp_arr ) {
	Insert_sort insert;
	int col = 2;
	int row = 2;
	arr.set_size(col, row);
	arr_t.copy(arr);
	exp_arr.set_size(col, row);
	arr(0, 0) = 1;
	arr(0, 1) = 2;
	arr(1, 0) = 3;
	arr(1, 1) = 4;
	exp_arr(0, 0) = 4;
	exp_arr(0, 1) = 1;
	exp_arr(1, 0) = 3;
	exp_arr(1, 1) = 2;
	bool correct = true;
	insert.sort(arr, arr_t, row, col);
	for (int rows = 0; rows < arr_t.get_row(); rows++) {
		for (int columns = 0; columns < arr_t.get_col(); columns++) {
			if ((exp_arr(rows, columns) != arr_t(rows, columns)))
				correct = false;
		}
	}
	if (correct) {
		return true;
	}
	else {
		cout << "Тест сортировки вставок не пройден!" << endl;
		cout << "Ожидалась такая матрица: " << endl;
		output_arr(exp_arr);
		cout << "Получилась такая матрица: " << endl;
		output_arr(arr_t);
		return false;
	}
}

bool Test3(Matrix& arr, Matrix& arr_t, Matrix& exp_arr) {
	Selection_sort selection;
	int col = 2;
	int row = 2;
	arr.set_size(col, row);
	arr_t.copy(arr);
	exp_arr.set_size(col, row);
	arr(0, 0) = 1;
	arr(0, 1) = 2;
	arr(1, 0) = 3;
	arr(1, 1) = 4;
	exp_arr(0, 0) = 4;
	exp_arr(0, 1) = 1;
	exp_arr(1, 0) = 3;
	exp_arr(1, 1) = 2;
	bool correct = true;
	selection.sort(arr, arr_t, row, col);
	for (int rows = 0; rows < arr_t.get_row(); rows++) {
		for (int columns = 0; columns < arr_t.get_col(); columns++) {
			if ((exp_arr(rows, columns) != arr_t(rows, columns)))
				correct = false;
		}
	}
	if (correct) {
		return true;
	}
	else {
		cout << "Тест сортировки выборки не пройден!" << endl;
		cout << "Ожидалась такая матрица: " << endl;
		output_arr(exp_arr);
		cout << "Получилась такая матрица: " << endl;
		output_arr(arr_t);
		return false;
	}
}

bool Test4(Matrix& arr, Matrix& arr_t, Matrix& exp_arr) {
	Shell_sort shell;
	int col = 2;
	int row = 2;
	arr.set_size(col, row);
	arr_t.copy(arr);
	exp_arr.set_size(col, row);
	arr(0, 0) = 1;
	arr(0, 1) = 2;
	arr(1, 0) = 3;
	arr(1, 1) = 4;
	exp_arr(0, 0) = 4;
	exp_arr(0, 1) = 1;
	exp_arr(1, 0) = 3;
	exp_arr(1, 1) = 2;
	bool correct = true;
	shell.sort(arr, arr_t, row, col);
	for (int rows = 0; rows < arr_t.get_row(); rows++) {
		for (int columns = 0; columns < arr_t.get_col(); columns++) {
			if ((exp_arr(rows, columns) != arr_t(rows, columns)))
				correct = false;
		}
	}
	if (correct) {
		return true;
	}
	else {
		cout << "Тест сортировки Шелла не пройден!" << endl;
		cout << "Ожидалась такая матрица: " << endl;
		output_arr(exp_arr);
		cout << "Получилась такая матрица: " << endl;
		output_arr(arr_t);
		return false;
	}
}

bool Test5(Matrix& arr, Matrix& arr_t, Matrix& exp_arr) {
	Quick_sort quick;
	int col = 2;
	int row = 2;
	arr.set_size(col, row);
	arr_t.copy(arr);
	exp_arr.set_size(col, row);
	arr(0, 0) = 1;
	arr(0, 1) = 2;
	arr(1, 0) = 3;
	arr(1, 1) = 4;
	exp_arr(0, 0) = 4;
	exp_arr(0, 1) = 1;
	exp_arr(1, 0) = 3;
	exp_arr(1, 1) = 2;
	bool correct = true;
	quick.sort(arr, arr_t, row, col);
	for (int rows = 0; rows < arr_t.get_row(); rows++) {
		for (int columns = 0; columns < arr_t.get_col(); columns++) {
			if ((exp_arr(rows, columns) != arr_t(rows, columns)))
				correct = false;
		}
	}
	if (correct) {
		return true;
	}
	else {
		cout << "Тест быстрой сортировки не пройден!" << endl;
		cout << "Ожидалась такая матрица: " << endl;
		output_arr(exp_arr);
		cout << "Получилась такая матрица: " << endl;
		output_arr(arr_t);
		return false;
	}
}

void run_tests(void) {
	Matrix arr, exp_arr, arr_t;
	Bubble_sort bubble;
	Selection_sort selection;
	Insert_sort insert;
	Shell_sort shell;
	Quick_sort quick;
	if ((Test1(arr, arr_t, exp_arr)) && (Test2(arr, arr_t, exp_arr)) && (Test3(arr, arr_t, exp_arr)) &&
		(Test4(arr, arr_t, exp_arr)) && (Test5(arr, arr_t, exp_arr))) cout << "Все тесты пройдены!" << endl;
}
