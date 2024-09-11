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

void vmt_write_v(vector v, float * a, int pos, int s){
    for(int i=pos; i<s; i++){
        v->v[i]=a[i];
    }
}

float vmt_get_v(vector v, int i){
    return v->v[i];
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

float vmt_dot_vv(vector a, vector b){
    float o = 0.;
    for (int i=0; i<a->l; i++){
        o+=a->v[i]*b->v[i];
    }
    return o;
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

void vmt_write_m(matrix m, float * a, int r, int c, int s){
    for(int i=r*m->c+c; i<s; i++){
        m->v[i]=a[i];
    }
}

float vmt_get_m(matrix m, int r, int c){
    return m->v[r*m->c+c];
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
    matrix a =vmt_rand_m(4, 3);
    vmt_print_m(a);
    printf("%f\n", vmt_get_m(a, 1, 1));
    return 0;
}
