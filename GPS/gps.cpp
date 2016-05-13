/*
 The Global Positioning System (GPS), a satellite positioning system developed by the US Department of Defense, has revolutionized positioning and navigation. In standalone mode, the system is able to provide real-time positions anywhere on earth, at any time of the day or night. GPS has found many uses amongst civilians and the private sector, too. In conjunction with a second GPS receiver, points can be positioned to millimetre level accuracy for geomatics- and surveying- related applications. Industry experts predict that positional information will become as commonplace as the time of day.
 This program defines a struct to represent 3D points positioned on the earth's surface by GPS, or some other positioning technique. It can then perform a number of operations on these points.
 */

#include "coord.h" // includes header file with function declaration
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    double sdist = 0.0; // variable for spatial distance
    double pdist = 0.0; // variable for planimetric distance
    double hdiff = 0.0; // variable for height difference
    double azi = 0.0; // variable for azimuth
    
    // variables in Point3D structure
    Point3D point1;
    Point3D point2;
    
    // collects all input needed to calculate the 4 pieces of information for both 3D points
    get_point (point1);
    get_point (point2);
    
    // prints 3D point variable
    print_point (point1);
    print_point (point2);
    
    // computes the spatial distance, planimetric distance, height difference, and azimuth for both points
    sdist = spatial_dist (point1,point2);
    pdist = plani_dist (point1,point2);
    hdiff = ht_diff (point1, point2);
    azi = azimuth (point1, point2);
    
    // outputs the 4 pieces of information to user (listed above)
    cout << "The spatial distance is: " << sdist << endl;
    cout << "The planimetric distance is: " << pdist << endl;
    cout << "The height difference is: " << hdiff << endl;
    cout << "The azimuth is: " << azi << endl;
    
    return 0;
}
