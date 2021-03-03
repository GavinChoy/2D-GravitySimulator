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
#include <complex>
#include "Particle.cpp"
using namespace std;

double const G = 1;

double const TIME_INTERVAL = 0.1;

int const MAX_ITERATIONS = 10;

int const MAX_PARTICLES = 2;

void terminal_plot();

int main(){

    // Licence info on program start
    cout << endl;
    cout << "2D Gravity Simulator  Copyright (C) 2021  Gavin Choy\n";
    cout << "This program comes with ABSOLUTELY NO WARRANTY.\n";
    cout << "This is free software, and you are welcome to redistribute it\n";
    cout << "under certain conditions.\n\n";

    Particle particle1(1.02, 1.01, 1, 1, 1);

    Particle particle2(5, -2, 3.4, 4, 1);

    Particle particles[MAX_PARTICLES] = {particle1, particle2};

    for (int i = 0; i < MAX_ITERATIONS; i++){

        double time = i * TIME_INTERVAL;

        for (int j = 0; j < MAX_PARTICLES; j++){

            for (int k = 0; k < MAX_PARTICLES; k++){

                particles[j].add_forces(G, particles[k].get_m(), particles[k].get_x(), particles[k].get_y());

            }

        }

    }

    return 0;
}

