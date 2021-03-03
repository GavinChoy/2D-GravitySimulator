/**
* 2D Gravity Simulator
* Copyright (C) 2021  Gavin Choy
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include<cmath>
using namespace std;

class Particle{

    private:

        double m = 1;
        double x = 0;
        double y = 0;
        double vx = 0;
        double vy = 0;

        double fx = 0;
        double fy = 0;

    public:

        Particle(double new_m, double new_x, double new_y, double new_vx, double new_vy){
            m = new_m;
            x = new_x;
            y = new_y;
            vx = new_vx;
            vy = new_vy;
        }

        double get_m(){return m;}

        double get_x(){return x;}

        double get_y(){return y;}

        double get_vx(){return vx;}

        double get_vy(){return vy;}

        void advance(){
            x += fx / m;
            y += fy / m;

            fx = 0;
            fy = 0;
        }

        void add_forces(double G, double m2, double x2, double y2){
            double distance = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));

            fx += G * m * m2 * (x - x2) / pow(distance, 3);
            fy += G * m * m2 * (y - y2) / pow(distance, 3);
        }
};
