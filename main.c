#include <stdio.h>
#include <omp.h>
#include "pgm.h"



int main(){

PGMImage *in=pgm_read("C:\\Users\\LENOVO i5\\Desktop\\Project-A\\apple.pgm");

if(!in){
printf("Error reading input\n");
return 1;
}

int w=in->width;
int h=in->height;
int N=w*h;
int maxval=in->maxval;

PGMImage *out_seq=pgm_create(w,h,in->maxval);
PGMImage *out_par=pgm_create(w,h,in->maxval);


////////////////////////seq////////////////////////

double t0=omp_get_wtime();
for(int i=0;i<N;i++){
    out_seq->data[i]=maxval- in->data[i];
}
   double t1=omp_get_wtime();
   double Tseq=t1-t0;

///////////////////////////////////////////////////




////////////par///////////////////////////////////
t0=omp_get_wtime();

#pragma omp parallel for
for(int i=0;i<N;i++){
    out_par->data[i]=maxval- in->data[i];
}
t1=omp_get_wtime();
double Tpar=t1-t0;



int is_identical=1;
for(int i=0;i<N;i++){
    if(out_par->data[i] != out_seq->data[i]){
    is_identical=0;
    break;
    }
}


pgm_write("negative-apple_seq.pgm",out_seq);
pgm_write("negative-apple_para.pgm", out_par);

printf("Tseq=%f\n",Tseq);
printf("Tpar=%f\n",Tpar);
printf("Speedup=%f\n",Tseq/Tpar);

pgm_free(in);
pgm_free(out_seq);
pgm_free(out_par);


return 0;}