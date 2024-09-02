import java.util.Scanner;
class YoungPhysicist{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x=0,y=0,z=0;
        int x1,y1,z1;
        for(int i=0;i<n;i++){
            x1 = sc.nextInt();
            y1 = sc.nextInt();
            z1 = sc.nextInt();
            x += x1;
            y += y1;
            z += z1;
        }
        if(x==0 && y==0 && z==0){
            System.out.println("Yes");
        }
        else{
            System.out.println("NO");
        }
        sc.close();
    }
}
