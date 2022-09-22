import controlP5.*;
import processing.serial.*;

Serial port;

ControlP5 cp5;

void setup()
{
  size(600, 600);
  port = new Serial(this, "/dev/cu.usbmodem14101", 9600);
  
  cp5 = new ControlP5(this);
  
  cp5.addButton("Forward")
  .setPosition(250, 100)
  .setSize(120, 70)
  ;
   cp5.addButton("Backward")
  .setPosition(250, 400)
  .setSize(120, 70)
  ;
  cp5.addButton("Left")
  .setPosition(50, 250)
  .setSize(120, 70)
  ;
  cp5.addButton("Right")
  .setPosition(450, 250)
  .setSize(120, 70)
  ;
  cp5.addButton("Stop")
  .setPosition(235, 215)
  .setSize(150, 150)
  ;
  cp5.addButton("Buzzer_On")
  .setPosition(15, 15)
  .setSize(50, 50)
  ;
  cp5.addButton("Buzzer_Off")
  .setPosition(525, 15)
  .setSize(50, 50)
  ;
}

void draw()
{
  background(111, 111, 111);
}

void Forward()
{
  port.write('F');
}

void Backward()
{
  port.write('B');
}

void Left()
{
  port.write('L');
}

void Right()
{
  port.write('R');
}

void Stop()
{
  port.write('S');
}

void Buzzer_On()
{
  port.write('V');
}

void Buzzer_Off()
{
  port.write('v');
}
