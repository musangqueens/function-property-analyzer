#include<iostream>
#include<string>
#include<string.h>
#include<windows.h>
#include<ctime>
#include<conio.h>
#include<cctype>

using namespace std;

void checkLength(),functionInput(),symmetricOutput(),symmetricCheck(), eflexCheck(),reflexOutput(),transCheck(),transOutput();

int y=0, length=0, diffPair=0, rTemp=0, cTemp=0, pair=0, i=0,r=0,c=0,r1=0,c1=0, ns=0; 
int same=0, symmetric=0, notSymmetric=0, found=0, next=1, reflexive=0;
int storage[4][10], tempArray[2][10], tempStorage[2][10], symRecommend[2][10], refRecommend[2][10], transRecommend[2][10];
bool transitive=false;

int main(){

		cout<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		cout<<"Insert your function details according the format below !!!"<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		cout<<endl;
		cout<<"Example R = {(1,3), (1,4), (2,3), (12,4), (3,17), (3,45)}"<<endl;
		cout<<"Number of elements : 12"<<endl;
		cout<<"Input 1 3 1 4 2 3 12 4 3 17 3 45 (One element at a time)"<<endl;
		cout<<endl;
		cout<<"Example S = {(3,13), (15,4), (7,6)}"<<endl;
		cout<<"Number of elements : 6"<<endl;
		cout<<"Input 3 13 15 4 7 6 (One element at a time)"<<endl<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl<<endl;
		
		system("pause");
		system("cls");
		
		checkLength();
		functionInput();
		symmetricCheck();
		symmetricOutput();	
		reflexCheck();
		reflexOutput();
		transCheck();
		transOutput();
		cout<<endl;
		
		return 0;
	}


void checkLength(){
	//system("cls");
	cout<<"Input number of elements : ";
	cin>>length;
	if(length%2 != 0){
		checkLength();
	}
}

void functionInput(){
	
	cout<<endl<<"Input your elements : "<<endl<<endl;
	
		for(r=0; r<(length)/2; r++){
			for(c=0; c<2; c++){
				cin>>storage[r][c];

			}
		}
	system("cls");
	cout<<"Your set is : ";
	
		for(r=0; r<(length)/2; r++){

				cout<<"("<<storage[r][0]<<","<<storage[r][1]<<") ";
		}
		cout<<endl<<endl;
}

void symmetricCheck(){

	for(r1=0; r1<(length/2); r1++){//Copy array
		//Recopying array
		tempStorage[r1][0]=storage[r1][0];
		tempStorage[r1][1]=storage[r1][1];
	
		//Marking (a,a) like from tempStorage
		if(storage[r1][0]==storage[r1][1]){
			tempStorage[r1][0]=-999; 
			tempStorage[r1][1]=-999;
			same++;
		}
	}

	for(r1=0; r1<(length/2); r1++){//row ori

		if(tempStorage[r1][0]!=-999 || tempStorage[r1][1]!=-999){//Exempting (a,a) like from searching
			
			for(r=0; r<(length/2); r++){
				
				if(storage[r1][0]!=tempStorage[r][1] && storage[r1][1]!=tempStorage[r][0]){
					
					ns=1;						
					if(r==(length/2)-1){//maximum loop for a row
						symRecommend[r1][0]=storage[r1][0];
						symRecommend[r1][1]=storage[r1][1];
						ns=(ns/ns);
					}
				}

				else if(storage[r1][0]==tempStorage[r][1] && storage[r1][1]==tempStorage[r][0]){
					
					ns=0;
					symmetric++;
					break;//Immediately terminate search for this row
				}
			}	
		}
		else{
			symRecommend[r1][0]=-999;
			symRecommend[r1][1]=-999;	
			}
	notSymmetric+=ns;
	}
	
	symmetric=symmetric/2;


}

void symmetricOutput(){
	
	if( notSymmetric==0){
		cout<<"Function is symmetric."<<endl<<endl;
		}
		
	else{
		cout<<"Not symmetric, ";
			
		for(r1=0; r1<length/2; r1++){
				
			if(symRecommend[r1][0]!=-999 && symRecommend[r1][1] !=-999 && (symRecommend[r1][0] != symRecommend[r1][1])){
	
				cout<<"("<<symRecommend[r1][1]<<","<<symRecommend[r1][0]<<") ";		
					}
				}
			cout<<"is/are missing from function."<<endl<<endl;
		}
}

void reflexCheck(){
	
	for(r1=0; r1<(length/2); r1++){
	
		storage[r1][2]=0;//Mark 0 all flags
		
			for(r=0;r<(length/2); r++){//Searching every row
			
				if(storage[r][0]==storage[r][1]){
					
					storage[r][2]=-1; //Flag -1 for all (a,a)
					
					if(storage[r1][0]==storage[r][0]){
						
						storage[r][2]=-1; //Flag -1 for (a,b) that have (a,a)
						storage[r1][2]=-1;//Flag the (a,a) head
					}
				}
			}
		
	reflexive=reflexive+storage[r1][2];
	}
}

void reflexOutput(){
	
	if(reflexive==((length/2)/-1) ){
		
		cout<<"Function is reflexive."<<endl<<endl;
	}
	
	else{
		
		cout<<"Not reflexive, ";
			
			for(int i=0; i<(length/2); i++){
					
				if(storage[i][2]!=-1){
						
					cout<<"("<<storage[i][0]<<","<<storage[i][0]<<") ";
				}
			}
		cout<<"is/are missing from your function."<<endl<<endl;
	}
	
	
}

void transCheck(){

	for(r1=0; r1<(length/2); r1++){//Searching every primary row
		
		for(r=0;r<(length/2); r++){//Searching every secondary row
		
			if(storage[r1][1]==storage[r][0]){//Filter if (a,b) & (b,c) is found
	
				for(int i=0; i<(length/2); i++){//Searching for (a,c)
					
					if(storage[r1][0]==storage[i][0] && storage[r][1]==storage[i][1]){
						reflexive++;
						transitive=true;
						//storage 4th col is for transitive flags
						storage[r1][3]=-1;
						storage[r][3]=-1;
						storage[i][3]=-1;
						//Marks which storage is transitive
						break;
					}
				}
			}
		}
	}
	
	
}

void transOutput(){

	if(transitive==false){
		
		for(r1=0; r1<(length/2); r1++){//Searching every primary row
		
			for(r=0;r<(length/2); r++){//Searching every secondary row
				
				if(storage[r1][1]==storage[r][0]){//Filter if (a,b) & (b,c) is found
				
					transRecommend[r1][0]=storage[r1][0];
					transRecommend[r1][1]=storage[r][1];
				
				}
				
			}
		}
		
		cout<<"Not transitive, you may add ";
		
			for(int i=0; i<(length/2); i++){
					
				if(transRecommend[i][0]!=0 && transRecommend[i][0]!=0 ){
						
					cout<<"("<<transRecommend[i][0]<<","<<transRecommend[i][1]<<") ";
				}
			}
		cout<<"to make your function transitive."<<endl;
	}
	
	else{
		
		cout<<"Function is transitive."<<endl;
		
	}	
	
}
