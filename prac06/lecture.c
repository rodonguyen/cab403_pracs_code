#include <stdio.h>

int main()
{
  monitor DiningPhilosophers
  {
    enum
    {
      THINKING,
      HUNGRY,
      EATING
    } state[5];

    condition self[5];

    void pickup(int i)
    {
      state[i] = HUNGRY;
      test(i);
      if (state[i] != EATING)
        self[i].wait();  // the process that invokes the operation is suspended until x.signal() 
    }

    void putdown(int i)
    {
      state[i] = THINKING;
      // check and let nearby phylosophers eat if they're hungry
      test((i + 4) % 5);
      test((i + 1) % 5);
    }

    /** If neighbours of i are not eating and i is hungry, i will eat */
    void test(int i)
    {
      if ((state[(i + 4) % 5] != EATING) &&
          (state[i] == HUNGRY) &&
          (state[(i + 1) % 5] != EATING))
      {
        state[i] = EATING; 
        self[i].signal();  //resumes one of processes (if any) that invoked x.wait()
      }
    }

    initialization_code()
    {
      for (int i = 0; i < 5; i++)
        state[i] = THINKING;
    }
  }
}
