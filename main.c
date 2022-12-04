#include <stdio.h>
int max_low;
_Bool equal=0;
int sort(int * low,int M){
    int max=low[0];
    if(equal==0){
        max_low=0;
    } else equal=0;
    for (int i = max_low+1; i < M; ++i) {
        if(low[i]>max){
            max=low[i];
            max_low=i;
        } else if(low[i]==max)equal=1;
    }
    return max;
}
int main() {
    int N,M;
    scanf("%d %d",&N,&M);
    int matrix[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d",&matrix[i][j]);
        }
    }
    for (int i = 0; i < N; ++i) {
        if(equal==1)i--;
        int max=sort(matrix[i],M);
            int fuck = 1;
            for (int j = 0; j < N; ++j) {
                if (matrix[j][max_low] > max) {
                    fuck = 0;
                    break;
                }
                if (fuck == 0)break;
            }
            if (fuck == 1)printf("%d %d %d\n", max, i + 1, max_low + 1);
    }
    return 0;
}
