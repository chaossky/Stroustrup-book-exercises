#include "book.h"

// Every drill exercise.  All code fragments are included in one file.
// Each fragment's "Success!" message is labeled with the question
// number.  Each fragment is preceded by a comment that shows the original
// line.  All fragments will execute properly in succession when the
// entire drill series is complete.  Go.

int main()
try {
	// 1.  Cout << "Success!\n";
	cout << "1. Success!\n";
	// 2.  cout << "Success!\n;
	cout << "2. Success!\n";
	// 3.  cout << "Success" << !\n"
	cout << "3. Success" << "!\n";
	// 4.  cout << success << '\n';
	cout << "4. success" << '\n';
	// 5.  string res=7; vector<int> v(10); v[5]=res; cout << "Success!\n";
	int res=7; vector<int> v(10); v[5]=res; cout << "5. Success!\n";
	// 6.  vector<int> v(10); v(5)=7; if(v(5)!=7) cout << "Success!\n";
	vector<int> va(10); va[5]=7; if(va[5]==7) cout << "6. Success!\n";
	// 7.  if(cond) cout<<"Success!\n"; else cout<<"Fail!\n";
	if(true) cout<<"7. Success!\n"; else cout<<"7. Fail!\n";
	// 8.  bool c=false; if(c) cout<<"Success!\n"; else cout<<"Fail!\n";
	bool c=false; if(!c) cout<<"8. Success!\n"; else cout<<"8. Fail!\n";
	// 9.  string s="ape"; boo c="fool"<s; if(c) cout<< "Success!\n";
	string s="ape"; bool ca="fool">s; if(ca) cout<<"9. Success!\n";
	// 10. string s="ape"; if(s=="fool") cout<<"Success!\n";
	string sa="ape"; if(sa!="fool") cout<<"10. Success!\n";
	// 11. string s="ape"; if(s=="fool") cout<"Success!\n";
	string sb="ape"; if(sb!="fool") cout<<"11. Success!\n";
	// 12. string s="ape"; if(s+"fool") cout<"Success!\n";
	string sc="ape"; if(sc!="fool") cout<<"12. Success!\n";
	// 13. vector<char> v(5); for(int i=0; 0<v.size(); ++i); cout<<"Success!\n";
	vector<char> vb(5); for(int i=0; i<vb.size(); ++i); cout<<"13. Success!\n";
	// 14. vector<char> v(5); for(int i=0; i<=v.size(); ++i); cout<<"Success!\n";
	vector<char> vc(5); for(int i=0; i<=vc.size(); ++i); cout<<"14. Success!\n";
	// 15. string s="Success!\n"; for(int i=0; i<6; ++i) cout<<s[i];
	string sd="15. Success!\n"; for(int i=0; i<13; ++i) cout<<sd[i];
	// 16. if(true) then cout<<"Success!\n"; else cout<<"Fail!\n";
	if(true) cout<<"16. Success!\n"; else cout<<"Fail!\n";
	// 17. int x=2000; char c=x; if(c==2000) cout<<"Success!\n";
	int x=200; char cb=x; if(cb==(char)200) cout<<"17. Success!\n";
	// 18. string s="Success!\n"; for (int i=0;i<10;++i) cout << s[i];
	string se="18. Success!\n"; for(int i=0;i<13;++i) cout << se[i];
	// 19. vector v(5); for(int i=0;i<=v.size();++i); cout << "Success!\n";
	vector<int> vd(5); for(int i=0;i<=vd.size();++i); cout<<"19. Success!\n";
	// 20. int i=0; int j=9; while(i<10) ++j; if(j<i) cout << "Success!\n";
	int ii=0; int jj=9; while(ii<10) ++ii; if(jj<ii) cout<<"20. Success!\n";
	// 21. int x=2; double d=5/(x-2); if(d==2*x+0.5) cout << "Success!\n";
	int xa=2; double d=5/(xa-1); if(d==2*(xa+0.5)) cout<<"21. Success!\n";
	// 22. string<char> s="Success!\n"; for (int i=0;i<=10;++i) cout << s[i];
	string sf="22. Success!\n"; for(int i=0;i<=14;++i) cout<<sf[i];
	// 23. int i=0; while(i<10) ++j; if(j<i) cout << "Success!\n";
	int ia=0; while(ia<10) ++ia; if(ia<11) cout<<"23. Success!\n";
	// 24. int x=4; double d=5/(x-2); if(d=2*x+0.5) cout << "Success!\n";
	int xb=4; double dd=5/(xb-2); if(dd<2*xb+0.5) cout<<"24. Success!\n";
	// 25. cin << "Success!\n";
	cout << "25. Success!\n";
	return 0;
}
catch(exception& e) {
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch(...) {
	cerr << "I have no clue what this is." << endl;
	return 2;
}
