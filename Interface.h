#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "Main.h"
#include "Array.h"

class Output_file_elements {
private:
	double* arr_elements;
	int arr_elements_size;

public:
	double& operator[] (const int index) {
		return arr_elements[index];
	}
	int get_size() {
		return arr_elements_size;
	}
	void set_size(int size) {
		arr_elements_size = size;
		arr_elements = new double[arr_elements_size];
	}

	~Output_file_elements() {
		delete[]arr_elements;
	}
};



class Bubble_sort;
class Selection_sort;
class Insert_sort;
class Shell_sort;
class Quick_sort;

enum Actions {
	END = 0, CONTINUE,
	MANUAL = 1, FILE_INPUT, GENERATION,
	YES = 1, NO,
	TEST = 1, TRY
};

int get_int();
double get_double();
void greetings();
bool end_program();
void result_file_name(std:: string& name);
bool test_or_try(void);
void input_types(Matrix& arr, Matrix& t_arr, int& col, int& row, int& mode);
void output_arr(Matrix& arr);
void results(Matrix& arr,Bubble_sort& bubble, Selection_sort& selection, Insert_sort& insert, Shell_sort& shell, Quick_sort& quick);
void generation_input(Matrix& arr, Matrix& t_arr, int& col, int& row);
void save_file(Matrix& arr, Matrix& arr_t, Bubble_sort& bubble, Selection_sort& selection, Insert_sort& insert, Shell_sort& shell, Quick_sort& quick);