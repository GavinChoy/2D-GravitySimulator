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

double const G = 6.67 * pow(10, -11);

double const TIME_INTERVAL = 100000;

int const MAX_ITERATIONS = 100000;
int const MAX_PARTICLES = 3;

void terminal_plot();

int main(){

    // Licence info on program start
    cout << "# " << endl;
    cout << "# " << "2D Gravity Simulator  Copyright (C) 2021  Gavin Choy\n";
    cout << "# " << "This program comes with ABSOLUTELY NO WARRANTY.\n";
    cout << "# " << "This is free software, and you are welcome to redistribute it\n";
    cout << "# " << "under certain conditions.\n\n";

    Particle particle1(2 * pow(10, 30), 0, 0, 5000, 0);

    Particle particle2(2 * pow(10, 30), 2.7 * pow(10, 12), 2.7 * pow(10, 12), -5000, 0);

    Particle particle3(5 * pow(10, 29), 1 * pow(10, 10), 5 * pow(10, 12), 0, 0);

    Particle particles[MAX_PARTICLES] = {particle1, particle2, particle3};

    for (int j = 0; j < MAX_PARTICLES; j++){
        cout << particles[j].get_x() << "\t" << particles[j].get_y() << "\t";
    }
    cout << endl;

    for (int i = 0; i < MAX_ITERATIONS; i++){

        for (int j = 0; j < MAX_PARTICLES; j++){

            for (int k = 0; k < MAX_PARTICLES; k++){

                if (k != j){
                    particles[j].add_forces(G, particles[k].get_m(), particles[k].get_x(), particles[k].get_y());
                }
            }
        }

        for (int j = 0; j < MAX_PARTICLES; j++){
            particles[j].advance(TIME_INTERVAL);

            cout << particles[j].get_x() << "\t" << particles[j].get_y() << "\t";
        }
        cout << endl;

    }

    return 0;
}

