//volatile const unsigned char font[910] [5] = {
//	0x00,0x00,0x00,0x00,0x00,0x00,0x5f,0x5f,0x00,0x00,	//  !
//	0x00,0x03,0x00,0x03,0x00,0x14,0x7f,0x14,0x7f,0x14,	// "#
//	0x24,0x2a,0x7f,0x2a,0x12,0x23,0x13,0x08,0x64,0x62,	// $%
//	0x36,0x49,0x55,0x22,0x50,0x00,0x05,0x03,0x00,0x00,	// &'
//	0x00,0x1c,0x22,0x41,0x00,0x00,0x41,0x22,0x1c,0x00,	// ()
//	0x14,0x08,0x3e,0x08,0x14,0x08,0x08,0x3e,0x08,0x08,	// *+
//	0x00,0x50,0x30,0x00,0x00,0x08,0x08,0x08,0x08,0x08,	// ,-
//	0x00,0x60,0x60,0x00,0x00,0x20,0x10,0x08,0x04,0x02,	// ./
//	0x3e,0x51,0x49,0x45,0x3e,0x00,0x42,0x7f,0x40,0x00,	// 01
//	0x42,0x61,0x51,0x49,0x46,0x21,0x41,0x45,0x4b,0x31,	// 23
//	0x18,0x14,0x12,0x7f,0x10,0x27,0x45,0x45,0x45,0x39,	// 45
//	0x3c,0x4a,0x49,0x49,0x30,0x01,0x71,0x09,0x05,0x03,	// 67
//	0x36,0x49,0x49,0x49,0x36,0x06,0x49,0x49,0x29,0x1e,	// 89
//	0x00,0x36,0x36,0x00,0x00,0x00,0x56,0x36,0x00,0x00,	// :;
//	0x08,0x14,0x22,0x41,0x00,0x14,0x14,0x14,0x14,0x14,	// <=
//	0x00,0x41,0x22,0x14,0x08,0x02,0x01,0x51,0x09,0x06,	// >?
//	0x32,0x49,0x79,0x41,0x3e,0x7e,0x11,0x11,0x11,0x7e,	// @A
//	0x7f,0x49,0x49,0x49,0x36,0x3e,0x41,0x41,0x41,0x22,	// BC
//	0x7f,0x41,0x41,0x22,0x1c,0x7f,0x49,0x49,0x49,0x41,	// DE
//	0x7f,0x09,0x09,0x09,0x01,0x3e,0x41,0x49,0x49,0x7a,	// FG
//	0x7f,0x08,0x08,0x08,0x7f,0x00,0x41,0x7f,0x41,0x00,	// HI
//	0x20,0x40,0x41,0x3f,0x01,0x7f,0x08,0x14,0x22,0x41,	// JK
//	0x7f,0x40,0x40,0x40,0x40,0x7f,0x02,0x0c,0x02,0x7f,	// LM
//	0x7f,0x04,0x08,0x10,0x7f,0x3e,0x41,0x41,0x41,0x3e,	// NO
//	0x7f,0x09,0x09,0x09,0x06,0x3e,0x41,0x51,0x21,0x5e,	// PQ
//	0x7f,0x09,0x19,0x29,0x46,0x46,0x49,0x49,0x49,0x31,	// RS
//	0x01,0x01,0x7f,0x01,0x01,0x3f,0x40,0x40,0x40,0x3f,	// TU
//	0x1f,0x20,0x40,0x20,0x1f,0x3f,0x40,0x38,0x40,0x3f,	// VW
//	0x63,0x14,0x08,0x14,0x63,0x07,0x08,0x70,0x08,0x07,	// XY
//	0x61,0x51,0x49,0x45,0x43,0x00,0x7f,0x41,0x41,0x00,	// Z[
//	0x02,0x04,0x08,0x10,0x20,0x00,0x41,0x41,0x7f,0x00,	// \]
//	0x04,0x02,0x01,0x02,0x04,0x40,0x40,0x40,0x40,0x40,	// ^_
//	0x00,0x01,0x02,0x04,0x00,0x20,0x54,0x54,0x54,0x78,	// `a
//	0x7f,0x48,0x44,0x44,0x38,0x38,0x44,0x44,0x44,0x20,	// bc
//	0x38,0x44,0x44,0x48,0x7f,0x38,0x54,0x54,0x54,0x18,	// de
//	0x08,0x7e,0x09,0x01,0x02,0x0c,0x52,0x52,0x52,0x3e,	// fg
//	0x7f,0x08,0x04,0x04,0x78,0x00,0x44,0x7d,0x40,0x00,	// hi
//	0x20,0x40,0x44,0x3d,0x00,0x7f,0x10,0x28,0x44,0x00,	// jk
//	0x00,0x41,0x7f,0x40,0x00,0x7c,0x04,0x18,0x04,0x78,	// lm
//	0x7c,0x08,0x04,0x04,0x78,0x38,0x44,0x44,0x44,0x38,	// no
//	0x7c,0x14,0x14,0x14,0x08,0x08,0x14,0x14,0x18,0x7c,	// pq
//	0x7c,0x08,0x04,0x04,0x08,0x48,0x54,0x54,0x54,0x20,	// rs
//	0x04,0x3f,0x44,0x40,0x20,0x3c,0x40,0x40,0x20,0x7c,	// tu
//	0x1c,0x20,0x40,0x20,0x1c,0x3c,0x40,0x30,0x40,0x3c,	// vw
//	0x44,0x28,0x10,0x28,0x44,0x0c,0x50,0x50,0x50,0x3c,	// xy
//	0x44,0x64,0x54,0x4c,0x44				// z
//};
//
//volatile const unsigned char bitmaps[13][8] = {
//	{0xc3,0xc3,0x00,0x18,0x18,0x81,0xff,0x7e}, // smiley 3 small
//	{0x3c,0x42,0x81,0x81,0xc3,0x24,0xa5,0xe7}, // Omega
//	{0x00,0x04,0x06,0xff,0xff,0x06,0x04,0x00},  // Arrow
//	{0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81}, // X
//	{0xBD,0xA1,0xA1,0xB9,0xA1,0xA1,0xA1,0x00}, // ifi
//	{0xEF,0x48,0x4B,0x49,0x4F,0x00,0x00,0x00}, // TG
//	{0x38,0x7f,0xE6,0xC0,0xE6,0x7f,0x38,0x00}, // Commodore symbol
//	{0x00,0x22,0x77,0x7f,0x3e,0x3e,0x1c,0x08}, // Heart
//	{0x1C,0x22,0x55,0x49,0x5d,0x22,0x1c,0x00}, // face
//	{0x37,0x42,0x22,0x12,0x62,0x00,0x7f,0x00}, // ST
//	{0x89,0x4A,0x2c,0xF8,0x1F,0x34,0x52,0x91}, // STAR
//	{0x18,0x3c,0x7e,0xdb,0xff,0x24,0x5a,0xa5}, // Space Invader
//	{0x00,0x9c,0xa2,0xc5,0xc1,0xa2,0x9c,0x00}	// Fish
//};
//
//
//
//const unsigned char paths[44] PROGMEM = {0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x67,0x57,0x47,0x37,0x27,0x17,
//0x04,0x03,0x12,0x21,0x30,0x40,0x51,0x62,0x73,0x74,0x65,0x56,0x47,0x37,0x26,0x15}; // circle, len 16, offset 28
//
//
//void effect_wormsqueeze (int size, int axis, int direction, int iterations, int delay)
//{
//	int x, y, i,j,k, dx, dy;
//	int cube_size;
//	int origin = 0;
//	
//	if (direction == -1)
//		origin = 7;
//	
//	cube_size = 8-(size-1);
//	
//	x = rand()%cube_size;
//	y = rand()%cube_size;
//	
//	for (i=0; i<iterations; i++)
//	{
//		dx = ((rand()%3)-1);
//		dy = ((rand()%3)-1);
//	
//		if ((x+dx) > 0 && (x+dx) < cube_size)
//			x += dx;
//			
//		if ((y+dy) > 0 && (y+dy) < cube_size)
//			y += dy;
//	
//		shift(axis, direction);
//		
//
//		for (j=0; j<size;j++)
//		{
//			for (k=0; k<size;k++)
//			{
//				if (axis == AXIS_Z)
//					setvoxel(x+j,y+k,origin);
//					
//				if (axis == AXIS_Y)
//					setvoxel(x+j,origin,y+k);
//					
//				if (axis == AXIS_X)
//					setvoxel(origin,y+j,x+k);
//			}
//		}
//		
//		delay_ms(delay);
//	}
//}
//
//  void font_getpath (unsigned char path, unsigned char *destination, int length)
//{
//	int i;
//	int offset = 0;
//	
//	if (path == 1)
//		offset=28;
//	
//	for (i = 0; i < length; i++)
//		destination[i] = pgm_read_byte(&paths[i+offset]);
//}
//
//   void effect_pathmove (unsigned char *path, int length)
//{
//	int i,z;
//	unsigned char state;
//	
//	for (i=(length-1);i>=1;i--)
//	{
//		for (z=0;z<8;z++)
//		{
//		
//			state = getvoxel(((path[(i-1)]>>4) & 0x0f), (path[(i-1)] & 0x0f), z);
//			altervoxel(((path[i]>>4) & 0x0f), (path[i] & 0x0f), z, state);
//		}
//	}
//	for (i=0;i<8;i++)
//		clrvoxel(((path[0]>>4) & 0x0f), (path[0] & 0x0f),i);
//}
//
//void effect_rand_patharound (int iterations, int delay)
//{
//	int z, dz, i;
//	z = 4;
//	unsigned char path[28];
//	
//	font_getpath(0,path,28);
//	
//	for (i = 0; i < iterations; i++)
//	{
//		dz = ((rand()%3)-1);
//		z += dz;
//		
//		if (z>7)
//			z = 7;
//			
//		if (z<0)
//			z = 0;
//		
//		effect_pathmove(path, 28);
//		setvoxel(0,7,z);
//		delay_ms(delay);
//	}
//}
//
//
//   void effect_intro(){
//int cnt,cnt_2,time; 
// 
//  //Bottom To Top  
//   
//  for(cnt=0;cnt<=7;cnt++){
//   box_wireframe(0, 0, 0, 7, 7, cnt);   
//   delay_ms(2000);
//  }
//  for(cnt=0;cnt<7;cnt++){
//  clrplane_z(cnt);
//  delay_ms(2000);  
//  }
//  
//  //Shift Things Right
//    //1
//  shift(AXIS_Y,-1);
//  for(cnt=0;cnt<=7;cnt++){
//  setvoxel(cnt,0,6);  
//  }
//  delay_ms(2000);  
//    //2
//  shift(AXIS_Y,-1);
//  for(cnt=0;cnt<=7;cnt++){
//  setvoxel(cnt,0,5);  
//  }
//  setvoxel(0,0,6);
//  setvoxel(7,0,6);
//  delay_ms(2000);  
//    //3
//  shift(AXIS_Y,-1);
//  for(cnt=0;cnt<=7;cnt++){
//  setvoxel(cnt,0,4);  
//  }
//  setvoxel(0,0,5);
//  setvoxel(7,0,5);
//  setvoxel(0,0,6);
//  setvoxel(7,0,6);
//  delay_ms(2000);
//
//    //4
//  shift(AXIS_Y,-1);
//  for(cnt=0;cnt<=7;cnt++){
//  setvoxel(cnt,0,3);  
//  }
//  setvoxel(0,0,4);
//  setvoxel(7,0,4);
//  setvoxel(0,0,5);
//  setvoxel(7,0,5);
//  setvoxel(0,0,6);
//  setvoxel(7,0,6);
//  delay_ms(2000);
//   
//    //5
//  shift(AXIS_Y,-1);
//  for(cnt=0;cnt<=7;cnt++){
//  setvoxel(cnt,0,2);  
//  }
//  setvoxel(0,0,3);
//  setvoxel(7,0,3);
//  setvoxel(0,0,4);
//  setvoxel(7,0,4);
//  setvoxel(0,0,5);
//  setvoxel(7,0,5);
//  setvoxel(0,0,6);
//  setvoxel(7,0,6);
//    delay_ms(2000);
//  
//    //6
//  shift(AXIS_Y,-1);
//  for(cnt=0;cnt<=7;cnt++){
//  setvoxel(cnt,0,1);  
//  }
//  setvoxel(0,0,2);
//  setvoxel(7,0,2);
//  setvoxel(0,0,3);
//  setvoxel(7,0,3);
//  setvoxel(0,0,4);
//  setvoxel(7,0,4);
//  setvoxel(0,0,5);
//  setvoxel(7,0,5);
//  delay_ms(2000);
//  
//  
//    //7
//  shift(AXIS_Y,-1);
//  for(cnt=0;cnt<=7;cnt++){
//  setvoxel(cnt,0,0);  
//  }
//  setvoxel(0,0,1);
//  setvoxel(7,0,1);
//  setvoxel(0,0,2);
//  setvoxel(7,0,2);
//  setvoxel(0,0,3);
//  setvoxel(7,0,3);
//  setvoxel(0,0,4);
//  setvoxel(7,0,4);  
//  setvoxel(0,0,5);
//  setvoxel(7,0,5);
//  delay_ms(2000);
//
//    //Right To Left   
//  for(cnt=0;cnt<=7;cnt++){
//   box_wireframe(0, 0, 0, 7, cnt, 7);   
//   delay_ms(2000);
//  }
//  for(cnt=0;cnt<7;cnt++){
//  clrplane_y(cnt);
//  delay_ms(2000);  
//  }
//
//  //Shift to the bottom
//  for(cnt_2=6;cnt_2>=0;cnt_2--){
//    shift(AXIS_Z,-1);
//    for(cnt=0;cnt<=7;cnt++){
//      setvoxel(cnt,cnt_2,0);  
//    }
//      for(cnt=6;cnt>cnt_2;cnt--){
//        setvoxel(0,cnt,0);
//        setvoxel(7,cnt,0);      
//      }
//    
//      delay_ms(2000);  
//  }   
//
//  //Make All Wall Box
//
//  for(cnt=0;cnt<=6;cnt++){
//    fill(0x00);    
//    box_walls(0,0,0,7,7,cnt); 
//    delay_ms(2000);  
//  }  
//  
//  time = 2000;
//  for(cnt_2=0;cnt_2<5;cnt_2++){
//  time = time - 300;
//  //Make Box Smaller
//    for(cnt=0;cnt<=3;cnt++){
//      fill(0x00);
//      box_walls(cnt,cnt,cnt,7-cnt,7-cnt,7-cnt);   
//      delay_ms(time);
//    }  
//    
//    //Make Box Bigger
//    for(cnt=0;cnt<=3;cnt++){
//      fill(0x00);
//      box_walls(3-cnt,3-cnt,3-cnt,4+cnt,4+cnt,4+cnt);   
//      delay_ms(time);
//    }  
//  }
//  for(cnt_2=0;cnt_2<5;cnt_2++){
//  time = time + 300;
//  //Make Box Smaller
//  for(cnt=0;cnt<=3;cnt++){
//    fill(0x00);
//    box_walls(cnt,cnt,cnt,7-cnt,7-cnt,7-cnt);   
//    delay_ms(time);
//  }  
//  
//  //Make Box Bigger
//  for(cnt=0;cnt<=3;cnt++){
//    fill(0x00);
//    box_walls(3-cnt,3-cnt,3-cnt,4+cnt,4+cnt,4+cnt);   
//    delay_ms(time);
//  }  
//  }  
//    delay_ms(2000);
//  
//}
//void sinelines (int iterations, int delay)
//{
//	int i,x;
//
//	float left, right, sine_base, x_dividor,ripple_height;
//
//	for (i=0; i<iterations; i++)
//	{
//		for (x=0; x<8 ;x++)
//		{
//			x_dividor = 2 + sin((float)i/100)+1;
//			ripple_height = 3 + (sin((float)i/200)+1)*6;
//
//			sine_base = (float) i/40 + (float) x/x_dividor;
//
//			left = 4 + sin(sine_base)*ripple_height;
//			right = 4 + cos(sine_base)*ripple_height;
//			right = 7-left;
//
//			//printf("%i %i \n", (int) left, (int) right);
//
//			line_3d(0-3, x, (int) left, 7+3, x, (int) right);
//			//line_3d((int) right, 7, x);
//		}
//	
//	// delay_ms(delay);
//	fill(0x00);
//	}
//}
//  void effect_random_sparkle_flash (int iterations, int voxels, int delay)
//{
//	int i;
//	int v;
//	for (i = 0; i < iterations; i++)
//	{
//		for (v=0;v<=voxels;v++)
//			setvoxel(rand()%8,rand()%8,rand()%8);
//			
//		delay_ms(delay);
//		fill(0x00);
//	}
//}
//
//  
//
//void draw_positions_axis (char axis, unsigned char positions[64], int invert)
//{
//	int x, y, p;
//	
//	fill(0x00);
//	
//	for (x=0; x<8; x++)
//	{
//		for (y=0; y<8; y++)
//		{
//			if (invert)
//			{
//				p = (7-positions[(x*8)+y]);
//			} else
//			{
//				p = positions[(x*8)+y];
//			}
//		
//			if (axis == AXIS_Z)
//				setvoxel(x,y,p);
//				
//			if (axis == AXIS_Y)
//				setvoxel(x,p,y);
//				
//			if (axis == AXIS_X)
//				setvoxel(p,y,x);
//		}
//	}
//	
//}
//
//  void effect_random_sparkle (void)
//{
//	int i;
//	
//	for (i=1;i<20;i++)
//	{
//		effect_random_sparkle_flash(5,i,200);
//	}
//	
//	for (i=20;i>=1;i--)
//	{
//		effect_random_sparkle_flash(5,i,200);
//	}
//	
//}
//
//   void side_ripples(int iterations, int delay)
//{
//	// 16 values for square root of a^2+b^2.  index a*4+b = 10*sqrt
//	// This gives the distance to 3.5,3.5 from the point
//	unsigned char sqrt_LUT[]={49,43,38,35,43,35,29,26,38,29,21,16,35,25,16,7};
//	//LUT_START // Macro from new tottymath.  Commented and replaced with full code
//	unsigned char LUT[65];
//	init_LUT(LUT);
//	int i;
//	unsigned char x,y,height,distance;
//	for (i=0;i<iterations*4;i+=4)
//	{
//		fill(0x00);
//		for (x=0;x<4;x++)
//			for(y=0;y<4;y++)
//			{
//				// x+y*4 gives no. from 0-15 for sqrt_LUT
//				distance=sqrt_LUT[x+y*4];// distance is 0-50 roughly
//				// height is sin of distance + iteration*4
//				//height=4+totty_sin(LUT,distance+i)/52;
//				height=(196+totty_sin(LUT,distance+i))/49;
//				// Use 4-way mirroring to save on calculations
//				setvoxel(x,height,y);
//				setvoxel(7-x,height,y);
//				setvoxel(x,height,7-y);
//				setvoxel(7-x,height,7-y);
//				setvoxel(x,7-height,y);
//				setvoxel(7-x,7-height,y);
//				setvoxel(x,7-height,7-y);
//				setvoxel(7-x,7-height,7-y);
//
//			}
//		delay_ms(delay);
//	}
//}
//
//   void mirror_ripples(int iterations, int delay)
//{
//	// 16 values for square root of a^2+b^2.  index a*4+b = 10*sqrt
//	// This gives the distance to 3.5,3.5 from the point
//	unsigned char sqrt_LUT[]={49,43,38,35,43,35,29,26,38,29,21,16,35,25,16,7};
//	//LUT_START // Macro from new tottymath.  Commented and replaced with full code
//	unsigned char LUT[65];
//	init_LUT(LUT);
//	int i;
//	unsigned char x,y,height,distance;
//	for (i=0;i<iterations*4;i+=4)
//	{
//		fill(0x00);
//		for (x=0;x<4;x++)
//			for(y=0;y<4;y++)
//			{
//				// x+y*4 gives no. from 0-15 for sqrt_LUT
//				distance=sqrt_LUT[x+y*4];// distance is 0-50 roughly
//				// height is sin of distance + iteration*4
//				//height=4+totty_sin(LUT,distance+i)/52;
//				height=(196+totty_sin(LUT,distance+i))/49;
//				// Use 4-way mirroring to save on calculations
//				setvoxel(x,y,height);
//				setvoxel(7-x,y,height);
//				setvoxel(x,7-y,height);
//				setvoxel(7-x,7-y,height);
//				setvoxel(x,y,7-height);
//				setvoxel(7-x,y,7-height);
//				setvoxel(x,7-y,7-height);
//				setvoxel(7-x,7-y,7-height);
//
//			}
//		delay_ms(delay);
//	}
//}
//
//   void quad_ripples(int iterations, int delay)
//{
//	// 16 values for square root of a^2+b^2.  index a*4+b = 10*sqrt
//	// This gives the distance to 3.5,3.5 from the point
//	unsigned char sqrt_LUT[]={49,43,38,35,43,35,29,26,38,29,21,16,35,25,16,7};
//	//LUT_START // Macro from new tottymath.  Commented and replaced with full code
//	unsigned char LUT[65];
//	init_LUT(LUT);
//	int i;
//	unsigned char x,y,height,distance;
//	for (i=0;i<iterations*4;i+=4)
//	{
//		fill(0x00);
//		for (x=0;x<4;x++)
//			for(y=0;y<4;y++)
//			{
//				// x+y*4 gives no. from 0-15 for sqrt_LUT
//				distance=sqrt_LUT[x+y*4];// distance is 0-50 roughly
//				// height is sin of distance + iteration*4
//				//height=4+totty_sin(LUT,distance+i)/52;
//				height=(196+totty_sin(LUT,distance+i))/49;
//				// Use 4-way mirroring to save on calculations
//				setvoxel(x,y,height);
//				setvoxel(7-x,y,height);
//				setvoxel(x,7-y,height);
//				setvoxel(7-x,7-y,height);
//				setvoxel(x,y,7-height);
//				setvoxel(7-x,y,7-height);
//				setvoxel(x,7-y,7-height);
//				setvoxel(7-x,7-y,7-height);
//				setvoxel(x,height,y);
//				setvoxel(7-x,height,y);
//				setvoxel(x,height,7-y);
//				setvoxel(7-x,height,7-y);
//				setvoxel(x,7-height,y);
//				setvoxel(7-x,7-height,y);
//				setvoxel(x,7-height,7-y);
//				setvoxel(7-x,7-height,7-y);
//
//
//			}
//		delay_ms(delay);
//	}
//}
//
//void init_LUT(unsigned char LUT[65])
//{
//	unsigned char i;
//	float sin_of,sine;
//	for (i=0;i<65;i++)
//	{
//		sin_of=i*PI/64; // Just need half a sin wave
//		sine=sin(sin_of);
//		// Use 181.0 as this squared is <32767, so we can multiply two sin or cos without overflowing an int.
//		LUT[i]=sine*181.0;
//	}
//}
//     void effect_axis_updown_randsuspend (char axis, int delay, int sleep, int invert)
//{
//	unsigned char positions[64];
//	unsigned char destinations[64];
//
//	int i,px;
//	
//    // Set 64 random positions
//	for (i=0; i<64; i++)
//	{
//		positions[i] = 0; // Set all starting positions to 0
//		destinations[i] = rand()%8;
//	}
//
//    // Loop 8 times to allow destination 7 to reach all the way
//	for (i=0; i<8; i++)
//	{
//        // For every iteration, move all position one step closer to their destination
//		for (px=0; px<64; px++)
//		{
//			if (positions[px]<destinations[px])
//			{
//				positions[px]++;
//			}
//		}
//        // Draw the positions and take a nap
//		draw_positions_axis (axis, positions,invert);
//		delay_ms(delay);
//	}
//	
//    // Set all destinations to 7 (opposite from the side they started out)
//	for (i=0; i<64; i++)
//	{
//		destinations[i] = 7;
//	}
//	
//    // Suspend the positions in mid-air for a while
//	delay_ms(sleep);
//	
//    // Then do the same thing one more time
//	for (i=0; i<8; i++)
//	{
//		for (px=0; px<64; px++)
//		{
//			if (positions[px]<destinations[px])
//			{
//				positions[px]++;
//			}
//			if (positions[px]>destinations[px])
//			{
//				positions[px]--;
//			}
//		}
//		draw_positions_axis (axis, positions,invert);
//		delay_ms(delay);
//	}
//}
//
//     void linespin (int iterations, int delay)
//{
//	float top_x, top_y, top_z, bot_x, bot_y, bot_z, sin_base;
//	float center_x, center_y;
//
//	center_x = 4;
//	center_y = 4;
//
//	int i, z;
//	for (i=0;i<iterations;i++)
//	{
//
//		//printf("Sin base %f \n",sin_base);
//
//		for (z = 0; z < 8; z++)
//		{
//
//		sin_base = (float)i/50 + (float)z/(10+(7*sin((float)i/200)));
//
//		top_x = center_x + sin(sin_base)*5;
//		top_y = center_x + cos(sin_base)*5;
//		//top_z = center_x + cos(sin_base/100)*2.5;
//
//		bot_x = center_x + sin(sin_base+3.14)*10;
//		bot_y = center_x + cos(sin_base+3.14)*10;
//		//bot_z = 7-top_z;
//		
//		bot_z = z;
//		top_z = z;
//
//		// setvoxel((int) top_x, (int) top_y, 7);
//		// setvoxel((int) bot_x, (int) bot_y, 0);
//
//		//printf("P1: %i %i %i P2: %i %i %i \n", (int) top_x, (int) top_y, 7, (int) bot_x, (int) bot_y, 0);
//
//		//line_3d((int) top_x, (int) top_y, (int) top_z, (int) bot_x, (int) bot_y, (int) bot_z);
//		line_3d((int) top_z, (int) top_x, (int) top_y, (int) bot_z, (int) bot_x, (int) bot_y);
//		}
//
//		// delay_ms(delay);
//		fill(0x00);
//	}
//
//}
//void line_3d (int x1, int y1, int z1, int x2, int y2, int z2)
//{
//	int i, dx, dy, dz, l, m, n, x_inc, y_inc, z_inc,
//	err_1, err_2, dx2, dy2, dz2;
//	int pixel[3];
//	pixel[0] = x1;
//	pixel[1] = y1;
//	pixel[2] = z1;
//	dx = x2 - x1;
//	dy = y2 - y1;
//	dz = z2 - z1;
//	x_inc = (dx < 0) ? -1 : 1;
//	l = abs(dx);
//	y_inc = (dy < 0) ? -1 : 1;
//	m = abs(dy);
//	z_inc = (dz < 0) ? -1 : 1;
//	n = abs(dz);
//	dx2 = l << 1;
//	dy2 = m << 1;
//	dz2 = n << 1;
//	if ((l >= m) && (l >= n)) {
//	err_1 = dy2 - l;
//	err_2 = dz2 - l;
//	for (i = 0; i < l; i++) {
//	//PUT_PIXEL(pixel);
//	setvoxel(pixel[0],pixel[1],pixel[2]);
//	//printf("Setting %i %i %i \n", pixel[0],pixel[1],pixel[2]);
//	if (err_1 > 0) {
//	pixel[1] += y_inc;
//	err_1 -= dx2;
//	}
//	if (err_2 > 0) {
//	pixel[2] += z_inc;
//	err_2 -= dx2;
//	}
//	err_1 += dy2;
//	err_2 += dz2;
//	pixel[0] += x_inc;
//	}
//	} else if ((m >= l) && (m >= n)) {
//	err_1 = dx2 - m;
//	err_2 = dz2 - m;
//	for (i = 0; i < m; i++) {
//	//PUT_PIXEL(pixel);
//	setvoxel(pixel[0],pixel[1],pixel[2]);
//	//printf("Setting %i %i %i \n", pixel[0],pixel[1],pixel[2]);
//	if (err_1 > 0) {
//	pixel[0] += x_inc;
//	err_1 -= dy2;
//	}
//	if (err_2 > 0) {
//	pixel[2] += z_inc;
//	err_2 -= dy2;
//	}
//	err_1 += dx2;
//	err_2 += dz2;
//	pixel[1] += y_inc;
//	}
//	} else {
//	err_1 = dy2 - n;
//	err_2 = dx2 - n;
//	for (i = 0; i < n; i++) {
//	setvoxel(pixel[0],pixel[1],pixel[2]);
//	//printf("Setting %i %i %i \n", pixel[0],pixel[1],pixel[2]);
//	//PUT_PIXEL(pixel);
//	if (err_1 > 0) {
//	pixel[1] += y_inc;
//	err_1 -= dz2;
//	}
//	if (err_2 > 0) {
//	pixel[0] += x_inc;
//	err_2 -= dz2;
//	}
//	err_1 += dy2;
//	err_2 += dx2;
//	pixel[2] += z_inc;
//	}
//	}
//	setvoxel(pixel[0],pixel[1],pixel[2]);
//	//printf("Setting %i %i %i \n", pixel[0],pixel[1],pixel[2]);
//	//PUT_PIXEL(pixel);
//}
//
//
//// ******************************************
//
//
//int totty_sin(unsigned char LUT[65],int sin_of)
//{
//	unsigned char inv=0;
//	if (sin_of<0)
//	{
//		sin_of=-sin_of;
//		inv=1;
//	}
//	sin_of&=0x7f; //127
//	if (sin_of>64)
//	{
//		sin_of-=64;
//		inv=1-inv;
//	}
//	if (inv)
//		return -LUT[sin_of];
//	else
//		return LUT[sin_of];
//}
//
//     void fireworks (int iterations, int n, int delay)
//{
//	fill(0x00);
//
//	int i,f,e;
//
//	float origin_x = 3;
//	float origin_y = 3;
//	float origin_z = 3;
//
//	int rand_y, rand_x, rand_z;
//
//	float slowrate, gravity;
//
//	// Particles and their position, x,y,z and their movement, dx, dy, dz
//	float particles[n][6];
//
//	for (i=0; i<iterations; i++)
//	{
//
//		origin_x = rand()%4;
//		origin_y = rand()%4;
//		origin_z = rand()%2;
//		origin_z +=5;
//        origin_x +=2;
//        origin_y +=2;
//
//		// shoot a particle up in the air
//		for (e=0;e<origin_z;e++)
//		{
//			setvoxel(origin_x,origin_y,e);
//			delay_ms(600+500*e);
//			fill(0x00);
//		}
//
//		// Fill particle array
//		for (f=0; f<n; f++)
//		{
//			// Position
//			particles[f][0] = origin_x;
//			particles[f][1] = origin_y;
//			particles[f][2] = origin_z;
//			
//			rand_x = rand()%200;
//			rand_y = rand()%200;
//			rand_z = rand()%200;
//
//			// Movement
//			particles[f][3] = 1-(float)rand_x/100; // dx
//			particles[f][4] = 1-(float)rand_y/100; // dy
//			particles[f][5] = 1-(float)rand_z/100; // dz
//		}
//
//		// explode
//		for (e=0; e<25; e++)
//		{
//			slowrate = 1+tan((e+0.1)/20)*10;
//			
//			gravity = tan((e+0.1)/20)/2;
//
//			for (f=0; f<n; f++)
//			{
//				particles[f][0] += particles[f][3]/slowrate;
//				particles[f][1] += particles[f][4]/slowrate;
//				particles[f][2] += particles[f][5]/slowrate;
//				particles[f][2] -= gravity;
//
//				setvoxel(particles[f][0],particles[f][1],particles[f][2]);
//
//
//			}
//
//			delay_ms(delay);
//			fill(0x00);
//		}
//
//	}
//
//}
//
//
//    void effect_box_wamp(int delayt)
//    {
//      for(int k = 0; k < 3; k++){
//       for(int i = 0; i < 4; i++){
//         fill(0x00);
//        box_filled(3 - i, 3 - i, 3 - i, 4 + i, 4 + i, 4 + i);
//        delay_ms(delayt);
//       }
//       for(int i = 3; i >= 0; i--){
//         fill(0x00);
//        box_filled(3 - i, 3 - i, 3 - i, 4 + i, 4 + i, 4 + i);
//        delay_ms(delayt);
//       }
//      }
//     
//      for(int k = 0; k < 3; k++){
//       for(int i = 0; i < 4; i++){
//         fill(0x00);
//        box_walls(3 - i, 3 - i, 3 - i, 4 + i, 4 + i, 4 + i);
//        delay_ms(delayt);
//       }
//       for(int i = 3; i >= 0; i--){
//         fill(0x00);
//        box_walls(3 - i, 3 - i, 3 - i, 4 + i, 4 + i, 4 + i);
//        delay_ms(delayt);
//       }
//      }
//     
//      for(int k = 0; k < 3; k++){
//       for(int i = 0; i < 4; i++){
//         fill(0x00);
//        box_wireframe(3 - i, 3 - i, 3 - i, 4 + i, 4 + i, 4 + i);
//        delay_ms(delayt);
//       }
//       for(int i = 3; i >= 0; i--){
//         fill(0x00);
//        box_wireframe(3 - i, 3 - i, 3 - i, 4 + i, 4 + i, 4 + i);
//        delay_ms(delayt);
//       }
//      }
//    }
//     
//  
//   void effect_boxside_randsend_parallel (char axis, int origin, int delayt, int mode)
//    {
//            int i;
//            int done;
//            unsigned char cubepos[64];
//            unsigned char pos[64];
//            int notdone = 1;
//            int notdone2 = 1;
//            int sent = 0;
//           
//            for (i=0;i<64;i++)
//            {
//                    pos[i] = 0;
//            }
//           
//            while (notdone)
//            {
//                    if (mode == 1)
//                    {
//                            notdone2 = 1;
//                            while (notdone2 && sent<64)
//                            {
//                                    i = rand()%64;
//                                    if (pos[i] == 0)
//                                    {
//                                            sent++;
//                                            pos[i] += 1;
//                                            notdone2 = 0;
//                                    }
//                            }
//                    } else if (mode == 2)
//                    {
//                            if (sent<64)
//                            {
//                                    pos[sent] += 1;
//                                    sent++;
//                            }
//                    }
//                   
//                    done = 0;
//                    for (i=0;i<64;i++)
//                    {
//                            if (pos[i] > 0 && pos[i] <7)
//                            {
//                                    pos[i] += 1;
//                            }
//                                   
//                            if (pos[i] == 7)
//                                    done++;
//                    }
//                   
//                    if (done == 64)
//                            notdone = 0;
//                   
//                    for (i=0;i<64;i++)
//                    {
//                            if (origin == 0)
//                            {
//                                    cubepos[i] = pos[i];
//                            } else
//                            {
//                                    cubepos[i] = (7-pos[i]);
//                            }
//                    }
//                   
//                   
//                    delay_ms(delayt);
//                    draw_positions_axis(axis,cubepos,0);
//     
//            }
//           
//    }
//     
//     
//    void effect_rain (int iterations)
//    {
//            int i, ii;
//            int rnd_x;
//            int rnd_y;
//            int rnd_num;
//           
//            for (ii=0;ii<iterations;ii++)
//            {
//                    rnd_num = rand()%4;
//                   
//                    for (i=0; i < rnd_num;i++)
//                    {
//                            rnd_x = rand()%8;
//                            rnd_y = rand()%8;
//                            setvoxel(rnd_x,rnd_y,7);
//                    }
//                   
//                    delay_ms(1000);
//                    shift(AXIS_Z,-1);
//            }
//    }
//     
//    // Set or clear exactly 512 voxels in a random order.
//    void effect_random_filler (int delayt, int state)
//    {
//            int x,y,z;
//            int loop = 0;
//           
//           
//            if (state == 1)
//            {
//                    fill(0x00);
//            } else
//            {
//                    fill(0xff);
//            }
//           
//            while (loop<511)
//            {
//                    x = rand()%8;
//                    y = rand()%8;
//                    z = rand()%8;
//     
//                    if ((state == 0 && getvoxel(x,y,z) == 0x01) || (state == 1 && getvoxel(x,y,z) == 0x00))
//                    {
//                            altervoxel(x,y,z,state);
//                            delay_ms(delayt);
//                            loop++;
//                    }      
//            }
//    }
//     
//     
//    void effect_blinky2()
//    {
//            int i,r;
//            fill(0x00);
//           
//            for (r=0;r<2;r++)
//            {
//                    i = 750;
//                    while (i>0)
//                    {
//                            fill(0x00);
//                            delay_ms(i);
//                           
//                            fill(0xff);
//                            delay_ms(100);
//                           
//                            i = i - (15+(1000/(i/10)));
//                    }
//                   
//                    delay_ms(1000);
//                   
//                    i = 750;
//                    while (i>0)
//                    {
//                            fill(0x00);
//                            delay_ms(751-i);
//                           
//                            fill(0xff);
//                            delay_ms(100);
//                           
//                            i = i - (15+(1000/(i/10)));
//                    }
//            }
//     
//    }
//     
//    // Draw a plane on one axis and send it back and forth once.
//    void effect_planboing (int plane, int speedd)
//    {
//            int i;
//            for (i=0;i<8;i++)
//            {
//                    fill(0x00);
//            setplane(plane, i);
//                    delay_ms(speedd);
//            }
//           
//            for (i=7;i>=0;i--)
//            {
//                    fill(0x00);
//            setplane(plane,i);
//                    delay_ms(speedd);
//            }
//    }
//     
//     
//     
//     
//
