#include <Arduino.h>

#include <draw.h>

cDraw::cDraw(void)
{
    _sizeX = 8;
    _sizeY = 8;
    _sizeZ = 8;
}

cDraw::~cDraw(void)
{

}

void cDraw::begin(cCube* Cube)
{
    _pCube = Cube;
}

// Set a single voxel to ON
void cDraw::setvoxel(int x, int y, int z)
{
    if(inrange(x,y,z))
    {
        //cube[z][y] |= (1 << x);
        _pCube->set_voxel((uint32_t)x, (uint32_t)y, (uint32_t)z, 1);
    }
}
 
 
// Set a single voxel to ON
void cDraw::clrvoxel(int x, int y, int z)
{
    if(inrange(x,y,z))
    {
        //cube[z][y] &= ~(1 << x);
        _pCube->set_voxel((uint32_t)x, (uint32_t)y, (uint32_t)z, 0);
    }
}
 
 
// This function validates that we are drawing inside the cube.
unsigned char cDraw::inrange(int x, int y, int z)
{
    if (x >= 0 && x < (int)_sizeX && y >= 0 && y < (int)_sizeY && z >= 0 && z < (int)_sizeZ)
    {
            return 0x01;
    } else
    {
            // One of the coordinates was outside the cube.
            return 0x00;
    }
}
 
// Get the current status of a voxel
unsigned char cDraw::getvoxel(int x, int y, int z)
{
    if (inrange(x,y,z))
    {
        //if (cube[z][y] & (1 << x))
        if(_pCube->get_voxel(x, y, z))
        {
            return 0x01;
        } else
        {
            return 0x00;
        }
    } else
    {
        return 0x00;
    }
}
 
// In some effect we want to just take bool and write it to a voxel
// this function calls the apropriate voxel manipulation function.
void cDraw::altervoxel(int x, int y, int z, int state)
{
    if (state == 1)
    {
            this->setvoxel(x,y,z);
    } else
    {
            this->clrvoxel(x,y,z);
    }
}
 
// Flip the state of a voxel.
// If the voxel is 1, its turned into a 0, and vice versa.
void cDraw::flpvoxel(int x, int y, int z)
{
    uint8_t value;

    if (inrange(x, y, z))
    {
        value = _pCube->get_voxel(x, y, z);
        value ^= 1;
        _pCube->set_voxel(x, y, z, value);
        //cube[z][y] ^= (1 << x);
    }
        
}
 
// Makes sure x1 is alwas smaller than x2
// This is usefull for functions that uses for loops,
// to avoid infinite loops
void argorder(int ix1, int ix2, int *ox1, int *ox2)
{
        if (ix1>ix2)
        {
                int tmp;
                tmp = ix1;
                ix1= ix2;
                ix2 = tmp;
        }
        *ox1 = ix1;
        *ox2 = ix2;
}
 
// Sets all voxels along a X/Y plane at a given point
// on axis Z
void cDraw::setplane_z(int z)
{
    uint32_t x, y;

    for(x = 0; x < _sizeX; x++)
    {
        for(y = 0; y < _sizeY; y++)
        {
            _pCube->set_voxel(x, y, z, 1);
        }
    }

    //int i;
    //if (z>=0 && z<8)
    //{
    //    for (i=0;i<8;i++)
    //    {
    //        //cube[z][i] = 0xff;
    //    }
    //}
}

 
// Clears voxels in the same manner as above
void cDraw::clrplane_z(int z)
{
    uint32_t x, y;

    for(x = 0; x < _sizeX; x++)
    {
        for(y = 0; y < _sizeY; y++)
        {
            _pCube->set_voxel(x, y, z, 0);
        }
    }
    //int i;
    //if (z>=0 && z<8)
    //{
    //    for (i=0;i<8;i++)
    //    {
    //            //cube[z][i] = 0x00;
    //    }
    //}
}
 
void cDraw::setplane_x(int x)
{
    uint32_t z, y;

    for(z = 0; z < _sizeZ; z++)
    {
        for(y = 0; y < _sizeY; y++)
        {
            _pCube->set_voxel(x, y, z, 1);
        }
    }
    //int z;
    //int y;
    //if (x>=0 && x<8)
    //{
    //    for (z=0;z<8;z++)
    //    {
    //        for (y=0;y<8;y++)
    //        {
    //            //cube[z][y] |= (1 << x);
    //        }
    //    }
    //}
}
 
