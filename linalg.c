#include "linalg.h"

Vec2 vec2(int a, int b)
{
    Vec2 u = {a, b};
    return u;
}

Vec2 vec2s(int a)
{
    return vec2(a, a);
}

Vec2 vec2_add(Vec2 u, Vec2 v)
{
    return vec2(u.x + v.x, u.y + v.y);
}

Vec2 vec2_sub(Vec2 u, Vec2 v)
{
    return vec2(u.x - v.x, u.y - v.y);
}

Vec2 vec2_mul(Vec2 u, Vec2 v)
{
    return vec2(u.x * v.x, u.y * v.y);
}

Vec2 vec2_div(Vec2 u, Vec2 v)
{
    return vec2(u.x / v.x, u.y / v.y);
}