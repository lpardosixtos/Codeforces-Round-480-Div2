#include <bits/stdc++.h>

using namespace std;

int main(void){

    string s;
    cin >> s;
    int conto=0, contj=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='o') conto++;
        else contj++;
    }
    if(conto==0 || contj%conto==0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
