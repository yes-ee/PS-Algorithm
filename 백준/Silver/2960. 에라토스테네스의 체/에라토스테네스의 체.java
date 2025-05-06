import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int n, k;
    static int[] arr;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        arr = new int[n+1];
        int cnt = 0;

        for (int i = 2; i <= n; i++) {
            if (arr[i] == 1) continue;
            for (int j = i; j <= n; j += i) {
                if (arr[j] == 1) continue;
                arr[j] = 1;
                cnt++;
                if (cnt == k) {
                    System.out.println(j);
                    return;
                } 
            }
        }

    }
}