void cDraw::clrplane_x(int x)
{
    uint32_t z, y;

    for(z = 0; z < _sizeZ; z++)
    {
        for(y = 0; y < _sizeY; y++)
        {
            _pCube->set_voxel(x, y, z, 0);
        }
    }
    //int z;
    //int y;
    //if (x>=0 && x<8)
    //{
    //    for (z=0;z<8;z++)
    //    {
    //        for (y=0;y<8;y++)
    //        {
    //            //cube[z][y] &= ~(1 << x);
    //        }
    //    }
    //}
}
 
void cDraw::setplane_y(int y)
{
    uint32_t x, z;

    for(x = 0; x < _sizeX; x++)
    {
        for(z = 0; z < _sizeZ; z++)
        {
            _pCube->set_voxel(x, y, z, 1);
        }
    }
    //int z;
    //if (y>=0 && y<8)
    //{
    //    for (z=0;z<8;z++)
    //    {
    //        //cube[z][y] = 0xff;
    //    }
    //}
}
 
void cDraw::clrplane_y(int y)
{
    uint32_t x, z;

    for(x = 0; x < _sizeX; x++)
    {
        for(z = 0; z < _sizeZ; z++)
        {
            _pCube->set_voxel(x, y, z, 0);
        }
    }
    //int z;
    //if (y>=0 && y<8)
    //{
    //    for (z=0;z<8;z++)
    //    {
    //        //cube[z][y] = 0x00;
    //    }
    //}
}
 
void cDraw::setplane(uDRAW_AXIS axis, unsigned char i)
{
    switch (axis)
    {
        case AXIS_X:
            this->setplane_x(i);
            break;
       
       case AXIS_Y:
            this->setplane_y(i);
            break;
 
       case AXIS_Z:
            this->setplane_z(i);
            break;
    }
}
 
void cDraw::clrplane(uDRAW_AXIS axis, unsigned char i)
{
    switch (axis)
    {
        case AXIS_X:
            this->clrplane_x(i);
            break;
       
       case AXIS_Y:
            this->clrplane_y(i);
            break;
 
       case AXIS_Z:
            this->clrplane_z(i);
            break;
    }
}
 
// Fill a value into all 64 byts of the cube buffer
// Mostly used for clearing. fill(0x00)
// or setting all on. fill(0xff)
void cDraw::fill (unsigned char pattern)
{
    //int z;
    //int y;
    //for (z=0;z<8;z++)
    //{
    //    for (y=0;y<8;y++)
    //    {
    //        //cube[z][y] = pattern;
    //    }
    //}

    _pCube->fill_array((uint8_t)pattern); 
}
 
 
 
// Draw a box with all walls drawn and all voxels inside set
void cDraw::box_filled(int x1, int y1, int z1, int x2, int y2, int z2)
{
    int iy;
    int iz;
 
    argorder(x1, x2, &x1, &x2);
    argorder(y1, y2, &y1, &y2);
    argorder(z1, z2, &z1, &z2);
 
    for (iz=z1;iz<=z2;iz++)
    {
        for (iy=y1;iy<=y2;iy++)
        {
            //cube[iz][iy] |= byteline(x1,x2);
        }
    }
}

 
// Darw a hollow box with side walls.
void cDraw::box_walls(int x1, int y1, int z1, int x2, int y2, int z2)
{
    int iy;
    int iz;
   
    argorder(x1, x2, &x1, &x2);
    argorder(y1, y2, &y1, &y2);
    argorder(z1, z2, &z1, &z2);

    for (iz=z1;iz<=z2;iz++)
    {
        for (iy=y1;iy<=y2;iy++)
        {      
            if (iy == y1 || iy == y2 || iz == z1 || iz == z2)
            {
                //cube[iz][iy] = byteline(x1,x2);
            } else
            {
                //cube[iz][iy] |= ((0x01 << x1) | (0x01 << x2));
            }
        }
    }
}

 
// Draw a wireframe box. This only draws the corners and edges,
// no walls.
void cDraw::box_wireframe(int x1, int y1, int z1, int x2, int y2, int z2)
{
    int iy;
    int iz;

    argorder(x1, x2, &x1, &x2);
    argorder(y1, y2, &y1, &y2);
    argorder(z1, z2, &z1, &z2);

    // Lines along X axis
    //cube[z1][y1] = byteline(x1,x2);
    //cube[z1][y2] = byteline(x1,x2);
    //cube[z2][y1] = byteline(x1,x2);
    //cube[z2][y2] = byteline(x1,x2);

    // Lines along Y axis
    for (iy=y1;iy<=y2;iy++)
    {
        setvoxel(x1,iy,z1);
        setvoxel(x1,iy,z2);
        setvoxel(x2,iy,z1);
        setvoxel(x2,iy,z2);
    }

    // Lines along Z axis
    for (iz=z1;iz<=z2;iz++)
    {
        setvoxel(x1,y1,iz);
        setvoxel(x1,y2,iz);
        setvoxel(x2,y1,iz);
        setvoxel(x2,y2,iz);
    }

}
 

