#include<iostream>
using namespace std;
int masivschisla[1000000];
//prowerka kolko puti se srestha cifra w chislo
int sreshtanenacifra(int m,int a,int c){
    int br=0;
    for(int i=0;i<m;i++){
        if(a%10==c)br++;
        a/=10;
    }
    return br;
}
// prowerka dali moje da e chislo ot bikowe i krawi
bool isOk(int m,int ch){
    for(int i=0;i<m;i++){
        if(sreshtanenacifra(m-i,ch,ch%10)>1){
            return true;
        }
        ch/=10;
    }
    return false;
}
//mahame ot masiva apriorno nevalidnite
void removeInvalidStart(int m,int br){
    for(int i=0;i<br/100;i++){
        masivschisla[i]=1;
    }
    for(int i=br/100;i<br;i++){
        masivschisla[i]=isOk(m,i);
    }
    for(int i=br;i<1000000;i++){
        masivschisla[i]=1;
    }
}
// prowerka dali dadeno chislo izpulnqwa uslowieto ot input
bool isValid(int ch,int b,int k,int m,int test){
    int curb=0,curk=0,ch1=ch,test1=test;
    for(int i=0;i<m;i++){
        if(ch1%10==test1%10)curb++;
        curk+=sreshtanenacifra(m,test,ch1%10);
        ch1/=10;
        test1/=10;
    }
    curk-=b;
    if(curb==b && curk==k){
        return 0;
    }else{
        return 1;
    }
}
// premahwame chislata koito ne mogat da budat ot inputa
void removeInvalidNumbers(int ch,int b,int kr,int m,int br){
    for(int i=0;i<br;i++){
        if(masivschisla[i]==0){
            masivschisla[i]=isValid(ch,b,kr,m,i);
        }
    }
}
int main(){
    int m,n;
    bool x=true;
    while(x){
        cin >> m;
        if(m<1 || m>6){
            cout << "molya wywedi drugo chilo" << endl;
        }else{
            x=false;
        }
    }
    cin >> n;
    int br=10;
    for(int i=1;i<m;i++){
        br*=10;
    }
    removeInvalidStart(m,br);
    int ch,bik,kr;
    while(n>0){
        n--;
        bool p=true;
        while(p){
            cin >> ch >> bik >> kr;
            if(bik<0 || bik>m || kr<0 || kr>m || bik+kr>m || isOk(m,ch)){
                cout << "molya wywedi drugi chisla" << endl;
            }else{
                p=false;
            }
        }
        removeInvalidNumbers(ch,bik,kr,m,br);
    }
    int brresh=0;
    for(int i=0;i<1000000;i++){
        if(masivschisla[i]==0){
            if(i<br/10){
                cout << "0";
            }
            cout << i << " ";
            brresh++;
        }
    }
    if(brresh==0){
        cout << "Nyama takowa chislo" << endl;
    }
    return 0;
}
