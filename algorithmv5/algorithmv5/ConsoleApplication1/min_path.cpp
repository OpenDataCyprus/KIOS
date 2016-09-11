#include "min_path.h"


using namespace std;
int counter;


void printPath(int dest,int *prev,int *path,int *length) {
    if (prev[dest] != -1){
        printPath(prev[dest],prev,path,length);
 //       std::cout<<" -> ";
        }
  // std::cout<< dest;
    counter++;
    path[counter]=dest;
	//cout<<dest;
    *length=counter;


}

void print_node_paths(const int *numnodes,const long double *d,const int p,int *prev,int *path,int destination,int *length)
{   counter=-1;
    printPath(destination,prev,path,length);
 // std:: cout<<std::endl;
// cout<<*length<<endl;
}

