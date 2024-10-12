#include "./vmt.h"
#include <time.h>
int main(){
    vmt_ndarr a = vmt_contig(2, 2, 3), b = vmt_contig(2, 2, 3), c = vmt_zero(2, 3, 3);
    vmt_print(a);
    printf("\n");
    vmt_print(b);
    printf("\n");
    vmt_matmul_trpa(a, b, c);
    vmt_print(c);
    return 0;
}
