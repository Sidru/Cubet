#ifndef DRAW_H
#define DRAW_H

#include <cube.h>

typedef enum
{
    AXIS_X,
    AXIS_Y,
    AXIS_Z
}uDRAW_AXIS;

class cDraw {

    private:
        cCube* _pCube;

    public:
        cDraw();
        ~cDraw();
        void begin(cCube* Cube);

 
        void setvoxel(int x, int y, int z);
        void clrvoxel(int x, int y, int z);
        unsigned char in_range(int x, int y, int z);
        unsigned char getvoxel(int x, int y, int z);
        void altervoxel(int x, int y, int z, int state);
        //void flpvoxel(int x, int y, int z);
        //void argorder(int ix1, int ix2, int *ox1, int *ox2);
        //
        

        void setplane_x(int x);
        void setplane_y(int y);
        void setplane_z(int z);
        void clrplane_x(int x);
        void clrplane_y(int y);
        void clrplane_z(int z);
        void setplane(uDRAW_AXIS axis, unsigned char i);
        void clrplane(uDRAW_AXIS axis, unsigned char i);
        void fill(unsigned char pattern);

        void shift(uDRAW_AXIS axis, int direction);
};

#endif
