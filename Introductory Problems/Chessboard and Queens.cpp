# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define REP(i,a,b) for (int i=a;i<=b;i++)
using namespace std;
bool board [8][8];
int c=0;

class {
	bool col[8]{0};
	bool diagl[15]{0};
	bool diagr[15]{0};
	int toDiagL(int r, int c){
		return r-c+7;
	}
	int toDiagR(int r, int c){
		return r+c;
	}
public:
	bool checkAll(int r, int c){
		return !(col[c] || diagl[toDiagL(r,c)]||diagr[toDiagR(r,c)]);
	}
	void setAll(int r, int c){
		col[c]=diagl[toDiagL(r,c)]=diagr[toDiagR(r,c)]=1;
	}
	void resetAll(int r, int c){
		col[c]=diagl[toDiagL(r,c)]=diagr[toDiagR(r,c)]=0;
	}	
} check;
void recu(int r){
	if (r==8) c++;
	else{
		REP(i,0,7){
			if (board[r][i]) continue;
			if (!check.checkAll(r,i)) continue;
			check.setAll(r,i);
			recu(r+1);
			check.resetAll(r,i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	REP (i,0,7){
		cin>>s;
		REP(j,0,7)
		{
			if (s[j]=='.') board[i][j]=0;
			else board[i][j]=1;
		}
	}
	recu(0);
	cout<<c<<endl;
	return 0;
}