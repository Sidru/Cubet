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
        uint32_t _sizeX;
        uint32_t _sizeY;
        uint32_t _sizeZ;

    public:
        cDraw();
        ~cDraw();
        void begin(cCube* Cube);

 
        void setvoxel(int x, int y, int z);
        void clrvoxel(int x, int y, int z);
        unsigned char inrange(int x, int y, int z);
        unsigned char getvoxel(int x, int y, int z);
        void altervoxel(int x, int y, int z, int state);
        void flpvoxel(int x, int y, int z);
        void argorder(int ix1, int ix2, int *ox1, int *ox2);
        void setplane_x(int x);
        void setplane_y(int y);
        void setplane_z(int z);
        void clrplane_x(int x);
        void clrplane_y(int y);
        void clrplane_z(int z);
        void setplane(uDRAW_AXIS axis, unsigned char i);
        void clrplane(uDRAW_AXIS axis, unsigned char i);
        void fill(unsigned char pattern);

        void box_filled(int x1, int y1, int z1, int x2, int y2, int z2);
        void box_walls(int x1, int y1, int z1, int x2, int y2, int z2);
        void box_wireframe(int x1, int y1, int z1, int x2, int y2, int z2);
        char byteline (int start, int end);    
        char flipbyte (char byte);



        void line(int x1, int y1, int z1, int x2, int y2, int z2);
        void line_3d(int x1, int y1, int z1, int x2, int y2, int z2);

        void shift(uDRAW_AXIS axis, int direction);
};

#endif
