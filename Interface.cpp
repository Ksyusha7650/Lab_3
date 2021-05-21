#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <filesystem>
#include <Windows.h>
#include "Interface.h"
#include "Points_array.h"

using namespace std;
using namespace filesystem;

double get_double() {
	double input = 0;
	cin >> input;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� �����." << endl;
		cin >> input;
	}
	return input;
}

int get_int() {
	int input = 0;
	cin >> input;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������� �����." << endl;
		cin >> input;
	}
	return input;
}

Point get_point(const int index) {
	Point point;
	string name_point;
	if (index == CENTER_POINT) name_point = "������ �����";
	else name_point = to_string(index + 1);
	cout << "������� ���������� " << name_point << " ����� �� x: ";
	point.x = get_double();
	cout << "������� ���������� " << name_point << " ����� �� y: ";
	point.y = get_double();
	cout << "������� ���������� " << name_point << " ����� �� z: ";
	point.z = get_double();
	cout << "---------------------------------" << endl;
	return point;
}

void user_input(int& size, Points_class& arr_point, int& radius, Point& center, res_points_class& res_point_arr) {
	cout << "������� ���������� �����." << endl;
	while (true) {
		size = get_int();
		if (size <= 0) {
			cout << "���������� ����� ������ ���� ������ ����." << endl;
		}
		else break;
	}
	arr_point.set_size(size);
	res_point_arr.set_size(size);
	for (int index = 0; index < size; index++) {
		Point new_point = get_point(index);
		arr_point[index] = new_point;
	}
	cout << "������� ������ �����: ";
	while (true) {
		radius = get_int();
		if (radius <= 0) {
			cout << "������ ������ ���� ������ ����." << endl;
		}
		else break;
	}
	cout << "---------------------------------" << endl;
	center = get_point(CENTER_POINT);
}

void generation_input(int& size, Points_class& arr_point, int& radius, Point& center, res_points_class& res_point_arr) {
	const int MIN_SIZE = 1;
	const int MAX_SIZE = 5;
	const int MIN_POINT = -50;
	const int MAX_POINT = 100;
	const int MIN_RADIUS = 50;
	const int MAX_RADIUS = 100;
	size = rand() % MAX_SIZE + MIN_SIZE;
	cout << "���������� �����: " << size << endl;
	arr_point.set_size(size);
	res_point_arr.set_size(size);
	for (int index = 0; index < arr_point.get_size(); index++) {
		arr_point[index].x = (static_cast <double> (rand() % (MAX_POINT - MIN_POINT)) + MIN_POINT);
		arr_point[index].y = (static_cast <double>(rand() % (MAX_POINT - MIN_POINT)) + MIN_POINT);
		arr_point[index].z = (static_cast <double>(rand() % (MAX_POINT - MIN_POINT)) + MIN_POINT);
	}
	radius = ((rand() % (MAX_RADIUS - MIN_RADIUS)) + MIN_RADIUS);
	center.x = (static_cast <double>(rand() % (MAX_POINT - MIN_POINT)) + MIN_POINT);
	center.y = (static_cast <double>(rand() % (MAX_POINT - MIN_POINT)) + MIN_POINT);
	center.z = (static_cast <double>(rand() % (MAX_POINT - MIN_POINT)) + MIN_POINT);
}

void output_point(Point point, const int index) {
	cout << "����� " << index << " � ������������: " << point.x << " ; " << point.y << " ; " << point.z;
}

void output_arr(Points_class& point_arr, int radius, Point center) {
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
	cout << "�������� ������: " << endl;
	cout << "�������� ������ � ������������ �����." << endl;
	for (int index = 0; index < point_arr.get_size(); index++) {
		output_point(point_arr[index], index + 1);
		cout << endl;
	}
	cout << "������ �����: " << radius << endl;
	cout << "����� �����: " << center.x << " ; " << center.y << " ; " << center.z << endl;
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
}

void res_output_arr(Points_class& point_arr, res_points_class& res_point_arr, HANDLE handle) {
	cout << "������������ ������ � ������������ �����." << endl;
	for (int index = 0; index < res_point_arr.get_size(); index++) {
		if (res_point_arr[index] == FALL) {
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			output_point(point_arr[index], index + 1);
			cout << " - ��������." << endl;
		}
		else {
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			output_point(point_arr[index], index + 1);
			cout << " - �� ��������." << endl;
		}
	}
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
}

