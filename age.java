import java.io.*;
public class Test#!/bin/bash

echo "filename ???"
read fn

for f in $fn
 do
   cat $f
done
{
	public static void main(String ars[])
	{
		
		int i;
		String str;
		try
		{
			str="";
			FileReader fr=new FileReader("input.txt");
			FileWriter fw1=new FileWriter("even.txt");
			FileWriter fw2=new FileWriter("odd.txt");
			while((i=fr.read())!=-1)
			{
				
				if((char)i !='\n')
					str=str+(char)i;
				else
				{
					int num=Integer.parseInt(str);
					if (num%2==0)
					{
						fw1.write(str);
						fw1.write("\n");
					
					}
					else
					{
						fw2.write(str);
						fw2.write("\n");
					}
					str="";
				}
			}
			fr.close();
			fw1.close();
			fw2.close();
			
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	
	}

}
