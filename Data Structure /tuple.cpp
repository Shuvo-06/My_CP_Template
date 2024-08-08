#include<bits/stdc++.h>
using namespace std;

int main(){
    //declaration
    tuple<int, char, string> t1, t2;

    //modifying tuple
    t1 = make_tuple(57, 'c', "shuvo");
    t2 = make_tuple(58, 's', "siam");
    get <0> (t1) = 58;

    //printing values of tuple
    cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << "\n";

    // Tuple size 
    cout << tuple_size <decltype(t1)> :: value << "\n";

    //Swapping tuples
    t1.swap(t2);

    //unpacking tuple values
    int var11;
    char var12;
    string var13;
    tie (var11, var12, var13) = t1;

    int var21;
    char var22; // no value will be assigned because of ignore keyword
    string var23;
    tie (var21, ignore, var23) = t2;

    //tuple concatenation
    auto t3 = tuple_cat(t1, t2);
    cout << get<0>(t3) << ' ' << get<1>(t3) << ' ' << get<2>(t3) << ' ' << get<3>(t3) << ' ' << get<4>(t3) << ' ' << get<5>(t3) << '\n';
    return 0;
}
