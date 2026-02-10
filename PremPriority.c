#include<stdio.h>
int main(){
	int n;
	printf("enter numbber of processes:");
	scanf("%d",&n);
	int bt[n],wt[n],pr[n];
	int i,j;
	printf("enter priorities:");
	for(i=0;i<n;i++){
		scanf("%d",&pr[i]);
	}
	printf("enter burst times");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	
	for( i=0;i<n-1;i++){
		for( j=0;j<n-i-1;j++){
		int temp;
			if(pr[j+1]<pr[j]){
				 temp=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=temp;
				
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
			}
		}
		}
		wt[0]=0;
		for(int i=1;i<n;i++){
			wt[i]=wt[i-1]+bt[i-1];
		}
		float awt=0;
		for(int i=0;i<n;i++){
		awt=awt+wt[i];
	}
		awt=awt/n;
		printf("%faverage waiting time",awt);
}
