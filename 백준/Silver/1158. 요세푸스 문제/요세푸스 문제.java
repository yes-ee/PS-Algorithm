import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		Queue<Integer> q = new LinkedList<>();

		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= n; i++)
			q.add(i);

		sb.append("<");

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < k - 1; j++) {
				int x = q.peek();
				q.remove();
				q.add(x);
			}
			sb.append(q.peek()).append(", ");
			q.remove();
		}

		sb.append(q.peek()).append(">");

		System.out.println(sb);
	}
}
