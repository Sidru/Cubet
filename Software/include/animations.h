#ifndef ANIMATIONS_H
#define ANIMATION_H

#include <Arduino.h>
#include <cube.h>

typedef enum
{
    ANIM_NONE = 0,
    ANIM_RAIN,
    ANIM_MAX
}uANIMATION;



class cAnim {
    private:
        uANIMATION active_anim;
        uint32_t step;
    public:
        cAnim();
        ~cAnim();
        void begin(cCube* Cube);
        void refresh(void);
        void start(uANIMATION anim, uint32_t iterations, uint32_t speed);
        void stop(void);
        uANIMATION get_anim(void);
};

void effect_rain(cDraw* Draw, int iterations);
void effect_planboing(cDraw* pDraw, uDRAW_AXIS plane, int speedd);
void effect_wormsqueeze(cDraw* Draw, int size, int axis, int direction, int iterations, int wait);
void effect_rand_patharound(cDraw* pDraw, int iterations, int delay);
void sinelines(cDraw* Draw, int iterations, int delay);


void draw_positions_axis(cDraw* pDraw, char axis, unsigned char positions[64], int invert);
void effect_random_sparkle(cDraw* pDraw);
void side_ripples(cDraw* pDraw, int iterations, int delay);
void mirror_ripples(cDraw* pDraw, int iterations, int delay);
void quad_ripples(cDraw* pDraw, int iterations, int delay);
void linespin(cDraw* pDraw, int iterations, int delay);

void effect_text(cDraw* pDraw, char* string, uint32_t size, uint32_t speed);




#endif
