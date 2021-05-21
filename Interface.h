#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "Main.h"
#include "Array.h"

using namespace std;
using namespace filesystem;

class Bubble_sort;
class Selection_sort;
class Insert_sort;
class Shell_sort;
class Quick_sort;

enum Actions {
	END = 1, CONTINUE,
	MANUAL = 1, FILE_INPUT, GENERATION,
	YES = 1, NO,
	TEST = 1, TRY
};

int get_int();
double get_double();
void greetings();
bool end_program();
void result_file_name(string& name);
bool test_or_try(void);
void input_types(Matrix& arr, Matrix& t_arr, int& col, int& row, int& mode);
void output_arr(Matrix& arr);
void results(Bubble_sort& bubble, Selection_sort& selection, Insert_sort& insert, Shell_sort& shell, Quick_sort& quick);
void generation_input(Matrix& arr, Matrix& t_arr, int& col, int& row);
