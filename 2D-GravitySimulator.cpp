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

#include <iostream>
#include "Particle.cpp"
using namespace std;

// Gravitational Constant
double const G = 6.67 * pow(10, -11);

// The step length for time
double const TIME_INTERVAL = 100000;

// The maximum number of time steps to simulate
int const MAX_ITERATIONS = 100000;

// The number of particles to simulate
int const MAX_PARTICLES = 3;

void run_simulation(Particle particles[]);

int main(){

    // Licence info on program start
    cout << "# " << endl;
    cout << "# " << "2D Gravity Simulator  Copyright (C) 2021  Gavin Choy\n";
    cout << "# " << "This program comes with ABSOLUTELY NO WARRANTY.\n";
    cout << "# " << "This is free software, and you are welcome to redistribute it\n";
    cout << "# " << "under certain conditions.\n\n";

    // Define particles with initial conditions
    Particle particle1(2 * pow(10, 30), 0, 0, 5000, 0);

    Particle particle2(2 * pow(10, 30), 2.7 * pow(10, 12), 2.7 * pow(10, 12), -5000, 0);

    Particle particle3(5 * pow(10, 29), 1 * pow(10, 10), 5 * pow(10, 12), 0, 0);

    // Array of particles
    Particle particles[MAX_PARTICLES] = {particle1, particle2, particle3};

    // Run the simulation and output the positions of each particle into the terminal
    run_simulation(particles);

    return 0;
}

void run_simulation(Particle particles[]){
    /**
    * Calculates and records the positions of the particles at each point in time.
    * @param particles An array of the Particle class.
    */

    // Output the initial positions of each particle to the terminal
    // Format: "particle1_x particle1_y particle2_x particle2_y" et cetera
    cout << "# " << "Format: \"particle1_x particle1_y particle2_x particle2_y\" et cetera\n\n";
    for (int j = 0; j < MAX_PARTICLES; j++){
        cout << particles[j].get_x() << "\t" << particles[j].get_y() << "\t";
    }
    cout << endl;

    // Simulate each point in time up to the maximum number of iterations
    for (int i = 0; i < MAX_ITERATIONS; i++){

        // For each particle, calculate the resultant force
        for (int j = 0; j < MAX_PARTICLES; j++){

            // Sum the contributions of each particle pair
            for (int k = 0; k < MAX_PARTICLES; k++){

                // Do not count particle self in the contributions
                if (k != j){
                    particles[j].add_forces(G, particles[k].get_m(), particles[k].get_x(), particles[k].get_y());
                }
            }
        }

        // For each particle, calculate their new position
        // Also, output the positions to the terminal
        for (int j = 0; j < MAX_PARTICLES; j++){
            particles[j].advance(TIME_INTERVAL);

            cout << particles[j].get_x() << "\t" << particles[j].get_y() << "\t";
        }
        cout << endl;

    }
};

