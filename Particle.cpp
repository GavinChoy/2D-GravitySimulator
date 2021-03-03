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

        // Mass of particle
        double m = 1;

        // Coordinates of particle
        double x = 0;
        double y = 0;

        // Velocity of particle
        double vx = 0;
        double vy = 0;

        // Temporary sum of the resultant force acting on particle
        double fx = 0;
        double fy = 0;

    public:

        Particle(double new_m, double new_x, double new_y, double new_vx, double new_vy){
            /**
            * Construct a Particle object.
            * @param new_m The mass of the particle.
            * @param new_x The initial x-coordinate of the particle.
            * @param new_y The initial y-coordinate of the particle.
            * @param new_vx The initial velocity in the x-direction of the particle.
            * @param new_vy The initial velocity in the y-direction of the particle.
            */

            m = new_m;
            x = new_x;
            y = new_y;
            vx = new_vx;
            vy = new_vy;
        }

        double get_m(){
            /**
            * @return Double The mass of this particle.
            */

            return m;
        }

        double get_x(){
            /**
            * @return Double The x-coordinate of this particle.
            */

            return x;
        }

        double get_y(){
            /**
            * @return Double The y-coordinate of this particle.
            */

            return y;
        }

        double get_vx(){
            /**
            * @return Double The velocity in the x-direction of this particle.
            */

            return vx;
        }

        double get_vy(){
            /**
            * @return Double The velocity in the y-direction of this particle.
            */

            return vy;
        }

        void advance(double dt){
            /**
            * Updates the position of this particle due to the resultant force acting.
            * @param dt The size of the time step.
            */

            // F = ma
            // v = at
            vx += (fx / m) * dt;
            vy += (fy / m) * dt;

            // new_x = x + vt
            x += vx * dt;
            y += vy * dt;

            // Reset the resulant force calculation for the next iteration
            fx = 0;
            fy = 0;
        }

        void add_forces(double G, double m2, double x2, double y2){
            /**
            * Calculates the force acting on this particle due to another particle.
            * @param G The gravitational constant.
            * @param m2 The mass of the other particle.
            * @param x2 The x-coordinate of the other particle.
            * @param y2 The y-coordinate of the other particle.
            */

            // Distance between the two particles
            double distance = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));

            // F = G m1 m2 / r^2 parallel to the path between the two particles
            fx += G * m * m2 * (x2 - x) / pow(distance, 3);
            fy += G * m * m2 * (y2 - y) / pow(distance, 3);
        }
};
