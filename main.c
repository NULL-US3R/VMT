#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int r, c;
    float * v;
};

typedef struct matrix * matrix;

matrix vmt_zero(int r, int c){
    matrix m = (matrix)malloc(sizeof(struct matrix));
    m->v = (float *)calloc(r*c, sizeof(float));
    m->r=r;
    m->c=c;
    return m;
}

matrix vmt_rand(int r, int c){
    matrix m = (matrix)malloc(sizeof(struct matrix));
    m->v = (float *)malloc(r*c*sizeof(float));
    m->r=r;
    m->c=c;
    for (int i=0; i<r*c; i++){
        m->v[i] = ((float)(rand()%1000000))/1000000;
    }
    return m;
}

void vmt_print(matrix m){
    for (int r=0; r<m->r; r++){
        for (int c=0; c<m->c; c++){
            printf("%1.6f ", m->v[r*m->c+c]);
        }
        printf("\n");
    }
}

void vmt_write(matrix m, float * a, int s){
    for(int i=0; i<s; i++){
        m->v[i]=a[i];
    }
}

void vmt_add_mm(matrix a, matrix b, matrix r){
    for (int i=0; i<r->r*r->c; i++){
        r->v[i]=a->v[i]+b->v[i];
    }
}

int main(){
    matrix a = vmt_rand(4, 2);

    vmt_print(a);
    return 0;
}
