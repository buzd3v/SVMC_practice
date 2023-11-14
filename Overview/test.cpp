#include <iostream>
template <size_t size_x, size_t size_y> void func(char (&arr)[size_x][size_y])
{
    printf("%p\n", &arr);
    std::cout << "size x: " << size_x << std::endl;
}

int main()
{
    char a1[10][10];
    char a2[5][5];

    printf("%p\n%p\n\n", &a1, &a2);
    func(a1);
    func(a2);

    return 0;
}