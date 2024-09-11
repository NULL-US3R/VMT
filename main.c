#include <stdio.h>
#include <stdlib.h>

struct vector{
    int l;
    float * v;
};

typedef struct vector * vector;

vector vmt_zero_v(int l){
    vector v = (vector)malloc(sizeof(struct vector));
    v->v = (float *)calloc(l, sizeof(float));
    v->l=l;
    return v;
}

vector vmt_rand_v(int l){
    vector v = (vector)malloc(sizeof(struct vector));
    v->v = (float *)malloc(l*sizeof(float));
    v->l=l;
    for (int i=0; i<l; i++){
        v->v[i] = ((float)(rand()%1000000))/1000000;
    }
    return v;
}

void vmt_print_v(vector v){
    for (int l=0; l<v->l; l++){
        printf("%1.6f ", v->v[l]);
    }
    printf("\n");
}

void vmt_write_v(vector v, float * a, int s){
    for(int i=0; i<s; i++){
        v->v[i]=a[i];
    }
}

void vmt_add_vvv(vector a, vector b, vector r){
    for (int i=0; i<r->l; i++){
        r->v[i]=a->v[i]+b->v[i];
    }
}

void vmt_sub_vvv(vector a, vector b, vector r){
    for (int i=0; i<r->l; i++){
        r->v[i]=a->v[i]-b->v[i];
    }
}

void vmt_mul_vvv(vector a, vector b, vector r){
    for (int i=0; i<r->l; i++){
        r->v[i]=a->v[i]*b->v[i];
    }
}

void vmt_div_vvv(vector a, vector b, vector r){
    for (int i=0; i<r->l; i++){
        r->v[i]=a->v[i]/b->v[i];
    }
}

struct matrix{
    int r, c;
    float * v;
};

typedef struct matrix * matrix;

matrix vmt_zero_m(int r, int c){
    matrix m = (matrix)malloc(sizeof(struct matrix));
    m->v = (float *)calloc(r*c, sizeof(float));
    m->r=r;
    m->c=c;
    return m;
}

matrix vmt_rand_m(int r, int c){
    matrix m = (matrix)malloc(sizeof(struct matrix));
    m->v = (float *)malloc(r*c*sizeof(float));
    m->r=r;
    m->c=c;
    for (int i=0; i<r*c; i++){
        m->v[i] = ((float)(rand()%1000000))/1000000;
    }
    return m;
}

void vmt_print_m(matrix m){
    for (int r=0; r<m->r; r++){
        for (int c=0; c<m->c; c++){
            printf("%1.6f ", m->v[r*m->c+c]);
        }
        printf("\n");
    }
}

void vmt_write_m(matrix m, float * a, int s){
    for(int i=0; i<s; i++){
        m->v[i]=a[i];
    }
}

void vmt_add_mmm(matrix a, matrix b, matrix r){
    for (int i=0; i<r->r*r->c; i++){
        r->v[i]=a->v[i]+b->v[i];
    }
}

void vmt_sub_mmm(matrix a, matrix b, matrix r){
    for (int i=0; i<r->r*r->c; i++){
        r->v[i]=a->v[i]-b->v[i];
    }
}

void vmt_mul_mmm(matrix a, matrix b, matrix r){
    for (int i=0; i<r->r*r->c; i++){
        r->v[i]=a->v[i]*b->v[i];
    }
}

void vmt_div_mmm(matrix a, matrix b, matrix r){
    for (int i=0; i<r->r*r->c; i++){
        r->v[i]=a->v[i]/b->v[i];
    }
}

int main(){
    vector a = vmt_zero_v(4);
    vector b = vmt_zero_v(4);
    float arr[]={1,2,3,4};
    vmt_write_v(a, arr, 3);
    vmt_print_v(a);
    vmt_div_vvv(a, a, b);
    vmt_print_v(b);
    return 0;
}
