#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void readFile(string file, vector<int> &type, vector<vector<double>> &featuresList) {
    ifstream ifs;
    int rows = 0;
    int cnt = 0;
    double input = 0.0;
    bool newLine = false;

    ifs.open(file);
    if(file == "CS170_SMALLtestdata__68.txt") {
        //ifs >> input;
        newLine = true;
        while(ifs >> input) {
            //cout << input << "    ";
            if(newLine) {
                type.push_back(static_cast<int>(input));
                featuresList.push_back(vector<double>()); //push back an empty vector to store contents of next line
                newLine = false;
            } else {
                featuresList[rows].push_back(input);
                cnt++;
                if(cnt == 10) {
                    newLine = true;
                    rows++;
                    cnt = 0;
                }
            }
        }
        //cout << "hi1";
        ifs.close();
    } else if(file == "CS170_largetestdata__60.txt") {
        newLine = true;
        while(ifs >> input) {
            if(newLine) {
                type.push_back(static_cast<int>(input));
                featuresList.push_back(vector<double>()); //push back an empty vector to store contents of next line
                newLine = false;
            } else {
                featuresList[rows].push_back(input);
                cnt++;
                if(cnt == 100) {
                    newLine = true;
                    rows++;
                    cnt = 0;
                }
            }
        }
        //cout << "hi2";
        ifs.close();
    } else {
        cout << "Unable to read file. Error code 1." << endl;
        return;
    }
    //cout << "hi3";
    return;
}

double leavingOneOut(vector<int> &type, vector<vector<double>> &featuresList) {
    //for all features, compare the current with the subsequent
    //calculate the Euclidean distance and return the smallest distance
    return 0.0;
}

vector<int> NN(vector<int> &type, vector<vector<double>> &featuresList) {
    vector<int> nearest;
    //iterate through every feature
    //add a feature and calculate the accuracy
    //keep track of best accuracy so far and update every loop
    //Once highest accuracy is found, 
    //return a vector of the features used for that accuracy
    return nearest;
}



int main() {
    string file;
    int option;
    //double featuresList[200] = {};
    vector<vector<double>> featuresList;
    //double classType[200] = {};
    vector<int> type;
    //type.resize(0);
    //cout << "first ele: " << type[0];

    cout << "Welcome to my Feature Selection Algorithm." << endl;
    cout << "Type in the name of the file to test: "; 
    cin >> file;

    if(file != "CS170_SMALLtestdata__68.txt" && 
       file != "CS170_largetestdata__60.txt") {
           cout << "Invalid file name." << endl;
           return -1;
    }

    cout << endl;
    cout << "1) Forward Selection" << endl;
    cout << "2) Backward Elimination" << endl;
    cout << "Type the number of the algorithm you want to run: " << endl;
    cin >> option;
    cout << endl;

    if(option != 1 && option != 2) {
        cout << "Invalid algorithm choice." << endl;
        return -1;
    }

    readFile(file, type, featuresList);

     //testing purposes for read function
    //cout << endl;
    //for(int i = 0; i < 4; i++) {
    //    cout << featuresList[0][i] << endl;
    //} 
    

    cout << "This dataset has " << featuresList[0].size() 
         << " features (not including the class attribute), with "
         << type.size() << " instances." << endl;

    cout << "Running nearest neighbor with all " << featuresList[0].size()
         << " features, using \"leaving-one-out\" evaluation, I get an accuracy of ";
         //<< 
    return 0;
}