bool show_or_try(void) {
	cout << "��� ����, ����� �������� ����� ������� 1." << endl;
	cout << "��� ����, ����� ��������� ��������� ������� 2." << endl;
	int mode = 0;
	while (!((mode == TEST) || (mode == TRY))) {
		mode = get_int();
		switch (mode) {
		case TEST: return true;
			break;
		case TRY: return false;
			break;
		default: cout << "������� ���� 1, ���� 2." << endl;
		}
	}
	return true;
}

void create_file(int mode, Points_class& point_arr, res_points_class& res_point_arr, int& size, int& radius, Point& center) {
	if (mode == READ_POINTS) {
		bool repeat = true;
		do {
			repeat = false;
			cout << "������� ���� �����, �� �������� ������� ������." << endl
				<< "�������: C:\\\\�����1(���� ����������)\\\\�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl
				<< "���� ������� ������ �������� �����, ���� �� � ����� ����� �������."
				<< endl;
			string name = "";
			cin >> name;
			fstream output_file(name);
			output_file >> size;
			output_file_points file_points;
			int AMOUNT_DATA = QUANTITY_COORDINATES * (size - CENTER_POINT) + SIZE_BYTE;
			file_points.set_size(AMOUNT_DATA);
			for (int index = 0; index < AMOUNT_DATA; index++) {
				if (!(output_file >> file_points[index])) {
					repeat = true;
				}
			}
			if (repeat) cout << "������������ ������." << endl;
			else {
				if (size <= 0) {
					cout << "���������� ����� ������ ���� ������ ����." << endl;
					repeat = true;
				}
				if (!(repeat)) {
					for (int index = 0; index < AMOUNT_DATA; index++) {
						output_file >> file_points[index];
					}
					int file_index = 0;
					point_arr.set_size(size);
					res_point_arr.set_size(size);
					for (int index = 0; index < size; index++) {
						point_arr[index].x = file_points[file_index];
						point_arr[index].y = file_points[file_index + 1];
						point_arr[index].z = file_points[file_index + 2];
						file_index += QUANTITY_COORDINATES;
					}
					radius = (int)(file_points[size*QUANTITY_COORDINATES]);
					if (radius <= 0) {
						cout << "������ ����� ������ ���� ������ ����." << endl;
						repeat = true;
					}
					center.x = file_points[AMOUNT_DATA - 3];
					center.y = file_points[AMOUNT_DATA - 2];
					center.z = file_points[AMOUNT_DATA - 1];
					output_file.close();

				}
			}
		} while (repeat);
	}
	else {
		bool repeat = true;
		do {
			repeat = false;
			cout << "������� ���� �����, � ������� ��������� ������." << endl << "�������: C:\\\\�����1(���� ����������)\\\\"
				"�����2(���� ����������)\\\\...\\\\�������� �����.txt " << endl << "���� ������� ������ �������� �����, ����� �� ����� � ����� ����� �������."
				<< endl;
			string name = "";
			cin >> name;
			if (ifstream(name)) {
				int rewrite = 0;
				cout << "���� ��� ����������." << endl;
				cout << "������� 0 ��� ����, ����� ������������ ������������ ����." << endl;
				cout << "������� 1 ��� ����, ����� ��������� ����." << endl;
				while (true) {
					rewrite = get_int();
					if (rewrite == REWRITE) {
						cout << "�� ������� ����� ������������ ����." << endl;
						break;
					}
					else if (rewrite == REPEAT) {
						cout << "�� ������� ����� ��������� ����." << endl;
						repeat = true;
						break;
					}
					else  cout << "������� 0, ���� 1" << endl;
				}
			}
			if (!(repeat)) {
				ofstream result_file(name, ofstream::app);
				error_code ec;
				if (!is_regular_file(name, ec)) {
					cout << "����� �������� ������������ ��������. ��������� ����." << endl;
					ec.clear();
					repeat = true;
				}
				if (!(repeat)) {
					result_file.clear();
					switch (mode) {
					case DATA:
						result_file << size << " ";
						for (int index = 0; index <= size; index++) {
							if (index != size)
								result_file << point_arr[index].x << " " << point_arr[index].y << " " << point_arr[index].z << " ";
							else  result_file << radius << " " << center.x << " " << center.y << " " << center.z << " ";
						}
						break;
					case RESULT:
						result_file
							<< "��������� ���������. " << endl
							<< "������������ ������ � ������������ �����:" << endl;
						for (int index = 0; index < res_point_arr.get_size(); index++) {
							if (res_point_arr[index] == FALL) {
								result_file << "����� " << index + 1 << "� ������������: " << point_arr[index].x << " ; " << point_arr[index].y << " ; " << point_arr[index].z
									<< " - ��������." << endl;
							}
							else {
								result_file << "����� " << index + 1 << " � ������������: " << point_arr[index].x << " ; " << point_arr[index].y << " ; " << point_arr[index].z
									<< " - �� ��������." << endl;
							}
						}
						cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;

						break;
					}
					result_file.close();
				}
			}
		} while (repeat);
	}
}

