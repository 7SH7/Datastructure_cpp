// 아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: Kim Seunghwan  분반: ECE20010  Student Number: 22000116// Topic: Performance Analysis - profiling
//
// Description:	This program profiles the complexity of sorting algorithms.
// It uses a for loop to control the size of the array. At each iteration,
// a new randomly ordered array of n numbers is created. In order to do more
// accurate timing, for each n, it do the sort as many times as needed to
// bring the total time up to 1 second (1000 ticks).
// This program uses clock(), not difftime() and time().
// The time complexity of the selection sort and quick sort is O(n^2)
// and O(n log n), respectively. This program compares the elapsed time of
// sort algorithm with the theoretical upper bound O(n^2) of the selection sort
// and O(n log n) of Quick Sort.  When it computes the elapsed time of O(n^2)
// and O(n log n), you may use Math functions as necessary. It assumes that the
// elapsed times for all three cases are exactly the same to begin with for
// STARTING_SAMPLES 1000.  Once the elapsed time of the selection sort for
// STARTING_SAMPLES is got, it is set to those for O(n^2) and O(n log n).
//
// Author: idebtor@gmail.com
//
// Compilation & Execution:
// $ g++ profiling.cpp -I../../include -L../../lib -lsort -o profiling
// 실행 파일에 내가 -lrand 추가해줌.
// $ g++ profiling.cpp -I../../include -L../../lib -lsort -lrand -o profiling
// $ ./profiling 50000

#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <ctime> /* clock_t, clock, CLOCKS_PER_SEC */
#include "sort.h"
#include "rand.h"
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// a helper function
// Compute the number of digit first and return step size such as 100, 1000, 10000 etc.
// Refer to some instructions provided in pset pdf file.
int getStep(int n)
{
	int digit = 1;
	int step = 1;

	// compute the number of digit first
	do
	{
		n = n / 10;
		if (n > 0)
			digit++;
	} while (n > 0);

	// compute the step
	for (int i = 0; i < (digit - 1); i++)
		step *= 10;
	return step;
}

void profiling(void (*sort_fp)(int *, int, bool (*comp)(int, int)), int *list, const int n, bool (*comp_fp)(int, int))
{
	int *saved = new (nothrow) int[n]; // to save the original list into a buffer
	assert(saved != nullptr);
	copy_n(list, n, saved); // to use the same sequence during repetitions

	cout << "         N\t repetitions\t   sort(sec)\n";
	for (int i = STARTING_SAMPLES; i <= n; i += getStep(i))
	{
		long repetitions = 0;
		clock_t start = clock();
		do
		{
			repetitions++;							// count the repetitions for one second
			copy_n(saved, n, list);					// get a copy of list from saved
			sort_fp(list, i, comp_fp);				// sort
		} while (clock() - start < CLOCKS_PER_SEC); // run it over one sec

		double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		duration /= repetitions;

		cout << fixed;
		cout << setw(10) << i << "\t" << setw(12) << repetitions << "\t" << setw(12) << duration << endl;
	}

	delete[] saved;
}

#if 1
int main(int argc, char *argv[])
{
	int N = 0;
	setvbuf(stdout, nullptr, _IONBF, 0); // prevent the output from buffered on console.

	if (argc == 1)
	{
		string str;
		cout << "The minimum number of entries is set to " << STARTING_SAMPLES << endl;
		cout << "Enter the number of max entries to sort: ";
		getline(cin, str);
		// stream.str(string str) 은 현재 stream의 값을 문자열 str로 바꿉니다.
		stringstream ss(str);
		ss >> N;
	}
	else if (argc == 2)
	{
		char *end;
		// strtol : 문자열을 long 값으로 변환 합니다.
		// 2진수, 8진수, 16진수 값을 10진수로 변환 합니다. (string to long)
		// strtol(str1, &end, 문자수+1);
		// -> str1을 ll으로 바꾸다가, 바꿀 수 없는 것이 나오면, 그 문자의 ptr을 end에 저장
		N = strtol(argv[1], &end, 10);
		if (N <= 0 || *end != '\0')
			std::cout << "Usage: profiling [N]\n";
	}

	if (N <= STARTING_SAMPLES)
	{
		cout << "Enter a number greater than " << STARTING_SAMPLES << ".\n";
		exit(EXIT_FAILURE);
	}

	cout << "The maximum sample data size is " << N << endl;

	int *list = new (nothrow) int[N];
	assert(list != nullptr);

	///////////// rewrite this part for DRY and MNN ////////////////////////

	void (*sort_fp[])(int *, int, bool (*comp)(int, int)) = {insertionsort, mergesort, quicksort};
	int _size = sizeof(sort_fp) / sizeof(sort_fp[0]);
	string sort_name[] = {"\n\tinsertionsort(): ", "\n\tmergesort(): ", "\n\tquicksort(): "};

	for (int i = 0; i < _size; i++)
	{
		cout << sort_name[i] + "sorted" << endl;
		for (int i = 0; i < N; i++)
			list[i] = i; // sorted data ready
		profiling(sort_fp[i], list, N, ::less);

		cout << sort_name[i] + "randomized" << endl;
		randomize(list, N);
		profiling(sort_fp[i], list, N, ::less); // randomized

		cout << sort_name[i] + "reversed" << endl;
		int j = N - 1;
		for (int i = 0; i < N; i++)
			list[i] = j--; // reversed sequence
		profiling(sort_fp[i], list, N, ::less);
	}

	///////////// rewrite this part for DRY and MNN ////////////////////////

	delete[] list;
	return EXIT_SUCCESS;
}
#endif
