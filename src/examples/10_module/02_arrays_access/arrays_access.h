//header
#include <ctime>//Converts timer value to readable string
#include <cstdlib>//for algorithms
#include <chrono>//Helps maintain time units
#include <iostream>

void populate_array(int list[], int size, bool randomize);

int linear_search(const int list[], int size, int search_value); //O(n)

int binary_search(const int list[], int size, int search_value); //O(log 2 base n)

void bubble_sort(int list[], int size); //O(n^2)