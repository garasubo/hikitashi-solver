#include "bunsu.h"
#include <cmath>

using namespace Bunsu;

static unsigned int euqlid(unsigned int a, unsigned int b)
{

    if(a < b) swap(a,b);
    if(b == 0) return 0;
    while(a%b!=0){
        unsigned int tmp_b = b;
        b = a%b;
        a = tmp_b;
    }
    return b;
}

void yakubun()
{
    unsigned int c = gcd(abs(bunshi), abs(bunbo));

    bunsi /= c;
    bunbo /= c;
}

Bunsu(int bunshi)
{
    this->bunshi = bunshi;
    this->bunbo = 1;
}

Bunsu(int bunshi, int bunbo)
{
    this->bunshi = bunshi;
    this->bunbo = bunbo;
    yakubun();
    if(this->bunbo < 0){
        this->bunbo *= -1;
        this->bunshi *= -1;
    }
}

Bunsu operator+(const Bunsu& b)
{
    int div = gcd(this->bunbo, b.bunbo);
    int bunshi = this->bushi * (b.bunbo/div) + b.bushi * (this->bunbo/div);
    int bunbo = this->bunbo * (b.bunbo / div);

    return Busu(bunshi, bunbo);
}
Bunsu operator+(int b)
{
    return (*this + Bunsu(b));
}
Bunsu operator-(const Bunsu& b)
{
    int div = gcd(this->bunbo, b.bunbo);
    int bunshi = this->bushi * (b.bunbo/div) - b.bushi * (this->bunbo/div);
    int bunbo = this->bunbo * (b.bunbo / div);

    return Bunsu(bunshi, bunbo);
    
}
Bunsu operator-(int b)
{
    return (*this - Bunsu(b));
}
Bunsu operator*(const Bunsu& b)
{
    int bunshi = this->bunshi * b.bunshi;
    int bunbo = this->bunbo * b.bunbo;
    return Bunsu(bunshi, bunbo);
}
Bunsu operator*(int b)
{
    return (*this * Bunsu(b));
}
Bunsu operator/(const Bunsu& b)
{
    int bunshi = this->bunshi * b.bunbo;
    int bunbo = this->bunbo * b.bunshi;
    return Bunsu(bunshi, bunbo);
}
Bunsu operator/(int b)
{
    return (*this / Bunsu(b));
}
