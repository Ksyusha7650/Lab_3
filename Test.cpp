//#include "Test.h"
//
//Matrix arr, exp_arr;
//Bubble_sort bubble;
//Selection_sort selection;
//Insert_sort insert;
//Shell_sort shell;
//Quick_sort quick;
//int col = 0, row = 0;
//void update_dates(void) {
//	
//}
//bool Test1(void) {
//	update_dates();
//	col = 2;
//	row = 2;
//	arr.set_size(col, row);
//	exp_arr.set_size(col, row);
//	arr(0, 0) = 1;
//	arr(0, 1) = 2;
//	arr(1, 0) = 3;
//	arr(1, 1) = 4;
//	exp_arr(0, 0) = 
//	int check = 0;
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	check_inclusion(point_arr, radius, center, res_point_arr);
//	for (int i = 0; i < res_point_arr.get_size(); i++) {
//		if (expected_res_point_arr[i] == res_point_arr[i])
//			check++;
//	}
//	if (check == res_point_arr.get_size()) {
//		return true;
//	}
//	else {
//		SetConsoleTextAttribute(handle, FOREGROUND_RED);
//		cout << "���� 1 �� �������!" << endl;
//		output_arr(point_arr, radius, center);
//		string expected_result, result;
//		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
//		for (int i = 0; i < res_point_arr.get_size(); i++) {
//			if (expected_res_point_arr[i] == 1) expected_result = " ��������.";
//			else expected_result = " �� ��������.";
//			cout << "���������, ��� ����� " << i + 1 << expected_result << endl;
//			if (res_point_arr[i] == 1) result = " ��������.";
//			else result = " �� ��������.";
//			cout << "�� ����������� ����� ����� " << i + 1 << result << endl;
//		}
//		return false;
//	}
//}
//
//bool Test2(void) {
//	update_dates();
//	quantity = 5;
//	point_arr.set_size(quantity);
//	res_point_arr.set_size(quantity);
//	expected_res_point_arr.set_size(quantity);
//	point_arr[0].x = 0;
//	point_arr[0].y = 0;
//	point_arr[0].z = 0;
//	point_arr[1].x = 1;
//	point_arr[1].y = 1;
//	point_arr[1].z = 1;
//	point_arr[2].x = 2;
//	point_arr[2].y = 2;
//	point_arr[2].z = 2;
//	point_arr[3].x = 3;
//	point_arr[3].y = 3;
//	point_arr[3].z = 3;
//	point_arr[4].x = 1.5;
//	point_arr[4].y = 0;
//	point_arr[4].z = 0;
//	radius = 4;
//	center.x = 0;
//	center.y = 0;
//	center.z = 0;
//	expected_res_point_arr[0] = 1;
//	expected_res_point_arr[1] = 1;
//	expected_res_point_arr[2] = 1;
//	expected_res_point_arr[3] = 0;
//	expected_res_point_arr[4] = 1;
//	int check = 0;
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	check_inclusion(point_arr, radius, center, res_point_arr);
//	for (int i = 0; i < res_point_arr.get_size(); i++) {
//		if (expected_res_point_arr[i] == res_point_arr[i])
//			check++;
//	}
//	if (check == res_point_arr.get_size()) {
//		return true;
//	}
//	else {
//		SetConsoleTextAttribute(handle, FOREGROUND_RED);
//		cout << "���� 2 �� �������!" << endl;
//		output_arr(point_arr, radius, center);
//		string expected_result, result;
//		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
//		for (int i = 0; i < res_point_arr.get_size(); i++) {
//			if (expected_res_point_arr[i] == 1) expected_result = " ��������.";
//			else expected_result = " �� ��������.";
//			cout << "���������, ��� ����� " << i + 1 << expected_result << endl;
//			if (res_point_arr[i] == 1) result = " ��������.";
//			else result = " �� ��������.";
//			cout << "�� ����������� ����� ����� " << i + 1 << result << endl;
//		}
//		return false;
//	}
//}
//
//bool Test3(void) {
//	update_dates();
//	quantity = 3;
//	point_arr.set_size(quantity);
//	res_point_arr.set_size(quantity);
//	expected_res_point_arr.set_size(quantity);
//	point_arr[0].x = 0;
//	point_arr[0].y = 0;
//	point_arr[0].z = 0;
//	point_arr[1].x = -1;
//	point_arr[1].y = -1;
//	point_arr[1].z = -1;
//	point_arr[2].x = 2;
//	point_arr[2].y = 2;
//	point_arr[2].z = 2;
//	radius = 2;
//	center.x = 1;
//	center.y = 1;
//	center.z = 1;
//	expected_res_point_arr[0] = 1;
//	expected_res_point_arr[1] = 0;
//	expected_res_point_arr[2] = 1;
//	int check = 0;
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	check_inclusion(point_arr, radius, center, res_point_arr);
//	for (int i = 0; i < res_point_arr.get_size(); i++) {
//		if (expected_res_point_arr[i] == res_point_arr[i])
//			check++;
//	}
//	if (check == res_point_arr.get_size()) {
//		return true;
//	}
//	else {
//		SetConsoleTextAttribute(handle, FOREGROUND_RED);
//		cout << "���� 3 �� �������!" << endl;
//		output_arr(point_arr, radius, center);
//		string expected_result, result;
//		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
//		for (int i = 0; i < res_point_arr.get_size(); i++) {
//			if (expected_res_point_arr[i] == 1) expected_result = " ��������.";
//			else expected_result = " �� ��������.";
//			cout << "���������, ��� ����� " << i + 1 << expected_result << endl;
//			if (res_point_arr[i] == 1) result = " ��������.";
//			else result = " �� ��������.";
//			cout << "�� ����������� ����� ����� " << i + 1 << result << endl;
//		}
//		return false;
//	}
//}
//
//bool Test4(void) {
//	update_dates();
//	quantity = 3;
//	point_arr.set_size(quantity);
//	res_point_arr.set_size(quantity);
//	expected_res_point_arr.set_size(quantity);
//	point_arr[0].x = 0;
//	point_arr[0].y = 0;
//	point_arr[0].z = 0;
//	point_arr[1].x = -1;
//	point_arr[1].y = -1;
//	point_arr[1].z = -1;
//	point_arr[2].x = 2;
//	point_arr[2].y = 2;
//	point_arr[2].z = 2;
//	radius = 2;
//	center.x = 100;
//	center.y = 100;
//	center.z = 100;
//	expected_res_point_arr[0] = 0;
//	expected_res_point_arr[1] = 0;
//	expected_res_point_arr[2] = 0;
//	int check = 0;
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	check_inclusion(point_arr, radius, center, res_point_arr);
//	for (int i = 0; i < res_point_arr.get_size(); i++) {
//		if (expected_res_point_arr[i] == res_point_arr[i])
//			check++;
//	}
//	if (check == res_point_arr.get_size()) {
//		return true;
//	}
//	else {
//		SetConsoleTextAttribute(handle, FOREGROUND_RED);
//		cout << "���� 4 �� �������!" << endl;
//		output_arr(point_arr, radius, center);
//		string expected_result, result;
//		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
//		for (int i = 0; i < res_point_arr.get_size(); i++) {
//			if (expected_res_point_arr[i] == 1) expected_result = " ��������.";
//			else expected_result = " �� ��������.";
//			cout << "���������, ��� ����� " << i + 1 << expected_result << endl;
//			if (res_point_arr[i] == 1) result = " ��������.";
//			else result = " �� ��������.";
//			cout << "�� ����������� ����� ����� " << i + 1 << result << endl;
//		}
//		return false;
//	}
//}
//
//void run_tests(void) {
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	if (Test1() && Test2() && Test3() && Test4()) {
//		SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
//		cout << "��� ����� ��������!" << endl;
//		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
//	}
//}
