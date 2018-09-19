#ifndef MYDEQUE_H
#define MYDEQUE_H
#include <iostream>
#include <cstdlib>
#include "chunk.h"
#define nullptr NULL


template<typename T, int Sizechunk = 5, int NbChunkMax = 7>
class MyDeque{
    private:
        chunk<T,Sizechunk> *deque[NbChunkMax] = NULL;
        int front_c;
        int back_c;
    public:
        MyDeque() : front_c(NbChunkMax /2),back_c(NbChunkMax/2){
            deque = new chunk<T,Sizechunk>[Sizechunk];
            deque[front_c] = new chunk<T,Sizechunk>;
        }

        ~MyDeque(){
            for(int i = 0 ; i < NbChunkMax ; i++){
                delete deque[i];
            }
            delete [] deque;
        }

        bool push_front(const T& c){
            if(front_c == 0) return false;

            if(!deque[front_c]->push_front(c)){
                deque[front_c]->push_back(c);
            }else{
                --front_c;
                deque[front_c] = new chunk<T,Sizechunk>[front_c];
                return true;
            }
        }

        bool back_front(const T& c){
            if(back_c == 0) return false;

            if(!deque[back_c]->push_back(c)){
                deque[back_c]->push_front(c);
            }else{
                --front_c;
                deque[back_c] = new chunk<T,Sizechunk>[back_c];
                return true;
            }
        }
};

#endif