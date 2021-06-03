#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265358979323846
double toRadians(double);
double distance(double lat1, double lon1, double lat2, double lon2);


 double distance(double lat1, double lat2, double lon1, double lon2) {
  double dlat, dlon, dist, a, c, r;
  
        lat1 = toRadians(lat1);
        lat2 = toRadians(lat2);
        lon1 = toRadians(lon1);
        lon2 = toRadians(lon2);
        
  if ((lat1 == lat2) && (lon1 == lon2)) {
    return 0;
  }
 return 1;
}

 double toRadians(double deg) {
  return (deg * pi / 180);
 }