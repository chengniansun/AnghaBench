#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  double FT_Fixed ;

/* Variables and functions */
 int FT_ANGLE_2PI ; 
 double FT_Sin (int) ; 
 int SPI ; 
 scalar_t__ THRESHOLD ; 
 scalar_t__ abs (double) ; 
 int error ; 
 int /*<<< orphan*/  printf (char*,int,double,int,double) ; 
 double sin (int) ; 

__attribute__((used)) static void
  test_sin( void )
  {
    int  i;


    for ( i = 0; i < FT_ANGLE_2PI; i += 0x10000L )
    {
      FT_Fixed  f1, f2;
      double    d2;


      f1 = FT_Sin(i);
      d2 = sin( i*SPI );
      f2 = (FT_Fixed)(d2*65536.0);

      if ( abs( f2-f1 ) > THRESHOLD )
      {
        error = 1;
        printf( "FT_Sin[%3d] = %.7f  sin[%3d] = %.7f\n",
                (i >> 16), f1/65536.0, (i >> 16), d2 );
      }
    }
  }