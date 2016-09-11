#include "min_pathLap.h"


using namespace std;
int counterr;


void printPathLap(int dest,int *prev,int *path,int *length) {
    if (prev[dest] != -1){
        printPathLap(prev[dest],prev,path,length);
 //       std::cout<<" -> ";
        }
  // std::cout<< dest;
    counterr++;
    path[counterr]=dest;
    *length=counterr;


}

void print_node_pathsLap(const int *numnodes,const long double *d,const int p,int *prev,int *path,int destination,int *length)
{   counterr=-1;
    printPathLap(destination,prev,path,length);
 // std:: cout<<std::endl;
// cout<<*length<<endl;
}

