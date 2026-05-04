*This project has been created as part of the 42 curriculum by smarques.*

## Description

The goal of this project is to understand the basics of threading a process and how to work within the same memory space. It introduces the concepts of concurrent programming, mutexes, data races, and deadlocks.

The project is based on Edsger Dijkstra's classic "Dining Philosophers problem". The simulation consists of philosophers sitting at a round table, alternating between three states: eating, sleeping, and thinking. Since they need two forks to eat and there is only one fork between each philosopher, resource management is required.

Handling an odd number of philosophers (like the classic 5) is particularly challenging because it naturally creates an asymmetry in resource distribution, increasing the risk of deadlocks if the lock ordering isn't managed perfectly.

## Instructions

To compile and run the project, navigate to the repository folder and use `make`:

```
cd philo
make
```

Execute the program with the following arguments:

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

* **`number_of_philosophers`**: The number of philosophers and also the number of forks.
* **`time_to_die`** (in ms): If a philosopher didn't start eating `time_to_die` milliseconds since the beginning of their last meal, they die.
* **`time_to_eat`** (in ms): The time it takes for a philosopher to eat (they need to hold two forks).
* **`time_to_sleep`** (in ms): The time a philosopher will spend sleeping.
* **`number_of_times_each_philosopher_must_eat`** *(optional)*: If all philosophers have eaten at least this many times, the simulation stops.

**Example of execution:**
```
./philo 5 800 200 200
```

## Resources

Most of the knowledge required for this project was acquired through peer-to-peer discussions, YouTube tutorials about multithreading in C, and some articles.

https://docs.oracle.com/cd/E19205-01/820-0619/geokj/index.html
https://docs.oracle.com/cd/E19205-01/820-0619/geojs/index.html
https://www.youtube.com/watch?v=zOpzGHwJ3MU
https://www.youtube.com/watch?v=IKG1P4rgm54
https://www.youtube.com/watch?v=oq29KUy29iQ

## How AI was used

AI was used for theoretical explanations. It helped me understand the concepts of the project, foresee potential concurrency issues (deadlocks and data races), and interpret complex Helgrind error logs during the debugging phase, since it was my first time using Helgrind.