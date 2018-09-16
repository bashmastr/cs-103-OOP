#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class DateandTime {
private:
	int hr,min,sec;
	string var;
	int day,month,year;

public:
	// default constructor
	DateandTime(){
		//time set
		hr = 1;
		min = 0;
		sec = 0;
		var = "pm";
		//date set
		day = 1;
		month = 1;
		year = 2018;
	}
	//constructor with parameter
	DateandTime(int h,int mi, int s,string v,int d,int m,int y){
		//time set
		hr = h;
		min = mi;
		sec = s;
		var = v;
		//date set
		day = d;
		month = m;
		year = y;
		set_time();		
	}
	/// constructor with default perameter
	/*DateandTime(int h=0,int mi=0, int s=0,string v="pm",int d=0,int m=0,int y=0){
		//time set
		hr = h;
		min = mi;
		sec = s;
		var = v;
		//date set
		day = d;
		month = m;
		year = y;	
	}*/
	/// Destrouctor 
	~DateandTime(){
		//time set
		hr = 0;
		min = 0;
		sec = 0;
		var = "00";
		//date set
		day = 0;
		month = 0;
		year = 0;
	}

	//control time
	void set_time(){
		if(sec > 60){
			sec = sec - 60;
			min = min + 1;
		}
		if(min > 60){
			min = min - 60;
			hr = hr + 1;
			if (hr > 12){
				hr = hr -12;
				if (var == "Pm"){
					var = "Am";
				}
				else{
					var = "Pm";
				}
			}
		}
	}

	//input Date
	void inputDate(){	
		cout<<"Enter a DAte in this formate : DD-MM-YYYY\n";
		string dt,d,m,y;
		cin>>dt;
		d = d + dt[0]+dt[1];
		m = m + dt[3]+dt[4];
		y = y + dt[6]+dt[7]+dt[8]+dt[9];
		day = atoi(d.c_str());///convert string into integers
		month = atoi(m.c_str());
		year = atoi(y.c_str());
	}
	//input time
	void inputTime(){
		cout<<"Enter time in this formate : HH:MM:SS\n";
		string ti,h,mi,s,v;
		cin>>ti;
		h = h + ti[0]+ti[1];///string catination
		mi = mi + ti[3]+ti[4];
		s = s +  ti[6]+ti[7];
		hr = atoi(h.c_str());
		min = atoi(mi.c_str());
		sec = atoi(s.c_str());
		set_time();
	}
	//show date 
	void shortdate(){
		cout<<"Date formate is : DD-MM-YYYY"<<endl;
		cout<<day<<"-"<<month<<"-"<<year<<endl;
	}
	//show Time
	void shortTime(){
		cout<<"Time formate is : HH:MM:SS"<<endl;
		cout<<hr<<":"<<min<<":"<<sec;
		short_pm_am();		
	}
	void short_pm_am(){
		cout<<var<<endl;
	}
	//show time and date together;
	void longDate(){
		shortTime();
		shortdate();
	}
	//show Date in English
	void EnglishDate(){
		string s[12]={"january","February","March","April","May","June",
					 "July","Augest","September","October","November","December"};
		cout<<"Date in English formate : "<<endl;			 
		cout<<day<<"th "<<s[month-1]<<","<<year<<endl;
	}
};

int main(){
	DateandTime d1;
	d1.inputDate();
	d1.inputTime();
	cout<<endl;
	d1.longDate();
	d1.EnglishDate();


	return 0;
}