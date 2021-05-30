#pragma once
#include "Array.h"
#include "Main.h"
#include "Interface.h"



class Isort {
protected:
	int c_comparisons = 0;
	int c_permutations = 0;
	virtual void sorting(double arr[], int length, int& comparisons, int& permutations) = 0;
public:
	void sort(Matrix& arr, Matrix& t_arr, int row, int col);
	
	int get_comparisons(){
		return c_comparisons;
	}
	int get_permutations() {
		return c_permutations;
	}
	void update_dates() {
		c_comparisons = 0;
		c_permutations = 0;
	}

	
};



 class Bubble_sort final: public Isort {
	void sorting(double arr[], int length, int& comparisons, int& permutations);
};

class Selection_sort final: public Isort {
	void sorting(double arr[], int length, int& comparisons, int& permutations);
};

class Insert_sort final: public Isort {
	void sorting(double arr[], int length, int& comparisons, int& permutations);
};

class Shell_sort final: public Isort {
	void sorting(double arr[], int length, int& comparisons, int& permutations);
};

class Quick_sort final: public Isort {
	void sorting(double arr[], int length, int& comparisons, int& permutations);
};

enum {
	BUBBLE, SELECTION, INSERT, SHELL, QUICK
};

void update_dates(Bubble_sort& bubble, Insert_sort& insert, Selection_sort& selection, Shell_sort& shell, Quick_sort& quick);