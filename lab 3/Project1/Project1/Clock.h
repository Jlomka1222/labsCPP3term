#pragma once
class Clock
{
private:
	char Brend[80];
	int Time;
	int year_of_issue;
public:
	void printTime()const;
	void printBrend()const;
	Clock(const char* brend, int Time, int year_of_issue);
	~Clock();
	int getTime()const;
	void setTime(int Time);
	void setBrend(const char*);
	const char* getBrend()const;
	void setYear(int year);
	int getYear();
	void printYear()const;
};