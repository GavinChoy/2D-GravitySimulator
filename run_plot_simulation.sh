#!/bin/bash

# 2D Gravity Simulator
# Copyright (C) 2021  Gavin Choy
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

echo ""
echo "2D Gravity Simulator  Copyright (C) 2021  Gavin Choy"
echo ""
echo "This program comes with ABSOLUTELY NO WARRANTY."
echo "This is free software, and you are welcome to redistribute it"
echo "under certain conditions."
echo ""

# Run simulation and record the positions of the particles in a log file
./2D-GravitySimulator > points.log

# Plot the paths of the particles
gnuplot gnuplotter.gnu
