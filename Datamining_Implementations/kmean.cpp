#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

void kmean ( double vals[200][4], int n )
{
	int cluster[200];
	double mean[3][4];
    int onnum;
	srand ( time( NULL ) ) ;
	int ran[3];
	ran[0] = rand ( ) % n;
	ran[1] = rand ( ) % n;
	ran[2] = rand ( ) % n;
	
	for ( int i  = 0 ; i < 3 ; i++ ) {
		for ( int j = 0 ; j < 4 ; j++ ) {
			mean[i][j] = vals[ran[i]][j];
		}
	}
	
	while ( true ) {
		int num_cluster[3] = { 0 , 0 , 0 };
		
		for ( int i = 0; i < n ; i++ ) {
			double min = INT_MAX;
			int index = 0;
			for ( int j = 0 ; j < 3 ; j++ ) {
				double t = abs( (vals[i][0] - mean[j][0]) ) + abs( (vals[i][1] - mean[j][1]) ) + abs( (vals[i][2] - mean[j][2]) ) + abs( (vals[i][3] - mean[j][3]) );
				if ( t < min ) {
					min = t;
					index = j;
				}
			}
			cluster[i] = index;
			num_cluster[index]++;
		}
		
		double temp[3][4];
		
		for ( int i = 0 ; i < 3 ; i++ ) {
			for ( int j = 0 ; j < 4 ; j++ ) {
				temp[i][j] = 0;
			}
		}
		
		for ( int i  = 0 ; i < n ; i++ ) {
			for ( int j = 0 ; j < 4 ; j++ ) {
				temp[cluster[i]][j] += vals[i][j];
			}
		}
		
		for ( int i = 0 ; i < 3 ; i++ ) {
			for ( int j = 0 ; j < 4 ; j++ ) {
				temp[i][j] /= num_cluster[i];
			}
		}
		
		bool flag = true;
		for ( int i = 0 ; i < 3 ; i++ ) {
			if ( abs( mean[i][0] - temp[i][0] ) > 0.5 or abs( mean[i][1] - temp[i][1] ) > 0.5 or abs( mean[i][2] - temp[i][2] ) > 0.5 or abs( mean[i][3] - temp[i][3] ) > 0.5 ) {
				flag = false;
				break;
			}
		}
		
		if ( flag ) {
			cout << num_cluster[0] << " " << num_cluster[1] << "  " << num_cluster[2] << endl;
			break;
		} else {
			for ( int i = 0 ; i < 3 ; i++ ) {
				for ( int j = 0 ; j < 4 ; j++ ) {
					mean[i][j] = temp[i][j];
				}
			}
		}
	}
	
	for ( int i = 0 ; i < n ; i++ ) {
		cout << i << "  " << cluster[i] << endl;
	}
}



int main()
{
	FILE *in = fopen( "iris.data", "r" );
	
	double a[200][4];
	double temp = 0.0;
	
	char s[200];
	char *p;
	int i , count;
	i = 0;
	while ( !feof( in ) ) {
		fgets( s, 200, in );
		p = strtok ( s, "," );
		count = 0;
		while ( p != NULL ) {
			temp = atof( p );
			p = strtok ( NULL, "," );
			if ( count == 4 ) {
				break;
			}
			a[i][count] = temp;
			count++;
		}
		i++;
	}
	
	kmean( a, i-1 );
	
	return 0;
}
