#include "min_pathTrail.h"


using namespace std;
int counterrr;


void printPathTrail(int dest,int *prev,int *path,int *length) {
    if (prev[dest] != -1){
        printPathTrail(prev[dest],prev,path,length);
 //       std::cout<<" -> ";
        }
  // std::cout<< dest;
    counterrr++;
    path[counterrr]=dest;
    *length=counterrr;


}

void print_node_pathsTrail(const int *numnodes,const long double *d,const int p,int *prev,int *path,int destination,int *length)
{   counterrr=-1;
    printPathTrail(destination,prev,path,length);
 // std:: cout<<std::endl;
// cout<<*length<<endl;
}

