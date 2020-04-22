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
void effect_planboing(cDraw* Draw, int plane, int speedd);
void effect_wormsqueeze(cDraw* Draw, int size, int axis, int direction, int iterations, int wait);
#endif
