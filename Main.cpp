#include "Main.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	greetings();
	bool end = false;
	int col = 0, mode = 0, row = 0, kind_sort = 0;
	Matrix arr, t_arr;
	Bubble_sort bubble;
	Selection_sort selection;
	Insert_sort insert;
	Shell_sort shell;
	Quick_sort quick;
	srand((unsigned)time(NULL));
	do {
	//	if (test_or_try()) run_tests();
	//	else {
			input_types(arr, t_arr, row, col, mode);
			bubble.Sort(arr, t_arr, arr.get_row(), arr.get_col(), BUBBLE);
			selection.Sort(arr, t_arr, arr.get_row(), arr.get_col(), SELECTION);
			insert.Sort(arr, t_arr, arr.get_row(), arr.get_col(), INSERT);
			shell.Sort(arr, t_arr, arr.get_row(), arr.get_col(), SHELL);
			quick.Sort(arr, t_arr, arr.get_row(), arr.get_col(), QUICK);
			results(bubble, selection, insert, shell, quick);
	//	}
		end = end_program();
	} while (end != true);
}

