#include "./vmt.h"
#include <time.h>
int main(){
    vmt_ndarr a=vmt_contig(2, 4, 5), b=vmt_zero(2, 5, 4);
    vmt_print(a);
    vmt_trp2d(a, b);
    vmt_print(b);
    return 0;
}
