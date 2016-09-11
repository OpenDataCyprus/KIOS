// basic file operations
#include <stdlib.h>
#include <stdio.h>      /* printf, NULL */
#include <string.h>
#include <iostream>
#include <math.h>
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include<time.h>
#include <iomanip>



	
#define MAX(a, b) ((a > b) ? (a) : (b))

#include "Haversine.h"
#include "dijkstraDis.h"
#include "dijkstraTime.h"
#include "dijkstraTimevSecond.h"
#include "DijkstraDisvSecond.h"
#include "min_path.h"


using namespace std;

int main () {



///////////////////////////////////////////////////////////////////////////////////
	


		ofstream myfile;

		stringstream converter;
		string readLine;
		string tmp;
		string tmpb;
	   double **adj_matrix;
	   double **adj_matrixTemp;

		string tmpc;
		 int numNodes=0;
		long int numWays=0;
		long int longestPath=0;
		long int tmpLongestPath=0;
		long int flag=1;
	    long int flagb=1;
	    long double **nodesPos;
		long long int **ways;
		long int wayCount=0;
		long int nodeCount=0;
		long int index=0;
		long int wayPath=0;
		long int wayFlag=0;
		double ** adjList;
		/////////////////////
		int firstNode=0;
		int secondNode=0;
		long double distance=0;
		int numOfLinks=0;
		int wayIndex=0;
		double elevationUpStream=0;
		double elevationDownStream=0;
		int flagDublicateLink=0;
		int source=0;
		int num_of_edges;
		int u;
		int v;
		int n;
		double *elevation;
	   long double *d;        // Pinakas gia apothikefsi tu mikroteru kostus gia kathe komvo
        int *prev;      // Pinakas gia apothikefsi tu monopatiou me to mikrotero kostos pu akoluthite
        int* visited ;
		double ** laneDurMatrix;
		double weight;
        int *path;
		int *pathFinal;
        int length;
        int dest;
		int sourceTemp;
		double duration;
		int difLevel=0;
		int disOrTime=0;
		int LapMode=0; // 0 is false 1 is true
		double speed=0;
		int firstPathStop=0;

		        
		
		ifstream fin;
		ifstream finb;



		fin.open("adjlist.txt");
	    finb.open("nodespos.txt");


       // Diavasma arithmu komvwn kai arithmu akmvn
       fin >> num_of_edges;
	   finb>> numNodes;

	     path=new int [numNodes+1];
		 pathFinal= new int [numNodes+1];

		  n = -1;
		           
		 for(int i=0; i<=numNodes;i++){
               path[i]=-1;
			   pathFinal[i]=-1;
              }

           d = new long double [numNodes+1];
           prev = new int [numNodes+1];
           visited = new int[numNodes+1];




	   nodesPos= new long double*[numNodes];
		for(int i = 0; i < numNodes; ++i)
			nodesPos[i] = new long double[4];
		       
		adj_matrix=new double *[numNodes+1];// numnodes +1 because we have the 0 where we dont count for it
           for (int i=0; i<=(numNodes); i++)
                 adj_matrix[i]=new double [numNodes+1];

		   		adj_matrixTemp=new double *[numNodes+1];// numnodes +1 because we have the 0 where we dont count for it
           for (int i=0; i<=(numNodes); i++)
                 adj_matrixTemp[i]=new double [numNodes+1];


		       for (int i = 0; i <= numNodes; i++)
             for (int j = 0; j<= numNodes ;j++){
                 adj_matrix[i][j] =99999999 ;
				 adj_matrixTemp[i][j]=99999999 ;}


			   adjList= new double*[num_of_edges+1];
		
			   for(int i = 0; i < num_of_edges+1; ++i)
					adjList[i] = new double[4];

			   elevation = new double[num_of_edges];


			   
			   for (int i = 0; i < num_of_edges; i++){

		
				  fin>>u;
				  fin>>v;
				  fin>>weight;
				  fin>>elevation[i];

				  //cout<<u<<" "<<v<<" "<<weight<<" "<<elevation[i]<<endl;
				  //int a;
				  //cin>>a;


				  v=v;
				  adj_matrix[u][v] =weight;
				  adj_matrixTemp[u][v] =weight;

				  adjList[i][0]=u;
				  adjList[i][1]=v;
				  adjList[i][2]=weight;
				  adjList[i][3]=elevation[i];

				  n = MAX(u, MAX(v, n));

		  }
				 

			   			    
			   for (int i = 0; i < numNodes; i++){


				   fin>>nodesPos[i][0];			   				   
				   fin>>nodesPos[i][1];
				   fin>>nodesPos[i][2];
				   fin>>nodesPos[i][3];

							
			   }


/////////////////////////////tHESE ARE THE ARQUMENTS/////////////////////////////////////



				cout<<"Give: 1->Expert 2->Intermidiate 3-> Basic"<<endl;
				cin>>difLevel;

				

				cout<<"Give: 1->Time 2->Distance Traning"<<endl;
				cin>>disOrTime;

				if(disOrTime==1){
					cout<<"Duration??"<<endl;
					cin>>duration;
				}else{
				
					cout<<"Distance??"<<endl;
					cin>>duration;
				
				}
				
	


				cout<<"Source"<<endl;


				cin>>source;
				// Speed declares

////////////////////////////////////////////////////////////////////////////////////////////////

				if (disOrTime==1){// this is for time based exercises 

						switch (difLevel){

						case 1: {			
					
							speed=8;
								break;


							}

						case 2: {
							speed=4;
							break;
							}
						case 3 : {
							speed=2;

							break;
					
								 }					
				
						default:
							break;
						}


						
						length=0;
												
						
						for(int i=0; i<numNodes;i++){
							path[i]=-1;
							pathFinal[i]=-1;
							}


						DijkstraTime(source,numNodes,num_of_edges,n,adj_matrix,prev,d,visited, duration, speed, difLevel, &dest, adjList);
						cout<<dest<<endl;

						print_node_paths(&numNodes,d,source,prev,path,dest,&length);


						for (int q=0; q<=(length);q++){
							pathFinal[q]=path[q];
						//	cout<<path[q]<<"->";
								
						}

						if(difLevel==1){//expert means path must be set as more easy
						

						for (int q=0; q<=(length-1);q++){
							adj_matrixTemp[path[q+1]][path[q]]=1;
							
						}

						}else{
							if(difLevel==2){
										for (int q=0; q<=(length-1);q++){
							adj_matrixTemp[path[q+1]][path[q]]=adj_matrix[path[q+1]][path[q]]+200;
										}
								
								
					}else{

						for (int q=0; q<=(length-1);q++){
											
							adj_matrixTemp[path[q+1]][path[q]]=adj_matrix[path[q+1]][path[q]]+500;
						}
								}

							
							
				}

				firstPathStop=length;

				length=0;
							            
				for(int i=0; i<numNodes;i++){
					path[i]=-1;
					}


				sourceTemp=source;
				source=dest;
				dest=sourceTemp;
				//cout<<source<<" "<<dest<<endl;

				DijkstraTimevSecond(source,numNodes,num_of_edges,n,adj_matrixTemp,prev,d,visited, duration, speed, difLevel, adjList);


			    print_node_paths(&numNodes,d,source,prev,path,dest,&length);

					// cout<<firstPathStop<<endl;

				//  cout<<endl;

				for (int q=0; q<=(length);q++){
					pathFinal[q+firstPathStop]=path[q];
					//	cout<<path[q]<<"->";

								
								
				}


				firstPathStop=firstPathStop+length;

				cout<<endl;
				for (int q=0; q<=(firstPathStop);q++){
							
					cout<<pathFinal[q]<<"->";
				}



				}else{ // this  is for distance based exercises
	

							
				length=0;
												
						
				for(int i=0; i<numNodes;i++){
					path[i]=-1;
					pathFinal[i]=-1;
					}


				dijkstraDis(source,numNodes,num_of_edges,n,adj_matrix,prev,d,visited, duration, difLevel, &dest, adjList);
				cout<<dest<<endl;

			    print_node_paths(&numNodes,d,source,prev,path,dest,&length);


				for (int q=0; q<=(length);q++){
					pathFinal[q]=path[q];
				//	cout<<path[q]<<"->";
								
				}

				if(difLevel==1){//expert means path must be set as more easy
						

				for (int q=0; q<=(length-1);q++){
					adj_matrixTemp[path[q+1]][path[q]]=1;
							
				}

				}else{
					if(difLevel==2){
								for (int q=0; q<=(length-1);q++){
					adj_matrixTemp[path[q+1]][path[q]]=adj_matrix[path[q+1]][path[q]]+200;
								}
								
								
					}else{

						for (int q=0; q<=(length-1);q++){
											
							adj_matrixTemp[path[q+1]][path[q]]=adj_matrix[path[q+1]][path[q]]+500;
						}
								}

							
							
				}

				firstPathStop=length;

				length=0;
							            
				for(int i=0; i<numNodes;i++){
					path[i]=-1;
					}


				sourceTemp=source;
				source=dest;
				dest=sourceTemp;
				//cout<<source<<" "<<dest<<endl;


				dijkstraDisvSecond(source,numNodes,num_of_edges,n,adj_matrixTemp,prev,d,visited, duration, difLevel, &dest, adjList);


			    print_node_paths(&numNodes,d,source,prev,path,dest,&length);

					// cout<<firstPathStop<<endl;

				//  cout<<endl;

				for (int q=0; q<=(length);q++){
					pathFinal[q+firstPathStop]=path[q];
					//	cout<<path[q]<<"->";

								
								
				}


				firstPathStop=firstPathStop+length;

				cout<<endl;
				for (int q=0; q<=(firstPathStop);q++){
							
					cout<<pathFinal[q]<<"->";
				}


					
				}
				


				 // dijkstraN(source, n, adj_matrix, prevN, dN,  visitedN);
					// print_node_paths(&numnodes,dN,source,prevN,pathN,dest,&lengthN);

			cout<<"FINISH";
			int a;
			cin>>a;

 return 0;



}