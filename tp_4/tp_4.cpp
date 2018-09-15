template<typename T>
void mySwap(T& a,T& b)
{
    T tmp;
    tmp = a;
    a = b ;
    b = tmp;
}

template<typename T>
const T& myMin(const T& a, const T& b)
{
    return (a < b )? a : b;
}
template<>
const string& myMin(const string &left,const string &right)
{
    return (left.length() < right.length())? left : right;
}
template<>
const char* const & myMin(const char* const & a, const char* const & b){
    unsigned int i = 0;
    while(a[i] != '\0'){
        if (b[i] == '\0') return b;
        i++;
    }
    return a;
}

template<typename T,unsigned int Size = 10>
class Tableau{
    private:
        T *tab;
        unsigned int taille = 0;
        unsigned int tailleMax = Size;
    public:
        Tableau(){ tab = new T[Size];}
        Tableau(const T *d, int d_lentgth){
            tab = new T[Size];
            for(int i =0 ; i <d_lentgth ;i++ ){
                insert(d[i]);
            }
        }
        
        void insert(const T& e){
            if(taille == tailleMax){
                T* tmp = new T[tailleMax +Size];
                for(unsigned int i = 0 ;i <taille ; i++){
                    tmp[i] = tab[i];
                }
                delete [] tab;
                tab = tmp;
            }
            tab[taille] = e;
            taille++;
        }

        unsigned getlenght(){
            return ;
        }

};

int main(){
	 /*
    int a = 5;
    int b = 6;
    cout <<"valeur de a "<<a <<" valeur de b "<<b<<endl;
    mySwap(a,b);
    cout <<"valeur de a "<<a <<" valeur de b "<<b<<endl;
    cout << "la plus petite valeur est : "<<myMin(a,b)<<endl;

    string a1 = "tata";
    string a2 = "tonton";

    cout <<"le plus petit est "<<myMin(a1,a2)<<endl;
    */
	return 0;
}