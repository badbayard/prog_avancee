#ifndef CHUNK_H
#include <iostream>
#define CHUNK_H

template<typename T,int Sizemax = 5>
class chunk{
    private:
        T *chunk;
        unsigned int size;
        int front_e;
        int back_e;

    public:
        chunk() : front_e(-1),back_e(-1){
                chunk = new T[Sizemax];
            }

        bool push_front(const T& e){
            if(front_e == -1){
                front_e = Sizemax / 2;
                back_e = Sizemax / 2;
                chunk[0] = e;
                --front_e;
                return true;
            }
            if(front_e == 0){
                return false;
            }
            --front_e;
            chunk[front_e] = e;
            return true;
        }

        bool push_back(const T& e){
            if(back_e == -1){
                front_e = Sizemax / 2;
                back_e = Sizemax / 2;
                chunk[0] = e;
                --back_e;
                return true;
            }
            if(back_e == 0) return false;

            --back_e;
            chunk[back_e] = e;
            return true;
        }
        ~chunk(){
            delete [] chunk;
        }

};

#endif