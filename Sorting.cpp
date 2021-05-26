#include "Sorting.h"

void ISort::Sort(Matrix& arr, Matrix& t_arr, int row, int col, int kind_sort) {
	switch (kind_sort) {
	case BUBBLE: cout << "Пузырьковая сортировка." << endl;
		break;
	case SELECTION:cout << "Сортировка выборки." << endl;
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
	for (int index = 0; index < col; index++) {
		if (!(index % odd_col == 0)) {
		for (int columns = 0; columns < row; columns++) {
				col_sort[odd_index] = arr(columns, index);
				odd_index++;

		}
		 Sorting(col_sort, odd_index, comparisons, permutations);
		 odd_index = 0;
		  for (int columns = 0; columns < row; columns++) {
			 t_arr(columns, index) = col_sort[odd_index];
			 odd_index++;
		  }
		 odd_index = 0;
		}
	}
	output_arr(t_arr);
	cout << "+ каждая строка по убыванию: " << endl;
	for (int index = 0; index < row; index++) {
		for (int columns = 0; columns < col; columns++) {
			row_sort[columns] = t_arr(index, columns);
		}
		Sorting(row_sort, col, comparisons, permutations);
		for (int columns = 0; columns < col; columns++) {
			t_arr(index, columns) = row_sort[columns];
		}
	}
	output_arr(t_arr);
	cout << "Количество перестановок: " << permutations << endl << "Количество сравнений: " << comparisons << endl;
	cout << "- - - - - - - - - - - -"  << endl;

}

void Bubble_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	bool is_sorted = true;
	for (int index = 0; index < length; index++) {
		is_sorted = true;
		for (int columns = (length - 1); columns > index; columns--) {
			if (arr[columns] > arr[columns - 1]) {
				swap(arr[columns], arr[columns - 1]);
				permutations++;
				is_sorted = false;
			}
			comparisons++;
		}
		if (is_sorted) break;
	}
}

void Insert_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	int current_index = 0;
	for (int index = 1; index < length; index++) {
		comparisons++;
		for (current_index = index; current_index > 0 && arr[current_index - 1] < arr[current_index]; current_index--) {
			swap(arr[current_index - 1], arr[current_index]);
			permutations++;
		}
	}
}


void Selection_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	for (int index = 0; index < length; index++) {
		int biggest_index = index;
		for (int current_index = index; current_index < length; current_index++) {
			comparisons++;
			if (arr[current_index] > arr[biggest_index]) {
				biggest_index = current_index;
			}
		}
		if (arr[index] < arr[biggest_index]) {
			swap(arr[index], arr[biggest_index]);
			permutations++;
		}
	}
	comparisons-=length;
}

void Shell_sort::Sorting(double arr[], int length, int& comparisons, int& permutations) {
	int second_element = length / 2;
	while (second_element > 0) {
		for (int index = second_element; index < length; index++) {
			int current_index = index;
			if (!(arr[current_index - second_element] < arr[current_index])) comparisons++;
			while ((current_index >= second_element) && (arr[current_index - second_element] < arr[current_index])) {
				swap(arr[current_index], arr[current_index - second_element]);
				current_index = current_index - second_element;
				comparisons += 2;
				permutations++;
			}
		}
		second_element = second_element / 2;
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
			if (arr[left_border] < arr[right_border]) {
				swap(arr[left_border], arr[right_border]);
				permutations++;
			}
			comparisons++;
			left_border++;
			right_border--;
		}
		
		
	} while (left_border <= right_border);
	if (right_border > 0) {
		Sorting(arr, right_border + 1, comparisons, permutations);
	}
	if (left_border < length) {
		Sorting(&arr[left_border], length - left_border, comparisons, permutations);
	}
}
void update_dates(Bubble_sort& bubble, Insert_sort& insert, Selection_sort& selection, Shell_sort& shell, Quick_sort& quick) {
	bubble.update_dates();
	selection.update_dates();
	insert.update_dates();
	shell.update_dates();
	quick.update_dates();
}

