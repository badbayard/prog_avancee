#include <iostream>

using namespace std;

class String{
    public:
        string tab;
        char b;

        String(string _tab){
            tab = _tab;
        }
        String(char a){
            b = a;
        }
        void getString(){
            //printf("%s",tab);
            cout<<tab<<endl;
        }
        void convert(char b){
            tab = b;
        }
        string concat(string f){
            return tab = tab + f;
        }
        int chlongueur (string mot){
            int i;
             i=0;
            while (mot[i]!='\0')
            {
                i=i+1;
            }
            return i;
        }
        
        bool compare(string f){
            int lg1 = chlongueur(tab);
            int lg2 = chlongueur(f);

            for(int i = 0 ; i < lg1 ; i++){
                if(tab[i] != f[i] ){
                    return false;
                }
            }
            return true;
        }
        
};


int main(){
    string a;
    cout<<"mettre un mot"<<endl;
    cin >> a;
    String essai1(a);
    String essai2('z');
    essai1.getString();
    essai2.getString();
    //essai1.concat("hello");
    cout <<"apres operation"<<endl;
    essai1.getString();
    cout <<essai1.compare("tarte")<<endl;
    return 0;
}