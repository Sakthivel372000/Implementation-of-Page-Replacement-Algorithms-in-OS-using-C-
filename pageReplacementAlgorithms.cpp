#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void displayForOpr(vector<char> v1){
   for (int j=0;j<v1.size();j++){
        cout << " ";
        cout << v1[j];
  }
   cout << "   -> "<< "Page Fault ";
   cout << endl;
}

int firstOccurence(char n , string s){
 int k =-1;
 for (int i=0;i<s.length();i++){
     if (s[i]== n){
        k=i;
        break;
     }
  }
  return k>=0 ? k :INT_MAX-1;
}

char whoToReplace(vector<char> v1, int framesSize,string s){
    int min1=INT_MIN,min2=INT_MIN;
    char ch;
    vector<pair<char,int>> v2;
    for(int i=0;i<v1.size();i++){
        int m =firstOccurence(v1[i],s);
        v2.push_back({v1[i],m});
    }
    for (int i=0;i<v2.size();i++){
        if (v2[i].second>min2){
            min2=v2[i].second;
        }
    }
    for (int j=0;j<v2.size();j++){
        int k=(int)v2[j].second;
        if (k == min2){
                ch = v2[j].first;
        }
    }
    return ch;
}

void display1(vector<pair<char,int>> v1){
  for (int j=0;j<v1.size();j++){
        cout << " ";
        cout << v1[j].first;
  }
   cout << "   -> "<< "Page Fault ";
   cout << endl;
}


void hitDisplayForOpr(vector<char> v1){
    for (int j=0;j<v1.size();j++){
        cout << " ";
        cout << v1[j];
  }
   cout << "   -> "<< "HIT ";
   cout << endl;
}

void OptimalPageReplacement(string str, int frameSize){
   vector<char> v1;
   int pageFault=0;
   for (int i=0;i<str.length();i++){
   if (v1.size()< frameSize){
      v1.push_back(str[i]);
      pageFault++;
      displayForOpr(v1);
   }
   else{
     int k=1;
     //for (int j=0;j<v1.size();j++){cout << " "; cout << v1[j]/*<<"  value  "<<v1[j].second*/;}
     for (int j=0;j<v1.size();j++){
        if (v1[j] == str[i]){
            k=0;
            hitDisplayForOpr(v1);
        }
     }
     if (k){
        //displayForOpr(v1);
        pageFault++;
        string s = str.substr(i);
        char  ans = whoToReplace(v1,frameSize,s);
        for (int k=0;k<v1.size();k++){
            if (v1[k]== ans){
                v1[k]= str[i];
                displayForOpr(v1);
            }
        }
     }
   }
 }
   cout <<endl;
   cout <<"The page Fault is :"<<pageFault<<" ";
   cout <<endl;
   cout << "The page Hit is "<< str.length()-pageFault;
}


void hitDisplay(vector<pair<char,int>> v1){
  for (int j=0;j<v1.size();j++){
        cout << " ";
        cout << v1[j].first;
  }
   cout << "   ->"<< "Hit ";
   cout << endl;
}

void LRU_PageReplacement(string str, int frameSize){
    vector<pair<char,int>> v1;
    int pageFault;
    for (int i=0;i<str.length();i++){
      if (v1.size()<frameSize){
        v1.push_back({str[i],i+1});
        pageFault++;
        display1(v1);
      }
      else{
        int k=1;
        int min1=INT_MAX;
        for (int j=0;j<v1.size();j++){
            if (v1[j].first == str[i]){
                 k=0;
                 v1[j].second= i+1;
                 hitDisplay(v1);
                 break;
            }
        }
            //display1(v1);
        for (int j=0;j<v1.size();j++){
             if (v1[j].second<min1){
                min1=v1[j].second;

             }
        }
        for (int j=0;j<v1.size();j++){
            if (k && v1[j].second ==min1 ){
                v1[j].first = str[i];
                v1[j].second = i+1;
                pageFault++;
                display1(v1);
            }
        }

     }
  }
   cout <<endl;
  cout <<"The page Fault is :"<<pageFault<<" ";
   cout <<endl;
  cout << "The page Hit is "<< str.length()-pageFault;
}


void display(vector<pair<char,int>> v1){
  for (int j=0;j<v1.size();j++){
        cout << " ";
        cout << v1[j].first;
  }
   cout << "   ->"<< "Page Fault ";
   cout << endl;
}

void fifoAlgorithm(string str, int frameSize){
  vector<pair<char,int>> v1;
  int pageFault;
  for (int i=0;i<str.length();i++){
    if (v1.size()<frameSize){
        //cout << v1.size();
        v1.push_back({str[i],i+1});
        pageFault++;
        display(v1);
    }
    else{
        int k=1;
        for (int j=0;j<v1.size();j++){
            if (v1[j].first == str[i]){
                 k=0;
                 hitDisplay(v1);
                 break;
            }
        }
        //display(v1);
        for (int j=0;j<v1.size();j++){
            if (k && v1[j].second == 1){
                v1[j].first = str[i];
                v1[j].second = frameSize;
                pageFault++;
                display(v1);
            }
        }
        for (int j=0;j<v1.size();j++){
            if ( k && v1[j].first!=str[i]){
                v1[j].second--;
            }
        }
    }
 }
 cout << endl;
 cout <<"The page Fault is :"<<pageFault<<" ";
 cout <<endl;
 cout << "The page Hit is "<< str.length()-pageFault;
}


int main (){

    int framesSize,pageFault=0;
    string referenceString;
    int frameSize;
    cout << "Enter the Reference String :      "<<endl;
    cin >> referenceString;
    char ch;
    cout << endl;
    cout << "Enter the Frame Size :     "<<endl;
    cin >> frameSize;
    do {
        int choice ;
        cout << "Enter the Algorithm to find Page Fault :    "<<endl;
        cout << endl;
        cout << "1 .FIFO "<<endl;
        cout <<"2.Optimal Page Replacement Algorithm  "<<endl;
        cout << "3.LRU Page Replacement  "<<endl;
        cout << endl;
        cout << "Your Choice : ";
        cin >> choice;
        cout << "##############################################";
        cout << endl;
        switch (choice){
          case 1 : fifoAlgorithm(referenceString,frameSize);
                   break;
          case 2 : OptimalPageReplacement(referenceString,frameSize);
                   break;
          case 3 : LRU_PageReplacement(referenceString,frameSize);
                    break;
        }
        cout << endl;
        cout << endl;
        cout << "Do you want to continue ? "<< endl;
        cin >> ch;
        cout << endl;
    }while (ch=='y' || ch =='Y');
    cout << endl;
    cout << "##############################################";

    return 0;
}


//
// 5432143543215
