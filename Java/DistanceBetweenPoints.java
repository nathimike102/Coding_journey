import java.util.Scanner;
public class DistanceBetweenPoints{
	public static void main(String[] args){
		Scanner read = new Scanner(System.in);
		int x1 = read.nextInt();
		int y1 = read.nextInt();
		int x2 = read.nextInt();
		int y2 = read.nextInt();

		double distance = Math.sqrt(Math.pow((x2-x1),2) + Math.pow((y2-y1),2));
		System.out.printf("%.4f",distance);
		read.close();
	}
}