#include <iostream>
#include <ctime> 
#include <vector>
#define MAX 1000
using namespace std;

unsigned t2, t3;
double C[MAX][MAX], A[MAX][MAX], B[MAX][MAX];

//Lleno matrices A y B
void init(){
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++){
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
}


void mulBloques(){
    int bi, bj, bk, i, j, k;
    bi = bj = bk = i =  j = k = 0;
    int blockSize=10; 
    t2=clock();
    for(bi=0; bi<MAX; bi+=blockSize){
        for(bj=0; bj<MAX; bj+=blockSize){
            for(bk=0; bk<MAX; bk+=blockSize){
                for(i=0; i<blockSize; i++){
                    for(j=0; j<blockSize; j++){
                        for(k=0; k<blockSize; k++){
                            C[bi+i][bj+j] += A[bi+i][bk+k]*B[bk+k][bj+j];
                        }
                    }
                }
            }
        }
    }
    t3=clock();                            
}
int main() {

    //MULTIPLICACION POR BLOQUES
    init();
   
    mulBloques();
    double time1 = (double(t3-t2)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejec.: " << time1 << endl;
    
}