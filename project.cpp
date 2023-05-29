#include<iostream>
using namespace std;

bool issafe ( int graph[][31]  , int color[] , int itemcolor , int n);
bool graphcolor(int graph[][31] ,int color[] , int numberofcolor , int n);
void printgraph(int color[]);

int main(){
	
	//tarif moteghayer 
	
	// the matris of the Iran map.
    int graph[][31] = {
     //0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30
          //0/azarbayejan ghrbi
		  {0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          //1/azarbayejan sharghi
		  {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          //2/zangan
		  {1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          //3/kordestan 
		  {1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          //4/ardebil
		  {0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          //5/gilan
		  {0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          //6/ghazvin 
		  {0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          //7/hamedan 
		  {0,0,1,1,0,0,1,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          //8/kermanshah 
		  {0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          //9/mazandaran 
		  {0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          //10/alborz
		  {0,0,0,0,0,0,1,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          //11/tehran
		  {0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
          //12/markazi
		  {0,0,0,0,0,0,1,1,0,0,1,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
          //13/lorestan
		  {0,0,0,0,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
          //14/ilam
		  {0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
          //15/golestan
		  {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
          //16/semnan
		  {0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,0,0,0,0,0,0},
          //17/
		  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,1,0,0,0,0,0},
          //18/
		  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,1,1},
          //19/
		  {0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
          //20/
		  {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,1,0,0,0,0,0,1,0,1,0},
          //21/
		  {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0},
          //22/
		  {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0},
          //23/
		  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
          //24/
		  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0},
          //25/
		  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1,0,0,0,0},
          //26/
		  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1},
          //27/
		  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0},
          //28/
		  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,1},
          //29/
		  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1},
          //30/
		  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,1,0}
        };
        
//	int n,m;
//	cout<<"please enter your length of your graph";
//	cin>>n;
//	cout<<"please enter your width of your graph";
//	cin>>m;
//	int graph[n][m];
//	for(int i; i<n ; i++)
//	  for (int j ; i<m ;j++){
//	  	cin>>iran[i][j];
//	  }


	int numberofcolor;
	cout<<"please enter your number of color :";
	cin>>numberofcolor;
	
//	int node;
//	cout<<"please enter your node of your graph";
	int color[31]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	if(graphcolor( graph , color , numberofcolor ,0) == false)
	   cout<<"solution does not exist"<<endl;
	   
	    
	return 0;
}

//tabe chek kardan emkan rang amizi 
bool issafe(int graph[][31] ,int color[] , int itemcolor , int n){
	
	for(int i=0 ; i < 31 ; i++)
		if(graph[n][i]==1 && color[i]==itemcolor)
		   return false;
		
	return true; 
}

//tabe rang amizi 
bool graphcolor(int graph[][31] , int color[] , int numberofcolor , int n){
	
	if(n==31){
		printgraph(color);
		return true;	
	}
	
	for(int i=1 ; i <=numberofcolor ; i++ ){
		if(issafe(graph,color,i,n)){
			color[n]=i;
				
////	graphcolor(graph ,color, numberofcolor ,n+1);

/* in if mige agar rang amizi man baraye in node dorost bashe man bayad node badi ra ham
   rang amizi konam. agar natavanestam node badi ra rang amizi konam rang entekhabi baraye 
   node feli eshtebah bode va bayad rang digari entekhab kard
*/
//dar in tabe ma node haye digar ra rang amizi mikonim
	if(graphcolor(graph ,color, numberofcolor ,n+1))
		return true;
		
		color[n]=0;	
		}
	}
	return false;
}

//tabe print javab dar khorogi
void printgraph(int color[]){
	char ch[31];
	//tabdil adad be horof
	for(int i=0 ; i <= 30 ; i++){
		if(color[i]==1) ch[i]='R';
		if(color[i]==2) ch[i]='B';
		if(color[i]==3) ch[i]='Y';
		if(color[i]==4) ch[i]='G';
		if(color[i]==5) ch[i]='P';
		if(color[i]==6) ch[i]='W';
		if(color[i]==7) ch[i]='O';
	}
	
	cout<<"answer of Solution: \n";	
	for(int i=0 ; i <= 30 ; i++){
		cout<<ch[i]<<"  ";
	}
//	cout<<endl;
//	cout<<"******************"<<endl;
}


