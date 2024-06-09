#include "a.h"
#include <cmath>

void mnog::calculations(){
    otvet = 0;
    for (int i = 0; i < LEN; i++){
      otvet += (kof[i] * pow(x, LEN-i-1));
    }
}
void mnog::print(){
    std::cout << "Ответ: " << otvet << std::endl;

}

void mnog::input(int a, int* b, int x1){
    LEN = a;
    for (int i = 0; i < LEN; i++){
        kof[i] = b[i];
    }
    x = x1;
} 
    mnog mnog::operator+(mnog& num){
        mnog result;
        if (max(LEN, num.LEN) == LEN){
            result.LEN = LEN;
            result.kof = new int[LEN];
            for (int i = 0; i < LEN; i++){
                result.kof[i] = kof[i];
            }
        }
        else{
            result.LEN = num.LEN;
            result.kof = new int(num.LEN);
            for (int i = 0; i < num.LEN; i++){
                result.kof[i] = num.kof[i];
            }
            
        }
        int g = 0;
        for (int i = max(LEN, num.LEN) - min(LEN, num.LEN); i < max(LEN, num.LEN); i++){
            if (max(LEN, num.LEN) == LEN){
                result.kof[i] = num.kof[g] + kof[i];
            }
            else{
                result.kof[i] = kof[g] + num.kof[i];
            }
            g++;
        }
        return result;
    }

    mnog mnog::operator-(mnog& num){
        mnog result;
        if (max(LEN, num.LEN) == LEN){
            result.LEN = LEN;
            result.kof = new int[LEN];
            for (int i = 0; i < LEN; i++){
                result.kof[i] = kof[i];
            }
        }
        else{
            result.LEN = num.LEN;
            result.kof = new int(num.LEN);
            for (int i = 0; i < num.LEN; i++){
                result.kof[i] = num.kof[i];
            }

        }
            int g = 0;
            for (int i = max(LEN, num.LEN) - min(LEN, num.LEN); i < max(LEN, num.LEN); i++){
                if (max(LEN, num.LEN) == LEN){
                    result.kof[i] = kof[i] - num.kof[g];
                }
                else{
                    result.kof[i] = kof[g] - num.kof[i];
                }
                g++;
            }
            return result;
        }
    mnog mnog::operator*(mnog& num){
        int* result = new int[LEN + num.LEN - 1];

        for (int i = 0; i < LEN + num.LEN - 1; i++) {
            result[i] = 0;
        }

        for (int i = 0; i < LEN; i++) {
            for (int j = 0; j < num.LEN; j++) {
                result[i + j] += kof[i] * num.kof[j];
            }
        }
        int newlen = LEN + num.LEN - 1;
        mnog result_mnog(newlen, result, 0);
        return result_mnog;
    }
    mnog mnog::operator/(mnog& num){
        if (LEN < num.LEN || (LEN == num.LEN && kof[0] < num.kof[0])){
            mnog result_mnog(1, new int[1]{0}, 0);
            return result_mnog;
        }
        mnog copy_of_first(*this);
        
        int* result = new int[LEN - num.LEN + 1];
        int max_it = LEN - num.LEN + 1;
        for (int i = 0; i < max_it; i++){
            result[i] = copy_of_first.kof[i] / num.kof[0];
                for (int j = 0; j < num.LEN; j++){
                copy_of_first.kof[i + j] -= num.kof[j] * result[i];
            }
        }
        mnog result_mnog(max_it, result, 0);
        return result_mnog;
    }

std::ostream& operator<<(std::ostream& out, const mnog& s){
    int newlen = 0;
    for (int i = 0; i < s.LEN; i++){
        if (s.kof[i] != 0) newlen = i + 1;
    }
    out << s.kof[0] << "x^" << newlen-1 << " ";
    for (int i = 1; i < newlen; i++){
        if (s.kof[i] != 0 && newlen - i - 1 != 0){
            if (s.kof[i] > 0){
                out << "+ "  << s.kof[i] << "x^" << newlen-i-1 << " ";
            }
            else if(s.kof[i] < 0){
                out << "- " << abs(s.kof[i]) << "x^" << newlen-i-1 << " ";
            }
        }
        else{
                if (s.kof[i] > 0){
                    out << "+ "  << s.kof[i];
                }
                else if(s.kof[i] < 0){
                    out << "- " << abs(s.kof[i]);
                }
        }
    }
    return out;
    }

void mnog::operator=(mnog& num){
    LEN = num.LEN;
    for (int i = 0; i < LEN; i++){
        kof[i] = num.kof[i];
    }
    x = num.x;
    otvet = num.otvet;
}
