#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> element;

main(){
    priority_queue<element,vector<element>,greater<element>> pq;
    pq.push(make_pair(1,5));
    pq.push(make_pair(10,7));
    pq.push(make_pair(5,7));
    pq.push(make_pair(8,6));
    pq.push(make_pair(3,3));
    while(!pq.empty()){
        element e = pq.top();
        pq.pop();
        cout << "(" << e.first << "," << e.second << ")" << endl;
    }
}
