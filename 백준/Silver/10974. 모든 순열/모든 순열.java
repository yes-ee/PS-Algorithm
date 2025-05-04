import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int n;
    static List<Integer> list = new ArrayList<>();
    static boolean[] visited = new boolean[10];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        bfs();
    }

    public static void bfs() {
        if (list.size() == n) {
            // print
            for (int e : list) {
                System.out.print(e + " ");
            }
            System.out.println();
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;

            list.add(i);
            visited[i] = true;
            bfs();
            visited[i] = false;
            list.remove(list.size() - 1);
        }
    }
}