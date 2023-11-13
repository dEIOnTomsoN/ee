import java.io.*;
public class Test2
{
	public static void main(String ars[])
	{
		
		int i;
		String str;
		try
		{
			str="";
			FileInputStream fr=new FileInputStream(new File("input.txt"));
			FileOutputStream fw1=new FileOutputStream(new File("even.txt"));
			FileOutputStream fw2=new FileOutputStream(new File("odd.txt"));
			while((i=fr.read())!=-1)
			{
				
				if((char)i !='\n')
					str=str+(char)i;
				else
				{
					System.out.println(str);
					int num=Integer.parseInt(str);
					if (num%2==0)
					{
						fw1.write(str.getBytes());
						fw1.write("\n".getBytes());
					
					}
					else
					{
						fw2.write(str.getBytes());
						fw2.write("\n".getBytes());
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