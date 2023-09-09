//Bars although simple is a necessity for this program. 
//Bars allows for a parameter to take in the name, value, and category of a line.
//Which is able to be processed later.

#include <iostream>
#include <string>
#include "myrandom.h" // used in graders, do not remove
using namespace std;

class Bar {
 private:
    //Private Variable
    string name;
    int value;
    string category;

 public:
    //Default Constructor
    Bar() {
        //Sets variables blank or 0
        name = "";
        value = 0;
        category = "";
    }
    //Parameterized Constructor
    Bar(string name, int value, string category) {
        this->name = name;  //Uses this-> to change the variables to the parameters
        this->value= value;
        this->category = category;
    }

    // Destructor:
    virtual ~Bar() {
        //No memory allocation no need for destructor
    }

	string getName() { //Gets Name
        return name;  
	}

	int getValue() { //Gets Value
        return value;   
	}

    
	string getCategory(){ //Gets Category
        return category; 
	}

    //Bool Operators
	bool operator<(const Bar &other) const { //Compares bars using less than
        if(this->value < other.value){
            return true;
        }
        return false;
	}

	bool operator<=(const Bar &other) const { //Compares bars using less than or equal to
        if(this->value <= other.value){
            return true;
        }
        return false;  
	}

	bool operator>(const Bar &other) const { //Compares bars using greater than
        if(this->value > other.value){
            return true;
        }
        return false;  
	}

	bool operator>=(const Bar &other) const { //Compares bars using greater than or equal to
        if(this->value >= other.value){
            return true;
        }
        return false;  
	}
};



