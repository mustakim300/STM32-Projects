
### Multiple_LED-Blink_Using_Timers


This project is about Multiple LED blink using Timers with the help of **STM32F103C8** microcontroller. In this I have used Timer delay . 
Here is the formula which is use to create require delay for the LED with the help of ARR and PSC register you can find that formula below.

**Time/Delay(sec)** = **`( (ARR+1)(PSC+1) ) / f`** 

In my case f is 8 MHz, if you are using these drivers please check first what is your frequency at that particular timer the you can apply this formula which is given above.


All things are done at register level you can find all the files in the repository itself.
You can find the Circuit-Diagram below which is used in this project.

**`Circuit :-`**

![Circuit](https://user-images.githubusercontent.com/68029648/196022790-cb56da7f-64c2-4b84-a1bc-cc865b66e447.png)



There is output video also available you can see the output in that.

**`Output-Video :`**




https://user-images.githubusercontent.com/68029648/196024063-6bcca36c-6e96-41f5-9288-3106258b6523.mp4


