#include<iostream>

using namespace std;
 
int main()
{
    int Prior[20]={2,6,3,5,4,10,9,1,12,3};
	int Process10[20],wt[20],tat[20],i,j,Position10,Buffer;
	float Average_wt=0,Average_tat=0,total=0,total10=0;
	int Bursttm10[20]={1,6,7,3,6,5,15,8,4,12};
    for(i=0;i<10;i++)
    {
        cout<<"\nP["<<i+1<<"]\n";
        cout<<"Burst Time: "<<Bursttm10[i];
        cout<<" Priority: "<<Prior[i];
       	Process10[i]=i+1;  
		cout<<endl;
    }
 
    for(i=0;i<10;i++)
    {
        Position10=i;
        for(j=i+1;j<10;j++)
        {
            if(Prior[j]>Prior[Position10])
                Position10=j;
        }
 
        Buffer=Prior[i];
        Prior[i]=Prior[Position10];
        Prior[Position10]=Buffer;
 
        Buffer=Bursttm10[i];
        Bursttm10[i]=Bursttm10[Position10];
        Bursttm10[Position10]=Buffer;
 
        Buffer=Process10[i];
        Process10[i]=Process10[Position10];
        Process10[Position10]=Buffer;
    }
 
    wt[0]=0; 
 
    //calculate waiting time
    for(i=1;i<10;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=Bursttm10[j];
 
        total+=wt[i];
    }
 
    total=0;
 
    cout<<("\nPriority\t");
	cout<<" \tProcess\t";
	cout<<"\t\tBurst Time\t";
	cout<<"\tWaiting Time\t";
	cout<<"\tTurnaround Time";
	
    for(i=0;i<10;i++)
    {
        tat[i]=Bursttm10[i]+wt[i];  
		   
		total10=total10+tat[i];
		
        total+=wt[i];
        
        cout<<"\n"<<Prior[i]<<"\t\t\t"<<"P["<<Process10[i]<<"]\t\t\t "<<Bursttm10[i]<<"\t\t\t  "<<wt[i]<<"\t\t\t"<<tat[i];
    }
    
    Average_wt=total/10;
	Average_tat=total10/10;  
    cout<<"\n\n	Average Waiting Time="<<Average_wt;
    cout<<"\nAverage Turnaround Time="<<Average_tat;
 
    return 0;
}
