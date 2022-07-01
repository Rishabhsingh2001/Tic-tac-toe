#include<iostream>
using namespace std;
class Player
{
	public:
	string name;
	int symb;
	void getdetails();
	void disp();	
};

void Player::getdetails()
{
	cout<<"\n Enter the name = ";
	cin>>name;
	do
	{
		cout<<"\n Enter the symbol (other than 0 and -1)= ";
		cin>>symb;		
	}while(symb==0 || symb==-1);

}
void Player::disp()
{
	cout<<"\n________________________________\n";
	cout<<"\n PLAYER    =  "<<name;
	cout<<"\n SYMBOL    =  "<<symb<<endl;	
}


int moves,pos;

void reset(int a[],int n);
void display(int a[],int n);
int check(int a[],Player p);

int main()
{
	int a[9];	
	reset(a,9);
	display(a,9);
	Player p;
	moves=1;
	Player ob1,ob2;
	ob1.getdetails();
	ob2.getdetails();
	while(ob1.symb==ob2.symb)
	{
		cout<<"\n Chose another int symbol = ";
		cin>>ob2.symb;
	}
	
	
	while(moves<=9)
	{
		if(moves%2==1)
		{
			do
			{
				cout<<"\nPlayer 1 "<<ob1.name<<" make a move(select pos) = ";
				cin>>pos;	
			}while(a[pos]!=0);
			a[pos]=ob1.symb;
			p = ob1;
		}
		else
		{
			do
			{
				cout<<"\nPlayer 2 "<<ob2.name<<" make a move(select pos) = ";
				cin>>pos;	
			}while(a[pos]!=0);
			a[pos]=ob2.symb;
			p=ob2;
		}
		
		display(a,9);
		if(check(a,p)==ob1.symb)
		{
			cout<<"\nWinner......\n";
			ob1.disp();
			break;
		}
		else if(check(a,p)==ob2.symb)
		{
			cout<<"\nWinner......\n";
			ob2.disp();
			break;
		}
		moves++;		
	}
	
	if(moves==10)
		cout<<"\nDraw\n";
	
	return 0;
}

void reset(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=0;
	}
}
void display(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		if(i%3==0)
			cout<<endl;
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}

int check(int a[],Player p)
{
	if(
		(a[0]==p.symb && a[1]==p.symb && a[2]==p.symb )||
		(a[3]==p.symb && a[4]==p.symb && a[5]==p.symb )||
		(a[6]==p.symb && a[7]==p.symb && a[8]==p.symb )||
		(a[0]==p.symb && a[3]==p.symb && a[6]==p.symb )||
		(a[1]==p.symb && a[4]==p.symb && a[7]==p.symb )||
		(a[2]==p.symb && a[5]==p.symb && a[8]==p.symb )||
		(a[0]==p.symb && a[4]==p.symb && a[8]==p.symb )||
		(a[2]==p.symb && a[4]==p.symb && a[6]==p.symb )
	)
	{
		return p.symb;	
	}
	else
	{
		return -1;
	}
}



