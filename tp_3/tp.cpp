#include <iostream>
#include <cstring>

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
        Expression(){}
        virtual int eval() const = 0;
        virtual Expression * clone() const = 0; 
        virtual ~Expression(){}      
};

class Constante:public Expression{
    public:
        int cst;
        Constante(int n): cst(n){}


        int eval()const {return cst;}


        Expression *clone() const
        {
            return new Constante(cst) ;
        }
};

class Plus:public Expression{
    public:
        Expression *ex1;
        Expression *ex2;

        Plus(const Expression &exp1, const Expression &exp2)
        {
            ex1 = exp1.clone();
            ex2 = exp2.clone();
        }

        int eval() const
        {
            return ex1->eval() + ex2->eval();
        }

        Expression *clone()const
        {
            return new Plus(*ex1,*ex2);
        }
};

class Min:public Expression{
    public:
        Expression *ex1;
        Expression *ex2;

        Min(const Expression &exp1, const Expression &exp2){
            ex1 = exp1.clone();
            ex2 = exp2.clone();
        }

        int eval() const{
            return ex1->eval() - ex2->eval();
        }
        Expression *clone() const
        {
            return new Min(*ex1,*ex2);
        }
};

class Mult: public Expression{
    public:
        Expression *ex1;
        Expression * ex2;

        Mult(const Expression &exp1, const Expression &exp2){
            ex1 = exp1.clone();
            ex2 = exp2.clone();
        }

        int eval() const{
            return ex1->eval() * ex2->eval();
        }

        Expression *clone() const
        {
            return new Mult(*ex1,*ex2);
        }    
};



int main (){
    /*
    fct a(5);
    cout<<a()<<endl;
    cout<<a()<<endl;
    */
   /*
   int a = 5;
   const Expression & e = Mult(Plus (Constante(a),Constante(-2)),Plus(Constante(1),Constante(3)));
   std::cout << e.eval() << std::endl;
   */
    return 0;
}