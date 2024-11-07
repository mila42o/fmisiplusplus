#include<iostream>
using namespace std;
int main(){
    int n,prpoz1=0,prpoz2=0,en=0;
    bool x=true;
    char a = 92;
    while(x){
        cin >> n;
        if(n<1 || n>23){
            cout << "molya wywedi drugo chilo" << endl;
        }else{
            x=false;
        }
    }
    en=4*n+1;
    prpoz1=2*n-1;
    prpoz2=2*n+1;
    //znamence na zamuk
    for(int j=0;j<2*n;j++){
        for(int i=0;i<3*n+2;i++){
            cout << " ";
        }
        cout << "|";
        if(j==0)cout << ">";
        cout << endl;
    }
    //purwa osnowa na kula
    for(int i=0;i<2*n;i++){
        for(int j=0;j<n+2;j++){
            if(i<n-1){
                cout << " ";
            }else{
                if((j==0 || j==n+1) && (i==n-1)){
                    cout << " ";
                }else if(j==0 || j==n+1){
                    cout << "|";
                }else{
                    cout << "_";
                }
            }
        }
        for(int k=0;k<en;k++){
            if(k==prpoz1){
                cout << "/";
                prpoz1--;
            }else if(k==prpoz2){
                cout << a;
            }else if(i==2*n-1){
                cout << "_";
            }else{
                cout << " ";
            }
        }
        if(i>=n-1){
            for(int j=0;j<n+2;j++){
                if((j==0 || j==n+1) && (i==n-1)){
                    cout << " ";
                }else if(j==0 || j==n+1){
                    cout << "|";
                }else{
                    cout << "_";
                }
            }
        }
        prpoz2++;
        cout << endl;
    }
    prpoz1=n;
    prpoz2=en-n-1;
    //wtori redowe na kula
    for(int i=0;i<2*n;i++){
        for(int j=0;j<n+2;j++){
            if(j==0 || j==n+1){
                cout << "|";
            }else{
                cout << "_";
            }
        }
        for(int k=0;k<en;k++){
            if(((k>prpoz1 && k<prpoz2) && i==n-1) || ((k<prpoz1 || k>prpoz2) && i==2*n-1)){
                cout << "_";
            }else if((i>n-1) && (k==prpoz1 || k==prpoz2)){
                cout << "|";
            }else{
                cout << " ";
            }
        }
        for(int j=0;j<n+2;j++){
            if(j==0 || j==n+1){
                cout << "|";
            }else{
                cout << "_";
            }
        }
        cout << endl;
    }
    return 0;
}
