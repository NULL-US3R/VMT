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

vmt_ndarr vmt_contig(int l,...){
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
    o->vals=(float *)malloc(c*sizeof(float));
    for (int i=0; i<c; i++){
        o->vals[i] = (float)i;
    }
    return o;
}

vmt_ndarr vmt_rand(int l,...){
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
    o->vals=(float *)malloc(c*sizeof(float));
    for (int i=0; i<c; i++){
        o->vals[i] = (float)(random()%1000)/1000;
    }
    return o;
}

void vmt_print(vmt_ndarr a){
    printf("{");
    for (int i=0; i<a->size; i++){
        int s=a->size;
        int count = 0;
        for (int j=0; j<a->dims-1; j++){
            s=s/a->shape[j];
            if (i%(s)==0){
                count=count+1;
            }
        }
        if (count>0 && !(i==0)){
            for (int k=0; k<a->dims-count; k++){
                printf(" ");
            }
        }
        for (int k=0; k<count; k++){
            printf("{");
        }
        printf("%1.3f", a->vals[i]);
        s=a->size;
        for (int j=0; j<a->dims-1; j++){
            s=s/a->shape[j];
            if ((i+1)%(s)==0){
                printf("}");
            }
        }
        if (!(i==a->size-1)){
            printf(", ");
            if ((i+1)%a->shape[a->dims-1]==0){
                printf("\n");
            }
        }
    }
    printf("}\n");
}

void vmt_add_aa(vmt_ndarr a, vmt_ndarr b, vmt_ndarr res){
    for (int i=0; i<res->size; i++){
        res->vals[i]=a->vals[i]+b->vals[i];
    }
}

void vmt_add_af(vmt_ndarr a, float b, vmt_ndarr res){
    for (int i=0; i<res->size; i++){
        res->vals[i]=a->vals[i]+b;
    }
}

void vmt_sub_aa(vmt_ndarr a, vmt_ndarr b, vmt_ndarr res){
    for (int i=0; i<res->size; i++){
        res->vals[i]=a->vals[i]-b->vals[i];
    }
}

void vmt_sub_af(vmt_ndarr a, float b, vmt_ndarr res){
    for (int i=0; i<res->size; i++){
        res->vals[i]=a->vals[i]-b;
    }
}

void vmt_mul_aa(vmt_ndarr a, vmt_ndarr b, vmt_ndarr res){
    for (int i=0; i<res->size; i++){
        res->vals[i]=a->vals[i]*b->vals[i];
    }
}

void vmt_mul_af(vmt_ndarr a, float b, vmt_ndarr res){
    for (int i=0; i<res->size; i++){
        res->vals[i]=a->vals[i]*b;
    }
}

void vmt_div_aa(vmt_ndarr a, vmt_ndarr b, vmt_ndarr res){
    for (int i=0; i<res->size; i++){
        res->vals[i]=a->vals[i]/b->vals[i];
    }
}

void vmt_div_af(vmt_ndarr a, float b, vmt_ndarr res){
    for (int i=0; i<res->size; i++){
        res->vals[i]=a->vals[i]/b;
    }
}

int main(){
    vmt_ndarr a = vmt_rand(2, 4, 3), b = vmt_rand(2, 4, 3), c = vmt_zero(2, 4, 3);
    vmt_print(a);
    vmt_print(b);
    vmt_div_aa(a, b, c);
    vmt_print(c);
    return 0;
}
