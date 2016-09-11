#include "Haversine.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R 6373
#define TO_RAD (3.1415926536 / 180)

using namespace std;

double ToRad( double nVal )
{
	return nVal * (3.1415926536/180);
}

double Haversine( long double nLat1, long double nLon1, long double nLat2,  long double nLon2 )
{
	double nRadius = 6372; // Earth's radius in Kilometers

	// Get the difference between our two points then convert the difference into radians
	double nDLat = ToRad(nLat2 - nLat1);  
	double nDLon = ToRad(nLon2 - nLon1); 

	nLat1 =  ToRad(nLat1);
	nLat2 =  ToRad(nLat2);
	
	double nA =	pow ( sin(nDLat/2), 2 ) +
				cos(nLat1) * cos(nLat2) * 
				pow ( sin(nDLon/2), 2 );
	
	double nC = 2 * atan2( sqrt(nA), sqrt( 1 - nA ));
	double nD = nRadius * nC;
	

	return nD*1000; // Return our calculated distance
}
	
	
	
	
	/*(double th1, double ph1, double th2, double ph2){

	double dx, dy, dz;
	ph1 -= ph2;
	ph1 *= TO_RAD, th1 *= TO_RAD, th2 *= TO_RAD;
 
	dz = sin(th1) - sin(th2);
	dx = cos(ph1) * cos(th1) - cos(th2);
	dy = sin(ph1) * cos(th1);
	return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}
*/