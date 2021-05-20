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
	for (int i = 0; i < col; i++) {
		if (!(i % odd_col == 0)) {
		for (int j = 0; j < row; j++) {
				col_sort[odd_index] = arr(j, i);
				odd_index++;
			}
		 Sorting(col_sort, odd_index, comparisons, permutations);
		 odd_index = 0;
		  for (int j = 0; j < row; j++) {
			 t_arr(j, i) = col_sort[odd_index];
			 odd_index++;
		  }
		 odd_index = 0;
		}
	}
	output_arr(t_arr);
	cout << "+ каждая строка по убыванию: " << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			row_sort[j] = t_arr(i, j);
		}
		Sorting(row_sort, col, comparisons, permutations);
		for (int j = 0; j < col; j++) {
			t_arr(i, j) = row_sort[j];
		}
	}
	output_arr(t_arr);
	cout << "Количество перестановок: " << permutations << endl << "Количество сравнений: " << comparisons << endl;
	cout << "- - - - - - - - - - - -"  << endl;

}

void Bubble_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	for (int i = 0; i < length; i++) {
		for (int j = (length - 1); j > i; j--) {
			if (arr[j] > arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				permutations++;
				comparisons++;
			}
			comparisons++;
		}
		comparisons++;
	}
}

void Selection_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	for (int i = 0; i < length; i++) {
		comparisons++;
		int biggest_index = i;
		for (int current_index = i; current_index < length; current_index++) {
			comparisons++;
			if (arr[current_index] > arr[biggest_index]) {
				biggest_index = current_index;
			}
			comparisons++;
		}
		swap(arr[i], arr[biggest_index]);
		permutations++;
	}
}

void Insert_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	int j = 0;
	int tmp = 0;
	for (int i = 0; i < length; i++) {
		comparisons++;
		tmp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] < tmp; j--) {
			arr[j + 1] = arr[j];
			comparisons += 2;
		}
		arr[j + 1] = tmp;
		permutations++;
	}
}

void Shell_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	int d = length / 2;
	while (d >= 1) {
		comparisons++;
		for (int i = d; i < length; i++) {
			comparisons++;
			int j = i;
			while ((j >= d) && (arr[j - d] < arr[j])) {
				swap(arr[j], arr[j - d]);
				j = j - d;
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
		Sorting(arr, length - left_border, comparisons, permutations);
//		Sorting_increase(&arr[i], length - i, comparisons, permutations);
	}
	comparisons++;
}

