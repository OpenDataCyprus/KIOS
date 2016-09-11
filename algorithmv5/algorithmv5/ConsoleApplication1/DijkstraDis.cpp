#include "DijkstraDis.h"

#define INFINITE 99999999

void dijkstraDis(int source,  int numNodes, int num_of_edges, int n,double **matrix,int *prev,long double *d,  int* visited, double distance, int difLevel, int *dest, double **adjList ) {


    int i, k, mini;
		double currentLaneCost=0.0;
	double distToCover=distance;
	int elevationPos;
    //int visited[num_of_edges];

   long double * dTemp= new long double [numNodes+1];



    // Arxikopoiiseis
    for (i = 0; i <= n; ++i) { 
        d[i] = INFINITE;
        prev[i] = -1;  
        visited[i] = 0; 
		dTemp[i]=INFINITE;
	}
    d[source] = 0;
	    dTemp[source] = 0;


    // Evresi komvu ton opoio den ehume episkefti,
    for (k = 0; k <= n; ++k)
    {
        mini = -1;
        for (i = 0; i <= n; ++i)
            if (!visited[i] && ((mini == -1) || (dTemp[i] < dTemp[mini])))
                mini = i;

        visited[mini] = 1;

        for (i = 0; i <= n; ++i){
            if (matrix[mini][i]!=INFINITE){

				for (int h=0; h<num_of_edges;h++){

					if ( (adjList[h][0]==mini) && (adjList[h][1]==i))
					{
						elevationPos=h;
						h=num_of_edges+10;
				
					}
				}
				if(difLevel==1){ // expert

					 currentLaneCost=(matrix[mini][i])-5*adjList[elevationPos][3]+100;

				}else{
									
					if(difLevel==2){ // Intermidiate
							
					 currentLaneCost=(matrix[mini][i])+1*adjList[elevationPos][3]+100;
					
					}else{// basic 
							
					 currentLaneCost=(matrix[mini][i])+5*adjList[elevationPos][3]+100;

					}
				}
                          
				if (dTemp[mini] +currentLaneCost < dTemp[i])
                {
                    d[i] = d[mini] + matrix[mini][i];
                    prev[i] = mini;
					dTemp[i]=dTemp[mini] +currentLaneCost ;

					if(d[i]>=distToCover){

						*dest=i;

						i=n+10;
						k=n+10;
											
					}

			
			}}
    }





}
}