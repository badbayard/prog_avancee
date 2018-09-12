#include <iostream>

using namespace std;

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

class Expression{
    public:
        virtual int eval() const;
        virtual Expression * clone() const;      
};

class Constante:public Expression{
    public:
        int cst;
        Constante(int n): cst(n){}
        int eval()const {return cst;}
        Constante *clone() {
            return new Constante(*this);
        }
};

class Plus:public Expression{
    public:
        Expression *ex1;
        Expression *ex2;

        Plus(const Expression &exp1, const Expression &exp2){
            ex1 = exp1.clone();
            ex2 = exp2.clone();
        }

        Plus(Plus &p_autre){
            ex1 = p_autre.ex1->clone();
            ex2 = p_autre.ex2->clone();
        }
        int eval() const override{
            return ex1->eval() + ex2->eval();
        }
}; 

int main (){
    fct a(5);
    cout<<a()<<endl;
    cout<<a()<<endl;
    return 0;
}