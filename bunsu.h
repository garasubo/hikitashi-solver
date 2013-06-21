#ifndef INCLUDED_BUNSU_H
#define INCLUDED_BUNSU_H

class Bunsu{
    int bunshi;
    int bunbo;
    void yakubun();
    public:
    Bunsu(){}
    Bunsu(int bunshi);
    Bunsu(int bunshi, int bunbo);
    Bunsu operator+(const Bunsu& b);
    Bunsu operator+(int b);
    Bunsu operator-(const Bunsu& b);
    Bunsu operator-(int b);
    Bunsu operator*(const Bunsu& b);
    Bunsu operator*(int b);
    Bunsu operator/(const Bunsu& b);
    Bunsu operator/(int b);
};


#endif
