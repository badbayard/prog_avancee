#include <iostream>

using namespace std;

class pixel{
  public:
    int a;
    int b;
    int c;

		pixel(){
			a = 0;
			b = 0;
			c = 0;
		}

		int get_a(){
			return a;
		}

		int get_b(){
			return b;
		}

		int get_c(){
			return c;
		}

		void set_a(int _a){
			a = _a;
		}

		void set_b(int _b){
			b = _b;
		}

		void set_c(int _c){
			c = _c;
		}

		~pixel(){}
};

class image{
	public:
		int largeur;
		int hauteur;
		pixel ** tab;

		image(int largeur,int hauteur){
			tab = new pixel*[hauteur];
			for(int i = 0 ; i < hauteur ; i++){
				tab[i] = new pixel[largeur];
			}
		}

		int get_largeur(){
			return largeur;
		}

		int get_hauteur(){
			return hauteur;
		}

		void set_largeur(int x){
			largeur = x ; 
		}

		void set_hauteur(int y){
			hauteur = y ; 
		}

		pixel& operator()(int x, int y){
			return tab[y][x];
		}

		~image(){
			for (int i =0; i< hauteur ; i++){
				delete []tab[i];
			}
			delete []tab;
		}

};


int main (){


	image essai(5,5);

	for(int i = 0 ; i< essai.get_hauteur();i++){
		for(int j = 0; j< essai.get_largeur();j++){
			essai(i,j).set_a(1);
			essai(i,j).set_b(2);
			essai(i,j).set_c(3);
		}
	}
/*
	pixel essai;
	cout <<essai.get_a()<<" valeur essai avant " <<endl;
	essai.set_a(80);
	cout <<essai.get_a()<<" valeur essai apres " <<endl;
  cout << "hello world"<<endl;
*/
  return 0 ;
}