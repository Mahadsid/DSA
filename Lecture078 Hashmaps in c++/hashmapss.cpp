#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){

    unordered_map<string, int> m;
    //insertion
    //mthd`1
    pair<string, int> p = make_pair("sid", 8);
    m.insert(p);

    //mthd`2
    pair<string, int> q("msid", 10);
    m.insert(q);

    //mthd`3
    m["mahad"] = 5;

    m["mahad"] = 4; // dusri baar upadtion hojayegi no duplicates allowed onley one key correspond one value

    //search 
    cout << m["mahad"] << endl; // it creates entry and map it with 0 if not present  

    cout << m.at("msid") << endl; // .at gives outofbound error if entry is not present

    //size
    cout << m.size() << endl;

    //to check presence
    cout << m.count("bro") << endl; // key absent->0, key present-> 1

    //erase
    m.erase("sid");

    //traverse map
    //mthd`1
    for(auto i :m){
        cout << i.first << " " << i.second << endl;
    }

    //mthd`2 iterator
    unordered_map<string, int> :: iterator it = m.begin(); // using unordered so 
    // things print unorderly if we use map both it prints orderly insertion wise
    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }








    return 0;
}