#include<iostream>
//#include<fstream>
using namespace std;

int main()
{
//ifstream file_("input.txt");

//if (file_.is_open()){

	int numOfProcess , WT[20] , BT[20] , AT[20] , TAT[20] , i=0 , j=0 , m=0 , k=1,l=0;
	double avWT=0,avTAT=0,avBT=0,RSTime=0,cpu;
	int sumAT=0 , sumBT=0 ,x=0 , y=0;

	cout<<"Enter number of process <maximum 20> \n";
	cin>>numOfProcess;

	cout<<"PID\tArrival T\tBurst T\n";
	cout<<"---------------------------------\n";

	//insert arivel time & burst time
	for ( i; i<numOfProcess; i++)
	{
		cout<<i<<"\t";
		cin>>AT[i];
		cout<<"\t\t\t";
		cin>>BT[i];
		cout<<"\t\n";
	}

	for (i=0; i<BT[m]; i)
	{
		cout<<"<system time   "<<l<<">"<<"process   "<<k<<"is running\n";
		l++;
		i++;
		
		if (i==BT[m])
		{
			cout<<"<system time   "<<l<<">"<<"process   "<<k<<"is finished......\n";
			m++;
			k++;
			i=0;
		

		if (m==numOfProcess)
		{cout<<"<system time   "<<l<<">"<<"all process  finish...........\n";}
	}

	}

	//sum of arrival time
	for (i=0 ; i<numOfProcess ; i++)
	{
		sumAT+=AT[i];
	}

	//sum of burst time
	for (i=0 ; i<numOfProcess ; i++)
	{
		sumBT+=BT[i];
	}


	//calculate respons time
	
	y = sumBT - BT[numOfProcess - 1];
	x = y;

	for (i = numOfProcess - 2 ; i > -1 ; i--) 
	{
		y = y - BT[i] ;
		x = x + y ;
	}

	//clculat average waiting time
	WT[0]=0;
	for (i=1;i<numOfProcess;i++)
	{
		WT[i]=0;
		for(j=0;j<i;j++)
			WT[i]+=BT[j];
				
	}

	//clculate  average turnaround time
	for (i=0;i<numOfProcess;i++)
	{
		if (i == 0) {
			TAT[i] = BT[i];
		}
		
		else 
		TAT[i] = BT[i] + WT[i] ;
		avTAT += TAT[i];
	}
	
       avWT = (avTAT - sumAT - sumBT) / numOfProcess;
	avTAT = (avTAT - sumAT) / numOfProcess;
	RSTime = (x - sumAT) / numOfProcess;
	
	

	cout << "Average Cpu useage:" << ( (sumBT/l ))*100 <<"%"<< endl;
	cout << "Average Response Time:" << RSTime << endl;
	cout<<"average Waiting Time : "<<avWT<<"\n";
	cout<<"avarage Turnaround Time : "<<avTAT<<"\n";


	//file_.close();}

	system("pause");
	return 0;
}
