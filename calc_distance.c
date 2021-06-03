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
else {
    dlat = lat2 - lat1;
    dlon = lon2 - lon1;
    a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    c = 2 * asin(sqrt(a));
    r = 6371;
    dist = c * r * 1000;

    return (dist);
  }
}

 double toRadians(double deg) {
  return (deg * pi / 180);
 }
