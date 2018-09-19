#include <iostream>
#include <iterator>
#include <deque>
#include <vector>
#include <algorithm>
#include <list>  


class fct{
    public:
        fct(int a): multiple(0), mul(a){}

        int operator()(){
            multiple++;
            return multiple*mul;
        }
    private:
        int multiple;
        int mul;
};

int main(){
    //int s1[5];
    std::vector<int> s1;
    std::deque<int> d;
    fct a(4);
    fct b(2);
    fct c(3);
    for(int i = 0 ; i < 5; i++){
        d.push_back(a());
    }
    std::ostream_iterator<int> out_it (std::cout," | ");
    std::copy (d.begin(),d.end(),out_it);

    for(int i = 0 ; i < 5 ; i++){
        s1.push_back(d[i]);
    }
    d.clear();
    std::vector<int> s2;
    for(int i = 0 ; i < 10 ; i++){
        s2.push_back(b());
    }
    std::cout<<std::endl;
    std::vector<int> s3;
    std::generate_n(std::inserter(s3,s3.begin()),10,c);
    std::copy (s1.begin(),s1.end(),out_it);
    std::cout<<std::endl;
    std::copy (s2.begin(),s2.end(),out_it);
    std::cout<<std::endl;
    std::copy (s3.begin(),s3.end(),out_it);

    std::list<int> l;
    l.resize(10);
    std::set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),l.begin());
    std::cout<<std::endl;
    std::copy (l.begin(),l.end(),out_it);
    

    return 0;
}