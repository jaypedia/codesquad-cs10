#include <stdio.h>
#include <stdlib.h>

const int constval = 30; // μμ   --- πTEXT
int function() { // ν¨μ           --- πTEXT
    return 20;
}

int uninitial; // μ΄κΈ°νλμ§ μμ μ μ­λ³μ --- ποΈ DATA (μ μ­λ³μ, μ μ λ³μ)
int initial = 30; // μ΄κΈ°νλ μ μ­λ³μ    --- ποΈ DATA (μ μ­λ³μ, μ μ λ³μ)
static int staticval = 70; // μ μ λ³μ   --- ποΈ DATA (μ μ­λ³μ, μ μ λ³μ)

int main(int argc, const char * argv[]) {
    int localval1 = 30; // μ§μ­λ³μ 1    --- π₯ STACK
    int localval2; // μ§μ­λ³μ 2         --- π₯ STACK

    printf("ENTER NUMBER : ");
    scanf("%d", &localval2);

    char *arr = malloc(sizeof(char) * 10) // λμ  ν λΉ λ³μ  --- π» HEAP

    /* ν¬μΈν° μΆλ ₯ μμ­ */
    printf("μμ Memory Address : \t\t %p \n", &constval);
    printf("λΉμ΄κΈ°ν λ³μ Memory Address :\t %p \n", &uninitial);
    printf("μ΄κΈ°ν λ³μ Memory Address : \t %p \n", &initial);
    printf("μ μ  λ³μ Memory Address : \t %p \n", &staticval);
    printf("ν¨μ Memory Address : \t\t %p \n", function);
    printf("μ§μ­λ³μ1 Memory Address : \t %p \n", &localval1);
    printf("μ§μ­λ³μ2 Memory Address : \t %p \n", &localval2);
    printf("λμ ν λΉλ³μ Memory Address : \t %p \n\n", arr);

    return 0;
}