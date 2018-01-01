/* coherent noise function over 1, 2 or 3 dimensions */
/* (copyright Ken Perlin) */

#ifndef PERLIN_NOISE_H
#define PERLIN_NOISE_H

#include "math_funcs.h"

#define B 0x100
#define BM 0xff

#define N 0x1000
#define NP 12   /* 2^N */
#define NM 0xfff

static int p[B + B + 2];
static float g3[B + B + 2][3];
static float g2[B + B + 2][2];
static float g1[B + B + 2];
static int start = 1;

static void init(void);

#define s_curve(t) ( t * t * (3. - 2. * t) )

#define lerp(t, a, b) ( a + t * (b - a) )

#define setup(i,b0,b1,r0,r1)\
	t = vec[i] + N;\
	b0 = ((int)t) & BM;\
	b1 = (b0+1) & BM;\
	r0 = t - (int)t;\
	r1 = r0 - 1.;

static double noise1(double arg);

static void normalize2(float v[2]);
static void normalize3(float v[3]);
static void init(void);

#endif // PERLIN_NOISE_H