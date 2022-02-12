#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;cin>>s;
	int n=s.size();
	string ns="|";
	for (char&c:s){
		ns.push_back(c);
		ns.push_back('|');
	}
	int nn=ns.size();
	vector<int> mxrad(nn,0);
	int rad=0,cen=0;
	while (cen<ns.size()){
		while (cen-rad-1>=0&&cen+rad+1<ns.size()&&ns[cen-rad-1]==ns[cen+rad+1]) ++rad;
		mxrad[cen]=rad;

		int oldcen=cen,oldrad=rad;
		cen+=1;rad=0;

		while (oldcen+oldrad>=cen){
			int mircen=oldcen-(cen-oldcen);
			int mxlen=oldcen+oldrad-cen;
			if (mxrad[mircen]<mxlen){
				mxrad[cen]=mxrad[mircen];
				cen+=1;
			}
			else if (mxrad[mircen]>mxlen){
				mxrad[cen]=mxlen;
				cen+=1;
			}
			else {
				rad=mxlen;
				break;
			}
		}
	}
	int mxi=-1,mx=-1;
	for (int i=0;i<nn;++i){
		if (mxrad[i]>mx){
			mxi=i;mx=mxrad[i];
		}
	}
	s.clear();
	for (int i=mxi-mx;i<=mxi+mx;++i){
		if (ns[i]!='|')s.push_back(ns[i]);
	}
	cout<<s<<'\n';
	return 0;

}