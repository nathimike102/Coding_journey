import java.util.Scanner;
public class LargestOfTwo{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int max;
		if(a>b){
			max=a;
		}
		else{
			max=b;
		}
		//Using Tenary
		int tMax = (a>b ? a : b);
		System.out.println(max);
		System.out.println(tMax);
		sc.close();
	}
}