### Lab class 5, Structs

This problem considers two-dimensional free diffusion of particles that perform a random motion. We consider *N* particles that all start in the origin of the coordinate system *(0,0)*. In each time step, every particle moves the same distance r=1, but each one moves in a different, random direction. All directions should be considered equally probable.

After a certain time we want to plot the positions of all the particles and some statistical properties of their coordinates, in particular their center of mass
and the mean square displacement (MSD).

The code you obtain at the start contains already some infrastructure.
Get familiar with it.

Things that are missing are:
* The function `push(...)` that takes all particles and advances their coordinates
 **one timestep**. Propagate every particle forward by a distance of *r=1* into
 a random direction.

* The function `statistics(...)` should take all particles and calculate their
mean square displacement, i.e. the mean value of the squared distances of
the particles from the origin. Additionally the function shall calculate
the position of the center of mass.
