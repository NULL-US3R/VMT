#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

struct vmt_ndarr{
    int dims, size;
    int * shape;
    float * vals;
};
typedef struct vmt_ndarr * vmt_ndarr;

vmt_ndarr vmt_zero(int l,...){
    va_list args;
    vmt_ndarr o = (vmt_ndarr)malloc(sizeof(struct vmt_ndarr));
    o->dims=l;
    o->shape = (int *)malloc(l*sizeof(int));
    va_start(args, l);
    for (int i=0; i<l; i++){
        o->shape[i]=va_arg(args, int);
    }
    va_end(args);
    int c=1;
    for (int i=0; i<l; i++){
        c*=o->shape[i];
    }
    o->size=c;
    o->vals=(float *)calloc(c, sizeof(float));
    return o;
}

void vmt_print(vmt_ndarr a){
    printf("{");
    for (int i=0; i<a->size; i++){
        printf(", %1.3f", a->vals[i]);
    }
    printf("}\nshape(");
    for (int i=0; i<a->dims; i++){
        if (i==0){
            printf("%i", a->shape[i]);
        }else{
            printf(", %i", a->shape[i]);
        }
    }
    printf(")\n");
}

int main(){
    vmt_ndarr a = vmt_zero(2, 5, 2);
    vmt_print(a);
    return 0;
}