// Returns a byte with a row of 1's drawn in it.
// byteline(2,5) gives 0b00111100
char cDraw::byteline (int start, int end)
{
    return ((0xff<<start) & ~(0xff<<(end+1)));
}
 
// Flips a byte 180 degrees.
// MSB becomes LSB, LSB becomes MSB.
char cDraw::flipbyte (char byte)
{
    char flop = 0x00;

    flop = (flop & 0b11111110) | (0b00000001 & (byte >> 7));
    flop = (flop & 0b11111101) | (0b00000010 & (byte >> 5));
    flop = (flop & 0b11111011) | (0b00000100 & (byte >> 3));
    flop = (flop & 0b11110111) | (0b00001000 & (byte >> 1));
    flop = (flop & 0b11101111) | (0b00010000 & (byte << 1));
    flop = (flop & 0b11011111) | (0b00100000 & (byte << 3));
    flop = (flop & 0b10111111) | (0b01000000 & (byte << 5));
    flop = (flop & 0b01111111) | (0b10000000 & (byte << 7));
    return flop;
}
 
// Draw a line between any coordinates in 3d space.
// Uses integer values for input, so dont expect smooth animations.
void cDraw::line(int x1, int y1, int z1, int x2, int y2, int z2)
{
    float xy;       // how many voxels do we move on the y axis for each step on the x axis
    float xz;       // how many voxels do we move on the y axis for each step on the x axis
    unsigned char x,y,z;
    unsigned char lasty,lastz;

    // We always want to draw the line from x=0 to x=7.
    // If x1 is bigget than x2, we need to flip all the values.
    if (x1>x2)
    {
        int tmp;
        tmp = x2; x2 = x1; x1 = tmp;
        tmp = y2; y2 = y1; y1 = tmp;
        tmp = z2; z2 = z1; z1 = tmp;
    }

   
    if (y1>y2)
    {
        xy = (float)(y1-y2)/(float)(x2-x1);
        lasty = y2;
    } else
    {
        xy = (float)(y2-y1)/(float)(x2-x1);
        lasty = y1;
    }

    if (z1>z2)
    {
        xz = (float)(z1-z2)/(float)(x2-x1);
        lastz = z2;
    } else
    {
        xz = (float)(z2-z1)/(float)(x2-x1);
        lastz = z1;
    }



    // For each step of x, y increments by:
    for (x = x1; x<=x2;x++)
    {
        y = (xy*(x-x1))+y1;
        z = (xz*(x-x1))+z1;
        this->setvoxel(x,y,z);
    }
   
}
 

