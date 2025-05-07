import java.util.LinkedList;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.Collections;
import java.util.Iterator;
import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static class Pair {
        int x;
        int y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    static int n, m, k, x;
    static int a, b;
    static boolean[] visited;
    static LinkedList<Integer> [] graph;
    static LinkedList<Integer> ans = new LinkedList<>();

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        visited = new boolean[n + 1];
        graph = new LinkedList[n + 1];

        for (int i = 1; i <= n; i++) {
            graph[i] = new LinkedList<Integer>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            graph[a].add(b);
        }

        bfs(x);

        if (ans.size() == 0) {
            System.out.println("-1");
        } else {
            Collections.sort(ans);
            Iterator<Integer> iter = ans.iterator();
            while (iter.hasNext()) {
                System.out.println(iter.next());
            }
        }
    }

    public static void bfs(int idx) {
        Queue<Pair> q = new LinkedList<>();
        visited[idx] = true;
        q.offer(new Pair(idx, 0));

        while (q.size() != 0) {
            Pair cc = q.poll();
            int cx = cc.x;
            int cdis = cc.y;

            Iterator<Integer> iter = graph[cx].listIterator();
            while(iter.hasNext()) {
                int nx = iter.next();
                if (!visited[nx]) {
                    visited[nx] = true;
                    if (cdis == k-1) {
                        ans.add(nx);
                    } else {
                        q.offer(new Pair(nx, cdis+1));
                    }
                }
            }
        }
    }
}

