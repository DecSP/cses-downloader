# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define REP(i,a,b) for (int i=a;i<=b;i++)
using namespace std;
enum dir {N,E,S,W,Nothing};
const int size=7;
bool board [size+2][size+2]={0};
ll C=0;
string ss;

void Go(dir d,int & r, int & c){
	switch (d){
		case N:
				board[r-1][c]=true;
			break;
		case S:
				board[r+1][c]=true;
			break;
		case E:
				board[r][c+1]=true;
			break;
		default:
				board[r][c-1]=true;
		}
}

void recu(int n, int r,int c){
	if (n==size*size) {
		 C++;
	}
	else{
		if (r==size&&c==1) {
			board[r][c]=false;
			return;
		}
		bool cN=!board[r-1][c],cS=!board[r+1][c],cW=!board[r][c-1],cE=!board[r][c+1];
		if (ss[n-1]!='?'){
			switch(ss[n-1]){
				case 'R':
					if (cE) {Go(E,r,c);recu(n+1,r,c+1);}
					break;
				case 'U':
					if (cN) {Go(N,r,c);recu(n+1,r-1,c);}
					break;
				case 'L':
					if (cW)	{Go(W,r,c);recu(n+1,r,c-1);}
					break;
				default:
					if (cS) {Go(S,r,c);recu(n+1,r+1,c);}
			}
			board[r][c]=false;
			return;
		}
		if (!board[r-1][c] && board[r-2][c] ) {			
			if (board[r-1][c-1]||board[r-1][c+1]) cS=cE=cW=false;
			else cN=false;
		}
		if (r+1!=size&&c!=1&&!board[r+1][c] && board[r+2][c] ) {			
			if (board[r+1][c-1]||board[r+1][c+1]) cN=cE=cW=false;
			else cS=false;
		}
		if (!board[r][c+1] && board[r][c+2] ) {			
			if (board[r-1][c+1]||board[r+1][c+1]) cS=cN=cW=false;
			else cE=false;
		}
		if (r!=size&&c-1!=1&&!board[r][c-1] && board[r][c-2] ) {			
			if (board[r-1][c-1]||board[r+1][c-1]) cS=cE=cN=false;
			else cW=false;
		}
		if (cE) {Go(E,r,c);recu(n+1,r,c+1);}
		if (cN) {Go(N,r,c);recu(n+1,r-1,c);}
		if (cW)	{Go(W,r,c);recu(n+1,r,c-1);}
		if (cS) {Go(S,r,c);recu(n+1,r+1,c);}
	}
	board[r][c]=false;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	REP (i,0,8) {
		board[0][i]=board[i][0]=board[size+1][i]=board[i][size+1]=true;
	}
	cin>>ss;
	board[1][1]=true;
	recu(1,1,1);
	cout<<C<<endl;

	return 0;
}