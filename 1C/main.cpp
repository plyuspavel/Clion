#include <stdio.h>
#include <assert.h>
#include <errno.h>

int weiging(long num);
long InputL(const char message[]);

int main()
{
    long number = 0;
    number = InputL("");
    if (number <= 0)
    {
        perror("Some problems: ");
        return 1;
    }

    weiging(number) ? printf("YES") : printf("NO");
    return 0;
}

int weiging(long num)
{
    assert(num > 0);
    if (num == 1) return 1;
    else
    {
        return   ((num % 4 == 0)? weiging(num / 4): 0)||
                (((num + 1) % 4 == 0)? weiging((num + 1) / 4): 0)||
                (((num - 1) % 4 == 0)? weiging((num - 1) / 4): 0);
    }

}

long InputL(const char message[])
{
    //printf("%s %ld", message);

    long num = 0;
    if (scanf("%ld", &num))
        return num;
    else
    {
        errno = EIO;
        return -1;
    }
}