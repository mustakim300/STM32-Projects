/* This is a Software delay */
void delay(int ms)
{
	int ticks=((3000/4)*ms);

	for(int i=1;i<ticks;i++);

}
