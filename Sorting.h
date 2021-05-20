#pragma once
#include "Array.h"
#include "Main.h"

class ISort {
protected:
	int comparisons = 0;
	int permutations = 0;
public:
	void Sort(Matrix& arr, Matrix& t_arr, int row, int col, int kind_sort);
	virtual void Sorting(double arr[], int length, int& comparisons, int& permutations) = 0;
	int get_comparisons(){
		return comparisons;
	}
	int get_permutations() {
		return permutations;
	}
};

 class Bubble_sort final: public ISort {
	void Sorting(double arr[], int length, int& comparisons, int& permutations);
};

class Selection_sort final: public ISort {
	void Sorting(double arr[], int length, int& comparisons, int& permutations);
};

class Insert_sort final: public ISort {
	void Sorting(double arr[], int length, int& comparisons, int& permutations);
};

class Shell_sort final: public ISort {
	void Sorting(double arr[], int length, int& comparisons, int& permutations);
};

class Quick_sort final: public ISort {
	void Sorting(double arr[], int length, int& comparisons, int& permutations);
};

enum {
	BUBBLE, SELECTION, INSERT, SHELL, QUICK
};
