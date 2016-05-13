/*
 The Global Positioning System (GPS), a satellite positioning system developed by the US Department of Defense, has revolutionized positioning and navigation. In standalone mode, the system is able to provide real-time positions anywhere on earth, at any time of the day or night. GPS has found many uses amongst civilians and the private sector, too. In conjunction with a second GPS receiver, points can be positioned to millimetre level accuracy for geomatics- and surveying- related applications. Industry experts predict that positional information will become as commonplace as the time of day.
 This program defines a struct to represent 3D points positioned on the earth's surface by GPS, or some other positioning technique. It can then perform a number of operations on these points.
 */

#include "coord.h" // includes header file with function declarations
#include <iostream>
#include <cmath>

using namespace std;

// gets information for the ID, the x, y, and z values, and the accuracy of the point
void get_point (Point3D &point)
{
    cout << "Please enter the ID for the point:\n";
    cin >> point.id;
    cout << "The ID of the point is: " << point.id << endl << endl;
    cout << "Please enter the x, y, and z values for the point:\n";
    cin >> point.x_coord >> point.y_coord >> point.z_coord;
    cout << "You entered " << point.x_coord << " for the value of x, " << point.y_coord << " for the value of y, and " << point.z_coord << " for the value of z.\n" << endl;
    do {
        cout << "Please enter the accuracy of point, where A = high accuracy, B = medium accuracy, and C = low accuracy.\n";
        cin >> point.order;
        cout << "The point is of accuracy: " << point.order << endl << endl;
    } while (point.order != 'a' && point.order != 'A' && point.order != 'b' && point.order != 'B' && point.order != 'c' && point.order != 'C');
}

// outputs the 3D point entered by user
void print_point (const Point3D &point)
{
    cout << "Point " << point.id << ": (" <<  point.x_coord << ", " << point.y_coord << ", " << point.z_coord << ")" << endl << endl;
}

// computes the spatial distance between 2 points
double spatial_dist (Point3D &point1, Point3D &point2)
{
    double s_dist = 0.0;
    s_dist = sqrt (pow ((point2.x_coord - point1.x_coord), 2) + pow ((point2.y_coord - point1.y_coord), 2) + pow ((point2.z_coord - point1.z_coord),2));
    return s_dist;
}

// computes the planimetric distance between 2 points
double plani_dist (Point3D &point1, Point3D &point2)
{
    double p_dist = 0.0;
    p_dist = sqrt (pow ((point2.x_coord - point1.x_coord), 2) + pow ((point2.y_coord - point1.y_coord), 2));
    return p_dist;
}

// computes the height difference between 2 points in the Z direction
double ht_diff (Point3D &point1, Point3D &point2)
{
    double h_dist = 0.0;
    h_dist = point2.z_coord - point1.z_coord;
    return h_dist;
}

//computes the azimuth, which is measured clockwise from north, between 2 points
double azimuth (Point3D &point1, Point3D &point2)
{
    double angle = 0.0;
    angle = atan2 ((point2.y_coord - point1.y_coord), (point2.x_coord - point1.x_coord));
    return angle; 
}
