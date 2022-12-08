# philo_bonus

#### Bonus part of philosophers project.
Base version can be found here: https://github.com/daviswillard/philothreads

### About project:

• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.<br /><br />
• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.<br /><br />
• There are also forks on the table. There are as many forks as philosophers.<br /><br />
• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.<br /><br />
• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.<br /><br />
• Every philosopher needs to eat and should never starve.<br /><br />
• Philosophers don’t speak with each other.<br /><br />
• Philosophers don’t know if another philosopher is about to die.<br /><br />

### How to start:
Program should take the following arguments:<br /><br />
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]<br /><br />
◦ number_of_philosophers: The number of philosophers and also the number
of forks.<br /><br />
◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the sim-
ulation, they die.<br /><br />
◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.<br /><br />
◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.<br /><br />
◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.<br /><br />![Screenshot_20221208_165204](https://user-images.githubusercontent.com/82828987/206463390-c5311623-f864-49c4-984e-aed2aadc0981.png)

