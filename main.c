//黄先生自己写的自己也看不懂的垃圾代码
#include <stdio.h>

int max_low;
_Bool equal = 0;

//先写一个用来寻找行内最大元素的函数
int sort(const int * low, int M) {
    int max = low[0];
    if (equal == 0) {
        max_low = 0;
    } else equal = 0;
    for (int i = max_low + 1; i < M; ++i) {
        if (low[i] > max) {
            max = low[i];
            max_low = i;  //标记最大元素所在列
        } else if (low[i] == max)equal = 1; //遇到与前面相等的数就标记
    }
    return max;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int matrix[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < N; ++i) {
        if (equal == 1)i--;//上一轮循环中发现了相同的
        int max = sort(*(matrix+i), M);
        int flag = 1;
        for (int j = 0; j < N; ++j) {
            if (matrix[j][max_low] > max) {
                flag = 0;
                break;
            }
        }
        if (flag == 1)printf("%d %d %d\n", max, i + 1, max_low + 1);
    }
    return 0;
}
