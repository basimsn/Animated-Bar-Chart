#include <iostream>
#include "barchartanimate.h"
using namespace std;


bool testBar() {
	//Bar Default Constructor
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor1: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor1: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor1: getCategory failed" << endl;
    	return false;
    }
	Bar b1;
	if (b1.getName() != "") {
    	cout << "testBarDefaultConstructor2: getName failed" << endl;
    	return false;
    } else if (b1.getValue() != 0) {
    	cout << "testBarDefaultConstructor2: getValue failed" << endl;
    	return false;
    } else if (b1.getCategory() != "") {
    	cout << "testBarDefaultConstructor2: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
	//Bar Parameter Constructor and Getter Functions
	Bar c("Chicago", 9234324, "US");
    if (c.getName() != "Chicago") {
    	cout << "testBarParamConstructor1: getName failed" << endl;
    	return false;
    } else if (c.getValue() != 9234324) {
    	cout << "testBarParamConstructor1: getValue failed" << endl;
    	return false;
    } else if (c.getCategory() != "US") {
    	cout << "testBarParamConstructor1: getCategory failed" << endl;
    	return false;
    }
	Bar c1("New York", 1567262, "US");
    if (c1.getName() != "New York") {
    	cout << "testBarParamConstructor2: getName failed" << endl;
    	return false;
    } else if (c1.getValue() != 1567262) {
    	cout << "testBarParamConstructor2: getValue failed" << endl;
    	return false;
    } else if (c1.getCategory() != "US") {
    	cout << "testBarParamConstructor2: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
	//Bar Bool Operator Functions
	if(c1>c){
		cout<<"Bool Operator1 > failed\n";
		return false;
	} else if(c1>= c){
		cout<<"Bool Operator1 >= failed\n";
		return false;
	} else if(c<= c1){
		cout<<"Bool Operator1 <= failed\n";
		return false;
	} else if(c< c1){
		cout<<"Bool Operator1 < failed\n";
		return false;
	}
	Bar c2("Houston", 1000, "US");
	if(c2>c1){
		cout<<"Bool Operator2 > failed\n";
		return false;
	} else if(c2>= c1){
		cout<<"Bool Operator2 >= failed\n";
		return false;
	} else if(c1<= c2){
		cout<<"Bool Operator2 <= failed\n";
		return false;
	} else if(c1< c2){
		cout<<"Bool Operator2 < failed\n";
		return false;
	}
	cout<<"testBarBoolOperators: all passed!\n";
	
	cout<<"\nAll Bar tests have passed!\n";

    return true;
}

bool testBarChart(){
	//BarChart Default Parameters
	BarChart b;
	BarChart b1;
	if(b.getCapacity() != 0 && b.getSize() != 0){
		cout<<"Default Constructor1 Failed\n";
		return false;
	} else if(b1.getCapacity() != 0 && b1.getSize() != 0){
		cout<<"Default Constructor2 Failed\n";
		return false;
	}
	cout<<"BarChart Default Constructor Passed\n";
	//BarChart Parameterized Constructor
	BarChart c(2);
	BarChart c1(3);
	if(c.getCapacity() != 2){
		cout<<"Parameterized Constructor1 Failed\n";
		return false;
	} else if(c1.getCapacity() != 3){
		cout<<"Parameterized Constructor2 Failed\n";
		return false;
	}
	cout<<"BarChart Parameterized Constructor Passed\n";
	//Copy Constructor and Getter Functions
	BarChart bc(10);
	BarChart bcCopy(bc);
	BarChart bc1(9);
	BarChart bcCopy1(bc1);
	if(bc.getSize() != bcCopy.getSize() && bc.getCapacity() != bcCopy.getCapacity()){
		cout<<"Copy Constructor1 Failed\n";
		return false;
	} else if(bc1.getSize() != bcCopy1.getSize() && bc1.getCapacity() != bcCopy1.getCapacity()){
		cout<<"Copy Constructor2 Failed\n";
		return false;
	}
	cout<<"BarChart Copy Constructor Passed\n";
	//Copy Operator
	BarChart cd;
	BarChart cd1(10);
	cd1 = cd;
	BarChart cd2;
	BarChart cd3(10);
	cd2 = cd3;
	if(cd.getSize() != cd1.getSize() && cd.getCapacity() != cd1.getCapacity()){
		cout<<"Copy Operator1 Failed\n";
		return false;
	} else if(cd2.getSize() != cd3.getSize() && cd2.getCapacity() != cd3.getCapacity()){
		cout<<"Copy Operator2 Failed\n";
		return false;
	}
	cout<<"BarChart Copy Operator Passed\n";
	//BarChart AddBar
	BarChart d(1);
	BarChart d1(2);
	if(!d.addBar("Chicago", 1020, "US")){
		cout<<"Add Bar1 Failed\n";
		return false;
	} else if(!d1.addBar("NYC", 1300, "US") && !d1.addBar("Paris", 1200, "France")){
		cout<<"Add Bar2 Failed\n";
		return false;
	}
	cout<<"BarChart AddBar Passed\n";
	//BarChart Dump
	//See Terminal For Testing
	BarChart e(3);
	e.addBar("Chicago", 1020, "US");
	e.addBar("NYC", 1300, "US");
	e.addBar("Paris", 1200, "France");
	e.dump(cout);

	BarChart e1(4);
	e1.addBar("Houston", 111, "US");
	e1.addBar("Denver", 220, "US");
	e1.addBar("Ibiza", 387, "Spain");
	e1.addBar("Berlin", 918, "Germany");
	e1.dump(cout);

	//BarChart Graph
	//See Terminal for Testing
	string red("\033[1;36m");
	string blue("\033[1;33m");
	string white("\033[1;37m");
	map<string, string> colorMap;
	colorMap["US"] = red;
	colorMap["France"] = blue;
	e.graph(cout, colorMap, 3);
	colorMap["Spain"] = white;
	colorMap["Germany"] = red;
	e1.graph(cout, colorMap, 4);

	cout<<"All BarChart test have passed!\n";

  return true;
}

int main() {
	testBar();
	testBarChart();
	
    return 0;
}