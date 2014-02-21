#pragma once
//с шаблонами пока не получается, поэтому тестироваться будет на int
bool is_ok(int *a, int *b, int n);

void test(void (*sortArray)(int *, int, int));
