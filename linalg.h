typedef struct {
    int x, y;
} Vec2;

Vec2 vec2s(int a);
Vec2 vec2(int a, int b);
Vec2 vec2_add(Vec2 u, Vec2 v);
Vec2 vec2_sub(Vec2 u, Vec2 v);
Vec2 vec2_mul(Vec2 u, Vec2 v);
Vec2 vec2_div(Vec2 u, Vec2 v);