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
            if(((endYear%4==0 && endYear%100!=0) || endYear%1000==0) && startMonth==2)brdni++;
            endMonth--;
            brdni+=brdaysinmonth[startMonth-1]-startDay;
            while(endMonth>startMonth){
                startMonth++;
                brdni+=brdaysinmonth[startMonth-1];
                if(((endYear%4==0 && endYear%100!=0) || endYear%1000==0) && startMonth==2)brdni++;
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
    countOfDays+=getCountOfDaysBetweenDates(1,1,year,day,month,year);
    int newday=1,newmonth=1,newyear=year;
    newyear+=countOfDays/365;
    countOfDays%=365;
    countOfDays-=((year-1)%4+(newyear-year))/4;
    countOfDays+=((year-1)%100+(newyear-year))/100;
    countOfDays-=((year-1)%1000+(newyear-year))/1000;
    if(countOfDays<0){
        newyear--;
        newmonth=12;
        newday=32+countOfDays;
    }else{
        while(countOfDays>=brdaysinmonth[newmonth-1]){
            if(((newyear%4==0 && newyear%100!=0) || newyear%1000==0) && newmonth==2)countOfDays--;
            countOfDays-=brdaysinmonth[newmonth-1];
            newmonth++;
        }
        newday+=countOfDays;
    }
    cout << newday << " " << newmonth << " " << newyear << endl;
}
void printDateBefore(int day, int month, int year, int countOfDays){
    int newyear=year-countOfDays/365-1;
    int newcount=getCountOfDaysBetweenDates(day,month,newyear,day,month,year)-countOfDays;
    //izpolzwame funkciqta za dateAfter
    printDateAfter(day,month,newyear,newcount);
}
int main(){
    int d1,m1,y1,d2,m2,y2,d;
    cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    cout << getCountOfDaysBetweenDates(d1,m1,y1,d2,m2,y2) << endl;
    cin >> d;
    printDateAfter(d1,m1,y1,d);
    printDateBefore(d2,m2,y2,d);
    return 0;
}
