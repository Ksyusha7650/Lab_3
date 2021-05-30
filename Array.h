#pragma once
class Matrix {
private:
	double** arr;
	int c_col, c_row;

public:

	double& operator () (const int row, const int col) {
		return arr [row][col];
	}
	int get_col() {
		return c_col;
	}
	int get_row() {
		return c_row;
	}
	void set_size(int col_t, int row_t) {
		c_col = col_t;
		c_row = row_t;
		arr = new double*[c_row];
		for (int rows = 0; rows < c_row; rows++) {
			arr[rows] = new double[c_col];
		}
	}

	void copy(Matrix& new_arr) {
		c_row = new_arr.c_row;
		c_col = new_arr.c_col;
		set_size(c_col, c_row);
		for (int rows = 0; rows < c_row; rows++) {
			for (int columns = 0; columns < c_col; columns++) {
				arr[rows][columns] = new_arr.arr[rows][columns];
			}
		}
	}

	~Matrix() {
		{
			for (int index = 0; index < c_row; index++) {
				delete[] arr[index];
			}
			delete[] arr;
			c_col = -1;
			c_row = -1;
		}
	}
};



	

