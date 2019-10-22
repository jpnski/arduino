#include <CheapStepper.h>
                                  
CheapStepper stepper (8, 9, 10, 11);
boolean moveClockwise = true;

void setup() 
{
  stepper.setRpm(20);
  
  for (int s=0; s<4096; s++)
  {
   stepper.step(moveClockwise);
   int nStep = stepper.getStep();
    
   }
}

void loop() 
{

}
