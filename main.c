#include "list.h"

int addelem(struct poly* _head, int _coef, int _degree)
{
    while (_head->next)
        _head = _head->next;

    _head->next = (struct poly *)malloc( sizeof(struct poly) );
    _head = _head->next;

    _head->degree = _degree;
    _head->coef = _coef;
    _head->next = NULL;

    return 0;
}

struct poly* findelem(struct poly* _head, int _index)   //indexing
{
    if (!_head) { printf("NULL-pointer head!\n"); return NULL; }
    if (_index < 0) { printf("The index must be greater than 0. Or can be 0.\n"); return NULL; }

    int index = 0;

    while (_head->next && _index != index)
    {
        ++index; _head = _head->next;
    }

    if (_index != index) return NULL;

    return _head;
}

void output(int size, int tmp, struct poly* OnlyOne)
{
    printf("\n");

    for (int j = 1; j <= size; ++j)
    {
        for (int i = 1; i <= size; ++i)
        {
            if (i == j){ continue; }
            else
            if (findelem(OnlyOne, j)->degree == findelem(OnlyOne, i)->degree)
            {
                sleep(2);
                printf("Polynomial is incorrect (same degrees are not welcome)\n");
                exit(0);
            }
        }
    }

    for (int i = 1; i <= size; ++i)
    {
        if (i == 1 && i != tmp)
        {
            printf("%dx^%d ", findelem(OnlyOne, i)->coef, findelem(OnlyOne, i)->degree);

        }
        else if (i == 1 && i == tmp)
        {
            printf("%d ", findelem(OnlyOne, i)->coef);
        }
        else
        {
            if (findelem(OnlyOne, i)->coef > 0 && i > 1)
            {
                printf("+ ");
            }

            else if (findelem(OnlyOne, i)->coef == 0)
            {
                break;
            }

            if (i == tmp)
            {
                printf("%d ", findelem(OnlyOne, i)->coef);
            } else
            printf("%dx^%d ", findelem(OnlyOne, i)->coef, findelem(OnlyOne, i)->degree);
        }
    }
}

int main()
{
    struct poly* first = inithead(0, 0);
    struct poly* second = inithead(0, 0);
    struct poly* final = inithead(0, 0);

    int size1, size2, coefficient, CurrentDegree, numberID, numberIDtmp = 0, FinalSize = 0, numberID1 = 0, numberID2 = 0;

    printf("\n-----------------------------------------\nEntering data for the first polynomial...\n");
    sleep(1);

    printf("(I) Enter number of monomials:\t");
    printf("\n");

    while ( scanf(" %d", &size1) == 0 || size1 <= 0)
    {
        printf("Input error! Try again.\t");
        while(getchar()!='\n');
    }

    for (int i = 1; i <= size1; ++i)
    {
        printf("Enter degree of current monomials:\t");

        while ( scanf(" %d", &CurrentDegree) == 0 || CurrentDegree < 0)
        {
            printf("Input error! Try again.\t");
            while(getchar()!='\n');
        }

        if (CurrentDegree != 0)
        {
            ++numberIDtmp;
        }
        if (CurrentDegree == 0)
        {
            numberID = numberIDtmp;
            numberID1 = i;
        }

        printf("Enter its coefficient:\t");

        while ( scanf(" %d", &coefficient) == 0 || coefficient == 0)
        {
            printf("Input error! Try again.\t");
            while(getchar()!='\n');
        }

        printf("\n");

        if (CurrentDegree % 2 == 0 || CurrentDegree == 0)
        {
            FinalSize++;
            addelem(final, coefficient, CurrentDegree);
        }

        addelem(first, coefficient, CurrentDegree);
    }

    printf("\nEntering data for the second polynomial...\n");
    sleep(1);

    printf("(II) Enter number of monomials:\t");
    printf("\n");

    while ( scanf(" %d", &size2) == 0 || size2 <= 0)
    {
        printf("Input error! Try again.\t");
        while(getchar()!='\n');
    }

    for (int i = 1; i <= size2; ++i)
    {
        printf("Enter degree of current monomials:\t");

        while ( scanf(" %d", &CurrentDegree) == 0 || CurrentDegree < 0)
        {
            printf("Input error! Try again.\t");
            while(getchar()!='\n');
        }

        if (CurrentDegree == 0)
        {
            numberID2 = i;
        }

        printf("Enter its coefficient:\t");

        while ( scanf(" %d", &coefficient) == 0 || coefficient == 0)
        {
            printf("Input error! Try again.\t");
            while(getchar()!='\n');
        }

        printf("\n");

        if (CurrentDegree % 2 == 1)
        {
            FinalSize++;
            addelem(final, coefficient, CurrentDegree);
        }

        addelem(second, coefficient, CurrentDegree);
    }

    printf("The first one...");
    output(size1, numberID1, first);
    sleep(1);
    printf("\nThe second one...");
    sleep(1);
    output(size2, numberID2, second);
    printf("\nThe final polynomial...");
    sleep(2);
    output(FinalSize, numberID, final);
    printf("\n-----------------------------------------\nPress \"F\"\n");

    getchar();
    return 0;
}