void cDraw::line_3d(int x1, int y1, int z1, int x2, int y2, int z2)
{
	int i, dx, dy, dz, l, m, n, x_inc, y_inc, z_inc,
	err_1, err_2, dx2, dy2, dz2;
	int pixel[3];
	pixel[0] = x1;
	pixel[1] = y1;
	pixel[2] = z1;
	dx = x2 - x1;
	dy = y2 - y1;
	dz = z2 - z1;
	x_inc = (dx < 0) ? -1 : 1;
	l = abs(dx);
	y_inc = (dy < 0) ? -1 : 1;
	m = abs(dy);
	z_inc = (dz < 0) ? -1 : 1;
	n = abs(dz);
	dx2 = l << 1;
	dy2 = m << 1;
	dz2 = n << 1;
	if ((l >= m) && (l >= n)) {
	err_1 = dy2 - l;
	err_2 = dz2 - l;
	for (i = 0; i < l; i++) {
	//PUT_PIXEL(pixel);
	this->setvoxel(pixel[0],pixel[1],pixel[2]);
	//printf("Setting %i %i %i \n", pixel[0],pixel[1],pixel[2]);
	if (err_1 > 0) {
	pixel[1] += y_inc;
	err_1 -= dx2;
	}
	if (err_2 > 0) {
	pixel[2] += z_inc;
	err_2 -= dx2;
	}
	err_1 += dy2;
	err_2 += dz2;
	pixel[0] += x_inc;
	}
	} else if ((m >= l) && (m >= n)) {
	err_1 = dx2 - m;
	err_2 = dz2 - m;
	for (i = 0; i < m; i++) {
	//PUT_PIXEL(pixel);
	this->setvoxel(pixel[0],pixel[1],pixel[2]);
	//printf("Setting %i %i %i \n", pixel[0],pixel[1],pixel[2]);
	if (err_1 > 0) {
	pixel[0] += x_inc;
	err_1 -= dy2;
	}
	if (err_2 > 0) {
	pixel[2] += z_inc;
	err_2 -= dy2;
	}
	err_1 += dx2;
	err_2 += dz2;
	pixel[1] += y_inc;
	}
	} else {
	err_1 = dy2 - n;
	err_2 = dx2 - n;
	for (i = 0; i < n; i++) {
	this->setvoxel(pixel[0],pixel[1],pixel[2]);
	//printf("Setting %i %i %i \n", pixel[0],pixel[1],pixel[2]);
	//PUT_PIXEL(pixel);
	if (err_1 > 0) {
	pixel[1] += y_inc;
	err_1 -= dz2;
	}
	if (err_2 > 0) {
	pixel[0] += x_inc;
	err_2 -= dz2;
	}
	err_1 += dy2;
	err_2 += dx2;
	pixel[2] += z_inc;
	}
	}
	this->setvoxel(pixel[0],pixel[1],pixel[2]);
	//printf("Setting %i %i %i \n", pixel[0],pixel[1],pixel[2]);
	//PUT_PIXEL(pixel);
}

 
// Shift the entire contents of the cube along an axis
// This is great for effects where you want to draw something
// on one side of the cube and have it flow towards the other
// side. Like rain flowing down the Z axiz.
void cDraw::shift (uDRAW_AXIS axis, int direction)
{
    int i, x ,y;
    int ii, iii;
    int state;

    for (i = 0; i < 8; i++)
    {
        if (direction == -1)
        {
            ii = i;
        } else
        {
            ii = (7-i);
        }      


        for (x = 0; x < 8; x++)
        {
            for (y = 0; y < 8; y++)
            {
                if (direction == -1)
                {
                    iii = ii+1;
                } else
                {
                    iii = ii-1;
                }
               
                if (axis == AXIS_Z)
                {
                    state = this->getvoxel(x,y,iii);
                    this->altervoxel(x,y,ii,state);
                }
               
                if (axis == AXIS_Y)
                {
                    state = this->getvoxel(x,iii,y);
                    this->altervoxel(x,ii,y,state);
                }
               
                if (axis == AXIS_X)
                {
                    state = this->getvoxel(iii,y,x);
                    this->altervoxel(ii,y,x,state);
                }
            }
        }
    }
   
    if (direction == -1)
    {
        i = 7;
    } else
    {
        i = 0;
    }      
   
    for (x = 0; x < 8; x++)
    {
        for (y = 0; y < 8; y++)
        {
            if (axis == AXIS_Z) this->clrvoxel(x,y,i);
                       
            if (axis == AXIS_Y) this->clrvoxel(x,i,y);
               
            if (axis == AXIS_X) this->clrvoxel(i,y,x);
        }
    }
}
