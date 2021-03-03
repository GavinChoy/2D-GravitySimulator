_University Course Assignment_

# 2D-GravitySimulator

I set myself the following additional goal (devised by me):

I know that there are no analytical solutions to the N-body problem so numerical simulations will need to be used for modelling the motion of the bodies which I am interested in. Using the simpler Euler's method enabled me to focus my efforts into making a simulator that could accept as many particles as required; an array stores all the particles (which have their own class) which are looped through to calculate the resultant forces on each particle. The resultant force will be used to calculate the change in velocity over a short time interval. Then, the velocity is modified to the new value. Finally, the time interval multiplied by the velocity is added to the position. My solution here is a two-dimensional program for simplicity, but it will be straightforward to extend the number of components. This cycle repeats until the maximum number of iterations allowed has been reached.

The resultant force on each particle is calculated as follows: for each other particle (excluding self), calculate the force contribution from the other particle on each dimension. All the contributions are then summed using a private variable in the Particle class. This implementation increases the flexibility, and therefore usefulness, of my program as any number of particles can be simulated by looping through the array of particles. A useful further improvement could be having user input (through the terminal or through a configuration file) for defining the particles, and the program determining the number of particles required and setting up the array of particles. To complete Assessment 5 within a reasonable time, I opted to loop through all the particle-particle combinations which reduced complexity; however, this is costly in computation time especially for systems with more particles. Perhaps, a good improvement would be to use Newton's Third Law which states that for each particle-particle interaction, the forces are equal and opposite - this would halve the number of calculations my program makes.

For this assessment, I wanted to build my own program instead of using the example source code so that I can simulate an n-body system. I also wanted to experiment with writing classes which was suitable for the particle - all the properties and methods relating are contained within the Particle class itself which improves code maintainability and reduces the likelihood of programming errors. Through writing the code myself, I encountered some interesting points for learning: for instance, I learnt that using sizeof(array) was not accurate when used on arrays of the Particle type so I had to implement a MAX_PARTICLES constant to end the loops. I also used double precision floating points for all physical quantities for accuracy and to allow for large numbers (like the Gravitational Constant, the masses and the distance) to be used.

After all the calculations have been done and recorded in a file, I used GNUPlot to display the paths of the particles. A bash script automates the calculation and the plotting.

The following figure was generated using the particles, their initial conditions and other parameters hardcoded in the source code provided:

![Output plot using the parameters provided in the source code.](/plot.png)

GitHub repository: https://github.com/GavinChoy/2D-GravitySimulator

My solution was in four files called 2D-GravitySimulator.cpp, Particle.cpp, run\_plot_simulation.sh and gnuplotter.gnu.
