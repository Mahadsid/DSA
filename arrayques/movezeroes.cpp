#include<iostream>
#include<vector>
using namespace std;


vector<int> movezeroes(vector<int> v) {

    int i = 0;

    for (int j = 0; j < v.size(); j++)
    {
        if (v[j]!=0)
        {
            swap(v[j],v[i]);
            i++;
        }
        
    }
    

    return v;

}

void print(vector<int> v) {

    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<int> v ;

    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(12);

    vector<int> ans = movezeroes(v);

    cout << "Printing reverse Array" <<endl;
    print(ans);


    return 0;
}
 