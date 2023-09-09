//BarChartAnimate allows for a set of bars in a specific time period to be in one barchart that is processed and 
//allows for animation through the time period that is selected through endIter. It also compares the bars from greatest
//to smallest, giving each category a color if it doesn't have one, and only prints based on the top variable that is inputted.

//For Creative Component, I made the different play speeds.
//Enter a number 1-3 for what speed is desired. Medium (2) Speed is the default speed. 
//I Created this because it is useful running it on different websites or IDEs. This is because
//for a website like replit, it is slow so I would select the fast speed and VSCode I would select slow because it is fast.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

class BarChartAnimate {
 private:
    //Private Variables
    BarChart* barcharts;
    int size;
    int capacity;
    string title;
    string xlabel;
    string source;
    map<string, string> colorMap;

 public:

    BarChartAnimate(string title, string xlabel, string source) { //Parameterized Constructor
        this->title = title; //Variables are set to the parameters
        this->xlabel = xlabel;
        this->source = source;
        barcharts = new BarChart[capacity]; //Memory Allocation to create new Barcharts
        capacity = 4;
        size =0;
    }

    virtual ~BarChartAnimate() { //Destructor
        delete[] barcharts;       
    }

    void addFrame(ifstream &file) { //Gets all of the bars from one time period, parses them, adds all the bars to one barchart, and sets all the barcharts and frames to the barchart pointer 
        string blank, repeat, fileWords, time, name, country, category, numbers, value;
        int numBars;
        getline(file, blank); //Gets Blank Line
        getline(file, numbers); //Gets the amount for bars for each frame
        if(numbers !=""){ //Prevents end of file crashes
            numBars = stoi(numbers); 
            int colorIndex =0;
            if(size == capacity){ //Condition if capacity is full
                int newCapacity = capacity*2;
                BarChart* newBarcharts = new BarChart[newCapacity]; //Creates new pointer with doubled capacity
                for(int i=0; i<size; i++){
                    newBarcharts[i] = barcharts[i]; //Makes the new pointer equal to the old pointer
                    newBarcharts[i].setFrame(barcharts[i].getFrame());
                }
                delete[] barcharts; //Deletes old pointer, makes old pointer equal to new pointer
                barcharts = newBarcharts;
                capacity = newCapacity;
            }

            string word;
            int words=0;
            BarChart barFrame(numBars); //Capacity is the amount of bars in a certain time period
            for(int j=0; j<numBars; j++){ //Loops through the amount of bars
                getline(file, fileWords); 
                for(int i=0; i<fileWords.size(); i++){ //Loop parses the bars into strings for each different category
                    if(fileWords[i]!= ','){
                        word+=fileWords[i];
                    }
                    else{
                        if(words ==0){
                            time =word;
                            word="";
                        }
                        else if(words == 1){
                            name = word;
                            word="";
                        }
                        else if(words == 2){
                            country = word;
                            word="";
                        }
                        else if(words == 3){
                            value = word;
                            word="";
                        }
                        words++;
                        
                    }
                }
                category = word;
                word=""; //Resets string and value for next line
                words=0;
                if(colorMap.count(category)== 0){ //Sets a color for a category that doesn't already have a color
                    colorMap[category] = COLORS[(colorIndex)%(COLORS.size())];
                    ++colorIndex;
                    if(colorIndex >=6){ //Starts over when colorIndex reaches the end
                        colorIndex =0;
                    }
                }
                int temp = stoi(value);
                barFrame.addBar(name, temp, category); //Adds bar to barchart

            }

            barcharts[this->size] = barFrame; //Adds barFrame to the pointer in order
            barcharts[this->size].setFrame(time); //Sets frame for that specific barFrame
            (this->size)++;
        }
    }

	void animate(ostream &output, int top, int endIter) { //Animates the Bar Graph and Creative Component
        int playSpeed; //Creative component gives different play speeds for the user to decide
        cout<<"Enter a number (1-3) play speed slow=1, medium =2, fast =3\n"; 
        cin>>playSpeed;
        unsigned int microsecond;
        if(playSpeed ==1){
            microsecond = 200000;
        }
        else if(playSpeed == 2){
            microsecond = 100000;
        }
        else{
            microsecond = 35000;
        }

        int temp = top; //Temp variable
        int numFrames= endIter;
        if(endIter ==-1){ //Allows for the looping of the whole file when -1 is endIter
            numFrames = size;
        }

        for(int i=0; i<numFrames; i++){ //Loops through the number of frames
            if(barcharts[i].getSize()<top || temp>top){ //If condition for when top is greater than the amount of bars in the barchart
                top = barcharts[i].getSize();
                if(top>temp){
                    top =temp;
                }
            }
            usleep(3*microsecond); //Output so the graph animates
            output<<CLEARCONSOLE;
            output<<BLACK<<title<<endl<<BLACK<<source<<endl;
            barcharts[i].graph(output, colorMap, top);
            output<<BLACK<<xlabel<<endl<<BLACK<<"Frame: "<<barcharts[i].getFrame()<<endl;
        }
	}

    int getSize(){ //Returns Size
        return size;         
    }

    BarChart& operator[](int i){ //Returns barcharts for the i element to be modified and read
         if (i<0 || i>this->size){
            cout<<"BarChart: i out of bounds\n";
         }
         else{
            return barcharts[i];
          } 
    }
};
