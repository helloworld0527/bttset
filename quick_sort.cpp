#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
void quick_sort(vector<string>& filepaths,int lo,int hi,int d);
void insertion(vector<string>& filepaths,int lo,int hi,int d);
bool small(string v,string w, int d);
int CUTOFF = 15;
void three_way_quick_sort(vector<string>& filepaths){
    quick_sort(filepaths, 0, filepaths.size()-1,0);
}

void quick_sort(vector<string>& filepaths,int lo,int hi,int d){
    if(hi <= lo +CUTOFF){
        insertion(filepaths, lo, hi, d);
        return;
    }

    int lt =lo, gt=hi;
    int v = filepaths[lo][d];
    int i = lo + 1;
    while(i<=gt){
        int t = filepaths[i][d];
        if(t < v){
            swap(filepaths[lt++],filepaths[i++]);
        }
        else if(t>v){
            swap(filepaths[i],filepaths[gt--]);
        }
        else{
            i++;
        }
    }
    quick_sort(filepaths, lo, lt-1, d);
    if(v >=0) quick_sort(filepaths, lt, gt, d+1);
    quick_sort(filepaths, gt+1, hi, d);
}
void insertion(vector<string>& filepaths,int lo,int hi,int d){
    for(int i=lo; i<=hi; i++){
        for(int j=i;j>lo && small(filepaths[j], filepaths[j-1], d); j--)
            swap(filepaths[j], filepaths[j-1]);
    }
}
bool small(string v,string w, int d){
    for(int i = d;i < min(v.size(),w.size()); i++){
        if(v[i] < w[i]) return true;
        if(v[i] > w[i]) return false;
    }
    return v.size() < w.size();
}
int main(){
    string filename = "test.txt";
    string line;
    //freopen("out.txt", "w", stdout);
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        //return EXIT_FAILURE;
    }
    vector<string> filepaths;
    while (getline(input_file, line)){
        stringstream ss(line);
        string value;
        while(ss>>value){
            filepaths.push_back(value);
        }
    }
    three_way_quick_sort(filepaths);
    for(int i=0;i<filepaths.size();i++){
        cout<<filepaths[i]<<endl;
    }
    cout<<"hello"<<endl;
    return 1;
}