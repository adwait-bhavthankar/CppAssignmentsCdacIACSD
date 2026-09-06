#include<iostream>
#include<string>
using namespace std;

template <typename T>
void minMax(T arr[], int size, T &minValue, T &maxValue){
    if(size<0){
        return;
    }
    minValue = arr[0];
    maxValue = arr[0];

    for(int i =0; i<size; i++){
        if(arr[i] < minValue){
            minValue = arr[i];
        }
        if(arr[i]> maxValue){
            maxValue = arr[i];
        }
    }
}

template<>
void minMax<string>(string arr[], int size, string &minValue, string &maxValue){
    if (size<0){
        return;
    }
    minValue = arr[0];
    maxValue = arr[0];

    for(int i =0; i<size; i++){
        if(arr[i].length() < minValue.length() ){
            minValue = arr[i];
        }
        if(arr[i].length() > maxValue.length()){
            maxValue = arr[i];
        }
    }
}


template<typename T>
double computeAvg(T arr[], int size){
    if(size <= 0){
        return 0.0;
    }

    double sum = 0.0;
    for(int i =0; i<size; i++){
        sum += arr[i];
    }
    return sum/size;

}

template<typename T>
void displayArray(T arr[], int size){
    cout<<"[";
    for(int i=0; i<size; i++){
        cout<<arr[i]<< (i == (size -1) ? "" : ",");
    }

    cout<<"]";

}


int main(){
    cout<<"For Int ====================="<<endl;
    int intArr[] = {4,5,6,7,8};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    int minimum;
    int maximum;
    double intAvg;

    displayArray(intArr, intSize);

    minMax(intArr,intSize, minimum,maximum);
    cout << "\nMinimum: " <<minimum<<endl;
    cout <<"Maximum: "<<maximum<<endl;
    intAvg = computeAvg(intArr,intSize);
    cout<<"Avg: "<<intAvg<<endl;


    // Double =====================
    cout << "\nFor Double =====================" << endl;
    double dblArr[] = {3.14, 2.71, 9.81, 1.41};
    int dblSize = sizeof(dblArr) / sizeof(dblArr[0]);
    double minDouble;
    double maxDouble;
    double dblAvg;

    displayArray(dblArr, dblSize);

    minMax(dblArr, dblSize, minDouble, maxDouble);
    cout << "\nMinimum: " << minDouble << endl;
    cout << "Maximum: " << maxDouble << endl;
    dblAvg = computeAvg(dblArr, dblSize);
    cout << "Avg: " << dblAvg << endl;

    // String =====================
    cout << "\nFor String =====================" << endl;
    string strArr[] = {"apple", "banana", "kiwi", "strawberry"};
    int strSize = sizeof(strArr) / sizeof(strArr[0]);
    string shortest;
    string longest;

    displayArray(strArr, strSize);

    minMax(strArr, strSize, shortest, longest);
    cout << "\nShortest: \"" << shortest << "\" (" << shortest.length() << " chars)" << endl;
    cout << "Longest: \"" << longest << "\" (" << longest.length() << " chars)" << endl;



}