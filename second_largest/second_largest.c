#include <stdio.h>

void show_array(int **arr, int col, int row)
{
    for(int i = 0; i< row; i++)
        for(int j = 0; j < col; j++)
        {
            printf("%d ", *((int *)arr + col*i + j));
            if(j == row -1)
                puts("");
        }
}

int find_second_largest(int *arr, int size, int step)
{
    int second_largest, largest ;

    second_largest = largest = *arr;

    for(int i = 1; i< size; i++)
    {
        if(*(arr + step*i) > largest)
        {
            second_largest = largest;
            largest = *(arr + step*i);
        }
        else if ( *(arr + i) > second_largest)
        {
            second_largest = *(arr + step*i);
        }
    }

    return second_largest;
}

int main()
{
    int arr[3][3] = {
        {1,2,7},
        {4,5,6},
        {7,8,9}
    };
    printf("%p arr[0] \n", arr[0]);
    printf("%p arr[0][1] \n", &arr[0][1]);
    printf("%p arr[1] \n", arr[1]);

    show_array(arr, 3,3);
    int row_test = 2;

    printf("second largest in row %d is %d\n", row_test, \
            find_second_largest(&arr[0][0],3, 3));

    return 0;
}
