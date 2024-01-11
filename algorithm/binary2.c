#include <stdio.h>
#define UNIT unsigned char

UNIT reverse(UNIT a)
{
    int m_4 = 0x0f;
    int m_2 = 0x33;
    int m_1 = 0x55;
    int b = ((a & m_4) << 4) + ((a >> 4) & m_4);
    int c = ((b & m_2) << 2) + ((b >> 2) & m_2);
    int d = ((c & m_1) << 1) + ((c >> 1) & m_1);

    return d;
}

int main()
{
    UNIT num = 13;
    printf("%d\n", reverse(num));
    return 0;
}