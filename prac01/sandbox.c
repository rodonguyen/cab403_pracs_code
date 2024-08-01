#include <stdio.h>
// #include <stdlib.h>
#include <limits.h> // this is called header file
#include <float.h>
#include <unistd.h>

#define PI 3.14159

float calculateCylinderVolume(float *radius, float *height);

float calculateCylinderVolumeNotSogood(float radius, float height);

int main()
{
  system("ps -o rss= -p $PPID");

  float radius = 5.5;
  float height = 6.6;
  calculateCylinderVolume(&radius, &height);
  // printf("The volume of the cylinder: %.5f\n", calculateCylinderVolume(&radius, &height));
  printf("The volume of the cylinder 2: %.5f\n", calculateCylinderVolumeNotSogood(radius, height));
  system("ps -o rss= -p $PPID");
}

float calculateCylinderVolume(float *radius, float *height) // float *radius = &radius, float *height = &height
{
  system("ps -o rss= -p $PPID");
  float result = PI * (*radius) * *radius * *height;
  system("ps -o rss= -p $PPID");
  return result;
}

float calculateCylinderVolumeNotSogood(float radius, float height) // float *radius = &radius, float *height = &height
{
  system("ps -o rss= -p $PPID");
  float result = PI * radius * radius * height;
  system("ps -o rss= -p $PPID");
  return result;
}