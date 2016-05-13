/*
 The Global Positioning System (GPS), a satellite positioning system developed by the US Department of Defense, has revolutionized positioning and navigation. In standalone mode, the system is able to provide real-time positions anywhere on earth, at any time of the day or night. GPS has found many uses amongst civilians and the private sector, too. In conjunction with a second GPS receiver, points can be positioned to millimetre level accuracy for geomatics- and surveying- related applications. Industry experts predict that positional information will become as commonplace as the time of day.
 This program defines a struct to represent 3D points positioned on the earth's surface by GPS, or some other positioning technique. It can then perform a number of operations on these points.
 */

#ifndef COORD_H
#define COORD_H

struct Point3D
{
    int id = 0; // ID of point
    double x_coord = 0.0; // x-coordinate of point
    double y_coord = 0.0; // y-coordinate of point
    double z_coord = 0.0; // z-coordinate of point
    char order = ' '; // accuracy of point
};

void get_point (Point3D &point);  // gets information for the ID, the x, y, and z values, and the accuracy of the point
void print_point (const Point3D &point); // outputs the 3D point entered by user
double spatial_dist (Point3D &point1, Point3D &point2); // computes the spatial distance between 2 points
double plani_dist (Point3D &point1, Point3D &point2); // computes the planimetric distance between 2 points
double ht_diff (Point3D &point1, Point3D &point2); // computes the height difference between 2 points in the Z direction
double azimuth (Point3D &point1, Point3D &point2); //computes the azimuth, which is measured clockwise from north, between 2 points

#endif








