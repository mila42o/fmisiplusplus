#include<iostream>
using namespace std;
int brdaysinmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int getCountOfDaysBetweenDates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear){
    int brdni=-1;
    if(endYear==startYear){
        if(endMonth==startMonth){
            if(endDay>=startDay){
                brdni=endDay-startDay;
            }
        }else if(endMonth>startMonth){
            brdni=endDay;
            if((endYear%4==0 && endYear%100!=0) || endYear%1000==0)brdaysinmonth[1]++;
            endMonth--;
            brdni+=brdaysinmonth[startMonth-1]-startDay;
            while(endMonth>startMonth){
                startMonth++;
                brdni+=brdaysinmonth[startMonth-1];
            }
        }
    }else if(endYear>startYear){
        brdni=endDay;
        if(((startYear%4==0 && startYear%100!=0) || startYear%1000==0) && startMonth==2)brdni++;
        brdni+=brdaysinmonth[startMonth-1]-startDay;
        endMonth--;
        while(endMonth>0){
            endMonth--;
            if(((endYear%4==0 && endYear%100!=0) || endYear%1000==0) && endMonth==2)brdni++;
            brdni+=brdaysinmonth[endMonth];
        }
        startMonth++;
        while(startMonth<=12){
            if(((startYear%4==0 && startYear%100!=0) || startYear%1000==0) && startMonth==2)brdni++;
            brdni+=brdaysinmonth[startMonth-1];
            startMonth++;
        }
        endYear--;
        brdni+=(endYear-startYear)*365;
        brdni+=(startYear%4+endYear-startYear)/4;
        brdni-=(startYear%100+endYear-startYear)/100;
        brdni+=(startYear%1000+endYear-startYear)/1000;
    }
    return brdni;
}
void printDateAfter(int day, int month, int year, int countOfDays){

}
void printDateBefore(int day, int month, int year, int countOfDays){

}
int main(){
    int d1,m1,y1,d2,m2,y2,d;
    cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2 >> d;
    cout << getCountOfDaysBetweenDates(d1,m1,y1,d2,m2,y2) << endl;
    return 0;
}
