#include "Sorting.h"

void ISort::Sort(Matrix& arr, Matrix& t_arr, int row, int col, int kind_sort) {
	switch (kind_sort) {
	case BUBBLE: cout << "Пузырьковая сортировка." << endl;
		break;
	case SELECTION:cout << "Сортировка отбора." << endl;
		break;
	case INSERT: cout << "Сортировка вставки." << endl;
		break;
	case SHELL: cout << "Сортировка Шелла." << endl;
		break;
	case QUICK:cout << "Быстрая сортировка." << endl;
		break;
	}
	cout << "- - - - - - - - - - - -" << endl;
	t_arr.copy(arr);
	cout << "Каждый четный столбец по убыванию: " << endl;
	const int odd_col = 2;
	int odd_index = 0;
	double* col_sort = new double[row];
	double* row_sort = new double[col];
	for (int rows = 0; rows < col; rows++) {
		if (!(rows % odd_col == 0)) {
		for (int columns = 0; columns < row; columns++) {
				col_sort[odd_index] = arr(columns, rows);
				odd_index++;
			}
		 Sorting(col_sort, odd_index, comparisons, permutations);
		 odd_index = 0;
		  for (int columns = 0; columns < row; columns++) {
			 t_arr(columns, rows) = col_sort[odd_index];
			 odd_index++;
		  }
		 odd_index = 0;
		}
	}
	output_arr(t_arr);
	cout << "+ каждая строка по убыванию: " << endl;
	for (int rows = 0; rows < row; rows++) {
		for (int columns = 0; columns < col; columns++) {
			row_sort[columns] = t_arr(rows, columns);
		}
		Sorting(row_sort, col, comparisons, permutations);
		for (int columns = 0; columns < col; columns++) {
			t_arr(rows, columns) = row_sort[columns];
		}
	}
	output_arr(t_arr);
	cout << "Количество перестановок: " << permutations << endl << "Количество сравнений: " << comparisons << endl;
	cout << "- - - - - - - - - - - -"  << endl;

}

void Bubble_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	for (int rows = 0; rows < length; rows++) {
		for (int columns = (length - 1); columns > rows; columns--) {
			if (arr[columns] > arr[columns - 1]) {
				swap(arr[columns], arr[columns - 1]);
				permutations++;
				comparisons++;
			}
			comparisons++;
		}
		comparisons++;
	}
}

void Selection_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	for (int rows = 0; rows < length; rows++) {
		comparisons++;
		int biggest_index = rows;
		for (int current_index = rows; current_index < length; current_index++) {
			comparisons++;
			if (arr[current_index] > arr[biggest_index]) {
				biggest_index = current_index;
			}
			comparisons++;
		}
		swap(arr[rows], arr[biggest_index]);
		permutations++;
	}
}

void Insert_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	int columns = 0;
	int tmp = 0;
	for (int rows = 0; rows < length; rows++) {
		comparisons++;
		tmp = arr[rows];
		for (columns = rows - 1; columns >= 0 && arr[columns] < tmp; columns--) {
			arr[columns + 1] = arr[columns];
			comparisons += 2;
		}
		arr[columns + 1] = tmp;
		permutations++;
	}
}

void Shell_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	int d = length / 2;
	while (d >= 1) {
		comparisons++;
		for (int rows = d; rows < length; rows++) {
			comparisons++;
			int columns = rows;
			while ((columns >= d) && (arr[columns - d] < arr[columns])) {
				swap(arr[columns], arr[columns - d]);
				columns = columns - d;
				comparisons += 2;
				permutations++;
			}
		}
		d = d / 2;
	}
}

void Quick_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	int left_border = 0;
	int right_border = length - 1;
	int key_element = arr[length / 2];
	do {
		while (arr[left_border] > key_element) {
			comparisons++;
			left_border++;
		}
		while (arr[right_border] < key_element) {
			comparisons++;
			right_border--;
		}
		if (left_border <= right_border) {
			swap(arr[left_border], arr[right_border]);
			left_border++;
			right_border--;
			permutations++;
		}
		comparisons++;
	} while (left_border <= right_border);
	if (right_border > 0) {
		Sorting(arr, right_border + 1, comparisons, permutations);
	}
	comparisons++;
	if (left_border < length) {
		Sorting(&arr[left_border], length - left_border, comparisons, permutations);
	}
	comparisons++;
}

