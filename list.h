#ifndef XWORK10_LIST_H
#define XWORK10_LIST_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
struct poly
{
    int coef;
    int degree;
    struct poly* next;
};

struct poly* inithead(int _coef, int _degree)
{
    struct poly* element = (struct poly *)malloc( sizeof(struct poly) );
    element->degree = _degree;
    element->coef = _coef;
    element->next = NULL;
    return element;
}
#endif //XWORK10_LIST_H
