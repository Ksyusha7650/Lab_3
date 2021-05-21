#pragma once
class Matrix {
private:
	double** arr;
	int col, row;

public:

	double& operator () (const int row, const int col) {
		return arr [row][col];
	}
	int get_col() {
		return col;
	}
	int get_row() {
		return row;
	}
	void set_size(int col_t, int row_t) {
		col = col_t;
		row = row_t;
		arr = new double*[row];
		for (int rows = 0; rows < row; rows++) {
			arr[rows] = new double[col];
		}
	}

	void copy(Matrix& new_arr) {
		row = new_arr.row;
		col = new_arr.col;
		set_size(col, row);
		for (int rows = 0; rows < row; rows++) {
			for (int columns = 0; columns < col; columns++) {
				arr[rows][columns] = new_arr.arr[rows][columns];
			}
		}
	}

	~Matrix() {
		{
			for (int index = 0; index < row; index++) {
				delete[] arr[index];
			}
			delete[] arr;
			col = -1;
			row = -1;
		}
	}
};
	

