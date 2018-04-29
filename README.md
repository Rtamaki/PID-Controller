# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)


## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## The PID Controller Implementation
The PID controller here was based in the code from the lessons from Module 2 Sel Driving Car Nanodegree. This project aims only to implement a control method to steer the car angle in the simulator from Term 2. All car position as well as the desired postion were already written and are not part of the scop of this project.
In summary, in this projectb I only added the necessary code to implement a PID controller and tunned the parameter

## The PID Controller Parameters
The PID contains 3 parameters 
1) Kp: which multiples the cross-track error(cte)
2) Kd: which multiples the derivate of the cross-track error
3) Ki: whichb multiples the sum(integration) of all the cross-track error

In basic control theory, we learn that when implementing a PID controller(actually ANY kind of linear controller) we need to make the transfer function of the closed loop system with no positives poles. The optimaly parameters for the controller are those that make the closed-loop system critically damped, that is, with no oscilation and with the highest speed possible to attain the marginal error.

However, here we don't have the plant(the car) transfer function, so we can't calculate the perfect parameters. Here we would also need to apply the discretization functions of discrete control theory, since the PID is programmed and not phisically implemented through electrical/mechanical instruments.

So to attain the given parameters we would need to experiment for the given track several times by applying a numerical optimization algorith, such as Newton's, Gradient Descend or "twidlle" (which personaly I don't like in the least because it is not optimized to attain stability, is weak against local minimum/maximum, and I not even sure if it stable, though I may be mistaken in this last one).

In this project, I did not apply any numeric algorithm, since the bottleneck is the simulation time and it is visually easy to not if the PID will stabilize the system or not. Also, if one understand wthe influence of each paramater, one can easily tune to repair the error.
In general:
1) Ki: needs to be small since it will multiply the SUM of all the erros. Also because of the nature of the integration, it will make the system slower to sudden changes (making it more stable to disturbances but may also make it too slow to environmet changes)
2) Kd: need to be greater than Kp to make the system stable(ad ideally, one degree order greater). It makes the system respond quicker to environment changes, but will make it "bumpy" because it will create oscilations from noise
3) Is the basic parameter and its influnce is a bitof the other two. If it is bigger, it will make the error more quickly disappear, but will also create greater oscilations and can even make the system unstable.

In the end, the set of parameters that worked for me were:
Kp = .1
Ki = 0.0001
Kd = 1





