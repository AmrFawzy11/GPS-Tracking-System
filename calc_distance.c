#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265358979323846

// Functions prototypes 
double toRadians(double);
double distance(double lat1, double lon1, double lat2, double lon2);

// the function calculates distance between two coordinate points using Haversine formula.
// lat1, lat2 are the latitudes of the first and second point respectivily.
// lon1, lon2 are the longitudes of the first and second point respectivily. 
 double distance(double lat1, double lat2, double lon1, double lon2) {
  double dlat, dlon, dist, a, c, r;
  
// convert the latitudes and the longitudes from decimal degree to radian degree.
        lat1 = toRadians(lat1);
        lat2 = toRadians(lat2);
        lon1 = toRadians(lon1);
        lon2 = toRadians(lon2);
  
// if the starting and the ending points are the same return zero   
  if ((lat1 == lat2) && (lon1 == lon2)) {
    return 0;
  }
else {
    // Haversine formula
    dlat = lat2 - lat1;
    dlon = lon2 - lon1;
    a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    c = 2 * asin(sqrt(a));
    r = 6371;                       // r is the Radius of earth in kilometers.
    dist = c * r * 1000;

    return (dist);
  }
}
// the function converts the decimal degree to radian degree.
 double toRadians(double deg) {
  return (deg * pi / 180);
 }
