#include "./vmt.h"
int main(){
    vmt_ndarr a=vmt_contig(2, 4, 5);
    vmt_print(a);
    return 0;
}
