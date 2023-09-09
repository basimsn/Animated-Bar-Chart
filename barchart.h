//Barchart allows for many bars to be inside one class with a frame
//From this one time period can be printed with the specific colors
//based on the category that it has. The bars are printed from greatest
//to smallest and the boxes are based on a percentage of how close it is
//to the max value of that time period.

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include "myrandom.h" // used in graders, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");


//
// NOTE: COMMENT AND UNCOMMENT AS NEEDED BASED ON YOUR TERMINAL
//
// Color codes for light mode terminals
// const string RED("\033[1;36m");
// const string PURPLE("\033[1;32m");
// const string BLUE("\033[1;33m");
// const string CYAN("\033[1;31m");
// const string GREEN("\033[1;35m");
// const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
// const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for darker mode terminals
const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
// const string RESET("\033[0m");
const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};

class BarChart {
 private:
    //Private Variables
    Bar* bars;
    int capacity;
    int size;
    string frame;
 public:
    BarChart() { //Default Constructor
        capacity = 0;
        size = 0;
    }

    BarChart(int n) { //Allocates memory for new bars
        capacity = n;
        size =0;
        bars =  new Bar[n];
    }

    BarChart(const BarChart& other) { //Copy constructor copies a BarChart to another
        bars = other.bars;
        capacity = other.capacity;
        size = other.size;
        frame =other.frame;
    }

    BarChart& operator=(const BarChart& other) { //Copy Operator makes a bnarchart equal to another and returns this
        size = other.size;
        capacity = other.capacity;
        bars = other.bars;
        frame = other.frame;

        return *this;
    }

    void clear() { //Clears up a barchart funtcion
        delete[] bars;
        capacity = 0;
        size = 0;
    }
    
    virtual ~BarChart() { //Destructor
        
    }
    
    void setFrame(string frame) { //Sets Frame
    	this->frame = frame;   
    }
    
    string getFrame() { //Gets Frame
        return frame;
    }

    bool addBar(string name, int value, string category) {
        if(this->size == this->capacity){
            return false;
        }
        else{
            Bar bp1;
            bp1= Bar(name,value, category);
            bars[this->size] = bp1;
            (this->size)++;

            return true;
        }
    }

    int getCapacity(){ //Created to make testing efficient and more accurate
        return capacity;
    }

    int getSize() { //Returns size
        return size;
    }
    
    Bar& operator[](int i) { //Returns the i element of thge bars pointer which allows for modification and the ability to output specifics
        if (i<0 || i>this->size){
            cout<<"BarChart: i out of bounds\n";
        }
        else{
            return bars[i];
        }
    }
    
    void dump(ostream &output) { //Dump allows for output to be possible which allows for testing to be easier
        sort(bars, bars+size, greater<Bar>()); //Sorts the bars from greatest to smallest
        for (int i = 0; i < (this->capacity); i++) { //Loops through the Barchart and outputs all the information
            output <<bars[i].getName()<<' '<<bars[i].getValue()<<' '<<bars[i].getCategory() <<endl;
	    }
        
    }

    void graph(ostream &output, map<string, string> &colorMap, int top) { //Graphs a BarChart, gives different colors to bars, sorts from greatest to least, and prints a specific amount (top)
    	int lenMax=60; 
        string color = "\033[1;36m"; 
        string barstr = "";
        sort(bars, bars+size, greater<Bar>()); //Sorts Bars
        for(int j=0; j<COLORS.size(); j++){
            for(int i=0; i<this->size; i++){
                colorMap.insert({bars[i].getCategory(), COLORS[j]}); //Provides a color with a category
            }
        }
        float max = bars[0].getValue();
        float length;
        for(int j=0; j<top; j++){ //Prints up to "top" bars
            if(colorMap.count(bars[j].getCategory()) ==1){
                color = colorMap[bars[j].getCategory()]; //Associates the color with the category
            }
            else{
                color = BLACK; //If condition if a category does not have a color associated with it
            }

            length = (((bars[j].getValue())/max)*60); //Formula to find how many boxes should be printed
            lenMax = length;
            for (int i = 0; i < lenMax; i++) {
                barstr += BOX; //Prints the amount of boxes needed
            }
            output << color << barstr <<" "<<bars[j].getName()<<' '<<bars[j].getValue()<< endl; //Output
            barstr=""; //Resets the boxs
        }
    }
    
};

