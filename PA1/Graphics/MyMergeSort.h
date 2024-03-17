#pragma once

class LineOrPoint {
public:
    int x;
    int y;
    LineOrPoint(int a=0,int b=0);
    int cross_with(LineOrPoint line);
};

int LinearSearch(LineOrPoint* s, int s_size, LineOrPoint p);
void combine(int* a, int* b, int a_size, int b_size);
void MergeSort(int* a, int a_size);