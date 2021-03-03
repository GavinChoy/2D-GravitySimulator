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

set key outside
plot 'points.log' u 1:2 w points, 'points.log' u 3:4 w points, 'points.log' u 5:6 w points
pause -1 "Press enter to exit"
