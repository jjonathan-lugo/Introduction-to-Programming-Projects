void tabulation(int const v, int const t)
{
	if (t >= 0 && t <= 12) //&& - checks if both conditions are true
	{
		print(" After");
		if (t < 10)
			print(" ");
			print(t); //print t in seconds
		print(" seconds, height is "); 
		print(height(v, t)); //print the height in feet
		print(" feet");
		new_line();
		wait(1); //wait(#) - print text at a certain pace
		tabulation(v, t + 1);
	}
}

//void main() //test tabulation function
//{
	//tabulation(201,0);
//}
