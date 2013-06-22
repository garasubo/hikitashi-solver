#ifndef INCLUDED_BUNSU_H
#define INCLUDED_BUNSU_H

class Bunsu{
    void yakubun();
    public:
    int bunshi;
    int bunbo;
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
    inline int getBunshi(){ return bunshi; }
    inline int getBunbo(){ return bunbo; }
    bool operator==(Bunsu b);
};

class BunsuComp{
    public:
    bool operator()(const Bunsu &a, const Bunsu &b);
};


#endif
