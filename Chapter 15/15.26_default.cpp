#include"Quote.h"
#include<iostream>

using namespace std;

int main(){
	Quote q1("1", 1), q2;
	Bulk_quote bq1("1",1,1,1), bq2;
	Own_quote oq1("1",2,3,4), oq2;
	
	q2 = q1;
	bq2 = bq1;
	oq2 = oq1;
}

/*
Quote constrcutor
Quote constrcutor
Disc_quote constructor
Bulk_quote constructor
Quote constrcutor
Disc_quote constructor
Own_quote constructor
*/