void greetings() {
	cout << "��������� ��������� ������� ������ ����������." << endl << "������: 404." << endl << "�������: 22." << endl <<
		"������ ����� 2:" << endl <<
		"� ���������� ������������ ����� ������ ����� (�������� �������� X, Y, Z) � �����(����� � ������). " << endl
		<< "�������� ���������, ��������� ����� (�� ����������), ������� �������� � �������� ������������� �����."
		<< endl;
}

void input_types(Points_class& arr_point, res_points_class& res_arr_point, int& size, int& mode, int& radius, Point& center) {
	cout << "�������� ������ ���������� ������� �����:" << endl << "������� 1 ��� ����� �������." << endl
		<< "������� 2 ��� ��������� ��������� ���������." << endl << "������� 3 ��� ������������� �������� ������ �� �����." << endl;
	bool repeat = true;
	do {
		repeat = false;
		int menu_type = get_int();
		mode = menu_type;
		switch (menu_type) {
		case MANUAL:
			cout << "�� ������� ����� ����� �������." << endl;
			cout << endl;
			user_input(size, arr_point, radius, center, res_arr_point);
			break;
		case GENERATE:
			cout << "�� ������� ����� ���������." << endl;
			generation_input(size, arr_point, radius, center, res_arr_point);
			break;
		case FILE_INPUT:
			cout << "�� ������� ����� ����� ������ �� �����." << endl;
			create_file(READ_POINTS, arr_point, res_arr_point, size, radius, center);
			break;
		default:
			cout << "������� ���� 1, ���� 2, ���� 3." << endl;
			repeat = true;
		}
	} while (repeat);
}

bool end_program() {
	cout << "��������� ���������? " << endl << "������� 0 ��� ����������." << endl << "������� 1 ��� �������." << endl;
	bool repeat = true;
	do {
		repeat = false;
		int end = get_int();
		switch (end) {
		case END:
			cout << "��������� �����������..." << endl;
			break;
		case CONTINUE:
			cout << "�� ������� ��������� ���������: " << endl;
			break;
		default:
			cout << "������� ���� 0, ���� 1." << endl;
			repeat = true;
		}
		return !(end);
	} while (repeat);
}


void saving_results(Points_class& point_arr, res_points_class& res_point_arr) {
	cout << "����a���� ���������� � ��������� �����?" << endl << "������� 1 ��� ����������." << endl << "������� 2, ����� ���������� ����������." << endl;
	int size_t = 0, radius_t = 0;
	Point center_t;
	while (true) {
		int save = get_int();
		if (save == YES) {
			create_file(RESULT, point_arr, res_point_arr, size_t, radius_t, center_t);
			break;
		}
		else if (save == NO) {
			cout << "�� ������� ���������� ����������." << endl;
			break;
		}
		else cout << "������� ���� 1, ���� 2." << endl;

	}
}

void save_data(Points_class& point_arr, int radius, Point center, res_points_class& res_t, int size) {
	cout << "�� ������ ��������� ������? ������� 1 - ��� ����������, 2 - ��� �������� ����������." << endl;
	while (true) {
		int save = get_int();
		if (save == YES) {
			create_file(DATA, point_arr, res_t, size, radius, center);
			cout << "������ ���������." << endl;
			break;
		}
		else if (save == NO) {
			cout << "�� ������� ���������� ����������." << endl;
			break;
		}
		else cout << "������� ���� 1, ���� 2." << endl;
	}
}
