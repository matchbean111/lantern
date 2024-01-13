#include <stdio.h>

int msb(int m){
    int count =0;
    while (m>0)
    {
        m = m >>1;
        count++;
    }
    return count-1;
}

int set_bit(int reslut, int i){
    return (1 << i) | reslut;
}

int get_bit(int m, int i){
    return (m >> i)  & 1;
}

int rangeBitwiseAnd(int m, int n){
    int msb1 = msb(m);
    int msb2 = msb(n);
    if (msb1 != msb2){
        return 0;
    }
    int msb = msb1;
    int result = 0;
    while (msb >= 0)
    {
        int x = get_bit(m,msb);
        int y = get_bit(n,msb);
        if (x != y) {
            return result;
        }else if (x == y && x == 1){
            result = set_bit(result, msb);
        }
        msb--;
    }
    
    return result;
}

int main() {
    printf("%X\n",rangeBitwiseAnd(0,0));


    return  0;
}