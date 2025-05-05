import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static Long a, b;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        a = sc.nextLong();
        b = sc.nextLong();

        Long lcm = a * b / getGcd(a, b);
        System.out.println(lcm);
    }

    public static Long getGcd(Long a, Long b) {
        if (b == 0) return a;
        else return getGcd(b, a % b);
    }
}