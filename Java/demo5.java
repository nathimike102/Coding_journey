
public class demo5 {
    //A function that takes N number of arguments
    static void add(int ... nums){
        //nums is an integer array
        int sum = 0;
        for(int i =0;i<nums.length;i++){
            sum += nums[i];
        }
        System.out.println(sum);
    }
    
    static int gcd(int a, int b){
        if(b == 0){
            return a;
        }
        return gcd(b, a%b);
    }
    static void lcm(int ... nums){
        int lcm = nums[0];
        for(int i=1;i<nums.length;i++){
            lcm = (((nums[i] * lcm)) / (gcd(nums[i], lcm)));
        }
    }

    static String first(String ... str){
        String s = "";
        for(int i=0;i<str.length;i++){
            s += str[i].charAt(0);
        }
        return s;
    }

    public static void main(String[] args){
        add(10, 20);
        add(20, 40, 50, 40);
        add(454, 345, 3535, 235, 2454, 3254);
    }
}
 