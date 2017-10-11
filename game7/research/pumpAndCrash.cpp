#include <math.h>
#include <stdio.h>

int computeP( int inD, int inS ) {
    int tempP = 2 + 8 * (inD - inS);
    
    if( tempP < 0 ) {
        return 0;
        }
    else {
        return tempP;
        }
    }


int newD( int inD, int inS ) {
    if( inS > inD ) {
        int change = (int)( floor( ( (float)inS - (float)inD ) / 2 ) );
        
        if( change > 0 ) {
            return inD + change;
            }
        else {
            return inS;
            }
        }
    else if( inS < inD ) {
        int change = (int)( floor( ( (float)inD - (float)inS ) / 2 ) );
        
        if( change > 0 ) {
            return inD - change;
            }
        else {
            return inS;
            }
        }
    else {
        return inD;
        }
    }


float computePf( float inD, int inS ) {
    float tempP = 2 + 8 * (inD - inS);
    
    if( tempP < 0 ) {
        return 0;
        }
    else {
        return tempP;
        }
    }


float newDf( float inD, int inS ) {
    if( inS > inD ) {
        float change = ( inS - inD ) / 2;
        
        if( change > 0 ) {
            return inD + change;
            }
        else {
            return inS;
            }
        }
    else if( inS < inD ) {
        float change = ( inD - inS ) / 2;
        
        if( change > 0 ) {
            return inD - change;
            }
        else {
            return inS;
            }
        }
    else {
        return inD;
        }
    }
    

int main() {
    
    for( int target=2; target<20; target++ ) {
        float money = 0;
        int units = 0;
        

        float d = 1;
        
        int s = 2 * target;
        
        
        float p = computeP( d, s );
        printf( "(s,d,p) = %d, %d, %d\n", s, (int)d, (int)p );
        

        money += p * s - 1 * s;
        
        units += s;
        

        d = newD( d, s );

        s = 1;
        
        while( d>1 ) {
            p = computeP( d, s );
            printf( "(s,d,p) = %d, %d, %d\n", s, (int)d, (int)p );

            money += p * s - 1 * s;
            units += s;
            
            d = newD( d, s );
            }

        /*
        // last one
        p = computeP( d, s );
        printf( "(s,d,p) = %d, %d, %d\n", s, (int)d, (int)p );

        money += p * s - 1 * s;
        units += s;
        */

        printf( "%d %f %f %d\n", 
                target, (float)money / (float)units, money, units );
        }
    }

        
        
