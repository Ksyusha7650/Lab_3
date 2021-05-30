#include "Main.h"
#include "Array.h"
#include "Interface.h"
#include "sorting.h"
#include "Test.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	greetings();
	bool end = false;
	int col = 0, mode = 0, row = 0;
	Matrix arr, t_arr;
	Bubble_sort bubble;
	Selection_sort selection;
	Insert_sort insert;
	Shell_sort shell;
	Quick_sort quick;
	srand(static_cast<unsigned char>(time(NULL)));
	do {
		if (test_or_try()) run_tests();
		else {
			for (int index = 0; index < 5; index++) {
				
			}
			input_types(arr, t_arr, row, col, mode);
			bubble.sort(arr, t_arr, arr.get_row(), arr.get_col());
			insert.sort(arr, t_arr, arr.get_row(), arr.get_col());
			selection.sort(arr, t_arr, arr.get_row(), arr.get_col());
			shell.sort(arr, t_arr, arr.get_row(), arr.get_col());
			quick.sort(arr, t_arr, arr.get_row(), arr.get_col());
			results(t_arr, bubble, selection, insert, shell, quick);
			save_file(arr, t_arr, bubble, selection, insert, shell, quick);
		}
		end = end_program();
		update_dates(bubble, insert, selection, shell, quick);
	} while (end != true);
}

