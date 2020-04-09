#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class project 
{
	public:
	int i,j,n,temp;
	int time=0,sum=0;
	int q=10;
	int *p=new int[n];
	int *bt=new int[n];
	int *at= new int[n];
	vector<int> rq;
	vector<int> gc;
	
	void getvalue()
	{
		cout<<"Enter No of Processes: ";
		cin>>n;
		cout<<"Enter Arival time and Burst Time respectively: "<<endl;
		for(i=0;i<n;i++)
		{
			cout<<"for process P"<<i+1<<" : ";
			cin>>at[i]>>bt[i];
			sum=sum+bt[i];
		}	
	}
	
	void process()
	{
		while(time<=sum)
		{
			cout<<"in Process";
			this->ready_queue();
			for(i=0;i<3;i++)
			{
				gc.push_back(n+1);
			}
		}
	}
		
	void ready_queue()
	{
		rq.clear();
		for(i=0;i<n;i++)
		{
			if(at[i]<=time)
			{
				rq.push_back(i);
			}
		}
		this->shortest_job();
	}
	
	void shortest_job()
	{
		int *p= new int[rq.size()];
		for(i=0;i<rq.size();i++)
		{
			temp=rq[i];
			p[i]=bt[temp];
		}
		sort(p,p+rq.size());
		temp=rq.size();
		rq.clear();
		for(i=0;i<n;i++)
		{
			for(j=0;j<temp;j++)
			{
				if(p[j]==bt[i])
				{
					rq.push_back(i);
				}
			}
		}
		this->gantt_chart();
	}
	
	void gantt_chart()
	{
		temp=rq[0];
		if(bt[temp]!=0)
		{
			if(bt[temp]<=q)
			{
				time=time+bt[temp];
				for(i=0;i<bt[temp];i++)
				{
					gc.push_back(temp);
				}
				bt[temp]=0;
				for(i=1;i<rq.size();i++)
				{
					rq[i-1]=rq[i];
				}
				rq.pop_back();
			}
			else
			{
				time=time+q;
				for(i=0;i<q;i++)
				{
					gc.push_back(temp);
				}
				bt[temp]=bt[temp]-q;
				temp=rq[0];
				for(i=1;i<rq.size();i++)
				{
					rq[i-1]=rq[i];
				}
				rq.pop_back();
				rq.push_back(temp);
			}
		}
	}
	
	void show_value()
	{
		int *tt=new int[n];
		int *wt=new int[n];
		for(i=gc.size()-1;i>=0;i++)
		{
			
		}
		
	}
};

int main()
{
	project o;
	o.getvalue();
	o.process();
	o.show_value();
	
}
